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
    BTreeNode<int>* ret;
    BTree<int> m_tree;
    m_tree.insert(1,NULL);
    ret=m_tree.find(1);
    m_tree.insert(2,ret);
    m_tree.insert(3,ret);
    ret=m_tree.find(2);
    m_tree.insert(4,ret);
    m_tree.insert(5,ret);
    ret=m_tree.find(3);
    m_tree.insert(6,ret);
    m_tree.insert(7,ret);

    ret=m_tree.find(4);
    m_tree.insert(8,ret);
    m_tree.insert(9,ret);

    ret=m_tree.find(5);
    m_tree.insert(10,ret);

    for(m_tree.begin();!m_tree.end();m_tree.next())
    {
        cout<<m_tree.current()<<" ";
    }
    cout<<endl;

    BTree<int> bt2;
    bt2.insert(0,NULL);
    ret=bt2.find(0);
    bt2.insert(6,ret);
    bt2.insert(2,ret);
    ret=bt2.find(2);
    bt2.insert(7,ret);
    bt2.insert(8,ret);
    cout<<endl;

    for(bt2.begin();!bt2.end();bt2.next())
    {
        cout<<bt2.current()<<" ";
    }
    cout<<endl;

    /*
    SharedPointer<Tree<int>> sp= m_tree.remove(3);

    for(sp->begin();!sp->end();sp->next())
    {
        cout<<sp->current()<<" ";
    }

    cout<<sp->height()<<endl;
    */
    /*
    LevelCommand,
    PreOrder
    InOrder
    PostOrder
    */
    /*
    SharedPointer<Array<int>> array=m_tree.traversal(InOrder);
    for(int i=0;i<array->length();i++)
    {
        cout<<(*array)[i]<<" ";
    }
    */
    /*
    cout<<endl;
    SharedPointer<Tree<int>> cl= m_tree.clone();
    for(cl->begin();!cl->end();cl->next())
    {
        cout<<cl->current()<<" ";
    }
    cout<<endl;
    */
    SharedPointer<BTree<int>> add=m_tree.add(bt2);
    for(add->begin();!add->end();add->next())
    {
        cout<<add->current()<<" ";
    }
    cout<<endl;

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

