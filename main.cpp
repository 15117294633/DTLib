#include <iostream>
#include "LinkList.h"
#include "DTString.h"
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include "DynamicArray.h"
#include "gtreenode.h"
#include "GTree.h"
#include "sort.h"
#include "btreenode.h"
#include "btree.h"
#include "find.h"
#include "matrixgraph.h"
#include  "SharedPointer.h"
#include "CircleList.h"
#include "concrete_factroy.h"
#include "StaticStack.h"
#include "LinkStack.h"
//设计模式部分

#include "concrete_build.h"
#include "builder.h"
#include "director.h"
#include "target.h"
#include "adapter.h"
#include "concrete_implementor.h"
#include "concrete_abstration.h"
#include "component.h"
#include "concrete_component.h"
#include "dectorator.h"
#include "concrete_decorator.h"
#include "composite.h"
#include "leaf.h"
using namespace DTLib;
using namespace std;
//做到胸中自有丘壑
/*
template< typename V, typename E >
Graph<V, E>& GraphEasy()
{
    static MatrixGraph<4, V, E> g;

    g.setEdge(0, 1, 1);
    g.setEdge(0, 2, 3);
    g.setEdge(1, 2, 1);
    g.setEdge(1, 3, 4);
    g.setEdge(2, 3, 1);

    return g;
}

*/
/*
template< typename V, typename E >
Graph<V, E>& GraphComplex()
{
    static ListGraph<V, E> g(5);

    g.setEdge(0, 1, 10);
    g.setEdge(0, 3, 30);
    g.setEdge(0, 4, 100);

    g.setEdge(1, 2, 50);

    g.setEdge(2, 4, 10);

    g.setEdge(3, 2, 20);
    g.setEdge(3, 4, 60);

    return g;
}
*/
class Test:public Object
{
public:
    int Values;
    Test()
    {
    }
    Test(int i)
    {
        Values=i;
    }
    ~Test()
    {
    }

};
//删除对象的宏定义
#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif
int main()
{
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

}

