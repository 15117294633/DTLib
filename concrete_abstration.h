#ifndef CONCRETE_ABSTRATION_H
#define CONCRETE_ABSTRATION_H
#include "abstraction.h"
#include "implementor.h"
namespace DTLib
{

    class PullChainSwitch:public Iswitch
    {
    public:
        PullChainSwitch(IElectricalEquipment* par):Iswitch(par)
        {

        }
        void open()
        {
            cout<<"PullChainSwitch::open"<<endl;
            this->my_equ->IsOpen();
        }
        void close()
        {
            cout<<"PullChainSwitch::open"<<endl;
            this->my_equ->IsClose();
        }
    };
    class TwoPositionSwitch:public Iswitch
    {
    public:
        TwoPositionSwitch(IElectricalEquipment* par):Iswitch(par)
        {

        }
        void open()
        {
            cout<<"TwoPositionSwitch::open"<<endl;
            this->my_equ->IsOpen();
        }
        void close()
        {
            cout<<"TwoPositionSwitch::open"<<endl;
            this->my_equ->IsClose();
        }
    };
}
#endif // CONCRETE_ABSTRATION_H
