#ifndef STATICQUEUE_H
#define STATICQUEUE_H
#include "Queue.h"
namespace DTLib {
template <typename T,int N>
class StaticQueue:public Queue<T>
{
 protected:
    T m_space[N];
    int m_rear;
    int m_front;
    int m_length;
public:
    StaticQueue()
    {
        m_rear=0;
        m_front=0;
        m_length=0;
    }
    int Capacity() const
    {
        return N;
    }
    void add(const T& e)
    {
         if(m_length<N)
         {

             m_space[m_rear]=e;
             m_rear=(m_rear+1)%N;
             m_length++;
         }
         else
         {
             THROW_EXCEPTION(InvalidOperatorException,"No space in current queue ");//抛出异常
         }
    }
    void remove()
    {
        if(m_length>0)
        {
            m_front=(m_front+1)%N;
            m_length--;
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
            return m_space[m_front];
        }
        else
        {
           THROW_EXCEPTION(InvalidOperatorException,"No element in current queue ");//抛出异常
        }
    }
    void clear()
    {
        m_rear=0;
        m_front=0;
        m_length=0;
    }
    int length() const
    {
        return m_length;
    }
};
}

#endif // STATICQUEUE_H
