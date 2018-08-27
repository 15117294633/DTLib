#ifndef DECTORATOR_H
#define DECTORATOR_H
#include "component.h"
#include "DTString.h"
namespace DTLib
{
    class CondimentDectorator:public IBeverage
    {
    protected :
        IBeverage *m_pBeverage;
    public:
        CondimentDectorator(IBeverage* beverage):m_pBeverage(beverage)
        {

        }
        String Name()
        {
             return m_pBeverage->Name();
        }
        double Cost()
        {
            return m_pBeverage->Cost();
        }
    };
}

#endif // DECTORATOR_H
