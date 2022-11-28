#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define Size 20

int top=-1, char_array[Size];
char s[30][30];
int k=0,i=0;
void push();
void pop();
void show();
void in_post();
void Push();
char *Pop();

int main()
{
int choice;

while(1)
{
printf("\nOperations performed by Stack");
printf("\n1.Push the element\n2.Pop the element\n3.Show\n4.End");
printf("\n\nEnter the choice:");
scanf("%d",&choice);

switch(choice)
{
case 1: push();
break;
case 2: Pop();
break;
case 3: show();
break;
case 4: exit(0);

default: printf("\nInvalid choice!!");
}
}
}

void push()
{
char ch;

if(top==Size-1)
{
printf("\nElements Exceeded!!");
}
else
{
printf("\nEnter element to be inserted to the stack:");
scanf("%s",&ch);
top=top+1;
char_array[top]=ch;
}
}

void pop()
{

if(top==-1)
{
printf("\nNo Elements!!");
}
else
{
printf("\nPopped element:  %c",char_array[top]);
top=top-1;
}
}

int icp(char ch)
{
    if(ch=='+'||ch=='-')
    return 1;
    if(ch=='*'||ch=='/')
    return 2;
    if(ch=='^')
    return 4;
    if(ch=='(')
    return 5;
    else
    return 0;
}

int isp(char ch)
{
    if(ch=='+'||ch=='-')
    return 1;
    if(ch=='*'||ch=='/')
    return 2;
    if(ch=='^')
    return 3;
    else
    return 0;
}

void in_post(char inexp[20])
{
    char_array;
    char postexp[Size];
    char tkn;
    //postexp[] has the postfix expression
    tkn=inexp[1];
    while(tkn!='\0')
    {
        if(isalpha(tkn)!=0)
        {
            postexp[k]=inexp[i];
            k++;
        }
        else:
        {
            if (tkn=='(') //open paranthesis
            {
                push('(');
            }
            else:
            {
                if (tkn==')') //open paranthesis
                {
                    while((tkn=pop())!='(')
                    {
                        postexp[k]=tkn;
                        k++;
                    }
                }
                else:
                {
                    while(top!=-1 && isp(char_array[top])>=icp(tkn))
                    {
                        postexp[k]=pop();
                        k++;
                    }
                    push(tkn);
                }
            }
        }
        //read next token
        i++;
        tkn=inexp[k];
    }
    {
        postexp[k]=pop();
        k++;
    }
    printf("Postfix expr = %s\n",postexp);
}

void Push(char s[Size])
{
    int str;
    str=isfull();
    if(str==1)
    printf("\nStack is full!");
    else
    strcpy(s[top++],s);
}

char *Pop()
{
    char *str;
    str=isempty();
    if(str==1)
    printf("\nStack is empty!");
    else
    {
        str=s[top--];
        return str;
    }
}

void post_infix(char_array[Size])
{
    char temp[size];
    for(int i=0;char_array[i]!='\0';i++)
    {
        {
            if(isalpha(char_array[i])!=0)
            {
                temp[0]=char_array[i];
                temp[1]="\0";
                Push(temp);
            }
            else
            {
                temp=Pop();
                temp1=Pop();
                temp2[0]=char_array[i];
                temp2[1]='\0';
                strcpy(inf,"(");
                strcat(inf,temp1);
                strcat(inf,temp2);
                strcat(inf,temp);
                strcat(inf,")");
                Push(inf);
            }
        }
        inf=Pop();
        printf("\n The infix expression is:");
        printf("\n%s",inf);
    }
}
void show()
{
if(top==-1)
{
printf("\nNo Elements!!");
}
else
{
printf("\nElements present in the stack: \n");
for(int i=top;i>=0;i--)
printf("%c\n",char_array[i]);
}
}