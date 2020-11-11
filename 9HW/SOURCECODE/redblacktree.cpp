#include <iostream>
using namespace std;
enum Color { RED, BLACK};
struct node
{
	int key;
	Color color;
	node *left, *right,*parent;
};
class RedBlackTree{
private:
	node *root;
protected:
	void rotateLeft(node *);//done
	void rotateRight(node *);//done
public:
	RedBlackTree(){
		root = NULL;
	}
	void insert(int);//done
	void RB_INSERT_FIXUP(node *);//done
	void  delet(int);//done
	void RB_DELETE_FIXUP(node *);//done
	node * predecessor(node *);
	node * successor(node *);//done
	node * getMinimum();//done
	node * getMaximum();//doncleare
	void search();//done
	void disp();
	void display(node *);
};

void RedBlackTree::rotateLeft(node *x)
{
     if(x->right==NULL)
           return ;
     else
     {
           node *y=x->right;
           if(y->left!=NULL)
           {
                  x->right=y->left;
                  y->left->parent=x;
           }
           else
                  x->right=NULL;
           if(x->parent!=NULL)
                y->parent=x->parent;
           if(x->parent==NULL)
                root=y;
           else
           {
               if(x==x->parent->left)
                       x->parent->left=y;
               else
                       x->parent->right=y;
           }
           y->left=x;
           x->parent=y;
     }
}
void RedBlackTree::rotateRight(node *x)
{
     if(x->left==NULL)
          return ;
     else
     {
         node *y=x->left;
         if(y->right!=NULL)
         {
                  x->left=y->right;
                  y->right->parent=x;
         }
         else
                 x->left=NULL;
         if(x->parent!=NULL)
                 y->parent=x->parent;
         if(x->parent==NULL)
               root=y;
         else
         {
             if(x==x->parent->left)
                   x->parent->left=y;
             else
                   x->parent->right=y;
         }
         y->right=x;
         x->parent=y;
     }
}

void RedBlackTree::insert(int z)
{
     node *p,*q;
     node *t=new node;
     t->key=z;
     t->left=NULL;
     t->right=NULL;
     t->color=RED;
     p=root;
     q=NULL;
     if(root==NULL)
     {
           root=t;
           t->parent=NULL;
     }
     else
     {
         while(p!=NULL)
         {
              q=p;
              if(p->key<t->key)
                  p=p->right;
              else
                  p=p->left;
         }
         t->parent=q;
         if(q->key<t->key)
              q->right=t;
         else
              q->left=t;
     }
     RB_INSERT_FIXUP(t);
}
void RedBlackTree::RB_INSERT_FIXUP(node *t)
{
     node *u;
     if(root==t)
     {
         t->color=BLACK;
         return;
     }
     while(t->parent!=NULL&&t->parent->color==RED)
     {
           node *g=t->parent->parent;
           if(g->left==t->parent)
           {
                        if(g->right!=NULL)
                        {
                              u=g->right;
                              if(u->color==RED)
                              {
                                   t->parent->color=BLACK;
                                   u->color=BLACK;
                                   g->color=RED;
                                   t=g;
                              }
                        }
                        else
                        {
                            if(t->parent->right==t)
                            {
                                 t=t->parent;
                                 rotateLeft(t);
                            }
                            t->parent->color=BLACK;
                            g->color=RED;
                            rotateRight(g);
                        }
           }
           else
           {
                        if(g->left!=NULL)
                        {
                             u=g->left;
                             if(u->color==RED)
                             {
                                  t->parent->color=BLACK;
                                  u->color=BLACK;
                                  g->color=RED;
                                  t=g;
                             }
                        }
                        else
                        {
                            if(t->parent->left==t)
                            {
                                   t=t->parent;
                                   rotateRight(t);
                            }
                            t->parent->color=BLACK;
                            g->color=RED;
                            rotateLeft(g);
                        }
           }
           root->color=BLACK;
     }
}

