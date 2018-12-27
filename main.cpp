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
#include "SmartPoint.h"
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
#include "proxy.h"
using namespace DTLib;
using namespace std;
//做到胸中自有丘壑==>侯杰
//做到知其所以然
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
int sum(int n)
{
    //出口条件
    if(n==1)
    {
        return 1;
    }
    else
    {
        return n+sum(n-1);
    }
}
int Fibonacci(int n)
{
    if(n==1|n==2)
    {
        return 1;


    }
    else
    {
        return Fibonacci(n-1)+Fibonacci(n-2);
    }
}
int strlen(char* str)
{
    while(*str)
    {
        return 1+strlen(str+1);
    }
}
/*------------------------------C生成链表----------------------------------*/
//head

struct Node
{
  int v;
  Node* next;
};
//creat a new List Node
struct Node* create_list(int len)
{
    //ret is a return header
    struct Node* ret = NULL;
    struct Node* slider = NULL;
    //struct Node
    for(int i=0;i<len;i++)
    {
      struct Node* node = (struct Node*)malloc(sizeof(struct Node));
      //judgemrnt
       if( node )
       {
           node->v = i;
           node->next = NULL;
           if( slider == NULL )
           {
               ret = node;
               slider = node;
           }
           else
           {
               slider->next = node;
               slider = node;
           }
       }
    }
    return ret;
   }
void display_list(struct Node* list)
{
    while( list )
    {
        printf("%d -> ", list->v);

        list = list->next;
    }

    printf("NULL \n");
}
void list_free(struct Node* list)
{
    while(list)
    {
        Node* tem=list;
        free(tem);
        list=list->next;
    }
}
Node*  reversal(Node* list)
{
    if(list==NULL||list->next==NULL)
    {
        return list;
    }
    else
    {

        Node* guard=list->next;
        Node* ret=reversal(list->next);
        guard->next=list;
        list->next=NULL;
        return ret;
    }
}
/*------------------------------end---------------------------------------*/
/*-----------------------------------------------------------------------*/
void HanoiTower(int n,char a,char b,char c)
{
    if(n<=0)
        cout<<"param Error"<<endl;
    else if(n==1)//出口
        cout<<a<<"->"<<c<<endl;
    else
     {
        HanoiTower(n-1,a,c,b);
        HanoiTower(1,a,b,c);
        HanoiTower(n-1,b,a,c);
     }
}

int main()
{
    GTree<int> bt;
    GTreeNode<int>* n=NULL;
    GTreeNode<int> node;



    node.values=1;
    bt.insert(&node);
    n=bt.find(1);

    GTreeNode<int> node1;
    node1.parent=n;
    node1.values=2;
    bt.insert(&node1);

    bt.insert(3,n);
    n=bt.find(2);
    bt.insert(4,n);
    bt.insert(5,n);
    n=bt.find(3);
    bt.insert(6,n);
    bt.insert(7,n);
    n=bt.find(4);
    bt.insert(8,n);
    bt.insert(9,n);
    n=bt.find(5);
    bt.insert(10,n);
 //           1
 //        2        3
 //     4    5   6   7
 //   8  9 10
 //  SharedPointer<Tree<T>> t=bt.
    cout<<bt.count()<<endl;
    cout<<bt.height()<<endl;
    cout<<bt.degree()<<endl;
}

