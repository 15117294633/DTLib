#ifndef LINKQUEUE_H
#define LINKQUEUE_H
#include "Object.h"
#include "Exception.h"
#include "LinkList.h"
#include "queue.h"
namespace DTLib
{
template<typename T>
class LinkQueue:public Queue<T>
{
   protected:
        LinkList<T> m_list;
   public:
       LinkQueue()
       {
       }
       void add(const T& e)
       {
          m_list.insert(e);
       }
       void remove()
       {
          if(m_list.length()>0)
          {
            m_list.remove(0);
          }
          else
          {
            THROW_EXCEPTION(InvalidOperatorException,"No element in current queue ");//抛出异常
          }
       }
       T front() const
       {
           if(m_list.length()>0)
           {
                return  m_list.get(0);
           }
           else
           {
                THROW_EXCEPTION(InvalidOperatorException,"No element in current queue ");//抛出异常
           }
       }
        void clear()
        {
            m_list.clear();
        }
        int length() const
        {
            return m_list.length();
        }
};
}
#endif // LINKQUEUE_H
