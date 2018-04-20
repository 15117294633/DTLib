#ifndef BTREENODE_H
#define BTREENODE_H
#include "Object.h"
#include <iostream>
namespace DTLib
{
template <typename T>
class BTreeNode:public TreeNode<T>
{
    protected:
    bool m_flag;//put it TreeNode
    void* operator new(unsigned int size)
    {
        return Object::operator new(size);
    }
    public:
    BTreeNode<T>* left;
    BTreeNode<T>* right;
    BTreeNode()
    {
        m_flag=false;
        left=NULL;
        right=NULL;
    }
    bool get_flag()
    {
        return m_flag;
    }
    //static
    static BTreeNode<T>* B_new()
    {
        BTreeNode<T>* ret=new BTreeNode<T>();
        if(ret!=NULL)
        {
            ret->m_flag=true;
        }
        return ret;
    }
};
}
#endif // BTREENODE_H
