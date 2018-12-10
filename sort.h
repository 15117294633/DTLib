#ifndef SORT_H
#define SORT_H
#include "Object.h"
#include "Array.h"
namespace DTLib
{
class Sort:public Object
{
private:
    Sort();
    Sort(const Sort&);
    Sort& operator = (const Sort&);
    //static must be
    template <typename T>
    static void Swap(T& a,T& b)
    {
        T c(a);
        a=b;
        b=c;
    }
    template <typename T>
    static int Partition(T array[],int begin,int end,bool min2max)
    {
        T pv=array[begin];
        while(begin<end)
        {
            while((begin<end)&&(min2max?(pv<array[end]):(pv>array[end])))
            {
                end--;
            }
            Swap(array[begin],array[end]);
            while((begin<end)&&(min2max?(pv>=array[begin]):(pv<=array[begin])))
            {
                begin++;
            }
        }
        array[begin]=pv;
        return begin;
    }
    template <typename T>
    static void Quick(T array[],int begin,int end,bool min2max)
    {
        //show entry
        if(begin<end)
        {
         int pivot=Partition(array,begin,end,min2max);
         Quick(array,begin,pivot-1,min2max);
         Quick(array,pivot+1,min2max);
        }
    }
public:
    //Select sort
    template <typename T>
    static void Select(T array[],int n,bool min2max=true)
    {
          for(int i=0;i<n;i++)
          {
              int min=i;
              for(int j=i+1;j<n;j++)
              {
                  if(array[min]>array[j])
                  {
                        min=j;
                  }
              }
              if(min!=i)
              {
                  Swap(array[i],array[min]);
              }
          }
    }
    //DTLib array class sort
    template <typename T>
    static void Select(Array<T>& array,bool min2max=true)
    {
        Select(array.array(),array.length(),min2max);
    }
    template <typename T>
    static void Insert(T array[],int n)
    {
        for(int i=1;i<n;i++)
        {
            int index=i;
            T temp=array[i];
            for(int j=i-1;j>=0;j--)
            {
                if(temp<array[j])
                {
                    array[j+1]=array[j];
                    index=j;
                }
                if(index!=i)
                {
                    array[index]=temp;
                }
            }
        }
    }
    //Like a Bubble from water
    template <typename T>
    static void Insert(Array<T>& array,bool min2max=true)
    {
        Insert(array.array(),array.length(),min2max);
    }
    template <typename T>
    static void Bubble(T array[],int len,bool min2max=true)
    {
        //冒泡排序
        bool exchange=true;
        for(int i=0;i<len&&exchange==true;i++)
        {
            exchange=false;
            for(int j=len-1;j>i;j--)
            {
                if(min2max?array[j]<array[j-1]:array[j]>array[j-1])
                {
                   Swap(array[j],array[j-1]);
                   exchange=true;
                }
            }
        }
    }
    template <typename T>
    static void Bubble(Array<T>& array,bool min2max=true)
    {
        Bubble(array.array(),array.length(),min2max);
    }
    template <typename T>
    static void Shell(T array[],int len ,bool min2max=true)
    {
        int d=len;
        do
        {
            d=d/3+1;
            //增量
            for(int i=d;i<len;i+=d)
            {
                //SHELL 条件
                int k=i;
                T e=array[i];
                for(int j=i-d;(j>=0)&&(min2max?(array[j]>e):(array[j]<e));j-=d)
                {
                    array[j+d]=array[j];
                    k=j;
                }
                if(k !=i)
                {
                    array[k]=e;
                }
            }

        }
        while(d>1);
    }
    template <typename T>
    static void Shell(Array<T>& array,bool min2max=true)
    {
        Shell(array.array(),array.length(),min2max);
    }
    /*练习的区域*/
    template <typename T>
    static void Merge(T array[],T temp[],int begin,int end)
    {
        if(begin<end)
        {
            //mid
            int mid=(begin+end)/2;
            //第一部分
            Merge(array,temp,begin,mid);
            Merge(array,temp,mid+1,end);
            Merge(array,temp,begin,mid,end);
        }
    }
    template <typename T>
    static void Merge(T array[],T temp[],int begin,int mid,int end)
    {
        int i=begin;
        int j=mid+1;
        int k=begin;
        while((i<=mid)&&(j<=end))
        {
            if(array[i]<array[j])
            {
                temp[k++]=array[i++];
            }
            else
            {
                temp[k++]=array[j++];
            }
        }
        while(i<=mid)
        {
            temp[k++]=array[i++];
        }
        while (j<=end)
        {
            temp[k++]=array[j++];
        }
        for(int i=begin;i<=end;i++)
        {
            array[i]=temp[i];
        }
    }
    template <typename T>
    static void Merge(T array[],int len)
    {
        T* temp=new T[len];
        if(temp!=nullptr)
        {
            Merge(array,temp,0,len-1);
        }
        delete[] temp;
    }
/***********************************************************************************/
    template <typename T>
    static void Quick(T array[],int len,bool min2max=true)
    {
        Quick(array,0,len-1,min2max);
    }
    template <typename T>
    static void Quick(Array<T>& array,bool min2max=true)
    {
        Quick(array.array(),array.length(),min2max);
    }
};
}
#endif // SORT_H
