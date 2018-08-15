#ifndef SUBJECT_H
#define SUBJECT_H
namespace DTLib
{
    class Observer
    {
    public:
        virtual void update(float temp,float humidity,float pressure);
    };
    class DisplayElement
    {
      public:
        virtual void display()=;
    };


}

#endif // SUBJECT_H
