#ifndef TREENODE_H
#define TREENODE_H
//desc:this is  parent treenode
#include "Object.h"
#include <iostream>
namespace DTLib
{
    template <typename T>
    class TreeNode:public Object
    {
      public:
        T values;
        TreeNode<T>* parent;//线性表
        TreeNode()
        {
            this->parent=NULL;
        }
        virtual ~TreeNode()=0;
    };
    template <typename T>
    TreeNode<T>::~TreeNode()
    {

    }
}
#endif // TREENODE_H
