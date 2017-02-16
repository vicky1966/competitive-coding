#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

struct node
{
	node *next;
	int data;
};

node *newnode(int data)
{
	node *temp=new node();
	temp->next=NULL;
	temp->data=data;
	return temp;
}

node *create()
{
	int data;	
	cout<<"Enter the data\n";
	cin>>data;
	node *root=NULL;
	node *temp;
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
		cout<<"\nEnter the data\n";
		cin>>data;
	}
	return root;
}


void p(node *root)
{
	while(root)
	{
		cout<<root->data;
		root=root->next;
	}
	cout<<endl;
}

node *summ(node *a,node *b)
{
	node *result,*curr=NULL;
	int carry=0;
	int sum;
	while(a!=NULL && b!=NULL)
	{
		if(curr==NULL)
		{
			sum=a->data + b->data + carry;
			carry=sum/10;
			curr=newnode(sum%10);
			result=curr;
			a=a->next;
			b=b->next;
			continue;
		}
			sum=a->data + b->data + carry;
			carry=sum/10;
			curr->next=newnode(sum%10);
			curr=curr->next;
			a=a->next;
			b=b->next;
	
	}
	
	while(a!=NULL)
	{
			if(curr==NULL)
		{
			sum=a->data + carry;
			carry=sum/10;
			curr=newnode(sum%10);
			result=curr;
			continue;
		}
			sum=a->data + carry;
			carry=sum/10;
			curr->next=newnode(sum%10);
			curr=curr->next;
			a=a->next;
			
		
	}
	
	
	while(b!=NULL)
	{
		if(curr==NULL)
		{
			sum=b->data + carry;
			carry=sum/10;
			curr=newnode(sum%10);
			result=curr;
			continue;
		}
			sum=b->data + carry;
			carry=sum/10;
			curr->next=newnode(sum%10);
			curr = curr->next;
			b=b->next;
			
	}
	
	while(carry)
	{
		curr->next=newnode(carry%10);
		carry=carry/10;	
	}
	
	return result;
}

                    
int main()
{
	node *root = create();

	node *root1= create();	
	p(root);
	p(root1);
	node *sum = summ(root,root1);
	p(sum);
	//preorder(root);
	//cout<<endl;
	//preorderwithoutrecursion(root);
	//cout<<endl;
	//inorder_without_stack(root);
}
