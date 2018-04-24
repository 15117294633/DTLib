#ifndef BTREE_H
#define BTREE_H
#include "BTreeNode.h"
#include "Tree.h"
#include "LinkQueue.h"
#include "Array.h"
#include "DynamicArray.h"
#include "circlequeue.h"
namespace DTLib {
enum BTTravelsal
{
    LevelCommand,
    PreOrder,
    InOrder,
    PostOrder
};
template <typename T>
class BTree:public Tree<T>
{ 
protected:

    CircleQueue<BTreeNode<T>*> queue;
    //插入的位置
    enum BTNodePos
    {
      ANY,
      LEFT,
      RIGHT
    };
    virtual BTreeNode<T>* find(BTreeNode<T>* node,const T& value) const
    {
        //creat a temp pointer
        BTreeNode<T>* ret=NULL;
        if(node!=NULL)
        {
            //出口条件
            if(node->values==value)
            {
                ret=node;
            }
            else
            {
                if(ret==NULL)
                {
                   ret=find (node->left,value);
                }
                if(ret==NULL)
                {
                   ret=find (node->right,value);
                }
            }
        }
        return ret;
    }
    virtual BTreeNode<T>* find(BTreeNode<T>* node,BTreeNode<T>* obj) const
    {
        BTreeNode<T>* ret=NULL;
        if(node!=NULL)
        {
            if(node==obj)
            {
                ret=node;
            }
            else
            {
                if(ret==NULL)
                {
                   ret=find (node->left,obj);
                }
                if(ret==NULL)
                {
                   ret=find (node->right,obj);
                }
            }
        }
        return ret;
    }
    //Common operator
    //np is parent node
    virtual bool insert(BTreeNode<T>* n,BTreeNode<T>* np,BTNodePos pos)
    {
        bool ret=true;
        switch(pos)
        {
        case ANY:
            if(np->left==NULL)
            {
                np->left=n;
            }
            else if(np->right==NULL)
            {
               np->right=n;
            }
            else
            {
                ret=false;
            }
            break;
        case LEFT:
            if(np->left==NULL)
            {
                np->left=n;
            }
            else
            {
                ret=false;
            }
            break;
        case RIGHT:
            if(np->right==NULL)
            {
                np->right=n;
            }
            else
            {
                ret=false;
            }
            break;
        }
        return ret;
    }

