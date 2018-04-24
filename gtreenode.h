#ifndef GTREENODE_H
#define GTREENODE_H
#include "TreeNode.h"
#include "LinkList.h"
#include "Object.h"
namespace DTLib {
template <typename T>
class GTreeNode:public TreeNode<T>
{
  protected:
    //step1
    GTreeNode(const GTreeNode<T>&);
    GTreeNode<T>& operator =(const GTreeNode<T>&);
    //step2
    bool m_flag;
    void* operator new (unsigned int size) throw()
    {
        return Object::operator new(size);
    }
  public:
    GTreeNode()
    {
        m_flag=false;
    }
    //step3
    static GTreeNode<T>* NewNode()
    {
      GTreeNode<T>* ret=new GTreeNode<T>();
      if(ret!=NULL)
      {
          ret->m_flag=true;
      }
      return ret;
    }
    //孩子节点链表
    LinkList<GTreeNode<T>*> child;//child node
    //step4
    bool get_flag()
    {
        return m_flag;
    }
};
}
#endif // GTREENODE_H
