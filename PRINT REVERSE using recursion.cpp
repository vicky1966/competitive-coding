#include<iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};	

node *newnode(int data)
{
	struct node *temp=new node();
	temp->data=data;
	temp->next=NULL;
	return temp;
}

struct node *create()
{
	struct node*root=NULL;
	struct node *temp;
	int data;
	cin>>data;
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
		cout<<" Enter the data\n";
		cin>>data;
	}
	return root;
}

void print(node *root)
{
	
	while(root!=NULL)
	{
		cout<<root->data<<" ";
		root=root->next;
	}
}

void print_reverse(node *root)
{
	if(root==NULL)
		return;
	print_reverse(root->next);
	cout<<root->data<<" ";
}

int main()
{
	struct node * root=create();
	
	print(root);
	cout<<endl;
	print_reverse(root);
}
