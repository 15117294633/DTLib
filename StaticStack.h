#ifndef STATICSTACK_H
#define STATICSTACK_H
#include "Stack.h"
#include"Exception.h"
namespace DTLib
{
    template <typename T,int N>
    //T,N
    class StaticStack:public Stack<T>
    {
       protected:
        //定义空间
        T m_space[N];
        //最顶端元素
        int m_top;
        //存储空间里面的元素
        int m_size;
       public:
        StaticStack()
        {
            //设置初始
            m_top=-1;
            m_size=0;
        }
        void push(const T& e)
        {
            if(m_size<N)
            {
                //m_space[ m_top++]=e;
                //异常安全--对于出现赋值操作必须考虑异常安全
                m_space[m_top+1]=e;
                m_top++;
                m_size++;
            }
            else
            {
              THROW_EXCEPTION(InvalidOperatorException,"No space in current space ");
            }
        }
        //自定义的
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
             THROW_EXCEPTION(InvalidOperatorException,"No Element in current stack ");
            }
        }
        //考虑一下是否返回其对象的引用--不需要，此时我只考虑顶端元素
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
