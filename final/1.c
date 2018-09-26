#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;

struct record
{
    char first[21];
    char last[21];
    float score;
    char zip[6];
    struct record *next;
};

struct record *head;
struct record *tail;

void insert(char a[],char b[],float sco,char z[])
{
    struct record *temp = (struct record*)malloc(sizeof(struct record));

    strcpy(temp->first,a);
    strcpy(temp->last,b);
    temp->score = sco;
    strcpy(temp->zip,z);
    temp->next = NULL;

    if (head == NULL)
    {
        head=temp;
        tail=temp;
        return;
    }
    tail->next=temp;
    tail=temp;
}
void addrec()
{
    struct record *temp = (struct record*)malloc(sizeof(struct record));

    printf("\n");
    printf("Enter first name: ");
    scanf("%s",temp->first);
    printf("Enter last name: ");
    scanf("%s",temp->last);
    printf("Enter score: ");
    scanf("%f",&temp->score);
    printf("Enter zip code: ");
    scanf("%s",temp->zip);

    if(head==NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
    n++;
}

void Print()
{
    struct record *temp = (struct record*)malloc(sizeof(struct record));

    temp = head;
    while(temp!=NULL)
    {
        printf("\nFirst name: %s, Last name: %s, score: %.1f, Zip code: %s",temp->first,temp->last,temp->score,temp->zip);

        temp=temp->next;
    }
}

void deletee()
{
    char lastc[20];

    printf("Enter the last name: ");
    scanf("%s",lastc);
    if(head->next == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    struct record *current = head;
    struct record *prev = NULL;

    while(current != NULL)
    {
        if(strcmp(current->last, lastc) == 0)
        {
            if(prev == NULL)
            {
                head = head->next;
                free(current);

                current = head;
                prev = NULL;
            }
            else
            {
                prev->next = current->next;

                free(current);

                current = prev->next;
            }
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
}


void searchzip()
{
    char cmp[6];

    printf("\nEnter the zip code: ");
    scanf("%s",cmp);
    struct record *temp = (struct record*)malloc(sizeof(struct record));
    temp = head;

    printf("\n");
    while(temp!=NULL)
    {
        if(strcmp(cmp,temp->zip)==0)
        {
            printf("First name: %s, Last name: %s, score: %0.1f, Zip code: %s.\n",temp->first,temp->last,temp->score,temp->zip);
        }
        temp = temp->next;
    }
}

void searchmm()
{
    int min,max;

    printf("\nEnter min and max(in this format: min-max): ");
    scanf("%d %d",&min,&max);

    struct record *temp = (struct record*)malloc(sizeof(struct record));

    temp = head;
    printf("\n");
    while(temp!=NULL)
    {
        if(temp->score >= min && temp->score <= max)
        {
            printf("First name: %s, Last name: %s, score: %0.1f, Zip code: %s.\n",temp->first,temp->last,temp->score,temp->zip);
        }
        temp = temp->next;
    }
}

void median()
{
    struct record *temp = (struct record*)malloc(sizeof(struct record));
    temp = head;

    int i,j,index=0,medcount=0,half=(n/2);
    float median;
    float array[n];
    float tempo;

    while(temp!=NULL)
    {
        array[index] = temp->score;
        index++;
        temp = temp->next;
    }

    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(array[i]>array[j])
            {
                tempo = array[i];
                array[i]=array[j];
                array[j]=tempo;
            }
        }
    }
    if( n%2 == 0)
    {
        median = ((array[half]+array[half-1])/2);
        printf("\nMedian is: %0.1f",median);
    }
    else
    {
        median = array[half];
        printf("\nMedian is: %0.1f",median);
    }

    for(i=0; i<n; i++)
    {
        if(array[i] > median)
        {
            medcount++;
        }
    }
    printf("\n%d students are above median\n",medcount);
}

int main()
{
    int i,choice;
    char firstn[20],lastn[20],zipn[20];
    float scoren;

    head = NULL;

    printf("Enter the number of records you want to enter(at least 5): ");
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        printf("\n");
        printf("Enter first name for person %d: ",i+1);
        scanf("%s",firstn);
        printf("Enter last name for %s: ",firstn);
        scanf("%s",lastn);
        printf("Enter score for %s: ",firstn);
        scanf("%f",&scoren);
        printf("Enter zip code for %s: ",firstn);
        scanf("%s",zipn);
        insert(firstn,lastn,scoren,zipn);
    }
    do
    {
        printf("\n\t\tMENU\t\t\n");
        printf("Print records(press 1)\n");
        printf("Add new record(press 2)\n");
        printf("Delete record(press 3)\n");
        printf("Search by zip(press 4)\n");
        printf("Search by score range(press 5)\n");
        printf("Find median score(press 6)\n");
        printf("Exit program(press 0)\n");

        printf("Please select a function: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            Print();
            break;
        case 2:
            addrec();
            break;
        case 3:
            deletee();
            break;
        case 4:
            searchzip();
            break;
        case 5:
            searchmm();
            break;
        case 6:
            median();
            break;
        case 0:
            printf("Goodbye!");
            return 0;
        }

    }
    while(choice!=0);
}

