#ifndef ADAPTER_H
#define ADAPTER_H
#include "adaptee.h"
namespace DTLib
{
    class Adapter:public Target
    {
    private:
         Adaptee* adapte;
    public:
         Adapter(Adaptee* param=nullptr):adapte(param)
         {

         }
         void charge()
         {
             adapte->charge_by_china();
         }
    };
}
#endif // ADAPTER_H
