#ifndef LEAF_H
#define LEAF_H
#include "Exception.h"
#include "component.h"
using namespace std;
namespace DTLib
{
   class Leaf:public Component
   {
   private:
     Leaf();
   protected:
     string m_name;
   public:
     Leaf(string name):Component(name) {}
     virtual ~Leaf(){}
     void Add(Component *cmpt)
     {
         THROW_EXCEPTION(InvalidOperatorException,"can not add ele into Leaf");
     }
     void Remove(Component *cmpt)
     {
          THROW_EXCEPTION(InvalidOperatorException,"can not remove ele from Leaf");
     }
     Component* GetChild(int index)
     {
           THROW_EXCEPTION(InvalidOperatorException,"can not GetChild from Leaf");
     }
     void Operation(int indent)
     {
         string newStr(indent, '-');
         cout << newStr << " " << m_name <<endl;
     }
   };
}
#endif // LEAF_H