void RedBlackTree::delet(int x)
{
     if(root==NULL)
     {
           cout<<"\nEmpty Tree." ;
           return ;
     }
     node *p;
     p=root;
     node *y=NULL;
     node *q=NULL;
     int found=0;
     while(p!=NULL&&found==0)
     {
           if(p->key==x)
               found=1;
           if(found==0)
           {
                 if(p->key<x) p=p->right;
                 else
                    p=p->left;
           }
     }
     if(found==0)
     {
            cout<<"\nElement Not Found.";
            return ;
     }
     else
     {
         cout<<"\nDeleted Element: "<<p->key;
         cout<<"\nColour: "; if(p->color==BLACK)
     cout<<"Black\n";
    else
     cout<<"Red\n"; 
 	if(p->parent!=NULL)
               cout<<"\nParent: "<<p->parent->key;
         else
               cout<<"\nThere is no parent of the node. "; 
           if(p->right!=NULL)
               cout<<"\nRight Child: "<<p->right->key;
         else
               cout<<"\nThere is no right child of the node. "; 
           if(p->left!=NULL)
               cout<<"\nLeft Child: "<<p->left->key;
         else
               cout<<"\nThere is no left child of the node.  ";
         cout<<"\nNode Deleted."; 
         if(p->left==NULL||p->right==NULL)
              y=p;
         else
              y=successor(p);
         if(y->left!=NULL)
              q=y->left;
         else
         {
              if(y->right!=NULL)
                   q=y->right;
              else
                   q=NULL;
         }
         if(q!=NULL)
              q->parent=y->parent;
         if(y->parent==NULL)
              root=q;
         else
         {
             if(y==y->parent->left)
                y->parent->left=q;
             else
                y->parent->right=q;
         }
         if(y!=p)
         {
             p->color=y->color;
             p->key=y->key;
         }
         if(y->color==BLACK)
             RB_DELETE_FIXUP(q);
     }
}
void RedBlackTree::RB_DELETE_FIXUP(node *p)
{
    node *s;
    while(p!=root&&p->color==BLACK)
    {
          if(p->parent->left==p)
          {
                  s=p->parent->right;
                  if(s->color==RED)
                  {
                         s->color=BLACK;
                         p->parent->color=RED;
                         rotateLeft(p->parent);
                         s=p->parent->right;
                  }
                  if(s->right->color==BLACK &&s->left->color==BLACK)
                  {
                         s->color=RED;
                         p=p->parent;
                  }
                  else
                  {
                      if(s->right->color==BLACK)
                      {
                             //s->left->color==BLACK;
                             s->color=BLACK;
                             rotateRight(s);
                             s=p->parent->right;
                      }
                      s->color=p->parent->color;
                      p->parent->color=BLACK;
                      s->right->color=BLACK;
                      rotateLeft(p->parent);
                      p=root;
                  }
          }
          else
          {
                  s=p->parent->left;
                  if(s->color==RED)
                  {
                        s->color=BLACK;
                        p->parent->color=RED;
                        rotateRight(p->parent);
                        s=p->parent->left;
                  }
                  if(s->left->color==BLACK &&s->right->color==BLACK)
                  {
                        s->color=RED;
                        p=p->parent;
                  }
                  else
                  {
                        if(s->left->color==BLACK)
                        {
                              s->right->color=BLACK;
                              s->color=RED;
                              rotateLeft(s);
                              s=p->parent->left;
                        }
                        s->color=p->parent->color;
                        p->parent->color=BLACK;
                        s->left->color=BLACK;
                        rotateRight(p->parent);
                        p=root;
                  }
          }
       p->color=BLACK;
       root->color=BLACK;
    }
}

node* RedBlackTree::successor(node *p)
{
      node *y=NULL;
     if(p->left!=NULL)
     {
         y=p->left;
         while(y->right!=NULL)
              y=y->right;
     }
     else
     {
         y=p->right;
         while(y->left!=NULL)
              y=y->left;
     }
     return y;
 }

 node* RedBlackTree::predecessor(node *p)
{
      node *y=NULL;
     if(p->left!=NULL)
     {
         y=p->left;
         while(y->right!=NULL)
              y=y->right;
     }
     else
     {
         y=p->right;
         while(y->left!=NULL)
              y=y->left;
     }
     return y;
 }
