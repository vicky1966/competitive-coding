/* 
 * File:   Merge K sorted linked list heap.cpp
 * Author: Vicky
 *
 * Created on September 23, 2016, 11:54 AM
 */

#include <iostream>

using namespace std;
struct node{
    node * next;
    int data;
};

node * create(node *head,int data)
{
    struct node *temp=new node();
    struct node *temp1=head;
    temp->data=data;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        while(temp1->next!=NULL)
        {
            temp1=temp1->next;
        }
        temp1->next=temp;
    }
    return head;
}

void print(struct node *head)
{struct node *p=head;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}


node *merge(node *head[],int n){
    struct node *temp=head[0];
    struct node *p=head[0];
    for(int i=1;i<n;i++)
    {
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=head[i];
    }
    return temp;
}


struct node* SortedMerge(struct node* a, struct node* b);
void FrontBackSplit(struct node* source,struct node** frontRef, struct node** backRef);
 
void MergeSort(struct node** headRef)
{
  struct node* head = *headRef;
  struct node* a;
  struct node* b;
 
  /* Base case -- length 0 or 1 */
  if ((head == NULL) || (head->next == NULL))
  {
    return;
  }
 
  /* Split head into 'a' and 'b' sublists */
  FrontBackSplit(head, &a, &b); 
 
  /* Recursively sort the sublists */
  MergeSort(&a);
  MergeSort(&b);
 
  /* answer = merge the two sorted lists together */
  *headRef = SortedMerge(a, b);
}

void FrontBackSplit(struct node* source,struct node** frontRef, struct node** backRef)
{
  struct node* fast;
  struct node* slow;
  if (source==NULL || source->next==NULL)
  {
    /* length < 2 cases */
    *frontRef = source;
    *backRef = NULL;
  }
  else
  {
    slow = source;
    fast = source->next;
 
    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL)
    {
      fast = fast->next;
      if (fast != NULL)
      {
        slow = slow->next;
        fast = fast->next;
      }
    }
 
    /* 'slow' is before the midpoint in the list, so split it in two
      at that point. */
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
  }
}

struct node* SortedMerge(struct node* a, struct node* b)
{
  struct node* result = NULL;
 
  /* Base cases */
  if (a == NULL)
     return(b);
  else if (b==NULL)
     return(a);
 
  /* Pick either a or b, and recur */
  if (a->data <= b->data)
  {
     result = a;
     result->next = SortedMerge(a->next, b);
  }
  else
  {
     result = b;
     result->next = SortedMerge(a, b->next);
  }
  return(result);
}

int main(int argc, char** argv) {
    int t;cin>>t;
    while(t--){
        int n;cin>>n;int arr[n];
        struct node* head[n]={NULL};
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            for(int j=0;j<arr[i];j++)
            {
                int x;cin>>x;
                head[i]=create(head[i],x);
            }
            print(head[i]);
        }
        struct node *p=merge(head,n);
        MergeSort(&p);
        print(p);
    }
    return 0;
}

