#ifndef IMPLEMENTOR_H
#define IMPLEMENTOR_H
namespace DTLib
{
    class IElectricalEquipment
    {
    public:
        virtual void IsOpen()=0;
        virtual void IsClose()=0;
    };
}
#endif // IMPLEMENTOR_H
