#ifndef CONCRETE_IMPLEMENTOR_H
#define CONCRETE_IMPLEMENTOR_H
#include "implementor.h"
using namespace std;
namespace DTLib
{
class Light:public IElectricalEquipment
{
    void IsOpen()
    {
        cout<<"Light is open"<<endl;
    }
    void IsClose()
    {
       cout<<"Light is close"<<endl;  
    }
};
class Fan:public IElectricalEquipment
{
    void IsOpen()
    {
        cout<<"Fans is open"<<endl;
    }
    void IsClose()
    {
       cout<<"Fans is close"<<endl;  
    }
};
}

#endif // CONCRETE_IMPLEMENTOR_H
