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
void detect_loop(node *s)
{
    int found=0;
    node *f=s;
    while(f && s && s->next)
    {
        f=f->next->next;
        s=s->next;
        if(f==s)
        {
            found=1;
            break;
        }
    }
    if(found==1)
        printf("Found loop\n");
    else
        printf("No loop detected\n");
}
void loop_length(node *h)
{
    int found=0,x=0;
    node *f=h,*s=h;
    while(f && s && s->next)
    {
        f=f->next->next;
        s=s->next;
        if(f==s)
        {
            x=1;
            break;
        }
    }
    if(x==1)
    {
        node *temp=s;
        while(temp->next!=s)
        {
            found++;
            temp=temp->next;
        }
    }
    if(found==0)
        printf("0");
    else
        printf("%d",found+1);
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
    first->next->next->next=first;
    printf("Loop detect: ");
    detect_loop(first);
    printf("Loop length : ");
    loop_length(first);
    full_delete(first);
    free(first);
}
