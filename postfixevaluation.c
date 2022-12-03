#include <stdio.h>
#include <ctype.h>
#include <math.h>

int stack[20];
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

int pop()
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

// CALCULATE FUNCTION
int calc(int a, int b, char op)
{
    int ans;
    switch (op)
    {
    case '+':
        ans = a + b;
        break;

    case '-':
        ans = a - b;
        break;

    case '*':
        ans = a * b;
        break;

    case '/':
        ans = a / b;
        break;

    case '^':
        ans = pow(a ,b);
        break;

    default:
        break;
    }
    return ans;
}

// POSTFIX EVALUATOR
void postfix_eval(char post[20])
{
    int z;
    for (int i = 0; post[i] != 0; i++)
    {
        if ((isalpha(post[i])) != 0)
        {
            printf("Enter the value of %c\n", post[i]);
            scanf("%d", &z);
            push(z);
            // printf("%d\n", z);
            // printf("%d\n", );

        }
        else
        {
            int op1 = pop();
            int op2 = pop();
            int ans = calc(op2, op1, post[i]);
            push(ans);
        }
    }
    printf("The Evaluation Result = %d\n", stack[top]);
}

int main()
{
    char exp[20];
    printf("Enter the Expression\n");
    scanf("%s", exp);

    printf("The string Entered is %s\n", exp);
    postfix_eval(exp);

    return 0;
}