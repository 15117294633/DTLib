#ifndef FIND_H
#define FIND_H
#include "Object.h"
namespace DTLib {
    class Find:public Object
    {
    protected:
        Find();
        Find(const Find&);
        Find& operator = (const Find&);

        template <typename T>
        static int rank(T array[],T values,int begin,int end)
        {
            if(begin<end)
            {
                int mid=begin+(end-begin)/2;
                if(array[values]<array[mid])
                {
                     return rank(array,values,begin,mid);
                }
                else if(array[values]>array[mid])
                {
                     return rank(array,values,mid,end);
                }
                else if(array[values]=array[mid])
                {
                    return mid;
                }
            }
            return 0;
        }
    public:
        template <typename T>
        static int rank(T array[],T values,int n)
        {
            rank(array,values,0,n);
        }
    };
}

#endif // FIND_H

