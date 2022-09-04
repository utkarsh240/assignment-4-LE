#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head, *temp, *newnode;
    int n, i, m;
    head = NULL;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    printf("Enter the value of m: ");
    scanf("%d", &m);
    printf("The linked list is: ");
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    struct node *p, *q;
    p = q = head;
    for (i = 0; i < m; i++)
    {
        q = q->next;
    }
    while (q != NULL)
    {
        p = p->next;
        q = q->next;
    }
    printf("\nThe %dth node from the end of the linked list is: %d", m, p->data);
    return 0;
}