#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    char name[30];
    struct Node *next;
};

// CREATING A LINK-LIST
void create(struct Node *head)
{
    // TEMPORARY TEMP REFERENCE IS CREATED FOR HEADG
    struct Node *temp = head;
    struct Node *curr;
    char choice;
    // label:
    do
    {
        curr = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter the Name:\n");
        scanf("%s", curr->name);
        printf("Enter the Roll_no:\n");
        scanf("%d", &curr->data);

        curr->next = NULL;
        temp->next = curr;
        temp = curr;

        printf("\n\nEnter y to print more\nEnter s to Save\n");
        scanf(" %c", &choice);

    } while (choice == 'y');

    
}

// DISPLAY
void display(struct Node *head)
{
    struct Node *curr;
    if (head->next == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        curr = head->next;
        printf("\n\nAddress \t Roll_no\t Name\t\t Address_Next\t Role\n");
        while (curr != NULL)
        {
            printf("%p\t %d\t\t %s\t\t %p\t", curr, curr->data, curr->name, curr->next);
            if (curr == head->next)
            {
                printf(" President\n");
            }

            else if (curr == head->next && curr->next == NULL)
            {
                printf(" President + Secretary\n");
            }

            else if (curr->next == NULL)
            {
                printf(" Secretary\n");
            }

            else
            {
                printf(" Member\n");
            }

            curr = curr->next;
        }
    }
}

// LENGTH OF LINK-LIST
int len(struct Node *head)
{
    int i = 0;
    struct Node *curr;
    curr = head->next;
    while (curr != NULL)
    {
        i++;
        curr = curr->next;
    }
    return i;
}

// INSERTION IN LINK-LIST
int insert(struct Node *head)
{
    struct Node *curr = head;
    int i = 1, pos;
    struct Node *new_node;

    printf("Enter the Position:\n");
    scanf("%d", &pos);

    new_node = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the Name:\n");
    scanf(" %s", new_node->name);

    printf("Enter the Roll_no:\n");
    scanf(" %d", &new_node->data);

    int k = len(head);
    if (pos > k + 1)
    {
        printf("Data can't be inserted\n");
        return 0;
    }
    else
    {
        while (curr != NULL && i < pos)
        {
            i++;
            curr = curr->next;
        }
        new_node->next = curr->next;
        curr->next = new_node;
        return 1;
    }
}

int deletion(struct Node *head)
{
    int pos;
    printf("Enter the Position you want to delete\n");
    scanf("%d", &pos);

    struct Node *prev = head;
    int counter = 1;
    struct Node *curr = head->next;
    int read = pos;

    int k = len(head);
    if (k < pos)
    {
        printf("OOPS....\nData can't be Deleted");
        return 0;
    }
    else
    {
        while (counter < pos && curr != NULL)
        {
            counter++;
            prev = curr;
            curr = curr->next;
        }

        struct Node *temp = curr;
        prev->next = curr->next;
        curr->next = NULL;
        free(temp);
    }
}

int Reverse(struct Node *head)
{
    struct Node *prev = NULL;
    struct Node *curr = head->next;
    while (curr != NULL)
    {
        struct Node *future = curr->next;
        curr->next = prev;
        prev = curr;
        curr = future;
    }
    head->next = prev;
    return 1;
}

// SORTING OF LL
int Sort(struct Node *head)
{
    int length = len(head);
    struct Node *temp;
    struct Node *curr;
    struct Node *prev;
    for (int i = 1; i <= length - 1; i++)
    {
        prev = head;
        curr = head->next;

        for (int j = 0; j < length - i; j++)
        {
            temp = curr->next;

            if (curr->data > temp->data)
            {
                prev->next = temp;
                curr->next = temp->next;
                temp->next = curr;
                prev = temp;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
    }
    return 1;
}

int Merge(struct Node *head_1, struct Node *head_2)
{
    int flag;
    struct Node *curr_1 = head_1->next;
    struct Node *curr_2 = head_2->next;
    struct Node *temp;

    if (curr_1->data < curr_2->data)
    {
        temp = head_1;
        int flag = 1;
    }

    else
    {
        temp = head_2;
        int flag = 0;
    }

    while (curr_1 != NULL && curr_2 != NULL)
    {
        if (curr_1->data < curr_2->data)
        {
            temp->next = curr_1;
            temp = curr_1;
            curr_1 = curr_1->next;
        }
        else
        {
            temp->next = curr_2;
            temp = curr_2;
            curr_2 = curr_2->next;
        }
    }
    if (curr_1 == NULL)
    {
        temp->next = curr_2;
    }

    if (curr_2 == NULL)
    {
        temp->next = curr_1;
    }

    if (flag == 1)
    {

        return 1;
    }

    else
    {
        return 2;
    }
}

int Concetenate(struct Node *head_1, struct Node *head_2)
{
    struct Node *temp = head_1->next;
    while (temp->next != NULL)
    {
        // head_1 = temp;
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        temp->next = head_2->next;
        free(head_2);
    }
        return 1;
}
int main()
{
    struct Node *head;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->next = NULL;

    create(head);
    display(head);

    struct Node *head_2;
    head_2 = (struct Node *)malloc(sizeof(struct Node));
    head_2->next = NULL;

    int choice, x, pos;

label:
    printf("\n\nEnter 1 for Insertion\nEnter 2 for Deletion\nEnter 3 for Reverse\nEnter 4 for Sort\nEnter 5 for Merging\nEnter 6 for Concentate\nEnter 0 to Exit\n");
    scanf("%d", &choice);

    int l = len(head);
    printf("\nThere are %d Members & 2 Executives\n", l);

    switch (choice)
    {
    case 0:
        goto end;

    case 1:
        // POSITION IS ALREADY ACCEPTED INSIDE INSERT FUNCTION
        x = insert(head);
        printf("\nYeaa!!... the Element is successfully Inserted");
        break;

    case 2:
        // POSITION IS ALREADY ACCEPTED INSIDE DELETE FUNCTION
        x = deletion(head);
        printf("\nYeaa!!... the Element is successfully Deleted");
        break;

    case 3:
        // POSITION IS ALREDAY ACCEPTED IN REVERSE FUNCTION
        x = Reverse(head);
        printf("\nYeaa!!... the Link-List is successfully Reversed");
        break;

    case 4:
        x = Sort(head);
        printf("\nYeaa!!... the Link-List is successfully Sorted");
        break;

    case 5:
        printf("Enter the second Link-list\n");
        create(head_2);
        // SORTING OF PREVIOUS & CURRENT LL IS NEEDED TO INSERT A NEW LL..
        Sort(head);
        Sort(head_2);
        x = Merge(head, head_2);

        printf("\nYeaa!!... the Link-List is successfully Merged");
        break;
    case 6:
        printf("Enter the second Link-list\n");
        create(head_2);
        // SORTING OF PREVIOUS & CURRENT LL IS NEEDED TO INSERT A NEW LL..
        x = Concetenate(head , head_2);

        printf("\nYeaa!!... the Link-List is successfully Concenated");
        break;

    default:
        break;
    }

    if (x == 1)
    {
        display(head);
        goto label;
    }
    else if (x == 2)
    {
        display(head_2);

        // SO NOW AFTER LABEL WE CAN PERFORM OPERATIONS AGAIN
        head = head_2;

        goto label;
    }

    else if (x == 0)
    {
        printf("Opps....Operation Failed");
        goto label;
    }

end:
    return 0;
}
