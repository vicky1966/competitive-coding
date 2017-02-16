#include<iostream>
using namespace std;

struct node
{
	int data;
	node *next;
	node *random;
};

node *newnode(int data)
{
	node *temp = new node();
	temp->next=NULL;
	temp->random=NULL;
	temp->data=data;
}

node *create()
{
	int data;
	cout<<"\nEnter the data\n";
	cin>>data;
	node *root=NULL;
	node *temp;
	int count=0;
	while(data!=-1)
	{
		if(root==NULL)
		{
			root=newnode(data);
			temp=root;
			
		}
		else
		{
			temp->next=newnode(data);
			temp=temp->next;
		}
		cout<<"\n Enter data\n";
		cin>>data;
	}
	return root;
}


void sorted(node **root2,node *root)
{
	if(*(root2)==NULL || (*root2)->data >=root->data)
	{
		root->next = *root2;
		*root2=root;
	}
	else
	{
		node *prev;
		node *temp=*root2;
		while(temp!=NULL && temp->data<=root->data)
		{
			prev=temp;
			temp=temp->next;
		}
		node *next=prev->next;
		prev->next=root;
		root->next=next;
	}
}
node *insertion(node *root)
{
	if(root==NULL || root->next==NULL)
	{
		return root;
	}
	node *root2=NULL;
	node *temp;
	while(root)
	{
		temp=root->next;
		sorted(&root2,root);
		root=temp;
	}
	return root2;
}


void p(node *root)
{
	node *temp=root;
	while(temp)
	{
		cout<<temp->data<<"\t";
		temp=temp->next;
	}
	cout<<endl;
}

int main()
{
	node *root = create();
	p(root);
	node *s=insertion(root);
	p(s);
}