node* RedBlackTree::getMinimum(){
	node *p = root;

	while(p!=NULL){
		p = p->left;
	}
	return p->parent;
}
node *RedBlackTree::getMaximum(){
	node *p = root;

	while(p!=NULL){
		p = p->right;
	}
	return p->parent;
}
void RedBlackTree::search()
{
     if(root==NULL)
     {
           cout<<"\nEmpty Tree\n" ;
           return  ;
     }
     int x;
     cout<<"\n Enter key of the node to be searched: "; cin>>x;
     node *p=root;
     int found=0;
     while(p!=NULL&& found==0)
     {
            if(p->key==x)
                found=1;
            if(found==0)
            {
                 if(p->key<x) p=p->right;
                 else
                      p=p->left;
            }
     }
     if(found==0)
          cout<<"\nElement Not Found.";
     else
     {
                cout<<"\n\t FOUND NODE: ";
                cout<<"\n Key: "<<p->key;
                cout<<"\n Colour: "; 
    if(p->color=='b')
     cout<<"Black";
    else
     cout<<"Red"; 
 	if(p->parent!=NULL)
       cout<<"\n Parent: "<<p->parent->key;
    else
        cout<<"\n There is no parent of the node. "; 
    if(p->right!=NULL)
        cout<<"\n Right Child: "<<p->right->key;
    else
		cout<<"\n There is no right child of the node. "; 
	if(p->left!=NULL)
        cout<<"\n Left Child: "<<p->left->key;
    else{
        cout<<"\n There is no left child of the node.  ";
        }
        cout<<endl;

     }
}

void RedBlackTree::disp()
{
     display(root);
}
void RedBlackTree::display(node *p)
{
     if(root==NULL)
     {
          cout<<"\nEmpty Tree.";
          return ;
     }
     if(p!=NULL)
     {
                cout<<"\n\t NODE: ";
                cout<<"\n Key: "<<p->key;
                cout<<"\n Colour: "; 
     if(p->color==BLACK)
     cout<<"Black";
    else
     cout<<"Red"; 
 	if(p->parent!=NULL)
                       cout<<"\n Parent: "<<p->parent->key;
                else
                       cout<<"\n There is no parent of the node. "; 
                if(p->right!=NULL)
                       cout<<"\n Right Child: "<<p->right->key;
                else
                       cout<<"\n There is no right child of the node. "; 
                if(p->left!=NULL)
                       cout<<"\n Left Child: "<<p->left->key;
                else
                       cout<<"\n There is no left child of the node.  ";
                cout<<endl; 
                if(p->left){
                 cout<<"\n\nLeft:\n"; display(p->left);
             }
		    if(p->right)
		    {
		     cout<<"\n\nRight:\n"; display(p->right);
		    }
     }
}



int main()
{
    int ch,y=0;
    RedBlackTree obj;
    do
    {
                cout<<"\n\t RED BLACK TREE " ;
                cout<<"\n 1. Insert in the tree ";
                cout<<"\n 2. Delete a node from the tree";
                cout<<"\n 3. Search for an element in the tree";
                cout<<"\n 4. Display Tree";
                cout<<"\n 5. Exit " ;
                cout<<"\nEnter Your Choice: "; cin>>ch;
                int x;
                switch(ch)
                {
                          case 1 : 
                          		cout<<"what element do you want to insert? ";
                          		cin>>x;
                          		obj.insert(x);
                                cout<<"\nNode Inserted.\n";
                                break;
                          case 2 : 
                          		cout<<"what element do you want to eliminate? ";
                          		cin>>x;
                          		obj.delet(x);
                                break;
                          case 3 :
                          		obj.search();
                                break;
                          case 4 :
                          		obj.disp();
                          case 5 : y=1;
                                   break;
                          default : cout<<"\nEnter a Valid Choice.";
                }
                cout<<endl;

    }while(y!=1);
    return 1;
}