    void free(BTreeNode<T>* node)
    {
        if(node!=NULL)
        {
            if(node->left!=NULL)
            {
                free(node->left);
            }
            if(node->right!=NULL)
            {
                free(node->right);
            }
            if(node->get_flag())
            {
                delete node;
            }
        }
    }
    void remove(BTreeNode<T>* node,BTree<T>* &ret)
    {
        if(node!=NULL)
        {
            //creat a new tree
            ret=new BTree<T>();
            if(ret!=NULL)
            {
                if(root()==NULL)
                {
                    this->m_root=NULL;
                }
                else
                {
                    //get parent
                    BTreeNode<T>* parent=dynamic_cast<BTreeNode<T>*>(node->parent);
                    if(parent->left==node)
                    {
                        parent->left=NULL;
                    }
                    else if(parent->right==node)
                    {
                        parent->right=NULL;
                    }
                   node->parent=NULL;
                }

                ret->m_root=node;
            }
            else
            {
                //cout<<node->values<<" ";
            }
        }
        else
        {
            //抛出参数异常的错误
        }
    }
    int count(BTreeNode<T>* node)const
    {
        return (node==NULL)?0:count(node->left)+count(node->right)+1;
    }
    int height(BTreeNode<T>*node) const
    {
       int h=0;
       if(node!=NULL)
       {
            int lh=height(node->left);
            int rh=height(node->right);
            h=((lh>rh)?lh:rh)+1;
       }
       else
       {
           //抛出异常information
       }
       return h;
    }
    //preorder
    void PreOrderTraversal(BTreeNode<T>* node,CircleQueue<BTreeNode<T>*>& queue)
    {
        if(node!=NULL)
        {
            queue.add(node);
            PreOrderTraversal(node->left,queue);
            PreOrderTraversal(node->right,queue);
        }
    }
    void InOrderTraversal(BTreeNode<T>* node,CircleQueue<BTreeNode<T>*>& queue)
    {
        if(node!=NULL)
        {
            InOrderTraversal(node->left,queue);
            queue.add(node);
            InOrderTraversal(node->right,queue);
        }
    }
    void LevelOrderTraversal(BTreeNode<T>* node,CircleQueue<BTreeNode<T>*>& queue)
    {
        if(node!=NULL)
        {
           CircleQueue<BTreeNode<T>*> tmp;
           tmp.add(node);
           while(tmp.length()>0)
           {
               //get head from queue
               BTreeNode<T>* node=tmp.front();
               if(node->left!=NULL)
                   tmp.add(node->left);
               if(node->right!=NULL)
                   tmp.add(node->right);
               if(tmp.length()>0)
               {
                  queue.add(tmp.front());
                  tmp.remove();
               }
           }
        }
        else
        {

        }
    }
    void PostOrderTraversal(BTreeNode<T>* node,CircleQueue<BTreeNode<T>*>& queue)
    {
        if(node!=NULL)
        {
            PostOrderTraversal(node->left,queue);
            PostOrderTraversal(node->right,queue);
            queue.add(node);
        }
    }
    //clone操作
    BTreeNode<T>* clone(BTreeNode<T>* node) const
    {
         BTreeNode<T>* n=NULL;
         if(node!=NULL)
          {
            n= BTreeNode<T>::B_new();
            if(n!=NULL)
            {
                n->values=node->values;
                n->left=clone(node->left);
                n->right=clone(node->right);
                if(n->left!=NULL)
                {
                    n->left->parent=n;
                }
                if(n->right!=NULL)
                {
                    n->left->parent=n;
                }
            }
            else
            {
                //throw expection
            }
         }
         return n;
    }
    //compare operator
    bool equal(BTreeNode<T>* lh,BTreeNode<T>*rh)
    {
        bool ret=false;
        if(lh==rh)
        {
            ret=true;
        }
        else if(lh!=NULL&&rh!=NULL)
        {
            ret=(lh->values=rh->values)&&(equal(lh->left,rh->left))&&(equal(lh->right,rh->right));
        }
        else
        {
            ret=false;
        }
        return ret;
    }
    BTreeNode<T>* add(BTreeNode<T>* lh,BTreeNode<T>* rh)const
    {
         BTreeNode<T>* ret=NULL;
         if((lh==0)&&(rh!=0))
         {
            ret=clone(rh);
         }
         else if((lh!=0)&&(rh==0))
         {
            ret=clone(lh);
         }
         else if((lh!=NULL)&&(rh!=NULL))
         {
            ret= BTreeNode<T>::B_new();
            if(ret!=NULL)
            {
                ret->values=lh->values+rh->values;
                ret->left=add(lh->left,rh->left);
                ret->right=add(lh->right,rh->right);
                if(ret->left!=NULL)
                {
                    ret->left->parent=ret;
                }
                if(ret->right!=NULL)
                {
                    ret->left->parent=ret;
                }
            }
            else
            {
                //throw expection
            }
         }
         return ret;
    }
    //重载版本
    void traversal(BTTravelsal order,CircleQueue<BTreeNode<T>*>& queue)
    {
        switch(order)
        {
        case PreOrder:
            PreOrderTraversal(root(),queue);
            break;
        case InOrder:
             InOrderTraversal(root(),queue);
            break ;
        case PostOrder:
             PostOrderTraversal(root(),queue);
            break;
        case LevelCommand:
         default :
            LevelOrderTraversal(root(),queue);
            //throw expection
            break;
        }
    }
    BTreeNode<T>* connect(CircleQueue<BTreeNode<T>*>& queue)
    {

        BTreeNode<T>* slider=queue.front();
        BTreeNode<T>* ret=queue.front();
        queue.remove();
        while(queue.length()>0)
        {
            slider->left=queue.front();
            queue.front()->right=slider;
            slider=queue.front();
            queue.remove();
        }
        slider->left=NULL;
        return ret;
    }
public:
     bool insert(TreeNode<T>* node)
     {
        return insert(node,ANY);
     }
     bool insert(TreeNode<T>* node,BTNodePos pos)
     {
         //ret
         bool ret=false;
         if(node!=NULL)
         {
             //first judgement tree has a node
             if(this->m_root==NULL)
             {
                node->parent=NULL;
                this->m_root=node;
                ret=true;
             }
             else
             {
                //here you find a parent list
                BTreeNode<T>* np=find(node->parent);
                if(np!=NULL)
                {
                    ret=insert(dynamic_cast<BTreeNode<T>*>(node),np,pos);
                }
                else
                {
                    //抛出异常
                }
             }
         }
         else
         {
             //抛出参数异常
         }
         return ret;
     }
     //insert 操作
     bool insert(const T& value,TreeNode<T>* parent)
     {
        return insert(value,parent,ANY);
     }
     bool insert(const T& value,TreeNode<T>* parent,BTNodePos pos)
     {
         bool ret=true;
         BTreeNode<T>* node= BTreeNode<T>::B_new();
         if(node!=NULL)
         {
             node->parent=parent;
             node->values=value;
             ret=insert(node,pos);
             if(!ret)
             {
                delete node;
             }
         }
         else
         {
             //抛出内存申请ERROR
         }
         return ret;
     }

