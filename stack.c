#include<stdio.h>
#include<stdlib.h>
#define Size 20

int Top=-1, char_array[Size];
void Push();
void Pop();
void show();

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
case 1: Push();
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

void Push()
{
char ch;

if(Top==Size-1)
{
printf("\nElements Exceeded!!");
}
else
{
printf("\nEnter element to be inserted to the stack:");
scanf("%s",&ch);
Top=Top+1;
char_array[Top]=ch;
}
}

void Pop()
{

if(Top==-1)
{
printf("\nNo Elements!!");
}
else
{
printf("\nPopped element:  %c",char_array[Top]);
Top=Top-1;
}
}

void show()
{

if(Top==-1)
{
printf("\nNo Elements!!");
}
else
{
printf("\nElements present in the stack: \n");
for(int i=Top;i>=0;i--)
printf("%c\n",char_array[i]);
}
}