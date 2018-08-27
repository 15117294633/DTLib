#ifndef CONCRETE_COMPONENT_H
#define CONCRETE_COMPONENT_H
#include "component.h"
namespace DTLib
{
    //黑咖啡
    class HouseBlend:public IBeverage
    {
    public:
        HouseBlend()
        {

        }
        String Name()
        {
            return "HouseBlend";
        }
        double Cost()
        {
            return 30.0;
        }
        // 深度烘培咖啡豆
        class DarkRoast : public IBeverage
        {
        public:
            String Name() {
                return "DarkRoast";
            }

            double Cost() {
                return 28.0;
            }
        };
    };
}
#endif // CONCRETE_COMPONENT_H
