#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};

node *create()
{
	cout<<"\nEnter the data\n";
	int data;	cin>>data;
	
	if(data==0)
		return NULL;
		node *p = new node();
	p->data=data;
	//p->left=NULL;
	//p->right=NULL;
	
	cout<<"\nEnter the left child of "<<data;
	p->left=create();
	
	cout<<"\nEnter the right child of "<<data;
	p->right=create();
	
	return p;
}

void inorder_print(node *root)
{
	if(root==NULL)
		return ;
	inorder_print(root->left);
	cout<<root->data<<" ";
	inorder_print(root->right);
}

int height(node *root)
{
	if(root==NULL)
		return 0;
	int l=height(root->left);
	int r=height(root->right);
	
	if(l>r)
		return l+1;
	else
		return r+1;
}

void levelwise(node *root,int h)
{
	if(root==NULL)
		return;
	if(h==1)
		cout<<root->data<<" ";
	else if(h>1)
	{
		levelwise(root->left,h-1);
		levelwise(root->right,h-1);
	}
}

void levelorder(node *root)
{
	if(root==NULL)
		return;
	int h = height(root);
	for(int i=1;i<=3;i++)
	{
		cout<<"\nLevel = "<<i<<" = ";
		levelwise(root,i);
	}
}

void levelorder_with_queue(node *root)
{
	if(root==NULL)
		return ;
	queue<node *> q;
	q.push(root);
	while(!q.empty())
	{
		node *temp = q.front();
		q.pop();
		cout<<temp->data<<" ";
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}
}

void inorder_with_stack(node *root)
{
	stack<node *> s;
	s.push(root);
	node *curr = root;
	while(!s.empty())
	{
		while(curr->left)
		{
			curr=curr->left;
			s.push(curr);
		}
		
		curr = s.top();
		s.pop();
		cout<<curr->data<<" ";
		if(curr->right)
		{
			s.push(curr->right);
			curr = s.top();
		}
			
	}
}

void indorder_without_recursion_and_stack(node *root) //using marris traversal
{
	node *curr = root;
	node *pre;
	
	while(curr!=NULL)
	{
		if(curr->left==NULL)
		{
			cout<<curr->data<<" ";
			curr = curr->right;
		}
		else
		{
			pre = curr->left;
			while(pre->right && pre->right!=curr )
			{
				pre=pre->right;
			}
			
			if(pre->right==NULL)
			{
				pre->right=curr;
				curr=curr->left;
			}
			else
			{
				pre->right=NULL;
				cout<<curr->data<<" ";
				curr = curr->right;
			}
			
		}
	}
}

int diameter(node *root)
{
	if(root==NULL)
		return 0;
	int height_of_l_tree=height(root->left);
	int height_of_r_tree=height(root->right);
	
	int ldiameter = diameter(root->left);
	int rdiameter = diameter(root->right);
	
	return max(height_of_r_tree + height_of_l_tree +1 , max(ldiameter,rdiameter));
}

void find_width(node *root,int h,int *w)
{
	if(root==NULL)
		return ;
	if(h==1 && root!=NULL)
		(*w)=(*w)+1;
		
	find_width(root->left,h-1,w);
	find_width(root->right,h-1,w);
	
}

int maximum_width(node *root)
{
	int h = height(root);
	int w=0;
	int ans=-1111;
	for(int i=1;i<=h;i++)
	{
		find_width(root,i,&w);
		//cout<<i<<"  "<<w<<endl;
		if(ans<w)
			ans=w;
		w=0;
	}
	return ans;
}

void printpath(int path[],int length)
{
	
	for(int i=0;i<length;i++)
	{
		cout<<path[i]<<" ";
	}
}

void findpaths(node *root,int path[],int length)
{
	if(root==NULL)
		return ;
		path[length++]=root->data;
	if(root->left==NULL && root->right==NULL)
	{
		cout<<"\nPath of "<<root->data<<" : ";
		printpath(path,length);
	}
	findpaths(root->left,path,length);
	findpaths(root->right,path,length);
}

