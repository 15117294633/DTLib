#ifndef _BACKPACK_H
#define _BACKPACK_H
#include "StaticArray.h"
namespace DTLib
{
    class obj
    {
    public:
        int weight;
        int price;
        int status; //0:未选中；1:已选中；2:已经不可选
        //重载赋值操作符
         obj& operator = (const obj& objs)
         {
            if(this!=&objs)
            {
               weight= objs.weight;
               price= objs.price;
               status=objs.status;
            }
            return *this;
         }
    };
    typedef struct
    {
        StaticArray<obj,7>  use_list;
        int totalC;
    }KNAPSACK_PROBLEM;
    class BackPack:public Object
    {
    protected:
        KNAPSACK_PROBLEM back;
    public:
        BackPack()
        {

        }
        enum
        {
            max_weight= 150
        };
        BackPack(StaticArray<obj,7>& obj_cal)//初始化接口
        {
            back.use_list=obj_cal;
            back.totalC=max_weight;
        }
        void GreedyAlgo()
        {
            int index=-1;
            int ntc = 0;
            while((index = Choose_func()) != -1)
            {
                if((ntc + back.use_list[index].weight) <= back.totalC)
                {
                    back.use_list[index].status = 1;
                    ntc += back.use_list[index].weight;
                    cout<<ntc<<":";
                    cout<<index<<endl;
                }
                else
                {
                     back.use_list[index].status = 2;//不做迭代
                }
            }
            //打印所选的列表
        }
        int Choose_func()
        {
            int index = -1;
            int mp = 0;
            for(int i = 0; i <back.use_list.length() ; i++)
            {
                if((back.use_list[i].status == 0) && (back.use_list[i].price > mp))
                {
                    mp = back.use_list[i].price;
                    index = i;
                }
            }
            return index;
        }
    };
}
#endif // 01_BACKPACK_H
