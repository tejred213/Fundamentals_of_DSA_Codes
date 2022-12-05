
#WORKING CODE#
# Also dont use same roll no.s, in searching they might repeat and ruin the output

#include<stdio.h>

struct student
{
int rno;
char name[30];
int marks;
};

void accept(struct student s[10],int n)
{
for(int i=0;i<n;i++)
{
printf("\nEnter roll no:");
scanf("%d",&s[i].rno);
printf("\nEnter student name:");
scanf("%s",s[i].name);
printf("\nEnter marks out of 100:");
scanf("%d",&s[i].marks);
}
}

void display(struct student s[10],int n)
{
printf("\nStudent data is as follows:");
for(int i=0;i<n;i++)
{
printf("\n%d\t%s\t\t%d",s[i].rno,s[i].name,s[i].marks);
}
}

void linsearch(struct student s[10],int n,int rollno)
{
for(int i=0;i<n;i++)
{
if(s[i].rno==rollno)
{
printf("The details of student with roll number %d are:\n%d\t%s\t\t%d",rollno,s[i].rno,s[i].name,s[i].marks);
}
}
}

void binsearch(struct student s[10],int low,int high,int m,int rollno)
{
while(low<=high)
{
    m=(low+high)/2;
    if(s[m].rno==rollno)
    {
    printf("\nThe details of student with roll number %d are:\n%d\t%s\t\t%d",rollno,s[m].rno,s[m].name,s[m].marks);
    high=low-1;
    }
    else if(s[m].rno<rollno)
       {
           low=m+1;
       }
    else//(s[m].rno>rollno)
       high=m-1;
}
}

int main()
{
int n,rollno,low,high,m,ch,ans;
struct student s[10];
printf("\nEnter the number of students:");
scanf("%d",&n);
accept(s,n);
display(s,n);
do
{
printf("\nEnter the student roll no you want to search:");
scanf("%d",&rollno);
printf("\nMenu for operations \t1 Linear Search \t2 Binary Search");
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch)
{
    case 1:
    linsearch(s,n,rollno);
    break;
   
    case 2:
    high=n-1;
    low=0;
    m=(high+low)/2;
    binsearch(s,low,high,m,rollno);
    break;
}
printf("\nDo you want to continue. Type 1 to continue:");
scanf("%d",&ans);
}
while(ans==1);
}
