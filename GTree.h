#ifndef GTREE_H
#define GTREE_H
#include "tree.h"
#include "GTreeNode.h"
#include "Exception.h"
#include "LinuxList.h"
#include "linkqueue.h"
namespace DTLib {
template <typename T>
class GTree:public Tree<T>
{
protected:
    GTree(const GTree<T>&);
    GTree<T>& operator =(const GTree<T>&);
    //LinkQueue
    LinkQueue<GTreeNode<T>*> queue;//队列
    //find操作的重载版本
    GTreeNode<T>* find(GTreeNode<T>* node,const T& value) const
    {
        GTreeNode<T>* ret=NULL;
        if(node!=NULL)
        {
            if(node->values==value)
            {
                return node;
            }
            else
            {
                //here is 遍历
                for(node->child.move(0);!node->child.end()&&(ret==NULL);node->child.next())
                {
                    ret=find(node->child.current(),value);
                }
            }
        }
        return ret;
    }
    GTreeNode<T>* find(GTreeNode<T>* node,GTreeNode<T>* obj) const
    {
        GTreeNode<T>* ret=NULL;
        if(node!=NULL)
        {
            //if node==obj 对象的时候递归end
            if(node==obj)
            {
                return node;
            }
            else
            {
                for(node->child.move(0);!node->child.end()&&ret==NULL;node->child.next())
                {
                    ret=find(node->child.current(),obj);
                }
            }
        }
        return ret;
    }
    void free(GTreeNode<T>* node)
    {
        //param的判断
        if(node!=NULL)
        {
           for(node->child.move(0);!node->child.end();node->child.next())
           {
               free(node->child.current());
           }
           //judgement 是否为堆space creat obj
           if(node->get_flag())
           {
               delete node;//can be delete
           }
           /*
           else
           {
               std::cout<<node->values;
           }
           */
        }
    }
    void remove(GTreeNode<T>* node,GTree<T>* &ret)
     {
        //指针的引用
        ret=new GTree();//创建新的对象
        if(ret!=NULL)
        {
            if(root()==NULL)
            {
                ret->m_root=NULL;
            }
            else
            {
                //代码编容易
                LinkList<GTreeNode<T>*>& child=dynamic_cast<GTreeNode<T>*>(node->parent)->child;
                //
                child.remove(child.find(node));
                queue.clear();
                node->parent=NULL;
            }
            ret->m_root=node;
        }
        else
        {
            //THORW EXPECTION
        }
     }
    //count 结点的查询操作
    int count(GTreeNode<T>* node) const
    {
        int ret=0;
        if(node!=NULL)
        {
            if(node->child.length()==0)
            {
                ret=1;
            }
            else
            {
                //遍历child链表
                for(node->child.move(0);!node->child.end();node->child.next())
                {
                        ret+=count(node->child.current());//剩下的节点
                }
                ret+=1;
             }
        }
        return ret;
    }
    int height(GTreeNode<T>* node) const
    {
       int ret=0;
       if(node!=NULL)
       {
           for(node->child.move(0);!node->child.end();node->child.next())
           {
              int h=height(node->child.current());
              if(h>ret)
              {
                  ret=h;
              }
           }
           ret+=1;
        }
       return ret;
    }
    int degree(GTreeNode<T>* node)const
    {
       int ret=0;
       if(node!=NULL)
       {
           ret=node->child.length();//cal child tree height
           for(node->child.move(0);!node->child.end();node->child.next())
           {
               int d=degree(node->child.current());
               if(d>ret)
               {
                   ret=d;
               }
           }
       }
       return ret;
    }
public:
    GTree()
    {

    }
    //insert operator
    bool insert(TreeNode<T>* node)
    {
         bool ret=false;
         if(node!=NULL)
         {
            if(this->m_root==NULL)
            {
                node->parent=NULL;
                this->m_root=node;
            }
            else
            {
                    //find
                GTreeNode<T>* np=find(node->parent);//find parent
                if(np!=NULL)
                {
                  //判断当前Node结点的parent是否存在
                    GTreeNode<T>* n=dynamic_cast<GTreeNode<T>*>(node);
                    if(np->child.find(n)<0)
                    {
                        np->child.insert(n);
                        ret=true;
                    }
                }
                else
                {
                        //throw memory malloc error
                }
            }
         }
         else
         {
         //throw param can not be a NULL
         }
         return ret;
    }
    bool insert(const T& value,TreeNode<T>* parent)
    {
        bool ret=false;
        GTreeNode<T>* node=GTreeNode<T>::NewNode();//工厂模式creat a node obj
        if(node!=NULL)
        {
            //维护父结点并且插入元素
            node->parent=parent;
            node->values=value;
            ret=insert(node);//ok
        }
        return ret;
    }
    GTreeNode<T>* find(TreeNode<T>* node)const
    {
        return find(root(),dynamic_cast<GTreeNode<T>*>(node));
    }
    GTreeNode<T>* find(const T& value)const
    {
        return find(root(),value);
    }
    SharedPointer<Tree<T>> remove(TreeNode<T>* node)
    {
        GTree<T>* ret=NULL;
        GTreeNode<T>* node_t=find(node);
        if(node_t==NULL)
        {
            //抛出异常
        }
        else
        {
         remove(node_t,ret);
        }
        return ret;
    }
    SharedPointer<Tree<T>> remove(const T& value)
    {
        GTree<T>* ret=NULL;
        GTreeNode<T>* node_t=find(value);
        if(node_t==NULL)
        {
        //抛出异常
        }
        else
        {
            remove(node_t,ret);
        }
        return ret;
    }
    GTreeNode<T>* root() const
    {
     return dynamic_cast<GTreeNode<T>*>(this->m_root);
    }
   void clear()
   {
        free(root());//程序BUG
        queue.clear();
        this->m_root=NULL;
   }
   int degree() const
   {
        return degree(root());
   }
   int height() const
   {
        return height(root());
   }
   int count() const
   {
        return count(root());
   }
   bool begin()
   {
       bool ret=(root()!=NULL);
       if(ret)
       {
          queue.add(root());//进队列
       }
       return ret;
   }
   bool end()
   {
       return (queue.length()==0);
   }
   bool next()
   {
       bool ret=(queue.length()>0);
       if(ret)
       {
           GTreeNode<T>* node=queue.front();
           //队头元素弹出
           queue.remove();
           //遍历子结点
           for(node->child.move(0);!node->child.end();node->child.next())
           {
               queue.add(node->child.current());
           }
       }
       return ret;
   }
   T current()
   {
       //add !empty
       if(!end())
       {
            return queue.front()->values;
       }
       else
       {
           //throw expection
       }
   }
};
}
#endif // GTREE_H