void paths(node *root)
{
	int path[500];
	findpaths(root,path,0);
}

int count_leaf(node *root,int *count)
{
	if(root==NULL)
		return 0;
	if(root->left==NULL && root->right==NULL)
	{
		(*count)++;
	}
	count_leaf(root->left,count);
	count_leaf(root->right,count);
}

void print_spiral(node *root,int h,bool flag)
{
	if(root==NULL)
		return ;
	if(h==1)
	{
		cout<<root->data<<" ";
		return ;
	}
	if(flag)
	{
		print_spiral(root->left,h-1,flag);
		print_spiral(root->right,h-1,flag);
	}
	else
	{
		print_spiral(root->right,h-1,flag);
		print_spiral(root->left,h-1,flag);
	}
}

void spiral(node *root)
{
	int h = height(root);
	bool flag=false;
	for(int i=1;i<=h;i++)
	{
		print_spiral(root,i,flag);
		cout<<endl;
		flag= !flag;
	}
}

void spiral_through_stack(node *root)
{
	if(root==NULL)
		return;
	stack<node *> s1;
	stack<node *> s2;
	s1.push(root);
	while(!s1.empty() || !s2.empty())
	{
		while(!s1.empty())
		{
			node *temp = s1.top();
			s1.pop();
			cout<<temp->data<<" ";
			if(temp->right)
				s2.push(temp->right);
			if(temp->left)
				s2.push(temp->left);
		}
		cout<<endl;
		while(!s2.empty())
		{
			node *temp = s2.top();
			s2.pop();
			cout<<temp->data<<" ";
			if(temp->left)
				s1.push(temp->left);
			if(temp->right)
				s1.push(temp->right);
		
		}
		cout<<endl;
		
	}
}

bool Children_sum(node *root , bool flag)
{
	if(root==NULL)
	{
		return 1;
	}
	if(flag == false)
		return false;
		if(root->left && root->right)
	if(!(root->data==(root->left->data + root->right->data)) )
	{
		flag = false;
	}
	Children_sum(root->left,flag);
	Children_sum(root->right,flag);
}

void create_tree_children_sum(node *root)
{
	if(root==NULL)
		return ;
		
	create_tree_children_sum(root->left);
	create_tree_children_sum(root->right);
	if((root)->left && (root)->right)
	{
		int sum =(root)->left->data + (root)->right->data;
		(root)->data=sum;
	}
}

bool root_to_leaf_sum(node *root,int sum)
{
	if(root == NULL)
		return (sum == 0);
	else
	{
		//cout<<" "<<root->data<<" "<<sum;
	int subsum = sum - root->data;
	bool ans=0;
	// cout<<" "<<subsum;
	if(subsum == 0 && root->left == NULL && root->right == NULL)
		return true;
	if(root->left)
		ans = ans || root_to_leaf_sum(root->left,subsum);
	if(root->right)
		ans = ans || root_to_leaf_sum(root->right,subsum);
	return ans;
	}
}

int difference(node *root,int k,int *diff,int ans)
{
   
   // cout<<ans<<endl;
    if(root)
    {
        
        
        ans=difference(root->left,k,diff,ans);
        int x=abs(root->data - k);
        cout<<" diff= "<<diff<<" ";
        if(x<*diff)
          {
              *diff=x;
              ans=root->data;
          }
         cout<<root->data<<" "<<x<<" "<<ans<<endl;
        ans=difference(root->right,k,diff,ans);
    }
    
    return ans;
}

int maxDiff(node *root, int k)
{
    //Your code here
    int diff=INT_MAX;
    int ans=-1;
    cout<<endl<<endl;
    ans=difference(root,k,&diff,ans);
    return ans;
}

struct node *newNode(int data)
{
	struct node *temp = new node();
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

int search(int in[],int start,int end,int data)
{
	for(int i=start;i<=end;i++)
	{
		if(in[i]==data)
			return i;
	}
}

struct node *tree_from_in_pre(int in[],int pre[],int instart,int inend)
{
	static int preIndex=0;
	if(instart>inend)
		return NULL;
	
