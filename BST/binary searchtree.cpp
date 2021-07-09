#include<iostream>
using namespace std;

struct node
{
    struct node* lchild;
    struct node* rchild;
    int data;
};

struct node* newNode(int item)
{
    node* ptr=new node;
    ptr->data=item;
    ptr->lchild=NULL;
    ptr->rchild=NULL;
    return ptr;
}

struct node* insert(struct node* r,int item)
{
    if(r==NULL)
		return newNode(item);
    else
	{
        struct node *temp=r;
        struct node * parent=NULL;
        while(temp!=NULL)
		{
            parent=temp;
            if(item>temp->data)
                temp=temp->rchild;
            else
                temp=temp->lchild;
        }
        if(item<parent->data)
            parent->lchild=newNode(item);
        else
        	parent->rchild=newNode(item);
    }
    return r;
}

void printInorder(struct node* root)
{
    if(root==NULL)
        return;
    else
	{
        printInorder(root->lchild);
        cout<<root->data<<" ";
        printInorder(root->rchild);
    }
}

void printPostorder(struct node* root)
{
    if(root==NULL)
        return;
    else
	{
        printPostorder(root->lchild);
        printPostorder(root->rchild);
        cout<<root->data<<" ";
    }
}

void printPreorder(struct node* root)
{
    if(root==NULL)
        return;
    else
	{
        cout<<root->data<<" ";
        printPreorder(root->lchild);
        printPreorder(root->rchild);
    }
}

int totalNodes(struct node* root)
{
    if(root==NULL)
        return 0;
    else
        return totalNodes(root->lchild)+totalNodes(root->rchild)+1;
}

int search(struct node* root,int key)
{
    if(root==NULL)
        return 0;
    else{
        if (root->data==key)
            return 1;
        else if(key< root->data)
            return search(root->lchild,key);
        else
          return search(root->rchild,key);
    }
}

int height(struct node* root)
{
    if(root==NULL)
        return 0;
    int lh=height(root->lchild);
    int rh=height(root->rchild);
    return(lh>rh?lh+1:rh+1);
}

int smallest(struct node* root)
{
    if(root==NULL)
        return -1;
    while(root->lchild!=NULL)
        root=root->lchild;
    return root->data;
}
int largest(struct node* root)
{
    if(root==NULL)
        return -1;
    while(root->rchild!=NULL)
        root=root->rchild;
    return root->data;
}

int externalNodes(struct node* root)
{
    if(root==NULL)
        return 0;
    else if(root->lchild==NULL && root->rchild==NULL)
        return 1;
    else
        return(externalNodes(root->lchild)+externalNodes(root->rchild));
}
int internalNodes(struct node* root)
{
    if(root==NULL)
        return 0;
    else if(root->lchild==NULL && root->rchild==NULL)
        return 0;
    else
        return(internalNodes(root->lchild)+internalNodes(root->rchild)+1);
}

void del(struct node** root,int key)
{
    if (*root==NULL)
		return;
    struct node* x=*root;
    struct node* parent=NULL;
    while(x!=NULL && x->data!=key)
	{
        parent=x;
        if(key<x->data)
            x=x->lchild;
        else
            x=x->rchild;
	}

	if(x==NULL)
	{
        cout<<"Element not found!! ";
        return;
    }
    if(x->lchild==NULL || x->rchild==NULL)
	{
        struct node* ptr;
        if(x->lchild==NULL) ptr=x->rchild;
        else ptr=x->lchild;
        if(parent==NULL)
		{
            *root=ptr;
            delete(x);
            return;
        }
        if(x==parent->lchild)
            parent->lchild=ptr;
        else
            parent->rchild=ptr;
            delete(x);
            return;
        }
    else
	{
        struct node* succ=x->rchild;
        struct node* psucc=NULL;
        while(succ->lchild!=NULL)
		{
            psucc=succ;
            succ=succ->lchild;
        }
        x->data=succ->data;
        if(psucc==NULL)
            x->rchild=succ->rchild;
        else
            psucc->lchild=succ->rchild;
        delete(succ);
        return;
    }
}

int main()
{
    int ch;
    struct node* root=NULL;
    while(ch!=12)
	{
        cout<<"**********************"<<endl;
        cout<<" 1: Insert an element\n 2: Preorder Traversal\n 3: Inorder Traversal\n 4: Postorder Traversal\n 5: Smallest element\n 6: Largest element\n 7: Delete element\n 8: Total no. of nodes\n 9: External nodes\n 10: Internal nodes\n 11: Height of tree\n 12: Exit\n ";
        cout<<"**********************"<<endl;
        cout<<"enter your choice: ";
		cin>>ch;
		switch(ch)
		{
            case 1:
                int n;
                cout<<"Enter the element: ";
                cin>>n;
                root=insert(root,n);
                cout<<endl;
                break;
            case 2:
                cout<<"Preorder traversal: ";
                printPreorder(root);
                cout<<endl;
                break;
            case 3:
                cout<<"Inorder traversal: ";
                printInorder(root);
                cout<<endl;
                break;
            case 4:
                cout<<"Postorder traversal: ";
                printPostorder(root);
                cout<<endl;
                break;
            case 5:
                cout<<"The smallest element is "<<smallest(root);
                cout<<endl;
                break;
            case 6:
                cout<<"The largest element is "<<largest(root);
                cout<<endl;
                break;
            case 7:
                int num;
                cout<<"enter the element you want to delete: ";
                cin>>num;
                del(&root,num);
                cout<<endl;
                break;
            case 8:
                cout<<"The total number of nodes is: "<<totalNodes(root);
                cout<<endl;
                break;
            case 9:
                 cout<<"The total number of external nodes is: "<<externalNodes(root);
                cout<<endl;
                break;
            case 10:
                 cout<<"The total number internal of nodes is: "<<internalNodes(root);
                cout<<endl;
                break;
            case 11:
                cout<<"Height of tree is: "<<height(root);
                cout<<endl;
                break;
            case 12:
                break;
            default:
                cout<<"Enter appropriate option!! ";
                cout<<endl;
                break;
        }
    }
    return 0;
}
