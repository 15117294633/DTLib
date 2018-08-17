#ifndef CONCRETEBUILD_H
#define CONCRETEBUILD_H
#include "builder.h"
namespace DTLib
{
    class ThinkPadBuilder :public IBuild
    {
    private:
        Computer* product;
    public:
        ThinkPadBuilder()
        {
            product=new Computer();
        }
        Computer* GetResult()
        {
            return product;
        }
        void BuildCpu()
        {
            product->SetmCpu("i5_6200U");
        }
        void BuildMainboard()
        {
            product->SetmMainboard("Intel DH57DD");
        }
        void BuildRam()
        {
            product->SetmRam("DDR4");
        }
        void BuildVideoCard()
        {
            product->SetVideoCard("NVIDIA Geforce 920MX");
        }

    };
    class YogaBuilder:public IBuild
    {

        Computer* product;
        YogaBuilder()
        {
            product=new Computer();
        }
        Computer* GetResult()
        {
            return product;
        }
        void BuildCpu()
        {
            product->SetmCpu("i5_7200u");
        }
        void BuildMainboard()
        {
            product->SetmMainboard("Intel_DP55KG");
        }
        void BuildRam()
        {
            product->SetmRam("DDR4_2133MHz");
        }
        virtual void BuildVideoCard()
        {
            product->SetVideoCard("gt940mx");
        }

    };
}
#endif // CONCRETEBUILD_H
