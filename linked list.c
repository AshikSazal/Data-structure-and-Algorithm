#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void insert(node *s,int data)
{
    while(s->next!=NULL)
    {
        s=s->next;
    }
    s->next=(node*)malloc(sizeof(node));
    s->next->data=data;
    s->next->next=NULL;
}
void display(node *s)
{
    while(s->next!=NULL)
    {
        printf("%d\n",s->next->data);
        s=s->next;
    }
}
int search(node *s,int search_data)
{
    int count=0;
    while(s->next!=NULL)
    {
        if(s->next->data==search_data)
            return count;
        s=s->next;
        count++;
    }
}
void full_delete(node *s)
{
    node *temp=s,*temp2;
    while(temp->next!=NULL)
    {
        temp2=temp->next;
        temp->next=temp->next->next;
        free(temp2);
    }
}
void delete_node(node *s,int delete_data)
{
    node *temp;
    while(s->next!=NULL)
    {
        if(s->next->data==delete_data && s->next->next==NULL)
        {
           temp=s->next;
           free(temp);
           s->next=NULL;
           break;
        }
        else if(s->next->data==delete_data && s->next->next!=NULL)
        {
            temp=s->next;
            s->next=s->next->next;
            free(temp);
        }
        s=s->next;
    }
}
int main()
{
    node *first=(node*)malloc(sizeof(node));
    first->next=NULL;
    insert(first,1);
    insert(first,2);
    insert(first,3);
    insert(first,4);
    insert(first,5);
    insert(first,6);
    insert(first,7);
    insert(first,8);
    display(first);
    delete_node(first,4);
    printf("After delete\n");
    display(first);
    full_delete(first);
    free(first);
}
