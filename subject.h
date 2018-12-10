#ifndef SUBJECT_H
#define SUBJECT_H
#include "LinkList.h"
namespace DTLib
{
    class Subject
    {
        public:
            //virtual void registerObserver(Observer* obj)=0;
            //virtual void removeObserver(Observer* obj)=0;
            virtual void notifyObservers();
    };
    class WeatherData:public Subject
    {
    private:

    public:
    };
    //供外部使用的接口
    class ITelco
    {
      public:
        virtual ~ITelco()
        {

        }
        virtual void Recharge(int monery)=0;
    };
}
#endif // SUBJECT_H
