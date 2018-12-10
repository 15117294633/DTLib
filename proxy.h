#ifndef PROXY_H
#define PROXY_H
#include "subject.h"
#include "realsubject.h"
class Proxy:public ITelco
{
public:
    Proxy():real(NULL)
    {

    }
    void Recharge(int monery)
    {
        if(real==NULL)
            real=new ChinaMobile();
        real->Recharge(monery);
    }
private:
     ChinaMobile* real;
};
#endif // PROXY_H
