#include "concrete_factroy.h"
//usage
//
//    AFactory* benz=AFactory::NewInstance(AFactory::AUDI);
//    cout<<benz->CreateCar()->Name().str()<<endl;
//    cout<<benz->CreateBike()->Name().str()<<endl;
//

AFactory* AFactory::NewInstance(Sort sort)
{
    AFactory* ret=nullptr;
    switch(sort)
    {
        case  BENZ:
            ret=new Benz_Factort();
        break;
        case BMW:
            ret=new Bmw_Factort();
            break;
        case AUDI:
            ret=new Audi_Factort();
            break;
    }
    return ret;
}