     BTreeNode<T>* find(TreeNode<T>* node)const
     {
         return find(root(),dynamic_cast<BTreeNode<T>*>(node));
     }
     BTreeNode<T>* find(const T& value)const
     {
         return find(root(),value);
     }
     SharedPointer<Tree<T>> remove(TreeNode<T>* node)
     {
         BTree<T>*  ret=NULL;
         BTreeNode<T>* node_t=find(node);
         remove(node_t,ret);
         return ret;
     }
     SharedPointer<Tree<T>> remove(const T& value)
     {
         BTree<T>*  ret=NULL;
         BTreeNode<T>* node_t=find(value);
         remove(node_t,ret);
         return ret;
     }
     BTreeNode<T>* root() const
     {
        return dynamic_cast<BTreeNode<T>*>(this->m_root);
     }
     void clear()//clear operator
     {
        free(root());
        this->m_root=NULL;
     }
     int degree() const
     {
         return 0;
     }
     int height() const
     {
         return height(root());
     }
     int count() const
     {
         return count(root());
     }
     //层次遍历算法
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
              BTreeNode<T>* node=queue.front();
              queue.remove();
              if(node->left!=NULL)
              {
                  queue.add(node->left);
              }
              if(node->right!=NULL)
              {
                  queue.add(node->right);
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
     //
     SharedPointer<Array<T>> traversal(BTTravelsal order)
     {
         DynamicArray<T>* ret=NULL;//creat a new ret object
         CircleQueue<BTreeNode<T>*> queue;//queue recerve
         traversal(order,queue);
         ret=new DynamicArray<T>(queue.length());
         //判断参数的合法性
         if(ret)
         {
            for(int i=0;i<ret->length();i++,queue.remove())
            {
                ret->set(i,queue.front()->values);
            }
         }
         else
         {
             //throw expection
         }
         return ret;
     }
     SharedPointer<BTree<T>> clone()const
     {
         //return Btree
         BTree<T>* ret=new BTree<T>();
         if(ret!=NULL)
         {
            ret->m_root=clone(root());
         }
         else
         {
             //throw exception
         }
        return ret;
     }
     SharedPointer<BTree<T>> add(const BTree<T>& btree) const
     {
        BTree<T>* ret=new BTree<T>();
        if(ret)
        {
            ret->m_root=add(root(),btree.root());
        }
        else
        {

        }
        return ret;
     }
     bool operator ==(const BTree<T>& btree)
     {
        return equal(root(),btree.root());
     }
     bool operator !=(const BTree<T>& btree)
     {
        return !(*this==btree);
     }
     BTreeNode<T>* thread(BTTravelsal order)
     {
         BTreeNode<T>* ret=NULL;
         CircleQueue<BTreeNode<T>*> queue;
         traversal(order,queue);
         ret=connect(queue);
         this->m_root=NULL;//tree clear
         this->queue.clear();//clear queue
         return ret;
     }
};
}
#endif // BTREE_H
