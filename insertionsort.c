#include<stdio.h>

struct student
{
int roll ;
char name[50];
int marks;
}
student[10];


void accept(struct student student[10],int n)
{
for(int i=0 ;i<n ;i++)
{
printf("please enter the student roll no :");
scanf("%d",&student[i].roll);
printf("please enter the student name :");
scanf("%s",&student[i].name);
printf("please enter the student marks:");
scanf("%d",&student[i].marks);
}
}

void display(struct student student[10],int n)
{for(int i=0;i<n;i++)
{

printf("%d\t%s\t%d\n",student[i].roll,student[i].name,student[i].marks);
}
}

void insert(struct student student[10],int n)
{
for(int i=1;i<n;i++)
{
int b=student[i].roll;
int j=i-1;
for( j=i-1 ;j>=0; j--)
{
if(student[j].roll>b)
{
student[j+1].roll=student[j].roll;
}
else
{
break;
}

}
student[j+1].roll=b;
}

}



int main()
{
int n,no;
printf("enter the no of students :");
scanf("%d",&n);
accept(student,n);
display(student,n);
printf("the sorted entries are :\n");
insert(student,n);
for(int i=0;i<n;i++)
{
printf("%d\t%s\t%d\n",student[i].roll,student[i].name,student[i].marks);
}



}
