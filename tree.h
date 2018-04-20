#ifndef TREE_H
#define TREE_H
#include "TreeNode.h"
#include "SharedPointer.h"//smartpointer
namespace DTLib
{
    template <typename T>
    class Tree:public Object
    {
    protected:
        TreeNode<T>* m_root;
    public:
        Tree() {m_root=NULL;}
        virtual bool insert(TreeNode<T>* node)=0;//node
        virtual bool insert(const T& value,TreeNode<T>* parent)=0;
        virtual TreeNode<T>* find(TreeNode<T>* node)const=0;
        virtual TreeNode<T>* find(const T& value)const=0;
        virtual SharedPointer<Tree<T>> remove(TreeNode<T>* node)=0;
        virtual SharedPointer<Tree<T>> remove(const T& value)=0;
        virtual TreeNode<T>* root() const=0;
        virtual void clear()=0;//clear operator
        virtual int degree() const=0;
        virtual int height() const=0;
        virtual int count() const=0;
    };
}
#endif // TREE_H
