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


node *reverse(node *root)
{
	node *next;
	node *current = root;
	node *prev=NULL;
	while(current)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	root=prev;
	return root;
}


node *mid(node *root)
{
	node *slow=root;
	node *fast=root->next;
	while(fast!=NULL && fast->next!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	

	return slow;
}


node * reorder(node *root)
{
	node *m = mid(root);
	node *first=root;
	node *second=m->next;
	m->next=NULL;
	//first = first->next;
	second = reverse(second);
	while(first || second)
	{
		if(second)
		{
			node *first_next = first->next;
			node *second_next = second->next;
			first->next = second;
			second->next = first_next;
			second = second_next;
			first = first_next;
		}
		else
		{
			first = first->next;
		}
	}
	p(root);
	
}

int main()
{
	node *root = create();
	p(root);
	

	
	reorder(root);

}
