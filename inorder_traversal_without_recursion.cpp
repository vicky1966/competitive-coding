#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;


struct node
{
	node *left;
	node *right;
	int data;
};

node *newnode(int data)
{
	node *temp=new node();
	temp->left=temp->right=NULL;
	temp->data=data;
	return temp;
}

node *create()
{
	int x;
	node *p;
	cout<<"\nEnter the data \n";
	cin>>x;
	
	if(x==0)
		return NULL;
	p=new node();
	p->data=x;
	cout<<"\nEnter the left child of "<<x;
	p->left=create();
	
	cout<<"\nenter the right child of "<<x;
	p->right=create();
	
	return p;
}

void preorder(node *t)
{
	if(t!=NULL)
	{
		cout<<t->data<<" ";
		preorder(t->left);
		preorder(t->right);
	}
}

void preorderwithoutrecursion(node *root)
{
	stack<node *> s;
	
	node *current =root;
	bool done =0;
	while(!done)
	{
		if(current!=NULL)
		{
			s.push(current);
			current=current->left;
		}
		else
		{
			if(!s.empty())
			{
				current = s.top();
				s.pop();
				cout<<current->data<<" ";
				current=current->right;
			}
			else
			done = 1;
		}
	}
	
}

void inorder_without_stack(node *root)
{
	node *current = root;
	while(current!=NULL)
	{
		if(current->left==NULL)
		{
			cout<<current->data<<" ";
			current=current->right;
		}
		else
		{
			node *pred=current->left;
			while(pred->right!=NULL && pred->right!=current)
				{
					pred=pred->right;
				}
			if(pred->right==NULL)
			{
				pred->right=current;
				current=current->left;
			}
			else if(pred->right==current)
			{
				pred->right=NULL;
				cout<<current->data<<" ";
				current=current->right;
			}
		}
	}
}

node * sum(node *a,node *b)
{
	node *temp=a;
	int carry=0;
	int sum=0;
	
	while(b!=NULL || temp!=NULL)
	{
		if(temp!=NULL && b!=NULL)
		{
			sum=temp->data+b->data+carry;
		}
		else if(temp!=NULL && b==NULL)
		{
			sum=temp->data+carry;
		}
		a->data=sum%10;
		carry=sum/10;
		temp=temp->next;
		b=b->next;
	}
	return a;
}


void p(node *root)
{
	while(root)
	{
		cout<<root->data;
		root=root->next;
	}
}

int main()
{
	node *root = create();
	node *root1= create();
	node *sum = sum(root,root1);
	p(sum);
	//preorder(root);
	//cout<<endl;
	//preorderwithoutrecursion(root);
	//cout<<endl;
	//inorder_without_stack(root);
}
