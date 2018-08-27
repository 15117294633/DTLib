#ifndef ABSTRACTION_H
#define ABSTRACTION_H
#include "implementor.h"
namespace DTLib {
    /*
            PullChainSwitch* pull=new PullChainSwitch(new Light());
            pull->open();
            pull->close();
            cout<<"------------------------------------------"<<endl;
            PullChainSwitch* pull_Fan=new PullChainSwitch(new Fan());
            pull_Fan->open();
            pull_Fan->close();
            cout<<"------------------------------------------"<<endl;
            TwoPositionSwitch* two_switch=new TwoPositionSwitch(new Light());
            two_switch->open();
            two_switch->close();
     */
    class Iswitch
    {
    protected:
        IElectricalEquipment* my_equ;
    public:
        Iswitch(IElectricalEquipment* param):my_equ(param)
        {
            
        }
        virtual void open()=0;
        virtual void close()=0;     
    };
}

#endif // ABSTRACTION_H
