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


void insertion_sort(struct student s[10],int n)
{
struct student key;
for(int i=1;i<n;i++)//n-1
{
key=s[i];
int j= i-1;
while(j>=0 && s[j].rno>key.rno)//
{
    s[j+1]=s[j];
    j=j-1;
}
s[j+1]=key;
}
}

void selection_sort(struct student s[10],int n)//3n^2-3n-n+1
{
struct student temp;
int minpos;
for(int i=0;i<=n-2;i++)//n-1
{
minpos=i;
for(int j=i+1;j<=n-1;j++)//n
{
if (s[j].rno<s[minpos].rno)//n
minpos=j;
}
if (i!=minpos)//n-1
{
temp=s[i];
s[i]=s[minpos];
s[minpos]=temp;
}
}
}

void shell_sort(struct student s[10],int n)
{
int gap,swapped;
struct student temp;
gap=n/2;
do
{
do
{
   swapped=0;
for(int i=0;i<n-gap;i++)
{
if(s[i].rno>s[i+gap].rno)
{
   temp=s[i];
s[i]=s[i+gap];
s[i+gap]=temp;
swapped=1;

}
}

}
while(swapped==1);
}
while((gap=gap/2)>=1);

}

void bucket_sort(struct student s[10],int n)
{
int i,j;
int bucket[20];
for(i=0;i<20;i++)
bucket[i]=0;
for(j=0;j<n;j++)
{
++bucket[s[j].rno];
}
for(i=0,j=0;i<20;i++)
{
for(;bucket[i]>0;--bucket[i])
{
s[j].rno=i;
j++;
}
}
}



int main()
{
int n,ch,ans;
struct student s[10];
printf("\nEnter the number of students:");
scanf("%d",&n);
accept(s,n);
display(s,n);
do
{
printf("\nMenu for operations \t1 Insertion Sort\t2 Selection Sort\t3 Shell Sort\t4 Bucket Sort" );
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch)
{

    case 1:
    insertion_sort(s,n);
    display(s,n);
    break;

    case 2:
    selection_sort(s,n);
    display(s,n);
    break;

    case 3:
    shell_sort(s,n);
    display(s,n);
    break;

    case 4:
    bucket_sort(s,n);
    display(s,n);
    break;

}
printf("\nDo you want to continue. Type 1 to continue:");
scanf("%d",&ans);
}
while(ans==1);
}