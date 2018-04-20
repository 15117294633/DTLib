#ifndef MATRIXGRAPH_H
#define MATRIXGRAPH_H
#include "graph.h"
#include "DynamicArray.h"
namespace DTLib
{
template <int N,typename V,typename E>
class MatrixGraph:public Graph<V,E>
{
protected:
    //模板技术开发
    V* vertexes[N];
    E* m_edges[N][N];
    int m_ecount;//record edge number
public:
    MatrixGraph()
    {
        for(int i=0;i<vCount();i++)
        {
            vertexes[i]=NULL;
            for(int j=0;j<vCount();j++)
            {
                //m_edges
                m_edges[i][j]=NULL;
            }
        }
        m_ecount=0;
    }
    V getVertex(int i)
    {
        V ret;
        if(!getVertex(i,ret))
        {
        //抛出异常信息
        }
        return ret;
    }
    bool getVertex(int i,V& values)
    {
        bool ret=((0<=i)&&(i<vCount()));
        if(ret)
        {
            if(vertexes[i]!=NULL)
            {
                values=*(vertexes[i]);
            }
            else
            {
                //抛出非法操作异常
            }
        }

        return ret;
    }
    bool setVertex(int i,const V& values)
    {
        bool ret=((0<=i)&&(i<vCount()));
        if(ret)
        {
            V* tmp=vertexes[i];
            if(tmp==NULL)
            {
                tmp=new V();
            }
            if(tmp!=NULL)
            {
                *tmp=values;
                vertexes[i]=tmp;
            }
            else
            {
                //内存申请失败异常
            }
        }
        return ret;
    }
    SharedPointer<Array<int>> Adjacent(int i)
    {
        DynamicArray<int>* ret=NULL;
        if((0<=i)&&(i<vCount()))
        {
            int n=0;
            for(int j=0;j<vCount();j++)
            {
                if(m_edges[i][j]!=NULL)
                {
                    n++;
                }
            }
            ret=new DynamicArray<int>(n);
            for(int k=0,m=0;k<vCount();k++)
            {
                if(m_edges[i][k]!=NULL)
                {
                    ret->set(m,k);
                    m++;
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
           //抛出异常
       }
       return ret;
    }
    bool getEdge(int i,int j,E& values)
    {
        bool ret=((0<=i)&&(i<vCount())&&(0<=j)&&(j<vCount()));
        if(ret)
        {
            if(m_edges[i][j]!=NULL)
            {
            values= *(m_edges[i][j]);
            }
            else
            {
                //抛出异常信息
            }
        }
        return ret;
    }
    bool setEdge(int i,int j,const E& values)
    {
     bool ret=((0<=i)&&(i<vCount())&&(0<=j)&&(j<vCount()));
     if(ret)
     {
         if(m_edges[i][j]==NULL)
         {
             m_edges[i][j]=new E();
         }
         if(m_edges[i][j]!=NULL)
         {
             *(m_edges[i][j])=values;
              m_ecount++;
         }
     }
     return ret;
    }
    bool removeEdge(int i,int j)
    {
        bool ret=((0<=i)&&(i<vCount())&&(0<=j)&&(j<vCount()));
        if(ret)
        {
             E* toDel=m_edges[i][j];
             m_edges[i][j]=NULL;
             if(toDel!=NULL)
             {
                 m_ecount--;
                 delete toDel;
             }
        }
        return ret;
    }
    int vCount()
    {
        return N;
    }
    int eCount()
    {
        return m_ecount;
    }
    int OD(int i)
    {
        int ret=0;
        if((0<=i)&&(i<vCount()))
        {
            for(int j=0;j<vCount();j++)
            {
                if(m_edges[i][j]!=NULL)
                {
                    ret++;
                }
            }
        }
        return ret;
    }
    int  ID(int i)
    {
        int ret=0;
        if((0<=i)&&(i<vCount()))
        {
            for(int j=0;j<vCount();j++)
            {
                if(m_edges[j][i]!=NULL)
                {
                    ret++;
                }
            }
        }
        return ret;
    }
    //判断是否领接
    bool isAdjacent(int i,int j)
    {
        return (0<=i)&&(i<vCount())&&(0<=j)&&(j<vCount())&&(m_edges[i][j]!=NULL);
    }
    ~MatrixGraph()
    {
        for(int i=0;i<vCount();i++)
        {
            for(int j=0;j<vCount();j++)
            {
                delete m_edges[i][j];
            }
            delete  vertexes[i];
        }
        m_ecount=0;
    }
};
}
#endif // MATRIXGRAPH_H
