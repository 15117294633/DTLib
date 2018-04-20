#ifndef LINKSTACK_H
#define LINKSTACK_H
#include "LinkList.h"
#include "Stack.h"
#include "Exception.h"
namespace DTLib
{
template <typename T>
class LinkStack:public Stack<T>
{
    protected:
        LinkList<T> m_list;
    public:
        void push(const T& e)
        {
            m_list.insert(0,e);
        }
        void pop()
        {
            if(m_list.length()>0)
            {
                 m_list.remove(0);
            }
            else
            {
                THROW_EXCEPTION(InvalidOperatorException,"No Element in current space ");//抛出异常
            }
        }
        T top() const
        {
            if(m_list.length()>0)
            {
                return m_list.get(0);
            }
            else
            {
                THROW_EXCEPTION(InvalidOperatorException,"No Element in current space ");
            }
       }
        void clear()
        {
          m_list.clear();
        }
        int size()
        {
            return m_list.length();
        }
};
}
#endif // LINKSTACK_H
