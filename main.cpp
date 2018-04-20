#include <iostream>
#include "LinkList.h"
#include "DTString.h"
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include "DynamicArray.h"
#include "sort.h"
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
int main()
{
    //C++11做法
    int array[10]={1,3,2,4,0,7,6,9,8,5};

    Sort::Merge(array,10);
    for(int i=0;i<10;i++)
    {
        cout<<array[i]<<endl;
    }
    //加入对数组类的排序算法

    DynamicArray<int> sb(5);
    sb[0]=2;
    sb[1]=1;
    sb[2]=4;
    sb[3]=3;
    sb[4]=0;
    /*
    Sort::Select(sb);
    for(int i=0;i<sb.length();i++)
    {
        cout<<sb[i]<<endl;
    }
    */
    /*
    DynamicArray<int> sp(12);
    int* temp=String::make_pmt("D.T.Software");
    for(int i=0;i<12;i++)
    {
        sp[i]=temp[i];
    }
    for(int i=0;i<sp.length();i++)
    {
        cout<<sp[i]<<endl;
    }
    free(temp);

    cout<<String::kmp("D.T.Software","Soft")<<endl;
    */


    /*
    Graph<int, int>& g = GraphEasy<int, int>();
    SharedPointer< Array<int> > p = g.Dijkstra(0, 4, 65535);

    for(int i=0; i<p->length(); i++)
    {
        cout << (*p)[i] << " ";
    }

    cout << endl;
*/
    return 0;
}

