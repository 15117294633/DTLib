#ifndef STATICLINKLIST_H
#define STATICLINKLIST_H
#include "LinkList.h"
namespace DTLib
{
template<typename T,int N>
class StaticLinkList:public LinkList<T>
{
protected:
    typedef typename LinkList<T>::Node Node;
    struct SNode : public Node
    {
        void* operator new(unsigned int size,void *loc)
        {
            (void)size;
            return loc;
        }
    };
    //creat new length
    char m_space[sizeof(SNode)*N]; //creat a new space to store
    int m_used[N];
    Node* creat()
    {
        SNode* ret=NULL;

        for(int i=0;i<N;i++)
        {
            if(!m_used[i])
            {
                ret=reinterpret_cast<SNode*>(m_space)+i;//ret is an address
                ret=new(ret)SNode();   //alloc memory
                m_used[i]=1;
                break;
            }
        }
        return ret;
    }
    void destory(Node* pn)
    {
        SNode* space=reinterpret_cast<SNode*>(m_space);
        SNode* psn=dynamic_cast<SNode*>(pn);
        for(int i=0;i<N;i++)
        {
            if(pn==(space+i))
            {
                m_used[i]=0;
                psn->~SNode();
                break;
            }
        }
    }
 public:
    StaticLinkList()
    {
        for(int i=0;i<N;i++)
        {
            m_used[i]=0;
        }
    }
    int capacity()
    {
        return N;
    }
    ~StaticLinkList()
    {
        this->~LinkList()
    }
};
}
#endif 
