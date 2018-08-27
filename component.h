#ifndef COMPONENT_H
#define COMPONENT_H
#include "DTString.h"
namespace DTLib
{
/*
    //测试代码严重的内存泄漏--用智能智能对象解决
    cout<<"Begin:HouseBlend"<<endl;
    IBeverage* houseblend=new HouseBlend();
    SharedPointer<CondimentDectorator> pCream=new Cream(houseblend);
    cout<<pCream->Name().str()<<":"<<pCream->Cost()<<endl;
    SharedPointer<CondimentDectorator> pCream1=new Mocha(pCream.get());
    cout<<pCream1->Name().str()<<":"<<pCream1->Cost()<<endl;
    SharedPointer<CondimentDectorator> pCream2 =new Syrup(pCream.get());
    cout<<pCream2->Name().str()<<":"<<pCream2->Cost()<<endl;
 */
    class IBeverage
    {
    public:
        virtual String Name() = 0;  // 名称
        virtual double Cost() = 0;  // 价钱
    };
}
#endif // COMPONENT_H
