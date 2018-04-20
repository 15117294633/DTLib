#ifndef DUALCIRCLELIST_H
#define DUALCIRCLELIST_H
#include "LinuxList.h"
#include "Object.h"
#include  "Exception.h"
#include "DualLinkList.h"
namespace DTLib {
template <typename T>
class DualCircleList:public DulaLinkList<T>
{
protected:
    struct Node:public Object
    {
        list_head head;
        T values;
    };
    list_head m_head;
    list_head* m_current;
    list_head* position(int i) const
    {
        list_head* ret=const_cast<list_head* >(&m_head);
        for(int p=0;p<i;p++)
        {
           ret=ret->next;
        }
        return ret;
    }
    int mod(int i) const
    {
        return (this->m_length==0)?0:(i%this->m_length);
    }
public:
    DualCircleList()
    {
        this->m_length=0;
        this->m_step=1;
        m_current=NULL;
        INIT_LIST_HEAD(&m_head);
    }
    bool insert(const T& e)
    {
       return insert(this->m_length,e);
    }
    bool insert(int i,const T& e)
    {
        bool ret=true;
        Node* node=new Node();
        i=i%(this->m_length+1);
        if(node!=NULL)
        {
            node->values=e;
            list_add_tail(&node->head,position(i)->next);
            this->m_length++;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException,"No memory to Creat memory");
        }
        return ret;
    }
    bool remove(int i)
    {
       bool ret=true;
       i=mod(i);
       ret=((0<=i)&&(i<this->m_length));
       if(ret)
       {
         list_head* toDel=position(i)->next;
         if(m_current==toDel)
         {
            m_current=toDel->next;
         }
         list_del(toDel);
         this->m_length--;
         delete list_entry(toDel,Node,head);
       }
       return ret;
    }
    bool set(int i,const T& e)
    {
      bool ret=true;
      i=mod(i);
      ret=((0<=i)&&(i<=this->m_length));
      if(ret)
      {
          list_entry(position(i)->next,Node,head)->values=e;
      }
      return ret;
    }
    T get(int i) const
    {
        T ret;
        if( get(i,ret))
        {
          return ret;
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException,"Index of i is valid");
        }

    }
    bool get(int i,T& e) const
    {
     bool ret=true;
     i=mod(i);
     ret=((0<=i)&&(i<=this->m_length));
     if(ret)
     {
         e=list_entry(position(i)->next,Node,head)->values;
     }
     return ret;
    }
    int find(const T& e) const
    {
        int ret=-1;
        int i=0;
        list_head* Slider=NULL;
        list_for_each(Slider,&m_head)
        {
            if(list_entry(Slider,Node,head)->values==e)
            {
                ret=i;
                break;
            }
            i++;
        }
        return ret;
    }
    int length() const
    {
        return this->m_length;
    }
    void clear()
    {
        while(this->m_length>0)
        {
            remove(0);
        }
    }
    bool move(int i,int step=1)
    {
        bool ret=true;
        i=mod(i);
        ret=((0<=i)&&(i<this->m_length));
        if(ret)
        {
           m_current=position(i);
        }
        this->m_step=step;
        return ret;
    }
    bool end()
    {
        return((m_current==NULL)||(this->m_length==0));
    }
    T current()
    {
        if(!end())
        {
            return list_entry(m_current,Node,head)->values;
        }
        else
        {
            THROW_EXCEPTION(InvalidOperatorException,"No values at current position");
        }
    }
    bool next()
    {
       int i=0;
       while((i<this->m_step)&&!end())
       {
           if(m_current!=&m_head)
           {
               m_current=m_current->next;
                i++;
           }
           else
           {
             m_current=m_current->next;
           }
       }
       if(m_current==&m_head)
       {
          m_current= m_current->next;
       }
       return  (i==this->m_step);
    }
    bool pre()
    {
        int i=0;
        while((i<this->m_step)&&!end())
        {
            if(m_current!=&m_head)
            {
                m_current=m_current->prev;
                 i++;
            }
            else
            {
              m_current=m_current->prev;
            }
        }
        if(m_current==&m_head)
        {
           m_current= m_current->prev;
        }

        return  (i==this->m_step);
    }
    ~DualCircleList()
    {
        clear();
    }
  };
}
#endif // DUALCIRCLELIST_H
