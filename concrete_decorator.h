#ifndef CONCRETE_DECORATOR_H
#define CONCRETE_DECORATOR_H
#include "dectorator.h"
#include "DTString.h"
namespace DTLib
{
    // 奶油
    class Cream : public CondimentDectorator
    {
    public:
        Cream(IBeverage *beverage) : CondimentDectorator(beverage) {}
        String Name() {
            return m_pBeverage->Name() + " Cream";
        }

        double Cost() {
            return this->m_pBeverage->Cost() + 3.5;
        }
    };
    // 摩卡
    class Mocha : public CondimentDectorator
    {
    public:
        Mocha(IBeverage *beverage) : CondimentDectorator(beverage) {}

        String Name() {
            return m_pBeverage->Name() + " Mocha";
        }

        double Cost() {
            return m_pBeverage->Cost() + 2.0;
        }
    };

    // 糖浆
    class Syrup : public CondimentDectorator
    {
    public:
        Syrup(IBeverage *beverage) : CondimentDectorator(beverage) {}
        String Name() {
            return m_pBeverage->Name() + " Syrup";
        }
        double Cost() {
            return m_pBeverage->Cost() + 3.0;
        }
    };
}
#endif // CONCRETE_DECORATOR_H
