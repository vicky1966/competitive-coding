#include<iostream>
#include<map>
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

node *clone(node *root)
{
	node *temp = root;
	node *root2=newnode(root->data);
	node *temp2=root2;
	map<node *,node *> m;
	m.insert(pair<node *,node *>(root,root2));
	root=root->next;
	while(root)
	{
		temp2->next=newnode(root->data);
		//m.insert(pair<node *,node*>(root,temp2->next));
		m[root]=temp2->next;
		temp2=temp2->next;
		root=root->next;
	}
	
	temp2=root2;
	
	map<node *,node *>:: iterator it;
	
	for(it=m.begin();it!=m.end();it++)
		cout<<it->second<<"\t"<<it->first<<"\t";
		
		
		

	while(temp)
	{
		temp2->random=m.find(temp->random)->second;
		temp2=temp2->next;
		temp=temp->next;
	}
	
	
	return root2;
}




node * k[10];
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
			k[count++]=root;
		}
		else
		{
			temp->next=newnode(data);
			k[count++]=temp->next;
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
		cout<<temp->data<<"\t\t";
		temp=temp->next;
	}
	cout<<endl;
	temp=root;
	while(temp)
	{
		cout<<temp<<"\t";
		temp=temp->next;
	}
	cout<<endl;
}

int main()
{
	node *root=create();
	p(root);

	cout<<endl; 
	cout<<endl;
	
	node *root2=clone(root);
	cout<<endl;
	p(root2);

}
