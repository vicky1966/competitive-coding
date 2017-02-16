#include<iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};

node *newnode(int data)
{
	node *temp = new node();
	temp->data=data;
	temp->next=NULL;
	return temp;
}

node *create()
{
	struct node *head=NULL;
	node *temp;
	cout<<"Enter data \n";
	int data;	cin>>data;
	
	while(data!=-1)
	{
		if(head==NULL)
		{
			head=newnode(data);
			temp=head;	
		}
		else
		{
			temp->next=newnode(data);
			temp=temp->next;
		}
		cout<<"\nEnter data \n";
		cin>>data;
	}
	return head;
}

void print_link(node *root)
{
	while(root)
	{
		cout<<root->data<<" ";
		root=root->next;
	}
}

void split(node *head,node **a,node **b)
{
	node *slow;
	node *fast;
	if(head==NULL || head->next==NULL)
	{
		*a=head;
		*b=NULL;
	}
	else
	{
		slow=head;
		fast=head->next;
		while(fast!=NULL && fast->next!=NULL)
		{
			
			fast=fast->next;
			if(fast->next!=NULL && fast!=NULL)
			{
				slow=slow->next;
				fast=fast->next;
			}
		}
		*b=slow->next;
		slow->next=NULL;
		*a=head;
	}
}

node *sorted(node *a,node *b)
{
	node *result = NULL;
	if(a==NULL)
		return b;
	if(b==NULL)
		return a;
		
	if(a->data <= b->data)
	{
		result = a;
		result->next=sorted(a->next,b);
	}
	else
	{
		result = b;
		result->next = sorted(a,b->next);
	}
	return result;
}

void merge(node **root)
{
	node *head = *root;
	node *a;
	node *b;
	if(head==NULL || head->next==NULL)
		return;
	split(head,&a,&b);
	
	merge(&a);
	merge(&b);
	
	*root = sorted(a,b);
}


int main()
{
	node *root;
	root = create();
	
	print_link(root);	
	merge(&root);
	cout<<endl;
	print_link(root);
}
