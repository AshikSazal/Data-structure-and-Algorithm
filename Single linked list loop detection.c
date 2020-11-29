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
        printf("found loop");
    else
        printf("not found");
}
int main()
{
    node *first=(node*)malloc(sizeof(node));
    first->next=NULL;
    insert(first,1);
    insert(first,2);
    insert(first,3);
    first->next->next->next=first;
    detect_loop(first);
    full_delete(first);
    free(first);
}
