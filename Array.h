#ifndef _ARRAY_H_
#define _ARRAY_H_
#include "Object.h"
namespace DTLib
{
template <typename T>
class Array:public Object
{
protected:
    T* m_array;//m_array
public:
    virtual bool set(int i,const T& e)
    {
        int ret=((0<=i)&&(i<length()));
        if(ret)
        {
            m_array[i]=e;
        }
       return ret;
    }
    virtual bool get(int i,T& e) const
    {
        int ret=((0<=i)&&(i<length()));
        if(ret)
        {
            e=m_array[i];
        }
        return ret;
    }
    virtual int length() const=0;
    T& operator[](int i)
    {
         int ret=((0<=i)&&(i<length()));
         if(ret)
         {
             return m_array[i];
         }
         else
         {
             THROW_EXCEPTION(IndexOutOfBoundsException,"Parameter is valid ......");
         }
    }
    T operator[](int i) const
    {
        return static_cast<Array<T>&>(*this)[i];
    }
    T* array() const
    {
        return m_array;
    }
};
}
#endif // ARRAY_H
