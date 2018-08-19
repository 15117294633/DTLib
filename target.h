#ifndef TARGET_H
#define TARGET_H
namespace DTLib
{
    class Target
    {
      public://目标类型
        virtual void charge()=0;
    };
}
#endif // TARGET_H
