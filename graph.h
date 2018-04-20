#ifndef GRAPH_H
#define GRAPH_H
#include "Object.h"
#include "SharedPointer.h"
#include "DynamicList.h"
#include "DynamicArray.h"
#include    "Array.h"
#include "LinkQueue.h"
#include "LinkStack.h"
#include "Sort.h"//排序
namespace DTLib
{
template <typename E>
struct Edge:public Object
{
  int b;
  int e;
  E value;
  Edge(int i=-1,int j=-1)
  {
    b=i;
    e=j;
  }
  Edge(int i,int j,const E& obj)
  {
    b=i;
    e=j;
    value=obj;
  }
  bool operator ==(const Edge<E>& obj)
  {
      return (b==obj.b)&&(e==obj.e);
  }
  bool operator !=(const Edge<E>&obj)
  {
      //操作符重载
      return !(*this==obj);
  }
  //重载比较操作符
  bool operator <(const Edge<E>& obj)
  {
      return (this->value<obj.value);
  }
  bool operator >(const Edge<E>& obj)
  {
      return (this->value>obj.value);
  }
};
template<typename V,typename E>
class Graph:public Object
{
protected:
    template <typename T>
    DynamicArray<T>* toArray(LinkQueue<T>& queue)
    {

        DynamicArray<T>* ret=new DynamicArray<T>(queue.length());
        if(ret!=NULL)
        {
            for(int i=0;i<ret->length();i++,queue.remove())
            {
                ret->set(i,queue.front());
            }
        }
        else
        {
            //抛出异常
        }
        return ret;
    }
    bool asUndirection()
    {
        bool ret=true;
        for(int i=0;i<vCount();i++)
        {
            for(int j=0;j<vCount();j++)
            {
                if(isAdjacent(i,j))
                {
                    ret=ret&&isAdjacent(j,i)&&(getEdge(i,j)==getEdge(j,i));
                }
             }
        }
        return ret;
    }
    SharedPointer<Array<Edge<E>>> getUndirectedEdges()
    {
        DynamicArray<Edge<E>>* ret=NULL;
        LinkQueue<Edge<E>> queue;
        if(asUndirection())
        {
            for(int i=0;i<vCount();i++)
            {
                for(int j=i;j<vCount();j++)
                {
                    if(isAdjacent(i,j))
                    {
                        queue.add(Edge<E>(i,j,getEdge(i,j)));
                    }
                }
            }
        }
        ret=toArray(queue);
        return ret;
    }
    int find(Array<int>& p,int v)
    {
        while(p[v]!=-1)
        {
            v=p[v];
        }
        return v;
    }
    //是否领接
    virtual bool isAdjacent(int i,int j)=0;
public:
    virtual V getVertex(int i)=0;
    virtual bool getVertex(int i,V& values)=0;
    virtual bool setVertex(int i,const V& values)=0;
    virtual SharedPointer<Array<int>> Adjacent(int i)=0;
    virtual E getEdge(int i,int j)=0;
    virtual bool getEdge(int i,int j,E& values)=0;
    virtual bool setEdge(int i,int j,const E& values)=0;
    virtual bool removeEdge(int i,int j)=0;
    virtual int vCount()=0;
    virtual int eCount()=0;
    virtual int OD(int i)=0;
    virtual int  ID(int i)=0;
    virtual int TD(int i)
    {
        return ID(i)+OD(i);
    }
    /*最小生成树算法*/
    //prim算法
    SharedPointer<Array<Edge<E>>> prim(const E& LIMIT)
    {
        LinkQueue<Edge<E>>   ret;
        if(asUndirection())
        {
            DynamicArray<bool> mark(vCount());
            DynamicArray<E> cost(vCount());
            DynamicArray<int> adjVex(vCount());
            SharedPointer<Array<int>> aj=NULL;//存放
            bool end=false;
            int v=0;
            //初始化工作
            for(int i=0;i<vCount();i++)
            {
               mark[i]=false;
               cost[i]=LIMIT;
               adjVex[i]=-1;
            }
            mark[v]=true;
            aj=Adjacent(v);//获取到其领接顶点
            for(int i=0;i<aj->length();i++)
            {
                cost[(*aj)[i]]=getEdge(v,(*aj)[i]);
                adjVex[(*aj)[i]]=v;
            }
            //算法开始主循环
            for(int i=0;i<vCount()&&!end;i++)
            {
                E m=LIMIT;
                int k=-1;
                for(int j=0;j<vCount();j++)
                {
                    //遍历F集合中的元素
                    if(!mark[j]&&cost[j]<m)
                    {
                        m=cost[j];
                        k=j;//record index
                    }
                }
                end=(k==-1);
                if(!end)
                {

                    ret.add(Edge<E>(adjVex[k],k,getEdge(adjVex[k],k)));//加入到返回队列里面
                    mark[k]=true;//标记其进入到mark数组中
                    aj=Adjacent(k);
                    for(int j=0;j<aj->length();j++)
                    {
                        if(!mark[(*aj)[j]]&&(getEdge(k,(*aj)[j])<cost[(*aj)[j]]))
                        {
                             //更新数组
                             cost[(*aj)[j]]=getEdge(k,(*aj)[j]);
                             adjVex[(*aj)[j]]=k;
                        }
                    }
                }
             }

        }
        else
        {
            THROW_EXCEPTION(InvalidOperatorException,"Prim operator is only for UNdirection graph");
        }

        if(ret.length()!=vCount()-1)
        {
            THROW_EXCEPTION(InvalidOperatorException,"No Enough edge for prim ");
        }
        return toArray(ret);
    }
    //Kruskal克鲁斯卡尔算法
    SharedPointer<Array<Edge<E>>> Kruskal(bool ismin=true)
    {
       DynamicArray<int> p(vCount());
       SharedPointer< Array<Edge<E>>> edge;//注意
       LinkQueue<Edge<E>> ret;
       //初始化操作
       edge=getUndirectedEdges();//获取到所有的边
       for(int i=0;i<vCount();i++)
       {
        p[i]=-1;//初始化为-1
       }
       Sort::Shell(*edge,ismin);//得到对应的智能指针的对象
       //主线操作 必须要注意长度信息
       for(int i=0;i<edge->length()&&(ret.length()<vCount());i++)
       {
            //Kruskal算法核心
           int b=find(p,(*edge)[i].b);
           int e=find(p,(*edge)[i].e);
           if(b!=e)
           {
               p[e]=b;
               ret.add((*edge)[i]);
           }
       }
       if(ret.length()!=vCount()-1)
       {
           THROW_EXCEPTION(InvalidOperatorException,"No Enough edge for prim ");
       }
       return toArray(ret);
    }
    //dijkstra迪杰斯特拉算法
    //param：i->j
    SharedPointer<Array<int>>Dijkstra(int i,int j,const E& LIMIT)
    {
         DynamicArray<E> dist(vCount());//记录i->j的权值
         DynamicArray<int> path(vCount());
         DynamicArray<int> mark(vCount());
         LinkQueue<int> ret;
         for(int k=0;k<vCount();k++)
         {
             dist[k]=isAdjacent(i,k)?path[k]=i,getEdge(i,k):LIMIT;
             path[k]=-1;
             mark[k]=false;
         }

         //算法核心
         mark[i]=true;
         for(int k=0;k<vCount();k++)
         {
             E max=LIMIT;
             int u=-1;//记录
             for(int m=0;m<vCount();m++)
             {
                 //注意运算符级别
                if(!mark[i]&&(dist[m]<max))
                {
                    max=dist[m];
                    u=m;
                }
             }
             if(u==-1)
             {
                 break;
             }
             mark[u]=true;
             for(int m=0;m<vCount();m++)
             {
                 if(!mark[m]&&isAdjacent(u,m)&&((dist[u]+getEdge(u,m)<dist[m])))
                 {
                     dist[m]=dist[u]+getEdge(u,m);
                     path[m]=u;
                 }
             }

         }
         for(int i=0;i<vCount();i++)
         {
             cout<<path[i]<<endl;
         }
         LinkStack<int> s;
        /*
         s.push(j);
         for(int k=path[j];k!=-1;k=path[k])
         {
             s.push(k);
         }
         */
         /*
         while(s.size()>0)
         {
             ret.add(s.top());
             s.pop();
         }
         */
         return toArray(ret);
    }
    //深度优先便利算法
    SharedPointer<Array<int>> DFS(int i)
    {
        DynamicArray<int>* ret=NULL;
        if((0<=i)&&(i<vCount()))
        {

         LinkStack<int> in;
         LinkQueue<int> out;
         DynamicArray<bool> visited(vCount());
         for(int i=0;i<visited.length();i++)
         {
             visited[i]=false;
         }
         in.push(i);
         while(in.size()>0)
         {
             int value=in.top();
             in.pop();
             if(!visited[value])
             {
                 SharedPointer<Array<int>> aj=Adjacent(value);
                 for(int j=aj->length()-1;j>=0;j--)
                 {
                     in.push((*aj)[j]);
                 }
                 out.add(value);
                 visited[value]=true;
             }
         }
          ret=toArray(out);
        }
        return ret;
    }
    //宽度优先遍历算法
    SharedPointer<Array<int>> BFS(int i)
    {
        DynamicArray<int>* ret=NULL;
        LinkQueue<int> in;
        LinkQueue<int> out;
        DynamicArray<bool> visited(vCount());

        for(int i=0;i<visited.length();i++)
        {
            visited[i]=false;
        }
        in.add(i);
        while (in.length()>0)
        {
            int v=in.front();
            in.remove();//删除操作
            if(!visited[v])
            {
                SharedPointer<Array<int>> sp=Adjacent(v);
                for(int j=0;j<sp->length();j++)
                {
                  in.add((*sp)[j]);
                }
                out.add(v);
                visited[v]=true;
            }
        }
        ret=toArray(out);
        return ret;
    }

};
}
#endif // GRAPH_H