	struct node *root = newNode(pre[preIndex++]);
	if(instart == inend)
	return root;
	
	int inIndex = search(in,instart,inend,root->data);
	
	root->left = tree_from_in_pre(in,pre,instart,inIndex-1);
	root->right= tree_from_in_pre(in,pre,inIndex+1,inend);
	
	return root;	
}

void printpathh(int path[],int index)
{
	cout<<"Path= ";
	for(int i=0;i<index;i++)
		cout<<path[i]<<" ";
	cout<<endl;	
}

void paths(node *root,int path[],int index)
{
	if(root==NULL)
		return;
	path[index++]=root->data;
	if(root->left==NULL && root->right==NULL)
		printpathh(path,index);
	paths(root->left,path,index);
	paths(root->right,path,index);
}

void print_root_to_leaf(node *root)
{
	int path[1000];
	paths(root,path,0);
}

void mirror(node *root)
{
	if(root==NULL)
		return ;
	mirror(root->left);
	mirror(root->right);
	node *temp=root->left;
	root->left=root->right;
	root->right=temp;
}

bool issame(node *a,node *b)
{
	if(a==NULL && b==NULL)
		return true;
	if(a!=NULL && b!=NULL && issame(a->left,b->left) && issame(a->right,b->right))
		return true;
	return false;
}

bool foldable(node *root)
{
	if(root==NULL)
		return true;
	bool res;
	mirror(root->left);
	res = issame(root->left,root->right);
	return res;
}
void printarray(int path[],int index)
{
	cout<<"\n";
	for(int i=0;i<index;i++)
		cout<<path[i]<<" ";
}

void ancesterprinting(node *root,int index ,int path[],int data)
{
	if(root==NULL) 
		return;
	if(root->left || root->right)
		path[index++]=root->data;
	if(root->left ==NULL && root->right==NULL && root->data==data)
		printarray(path,index);
	ancesterprinting(root->left,index,path,data);
	ancesterprinting(root->right,index,path,data);
}

void vertical(node *root , int hd , int arr[],int *min,int *max)
{
	if(root==NULL)
		return ;
		if((hd+10)>*max)
			*max=hd+10;
		if((hd+10)<*min)
		*min=hd+10;
	arr[hd+10]+=root->data;
	vertical(root->right,hd+1,arr,min,max);
	vertical(root->left,hd-1,arr,min,max);
}

void maximum_sum_leaf_to_root(node *root,int *max,int sum)
{
	if(root==NULL)
		return ;
	sum+=root->data;
	if(root->left == NULL && root->right == NULL)
	{
		if(*max < sum)
		{
			*max=sum;
		}
	}
	maximum_sum_leaf_to_root(root->left,max,sum);
	maximum_sum_leaf_to_root(root->right,max,sum);	
}

int maximum(int arr[],int start,int end)
{
	int sum=-9999;
	int index;
	for(int i=start;i<=end;i++)
	{
		if(sum<arr[i])
		{
			sum=arr[i];
			index=i;
		}
	}
	return index;
}

node *Construct_Special_Binary_Tree(int inorder[],int start,int end)
{
	if(start>end)
		return NULL;
	int i = maximum(inorder,start,end);
	node *root = newNode(inorder[i]);
	if(start == end)
		return root;
	root->left = Construct_Special_Binary_Tree(inorder,start,i-1);	
	root->right = Construct_Special_Binary_Tree(inorder,i+1,end);
	
	return root;
}

node *Construct_a_special_tree_from_given_preorder_traversal()
{
	
}
bool check_complete_binary_tree(node *root,bool *flag)
{
	if(root == NULL)
	 return true;
	if(root->right && root->left==NULL)
	{
		return false;
	}
	if(root->left && root->right == NULL)
	{
		*flag=false;
	}
	else if(*flag==false && (root->left || root->right))
	{
		return false;	
	}
	return (check_complete_binary_tree(root->left,flag) && check_complete_binary_tree(root->right,flag));
}

void print_left_part(node *root)
{
	if(root)
	{
		if(root->left)
		{
			cout<<root->data<<" ";
			print_left_part(root->left);
		}
		else if(root->right)
		{
			cout<<root->data<<" ";
			print_left_part(root->right);
		}
	}
}

void print_right_part(node *root)
{
	if(root)
	{
		if(root->left)
		{
			print_left_part(root->left);
			cout<<root->data<<" ";
		}
		else if(root->right)
		{
			print_left_part(root->right);
			cout<<root->data<<" ";
		}
	}
}

void print_leaves(node *root)
{
	if(root)
	{
		print_leaves(root->left);
		if(root->left==NULL && root->right==NULL)
			cout<<root->data<<" ";
		print_leaves(root->right);
	}
}

void print_boundary(node *root)
{
	if(root)
	{
		cout<<root->data<<" ";
		print_left_part(root->left);
		print_leaves(root->left);
		print_leaves(root->right);
		print_right_part(root->right);
	}
}

int main()
{
	int size;
	cin>>size;
	//int inorder[size];
	//for(int i=0;i<size;i++)
	//	cin>>inorder[i];
	//node *root = Construct_Special_Binary_Tree(inorder,0,size-1);
	//inorder_print(root);

	node *root = create();
	print_boundary(root);
	//bool flag=true;
	//cout<<check_complete_binary_tree(root,&flag);	
	//static int path[20]={0};
	//int max=-9999;
	//maximum_sum_leaf_to_root(root,&max,0);
	//cout<<max;
	//int min=100,max=-100;
	//vertical(root,0,path,&min,&max);
	//for(int i=min;i<=max;i++)
	//{
	//	cout<<path[i]<<endl;
	//}
	//ancesterprinting(root,0,path,5);
//	cout<<endl<<foldable(root);
	//cout<<endl<<"Paths from root to leaf\n";
	//print_root_to_leaf(root);
	
	//cout<<maxDiff(root, 4);
	
	
	//cout<<endl<<endl<<"Enter the sum value \t";
	//int sum;	cin>>sum;
	//cout<<endl<<root_to_leaf_sum(root,sum)<<endl;
	
//	cout<<endl;
	//cout<<endl;
	//cout<<"height of tree = "<<height(root)<<endl;
	//levelorder(root);
	//cout<<endl<<"----------------------\nlevel order with queue \n----------------------\n";
	//levelorder_with_queue(root);
	//cout<<endl<<"\n----------------------\nInorder order with stack \n----------------------\n";
//	inorder_with_stack(root);
	
//	cout<<endl<<"\n----------------------\nInorder order without stack and recursion \n----------------------\n";
//	indorder_without_recursion_and_stack(root);
	
//	cout<<endl<<"Diameter of tree is \n";
//	cout<<diameter(root);
	
//	cout<<endl<<"Maximum width ";
//	cout<<maximum_width(root);
	
//	cout<<endl<<"\n----------------------\nPath upto all leaves\n----------------------\n";
//	paths(root);
//	int count =0 ;
//	count_leaf(root,&count);

//	cout<<"\nTotal no. of leaf nodes are = "<<count<<endl;
//	cout<<endl<<"\n----------------------\nSpiral Print Of Tree\n----------------------\n";
//	spiral(root);
//	cout<<endl<<"\n----------------------\nSpiral Print Of Tree\n----------------------\n";
//	spiral_through_stack(root);
	
//	bool flag=true;
//	cout<<Children_sum(root,flag);
	
//	create_tree_children_sum(root);
//	cout<<Children_sum(root,flag);
	
/*	cout<<endl<<"Enter Total no of elements\n";
	int end;
	cin>>end;
	int in[10]; int pre[10];
	for(int i=0;i<end;i++)
	{
		cin>>in[i];
	}

	for(int i=0;i<end;i++)
	{
		cin>>pre[i];
	}	
	node *r=tree_from_in_pre(in,pre,0,end-1);
	indorder_without_recursion_and_stack(r);
*/
}
