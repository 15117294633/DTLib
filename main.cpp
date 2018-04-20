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
  //测试代码
   GTreeNode<char> root;
   root.parent=NULL;//Comfire
   root.values='A';
   GTree<char> my;
   my.insert(&root);
   GTreeNode<char>* temp=NULL;
   temp=my.find(&root);
   my.insert('B',temp);
   my.insert('C',temp);
   my.insert('D',temp);
   temp=my.find('B');
   my.insert('E',temp);
   my.insert('F',temp);
   temp=my.find('E');
   my.insert('K',temp);
   my.insert('L',temp);
   temp=my.find('C');
   my.insert('G',temp);

   temp=my.find('D');
   my.insert('H',temp);
   my.insert('I',temp);
   my.insert('J',temp);
   temp=my.find('H');
   my.insert('M',temp);

//   const char* freach="KLFGMIJ";
//   while (*freach!='\0') {
//       TreeNode<char>* temp1;
//       temp1=my.find(*freach);
//       while(temp1!=NULL)
//       {
//          cout<<temp1->values<<" ";
//          temp1=temp1->parent;
//       }
//       cout<<endl;
//       freach++;
//   }
  SharedPointer<Tree<char>> sp=my.remove('D');
  const char* freach="MIJ";
  while (*freach!='\0') {
      TreeNode<char>* temp1;
      temp1=sp->find(*freach);
      while(temp1!=NULL)
      {
         cout<<temp1->values<<" ";
         temp1=temp1->parent;
      }
      cout<<endl;
      freach++;
  }

  cout<<sp->count()<<endl;
  cout<<sp->height()<<endl;
  cout<<sp->degree()<<endl;

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

