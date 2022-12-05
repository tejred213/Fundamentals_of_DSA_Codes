#include <stdio.h>
#include <ctype.h>

char stack[20];
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

int isp(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }

    if (ch == '*' || ch == '/')
    {
        return 2;
    }

    if (ch == '^')
    {
        return 4;
    }

    else
    {
        return 0;
    }
}

int icp(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }

    if (ch == '*' || ch == '/')
    {
        return 2;
    }

    if (ch == '^')
    {
        return 3;
    }

    else
    {
        return 0;
    }
}

void infix_postfix(char exp[20])
{
    int k = 0, i = 0;
    char tkn = exp[i];
    char post_exp[20];

    while (tkn != '\0')
    {
        if (isalpha(tkn) != 0)
        {
            printf("%c\n", tkn);
            post_exp[k] = exp[i];
            k++;
        }

        else
        {
            if (tkn == '(')
            {
                push('(');
            }

            else
            {
                if (tkn == ')')
                {
                    while ((tkn = pop()) != '(')
                    {
                        post_exp[k] = tkn;
                        k++;
                    }
                }

                else
                {
                    while (isempty() == 0 && (isp(stack[top]) >= icp(tkn)))
                    {
                        post_exp[k] = pop();
                        k++;
                    }
                    push(tkn);
                }
            }
        }
        i++;
        tkn = exp[i];
    }
    while (isempty() != 1)

    {
        post_exp[k] = pop();
        k++;
    }
    printf("the Expression is %s\n", post_exp);
}

int main()
{
    char exp[20];
    printf("Enter the Expression\n");
    scanf("%s", exp);

    printf("The string displayed is %s\n", exp);
    infix_postfix(exp);

    return 0;
}