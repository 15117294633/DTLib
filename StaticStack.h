#ifndef STATICSTACK_H
#define STATICSTACK_H
#include "Stack.h"
#include"Exception.h"
namespace DTLib
{
    template <typename T,int N>
    class StaticStack:public Stack<T>
    {
       protected:
        T m_space[N];
        int m_top;
        int m_size;
       public:
        StaticStack()
        {
            m_top=-1;
            m_size=0;
        }
        void push(const T& e)
        {
            if(m_size<N)
            {
                m_space[m_top+1]=e;
                m_top++;
                m_size++;
            }
            else
            {
              THROW_EXCEPTION(InvalidOperatorException,"No space in current space ");
            }
        }
        int Capacity() const
        {
            return N;
        }
        void pop()
        {
            if(m_size>0)
            {
                m_top--;
                m_size--;
            }
            else
            {
             THROW_EXCEPTION(InvalidOperatorException,"No Element in current space ");
            }
        }
        T top() const
        {
            if(m_size>0)
            {
                return m_space[m_top];
            }
            else
            {
             THROW_EXCEPTION(InvalidOperatorException,"No Element in current space ");
            }
        }
        void clear()
        {
            m_top=-1;
            m_size=0;
        }
        int size()
        {
            return m_size;
        }
    };
}
#endif // STATICSTACK_H
