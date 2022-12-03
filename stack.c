#include <stdio.h>

char stack[50];
int top = -1;
int maxsize = 50;

int isfull()
{
    if (top == maxsize - 1)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

int isempty()
{
    if (top == -1)
    {
        return -1;
    }

    else
    {
        return 0;
    }
}

void push(char item)
{
    if (isfull() == 0)
    {
        top = top + 1;
        stack[top] = item;
    }
    else
    {
        printf("Oops... Stack is full Now\n\n");
    }
}

char pop()
{
    if (isempty() == -1)
    {
        printf("Oops... Stack is Empty\n");
    }
    else
    {
        int temp = top;
        top = top - 1;
        return (stack[temp]);
    }
}

int main()
{
    char item, c;
    int n, choice;

label:
    printf("Enter 1 for Push\nEnter 2 for Pop\n");
    scanf("%d", &choice);

    switch (choice)
    {
        
    case 1:
        printf("Enter the no. of Element you want to push\n");
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            printf("Enter the Element you want to push\n\n");
            scanf(" %c", &item);
            push(item);
        }
        break;

    case 2:
        c = pop();
        printf("The popped character id %c\n\n", c);
        break;

    }

    goto label;
    return 0;
}