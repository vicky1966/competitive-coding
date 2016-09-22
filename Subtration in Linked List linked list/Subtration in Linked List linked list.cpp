/* 
 * File:   Subtration in Linked List linked list.cpp
 * Author: Vicky
 *
 * Created on September 22, 2016, 11:14 PM
 */

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
void reverseUtil(node *curr, node *prev, node **head);
void printr(struct node *head)
{
    if(head==NULL)
    {
        return;
    }
    printr(head->next);
    cout<<head->data<<" ";
}
void print(struct node *head)
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
struct node *create(struct node *head,int data)
{
    struct node *temp=new node();
    temp->data=data;
    temp->next=NULL;
    struct node *temp1=head;
    if(head==NULL)
    {
        head=temp;
        return head;
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

void reverse(node **head)
{
    if (!head)
        return;
    reverseUtil(*head, NULL, head);
}
 
// A simple and tail recursive function to reverse
// a linked list.  prev is passed as NULL initially.
void reverseUtil(node *curr, node *prev, node **head)
{
    /* If last node mark it head*/
    if (!curr->next)
    {
        *head = curr;
 
        /* Update next to prev node */
        curr->next = prev;
        return;
    }
 
    /* Save curr->next node for recursive call */
    node *next = curr->next;
 
    /* and update next ..*/
    curr->next = prev;
 
    reverseUtil(next, curr, head);
}

struct node* diffe(struct node* head1,struct node *head2,int n,int m,int flag)
{
    struct node *temp1;
    struct node *temp2;
    if(flag==1)
    {
        temp1=head1;
        temp2=head2;
    }
    else if(flag==2)
    {
        temp1=head2;
        temp2=head1;
        
    }
    struct node *result=NULL;
    int carry=0;
        while(temp2!=NULL)
        {
            
                if(temp2->data<=((temp1->data)-carry))
                {
                    result=create(result,(temp1->data)-carry-(temp2->data));
                    carry=0;
                }
                else
                {
                    int x=temp1->data+10-carry;
                    result=create(result,x-(temp2->data));
                    carry=1;
                }
                temp1=temp1->next;
                temp2=temp2->next;
        }
    int x=0;
        while(temp1!=NULL)
        {
               if(temp1->data-carry<0)
               {
                x=temp1->data+10-carry;   
               }
               else
               {
                   x=temp1->data-carry;
                   carry=0;
               }
                   
                 
            result=create(result,x);
            temp1=temp1->next;
        }

    cout<<endl;
    reverse(&result);
    print(result);
    cout<<endl;
}


int main(int argc, char** argv) {
    int t;cin>>t;
    while(t--)
    {
        struct node *head1=NULL;
        struct node *head2=NULL;
        int n;cin>>n;
        for(int i=0;i<n;i++)
        {
            int x;cin>>x;
        head1=create(head1,x);     
        }
       int m;cin>>m;
        for(int i=0;i<m;i++)
        {
            int x;cin>>x;
        head2=create(head2,x);     
        }
       // print(head1);
        //cout<<endl;
        //print(head2);
        //cout<<endl;
        
       int flag=0;
        struct node* temp1=head1;
        struct node* temp2=head2;
        if(n>m)
            flag=1;
        else if(m>n)
            flag=2;
        else if(n==m)
        {
            while(temp1!=NULL)
            {
                if(temp1->data>temp2->data)
                {
                    flag=1;
                    break;
                }
                else if(temp2->data>temp1->data)
                {
                    flag=2;
                    break;
                }
                temp1=temp1->next;
                temp2=temp2->next;
            }
        }
       
       
       reverse(&head2);
        //print(head2);
        reverse(&head1);
        //print(head1);
        
        
                
        diffe(head1,head2,n,m,flag);
    }
    return 0;
}

