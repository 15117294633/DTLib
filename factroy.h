#ifndef FACTROY_H
#define FACTROY_H
#include "product.h"
class AFactory
{
public:
     enum Sort
     {
         BENZ,
         BMW,
         AUDI
     };
     virtual ICar* CreateCar()=0;
     virtual IBike* CreateBike()=0;
     static AFactory* NewInstance(Sort sort);

};
#endif // FACTROY_H
