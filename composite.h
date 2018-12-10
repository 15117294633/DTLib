#ifndef COMPOSITE_H
#define COMPOSITE_H
#include "component.h"
#include "LinkList.h"
using namespace std;
namespace DTLib
{
/*
  Component *pRoot = new Composite("A");

  Component *pDepart1 = new Composite("B");
  pDepart1->Add(new Leaf("C"));
  pDepart1->Add(new Leaf("D"));
  pRoot->Add(pDepart1);

  Component *pDepart2 = new Composite("E");
  pDepart2->Add(new Leaf("F"));
  pDepart2->Add(new Leaf("G"));
  pDepart2->Add(new Leaf("H"));
  pDepart2->Add(new Leaf("I"));
  pDepart2->Add(new Leaf("J"));
  pRoot->Add(pDepart2);

  pRoot->Add(new Leaf("K"));
  pRoot->Add(new Leaf("L"));

  pRoot->Operation(0);

 */
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
