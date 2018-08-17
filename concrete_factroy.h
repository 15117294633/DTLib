#ifndef CONCRETE_FACTROY_H
#define CONCRETE_FACTROY_H
#include "concrete_product.h"
#include "factroy.h"
    class Benz_Factort:public AFactory
    {
    public:
        ICar* CreateCar()
        {
            return new BenzCar();
        }
        IBike* CreateBike()
        {
            return new BenzBike();
        }
    };
    class Bmw_Factort:public AFactory
    {
    public:
        ICar* CreateCar()
        {
            return new BmwCar();
        }
        IBike* CreateBike()
        {
            return new BmwBike();
        }
    };
    class Audi_Factort:public AFactory
    {
    public:
        ICar* CreateCar()
        {
            return new AudiCar();
        }
        IBike* CreateBike()
        {
            return new AudiBike();
        }
    };
#endif // CONCRETE_FACTROY_H
