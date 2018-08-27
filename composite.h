#ifndef COMPOSITE_H
#define COMPOSITE_H
#include "component.h"
#include "LinkList.h"
using namespace std;
namespace DTLib
{
    class Composite:public Component
    {
    private:
        Composite ();
        LinkList<Component*> list;
    public:
        Composite(string name):Component(name) {}
         ~Composite()
        {
          list.clear();
        }
        void Add(Component* cmpt)
        {
            list.insert(cmpt);
        }
        void Remove(Component *cmpt)
        {
            list.remove(list.find(cmpt));
        }
        Component* GetChild(int index)
        {
              if(index>=list.length())
              {
                  THROW_EXCEPTION(IndexOutOfBoundsException,"index is not exist");
              }
              else
              {
                  return list.get(index);
              }
        }
        void Operation(int indent)
        {

        }
    };
}

#endif // COMPOSITE_H
