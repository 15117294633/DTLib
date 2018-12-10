#ifndef REALSUBJECT_H
#define REALSUBJECT_H
#include "subject.h"
#include <iostream>
using namespace DTLib;
namespace DTLib
{
    class ChinaMobile:public ITelco
    {
    public:
        void Recharge(int monery)
        {
           cout<<"charge:"<<monery<<endl;
        }
    };
}
#endif // REALSUBJECT_H
