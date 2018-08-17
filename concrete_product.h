#ifndef CONCRETE_PRODUCT_H
#define CONCRETE_PRODUCT_H
#include "product.h"
#include "DTString.h"

    /********** 汽车 **********/
    // 奔驰
    class BenzCar : public ICar
    {
    public:
        String Name() {
            return "Benz Car";
        }
    };
    // 宝马
    class BmwCar : public ICar
    {
    public:
        String Name() {
            return "Bmw Car";
        }
    };
    // 奥迪
    class AudiCar : public ICar
    {
    public:
        String Name() {
            return "Audi Car";
        }
    };

    /********** 自行车 **********/
    // 奔驰
    class BenzBike : public IBike
    {
    public:
        String Name() {
            return "Benz Bike";
        }
    };
    // 宝马
    class BmwBike : public IBike
    {
    public:
        String Name() {
            return "Bmw Bike";
        }
    };
    // 奥迪
    class AudiBike : public IBike
    {
    public:
        String Name() {
            return "Audi Bike";
        }
    };


#endif // CONCRETE_PRODUCT_H
