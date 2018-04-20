#ifndef _SHAREDPOINTER_H_
#define _SHAREDPOINTER_H_
#include "Pointer.h"
#include <cstdlib>
#include "Exception.h"
namespace DTLib
{
    template <typename T>
    class SharedPointer:public Pointer<T>
    {
    protected:
        int* m_ref;
        void as_sign(const SharedPointer<T>& obj)
        {
            this->m_ref=obj.m_ref;
            this->m_pointer=obj.m_pointer;
            if(this->m_pointer)
            {
                (*this->m_ref)++;
            }
        }
    public:
        SharedPointer(T* p=NULL):m_ref(NULL)
        {
            if(p!=NULL)
            {
                this->m_ref=static_cast<int*>((std::malloc(sizeof(int))));
                if(this->m_ref)
                {
                    *(this->m_ref)=1;
                    this->m_pointer=p;
                }
                else
                {
                    THROW_EXCEPTION(NoEnoughMemoryException,"Not enough memory to creat shared_pointer...");
                }
            }
        }
        SharedPointer(const SharedPointer<T>& obj)//:Pointer(NULL)
        {
            as_sign(obj);
        }
        SharedPointer<T>& operator =(const SharedPointer<T>& obj)
        {
            if(this!=&obj)
            {
                clear();
                as_sign(obj);
            }
            return *this;
        }
        void clear()
        {
            T* toDel=this->m_pointer;
            int* ref=this->m_ref;
            this->m_pointer=NULL;
            this->m_ref=NULL;
            if(ref)
            {
                (*ref)--;
                if( *ref==0)
                {
                    free(ref);
                    delete toDel;
                }
            }
        }
        ~SharedPointer()
        {
            clear();
        }
    };
    template <typename T>
    bool operator ==(const SharedPointer<T>& l,const SharedPointer<T>& n)
    {
        return (l.get()==n.get());
    }
    template <typename T>
    bool operator !=(const SharedPointer<T>& l,const SharedPointer<T>& n)
    {
        return !(l==n);
    }
}


#endif // SHAREDPOINTER_H
