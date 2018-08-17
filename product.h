#ifndef PRODUCT_H
#define PRODUCT_H
#include "DTString.h"
using namespace DTLib;
class ICar
{
    public:
    virtual String Name()=0;
};
class IBike
{
    public:
        virtual String Name()=0;
};
#endif // PRODUCT_H
