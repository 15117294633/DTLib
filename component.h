#ifndef COMPONENT_H
#define COMPONENT_H
#include "DTString.h"
using namespace std;
namespace DTLib
{
/*
    //测试代码严重的内存泄漏--用智能指针解决
    cout<<"Begin:HouseBlend"<<endl;
    IBeverage* houseblend=new HouseBlend();
    SharedPointer<CondimentDectorator> pCream=new Cream(houseblend);
    cout<<pCream->Name().str()<<":"<<pCream->Cost()<<endl;
    SharedPointer<CondimentDectorator> pCream1=new Mocha(pCream.get());
    cout<<pCream1->Name().str()<<":"<<pCream1->Cost()<<endl;
    SharedPointer<CondimentDectorator> pCream2 =new Syrup(pCream.get());
    cout<<pCream2->Name().str()<<":"<<pCream2->Cost()<<endl;
 */
    //装饰者模式,辛巴克咖啡
    class IBeverage
    {
    public:
        virtual String Name() = 0;  // 名称
        virtual double Cost() = 0;  // 价钱
    };
    //组合者设计模式
    class Component
    {
      private:
        Component();
      protected:
        string m_name;
      public:
        Component(string name) : m_name(name) {}
        virtual ~Component() {}
        virtual void Add(Component *cmpt) = 0;  // 添加构件
        virtual void Remove(Component *cmpt) = 0;  // 删除构件
        virtual Component* GetChild(int index) = 0;  // 获取构件
        virtual void Operation(int indent) = 0;  // 显示构件（以缩进的方式
        string Get_name()
        {
            return m_name;
        }
    };
}
#endif // COMPONENT_H
