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
        //step1
        bool m_flag;
        void* operator new(unsigned int size)
        {
            return Object::operator new(size);
        }
        TreeNode()
        {
            this->m_flag=false;
            this->parent=NULL;
        }
        bool get_flag()
        {
            //get flag
            return m_flag;
        }
        virtual ~TreeNode()=0;
    };
    template <typename T>
    TreeNode<T>::~TreeNode()
    {

    }
}
#endif // TREENODE_H
