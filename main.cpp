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
using namespace DTLib;
using namespace std;
#include "concrete_build.h"
#include "builder.h"
#include "director.h"
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
int main()
{
    IBuild* build=new ThinkPadBuilder();
    Director::Create(build);
    //print
    cout<<(build->GetResult()->GetCPU()+" "+build->GetResult()->GetMainboard()+" "+build->GetResult()->GetRam()+" "+build->GetResult()->GetVideoCard()).str()<<endl;
}

