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
    Test()
    {
        cout<<"Test()"<<endl;
    }
    ~Test()
    {
        cout<<"~Test()"<<endl;
    }
    int Values;
};
void jose(int num,int start,int index)
{
    CircleList<int> list;
    for(int i=1;i<=num;i++)
    {
        list.insert(i);
    }
   list.move(start-1,index-1);
   while(list.length()>0)
   {
       list.next();
       cout<<list.current()<<endl;
       list.remove(list.find(list.current()));
   }
}
int main()
{
    jose(41,1,3);
    return 0;
}

