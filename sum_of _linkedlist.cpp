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
		cout<<root->data<<" ";
		root=root->next;
	}
	cout<<endl;
}



node * summ(node *a,node *b)
{
	node *temp=a;
	int carry=0;
	int sum=0;
	node *prev;
	while(b!=NULL || temp!=NULL)
	{
		if(temp!=NULL && b!=NULL)
		{
			sum=temp->data+b->data+carry;
			temp->data=sum%10;
			carry=sum/10;
		}
		else if(temp!=NULL && b==NULL)
		{
			sum=temp->data+carry;
			temp->data=sum%10;
			carry=sum/10;
		}
		else if(temp==NULL && b!=NULL)
		{
			sum=b->data+carry;
			if(a==NULL)
			{
				a=newnode(sum);
				temp=a;
			}
				
			else
			{
				prev->next=newnode(sum);
				prev=prev->next;
			}
			carry=sum/10;
			
		}
		if(temp!=NULL)
		{
			prev=temp;
			temp=temp->next;
		}	
		if(b!=NULL)
		b=b->next;
	}
	while(carry)
	{
		prev->next=newnode(carry);
		carry=carry/10;
	}
	return a;
}

void del(node **root,int m,int n)
{
	node *temp=*root;
	node *last;
	while(temp )
	{
		for(int i=1;i<m && temp!=NULL;i++)
		{
			temp=temp->next;
		}
		if(temp==NULL)
		return;
		node *p=temp;
		for(int i=1;i<=n && p!=NULL;i++)
		{
			p=p->next;
		}
		temp->next=p->next;
		temp=temp->next;
	}
}        

node *l(node *root)
{
	node *temp=root;
	while(temp->next!=NULL)
		temp=temp->next;
	return temp;
}

node *partition(node *start,node *end)
{
	int pivot=end->data;
	node *temp=start;
	node *pindex=start;
	//cout<<"temp->data= "<<temp->data;
	node *prev=start;
	while(temp!=end)
	{
		if(temp->data <= pivot)
		{
			int data = temp->data;
			temp->data=pindex->data;
			pindex->data=data;
			prev=pindex;
			//cout<<"\n prev->data= "<<prev->data;
			pindex=pindex->next;
		}
		temp=temp->next;
	}
	int data=pindex->data;
	pindex->data=end->data;
	end->data=data;
	return prev;
}


void quick(node *start,node *end)
{
	if(end!=NULL && start!=end && start!=end->next)
	{
		node *pp = partition(start,end);
		//cout<<pp->data<<" \n";
		//p(start);
		if(pp!=start)
		{
			quick(start,pp);
		quick(pp->next->next,end);
		}
		else
		{
			quick(pp->next,end);
		}
		
	}
}

void quicksort(node *root)
{
	if(root== NULL)
		return ;
	else
	{
		node *last = l(root);
		//cout<<last->data;
		quick(root,last);
	}
}

int main()
{
	node *root = create();
	p(root);
	quicksort(root);
	//quicksort(root);
	p(root);
	//cout<<"\n Enter the m and n\n";
	//int m,n;
	//cin>>m>>n;
	//del(&root,m,n);
	//p(root);
	//preorder(root);
	//cout<<endl;
	//preorderwithoutrecursion(root);
	//cout<<endl;
	//inorder_without_stack(root);
	quicksort(root);
}
