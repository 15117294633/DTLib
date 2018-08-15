#ifndef SUBJECT_H
#define SUBJECT_H
#include "LinkList.h"
namespace DTLib
{
    class Subject
    {
        public:
            virtual void registerObserver(Observer* obj)=0;
            virtual void removeObserver(Observer* obj)=0;
            virtual void notifyObservers();
    };
    class WeatherData:public Subject
    {
    private:
        LinkList<>
    public:
    };
}
#endif // SUBJECT_H
