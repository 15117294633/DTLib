#ifndef LISTGRAPH_H
#define LISTGRAPH_H
#include "Object.h"
#include "graph.h"
#include "LinkList.h"
#include "DynamicArray.h"
//临接链表表示法
namespace DTLib
{

template <typename V,typename E>
class  ListGraph:public Graph<V,E>
{
protected:
    struct Vertex:public Object
    {
        V* values;
        LinkList<Edge<E>> edge;
        Vertex()
        {
            values=NULL;
        }
    };
    LinkList<Vertex*> m_list;
public:
    ListGraph()
    {
    }
    ListGraph(unsigned int n)
    {
        for(int i=0;i<n;i++)
        {
           addVertex();
        }
    }
    int addVertex()
    {
        int ret=-1;
        Vertex* v=new Vertex();
        if(v!=NULL)
        {
            m_list.insert(v);//m_list数据
            ret=m_list.length()-1;//index operator
        }
        else
        {
        //throw ex
        }
        return ret;
    }
    int addVertex(const V& value)
    {
        int ret=addVertex();
        if(ret>=0)
        {
            setVertex(ret,value);
        }
        return ret;
    }
    //删除一个节点的时候，要把以他为end的值给删掉
    void removeVertex()
    {
        int index=m_list.length()-1;
        Vertex* v=m_list.get(index);
        if(m_list.remove(index))
        {
            for(int i=(m_list.move(0),0);!m_list.end();m_list.next(),i++)
            {
                int e_pos=m_list.current()->edge.find(Edge<E>(i,index));
                if(e_pos>=0)
                {
                    m_list.current()->edge.remove(e_pos);
                }
            }
            delete v->values;
            delete v;
        }

    }
    V getVertex(int i)
    {
        V   ret;
        if(!getVertex(i,ret))
        {
            //throw ex
        }
        return ret;
    }
    bool getVertex(int i,V& values)
    {
       bool ret=((0<=i)&&(i<vCount()));
       if(ret)
       {
         Vertex* v=m_list.get(i);
         if(v->values!=NULL)
         {
             values=*(v->values);
         }
         else
         {
             //throw ex
         }
       }
       return ret;
    }
    bool setVertex(int i,const V& values)
    {
       bool ret=((0<=i)&&(i<vCount()));
       if(ret)
       {
           Vertex* v=m_list.get(i);
           V* dat=v->values;
           if(dat==NULL)
           {
               dat=new V();//申请space
           }
           if(dat!=NULL)
           {
               *(dat)=values;
               v->values=dat;
           }
           else
           {
               //throw ex
           }
       }
       return ret;
    }
    SharedPointer<Array<int>> Adjacent(int i)
    {
        DynamicArray<int>* ret=NULL;
        if((0<=i)&&(i<vCount()))
        {
            Vertex* v=m_list.get(i);
            ret=new DynamicArray<int>(v->edge.length());
            if(ret!=NULL)
            {
               for(int k=(v->edge.move(0),0);!v->edge.end();v->edge.next(),k++)
               {
                   ret->set(k,v->edge.current().e);
               }
            }
        }
        return ret;
    }
    E getEdge(int i,int j)
    {
        E ret;
        if(!getEdge(i,j,ret))
        {

        }
        return ret;
    }
    bool getEdge(int i,int j,E& values)
    {
         bool ret=((0<=i)&&(i<vCount())&&(0<=j)&&(j<vCount()));
         if(ret)
         {
            Vertex* v=m_list.get(i);
            int pos=v->edge.find(Edge<E>(i,j));
            if(pos>=0)
            {
                values=v->edge.get(pos).value;
            }
            else
            {
                //throw ex
            }
         }
         return ret;
    }
    bool setEdge(int i,int j,const E& values)
    {
        bool ret=((0<=i)&&(i<vCount())&&(0<=j)&&(j<vCount()));
        if(ret)
        {
           Vertex* v=m_list.get(i);
           int pos=v->edge.find(Edge<E>(i,j));
           if(pos>=0)
           {
              ret=v->edge.set(pos,Edge<E>(i,j,values));
           }
           else
           {
              ret=v->edge.insert(0,Edge<E>(i,j,values));
           }
        }
        return ret;
    }

    bool removeEdge(int i,int j)
    {
     bool ret=((0<=i)&&(i<vCount())&&(0<=j)&&(j<vCount()));
     if(ret)
     {
         Vertex* v=m_list.get(i);
         int pos=v->edge.find(Edge<E>(i,j));
         if(pos>=0)
         {
            ret=v->edge.remove(pos);
         }
         else
         {
             //throw ex
         }
     }
     return ret;
    }
    int vCount()
    {
        return m_list.length();
    }
    int eCount()
    {
        int ret=0;
        for(m_list.move(0);!m_list.end();m_list.next())
        {
            ret+=m_list.current()->edge.length();
        }
        return ret;
    }
    int ID(int i)
    {
        int ret=0;
        if((0<=i)&&(i<vCount()))
        {
            for(m_list.move(0);!m_list.end();m_list.next())
            {
                LinkList<Edge<E>>& e=m_list.current()->edge;
                for(e.move(0);!e.end();e.next())
                {
                    if(e.current().e==i)
                    {
                        ret++;
                    }
                }
            }
        }
        return ret;
    }
    int  OD(int i)
    {
       int ret=0;
       if((0<=i)&&(i<vCount()))
       {
           ret=m_list.get(i)->edge.length();
       }
       return ret;
    }
    bool isAdjacent(int i,int j)
    {
        bool flag=(m_list.get(i)->edge.find(Edge<E>(i,j))>=0);
        return (0<=i)&&(i<vCount())&&(0<=j)&&(j<vCount()&&flag);
    }
    ~ListGraph()
    {
        while(m_list.length()>0)
        {
            Vertex* todel=m_list.get(0);
            m_list.remove(0);
            delete todel->values;
            delete todel;
        }
    }
};
}
#endif // LISTGRAPH_H
