#ifndef BUILDER_H
#define BUILDER_H
#include "Build_product.h"
//IBuild* build=new ThinkPadBuilder();
//Director::Create(build);
//print
//cout<<(build->GetResult()->GetCPU()+" "+build->GetResult()->GetMainboard()+" "+build->GetResult()->GetRam()+" "+build->GetResult()->GetVideoCard()).str()<<endl;
namespace DTLib
{
    class IBuild
    {
      public:
        virtual void BuildCpu() = 0;  // 创建 CPU
        virtual void BuildMainboard() = 0;  // 创建主板
        virtual void BuildRam() = 0;  // 创建内存
        virtual void BuildVideoCard() = 0;  // 创建显卡
        virtual Computer* GetResult() = 0;  // 获取建造后的产品
    };
}
#endif // BUILDER_H
