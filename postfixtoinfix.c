#include <stdio.h>
#include <ctype.h>
#include <string.h>



char stack[20][20];
int top = -1;
int maxsize = 20;

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
        return 1;
    }

    else
    {
        return 0;
    }
}

void push(char item[20])
{
    if (isfull() == 1)
    {
        printf("Oops... Stack is full Now\n\n");
    }
    else
    {
        strcpy(stack[++top], item);
    }
}

void pop(char item[20])
{
    if (isempty() == -1)
    {
        printf("Oops... Stack is Empty\n");
    }
    
    else
    {
        strcpy(item, stack[top]);
        top--;
    }
}

void postfix_infix(char exp[20])
{
    char s1[20];
    char s2[20];
    char s3[20];
    char temp[20];
    char inf[20];

    for (int i = 0; exp[i] != '\0'; i++)
    {
        s1[0] = exp[i];
        s1[1] = '\0';
        if ((isalpha(exp[i])) != 0)
        {
            push(s1);
        }

        else
        {
            pop(s2);
            pop(s3);
            strcpy(inf, "(");
            strcat(inf, s3);
            strcat(inf, s1);
            strcat(inf, s2);
            strcat(inf, ")");
            push(inf);
        }
    }
    pop(inf);

    printf("\nThe Final Expression is %s\n", inf);
}

int main()
{
    char exp[20];
    printf("Enter the Expression\n");
    scanf("%s", exp);

    printf("The string Entered is %s\n", exp);
    postfix_infix(exp);

    return 0;
}