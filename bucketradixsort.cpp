#include <stdio.h>
#define as 10

void accept(int s[as],int n)
{
int i;
for(int i=0;i<n;i++)
{
printf("enter roll no.:");
scanf("%d",&s[i]);
}
}

void display(int s[as],int n)
{
int roll;
printf("\n Database is as follows: \t");
for(int i=0;i<n;i++)
{
printf("%d\t",s[i]);
}
}

void BucketSort(int s[as],int n) // O(n+k) time complexity
{
int i,j;
int bucket[100];
//buckets can store maximum number 100
for(i=0;i<100;i++)
bucket[i]=0;
for(j=0;j<n;j++)
{
++bucket[s[j]];
//counting number for each bracket
}
for(i=0,j=0;i<100;i++)
{

for(;bucket[i]>0; --bucket[i])
{
s[j]=i;
j++;
}
}
}

void Radix_sort(int s[as], int n)// O(nd) time complexity

{
int large,pass,div,bktno,i,j,k,count[10],bkt[20][20];
large=s[0];
for(i=0;i<n;i++)
{
if(s[i]>large)
{
large=s[i];
}
}
pass=0;
while(large>0)
{
pass++;
large=large/10;
}
div=1;
for(i=1;i<=pass;i++)
{
for(j=0;j<=9;j++)
{
count[j]=0;
}
for(j=0;j<n;j++)
{
bktno=(s[j]/div)%10;
bkt[bktno][count[bktno]]=s[j];
count[bktno]++;
}
j=0;
for(bktno=0;bktno<=9;bktno++)
{
for(k=0;k<count[bktno];k++)
{
s[j]=bkt[bktno][k];
j++;
}
}
div=div*10;
}
}
int main()
{
int i;
int s[as],n,ch,ans;
printf("enter the number of students : \t");
scanf("%d",&n);
accept(s,n);
display(s,n);
do
{
printf("\nMenu for operations \t1 Bucket Sort\t2 Radix Sort" );
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch)
{

   case 1:
   BucketSort(s,n);
   display(s,n);
   break;

   case 2:
   Radix_sort(s,n);
   display(s,n);
   break;
}
printf("\nDo you want to continue. Type 1 to continue:");
scanf("%d",&ans);
}
while(ans==1);
}