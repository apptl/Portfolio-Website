#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* top = NULL;  /* empty list/stack */

void Push(int x)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next=top;
    top=temp;
}

void Print()
{
    struct node*temp=top;
    printf("List is:");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }

    printf("\n");
}

void Pop()
{
    struct node *temp;
    if (top == NULL)
        return;

    temp = top;
    top=top->next;
    free(temp);
}

int main()
{
    int n, i, x;
    printf("How many numbers?\n");

    scanf("%d",&n);
    for (i=0; i<n; i++)
    {
        printf("Enter the number\n");
        scanf("%d",&x);
        Push(x);
        Print();
    }

    Pop();
    printf("After pop:\n ");
    Print();
}

