#ifndef CIRCLEQUEUE_H
#define CIRCLEQUEUE_H
#include "Object.h"
#include "Exception.h"
#include "LinuxList.h"
#include "queue.h"
namespace DTLib
{
    template <typename T>
    class CircleQueue:public Queue<T>
    {
    protected:
        struct Node:public Object
        {
            list_head head;
            T Values;
        };
        list_head m_head;
        int m_length;
    public:
        CircleQueue()
        {
           m_length=0;
           INIT_LIST_HEAD(&m_head);
        }
        void add(const T& e)
        {
          Node* node=new Node;
          if(node!=NULL)
          {
            node->Values=e;
            list_add_tail(&node->head,&m_head);
            m_length++;
          }
          else
          {
             THROW_EXCEPTION(NoEnoughMemoryException,"No memroy to creat Circle Queue......");
          }
        }
        void remove()
        {
           if(m_length>0)
           {
             list_head* toDel=m_head.next;
             list_del(toDel);
             m_length--;
             delete list_entry(toDel,Node,head);
           }
           else
           {
             THROW_EXCEPTION(InvalidOperatorException,"No element in current queue ");//抛出异常
           }
        }
        T front() const
        {
            if(m_length>0)
            {
                 return  list_entry(m_head.next,Node,head)->Values;
            }
            else
            {
                 THROW_EXCEPTION(InvalidOperatorException,"No element in current queue ");//抛出异常
            }
        }
         void clear()
         {
            while(m_length>0)
            {
                remove();
            }
         }
         int length() const
         {
             return m_length;
         }
    };
}

#endif // CIRCLEQUEUE_H
