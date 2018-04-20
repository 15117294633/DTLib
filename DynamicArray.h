#ifndef _DYNAMICARRAY_H_
#define _DYNAMICARRAY_H_
#include "Array.h"
#include "Exception.h"
namespace DTLib
{
template<typename T>
class DynamicArray:public Array<T>
{
protected:
    int m_length;
    T* copy(T* array,int len,int newlen)
    {
        T* ret=new T[newlen];
        if(ret!=NULL)
        {
            int size=(len<newlen)?len:newlen;
            for(int i=0;i<size;i++)
            {
                ret[i]=array[i];
            }
        }
        return ret;
    }
    void update(T*array,int length)
    {
        if(array!=NULL)
        {
            T* temp=this->m_array;
            this->m_array=array;
            this->m_length=length;
            delete[] temp;
        }
        else
        {
              THROW_EXCEPTION(NoEnoughMemoryException,"No memroy to creat Dynamic obj ......");
        }
    }
    void init(T*array,int length)
    {
        if(array!=NULL)
        {
            this->m_array=array;
            this->m_length=length;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException,"No memroy to creat Dynamic obj......");
        }
    }
public:
    DynamicArray(int length) //初始化
    {
        init(new T[length],length);
        /*
        this->m_array=new T[length];
        if(this->m_array!=NULL)
        {
            this->m_length=length;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException,"No memroy to creat Dynamic obj ......");
        }
        */
    }
    DynamicArray(const DynamicArray<T>& obj)
    {
        init(copy(obj.m_array,obj.m_length,obj.m_length),obj.m_length);
        /*
        this->m_array=new T[obj.length()];
        if(this->m_array!=NULL)
        {
            this->m_length=obj.m_length;
            for(int i=0;i<obj.m_length;i++)
            {
                this->m_array[i]=obj.m_array[i];
            }
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException,"No memroy to creat Dynamic obj ......");//出错处理
        }
        */

    }
    DynamicArray<T>& operator = (const DynamicArray<T>& obj)
    {
        if(this!=&obj)
        {
            update(copy(obj.m_array,obj.m_length,obj.m_length),obj.m_length);

            /*
            T* array= new T[obj.m_length];
            if(array!=NULL)
            {
              for(int i=0;i<obj.m_length;i++)
              {
                  array[i]=obj.m_array[i];
              }
              T* temp=this->m_array;
              this->m_array=array;
              this->m_length=obj.m_length;
              delete[] temp;//release
            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoryException,"No memroy to creat Dynamic obj ......");
            }*/
        return *this;
        }
    }
    void resize(int length)
    {
        if(length!=m_length)
        {

            update(copy(this->m_array,m_length,length),length);
            /*
            T* array=new T[length];

            if(array!=NULL)
            {
                int size=length>m_length?m_length:length;
                for(int i=0;i<size;i++)
                {
                    array[i]=this->m_array[i];
                }
                T* temp=this->m_array;
                this->m_array=array;
                this->m_length=length;
                delete[] temp;
            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoryException,"No memroy to creat Dynamic obj ......");
            }
            */
        }
        return *this;

    }
    int length() const
    {
        return m_length;
    }
    ~DynamicArray()
    {
        delete[] this->m_array;//happened memory
    }
};
}
#endif // DYNAMICARRAY_H
