#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_initially(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void traverse(struct node *head)
{
    struct node *temp;
    temp = head;
    printf("The list is: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}

int isEmpty(struct node *head)
{
    if (head == NULL)
        return 1;
    else
        return 0;
}

void insert(struct node **head, int pos, int data)
{
    struct node *temp, *newNode;
    int i;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (pos == 1)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        temp = *head;
        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void delete (struct node **head, int pos)
{
    struct node *temp, *temp1;
    int i;
    if (pos == 1)
    {
        temp = *head;
        *head = temp->next;
        free(temp);
    }
    else
    {
        temp = *head;
        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        temp1 = temp->next;
        temp->next = temp1->next;
        free(temp1);
    }
}

void deleteKey(struct node **head, int key)
{
    struct node *temp, *temp1;
    temp = *head;
    if (temp->data == key)
    {
        *head = temp->next;
        free(temp);
    }
    else
    {
        while (temp->next->data != key)
        {
            temp = temp->next;
        }
        temp1 = temp->next;
        temp->next = temp1->next;
        free(temp1);
    }
}

int count(struct node *head)
{
    struct node *temp;
    int count = 0;
    temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int search(struct node *head, int key)
{
    struct node *temp;
    int pos = 1;
    temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
            return pos;
        pos++;
        temp = temp->next;
    }
    return 1;
}

int main()
{
    insert_initially(18);
    insert_initially(21);
    insert_initially(32);
    insert_initially(47);
    insert_initially(54);
    insert_initially(63);
    int choice, pos, data, key;
    while (1)
    {
        printf(" 1. Traverse the list\n ");
        printf(" 2. Check if the list is empty\n ");
        printf(" 3. insert a node at certian position in the list (position is given by the user)\n ");
        printf(" 4. delete a node at a certain position in the list (position is given by the user)\n ");
        printf(" 5. delete the node for any given key\n ");
        printf(" 6. count the total number of nodes in the list\n ");
        printf(" 7. search for a given element in the list\n ");
        printf(" 8. Exit\n\n ");
        printf(" Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            traverse(head);
            break;
        case 2:
            if (isEmpty(head))
                printf(" List is empty \n");
            else
                printf(" List is not empty \n");
            break;
        case 3:
            printf(" Enter the position: ");
            scanf("%d", &pos);
            printf(" Enter the data: ");
            scanf("%d", &data);
            insert(&head, pos, data);
            break;
        case 4:
            printf(" Enter the position: ");
            scanf("%d", &pos);
            delete (&head, pos);
            break;
        case 5:
            printf(" Enter the key: ");
            scanf("%d", &key);
            deleteKey(&head, key);
            break;
        case 6:
            printf(" Total number of nodes in the list: %d \n", count(head));
            break;
        case 7:
            printf(" Enter the key: ");
            scanf("%d", &key);
            if (search(head, key) == -1)
                printf(" Key not found \n");
            else
                printf(" Key found at position %d \n", search(head, key));
            break;
        case 8:
            exit(0);
        default:
            printf(" Invalid choice \n");
        }
        printf(" ");
    }
    return 0;
}