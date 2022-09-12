#include<stdio.h>

void accept(int a[10][10], int b[10][10], int row, int col)
{
for(int i=0;i<row;i++)
{
for(int j=0;j<col;j++)
{
printf("Enter the elements of the matrix");
scanf("%d",&a[i][j]);
}
}
}

void display (int a[10][10], int row, int col)
{
for(int i=0;i<row;i++)
{
for(int j=0;j<col;j++)
{
printf("%d\t",a[i][j]);
}
printf("\n");
}
}



void compact ( int a[10][10] ,int b[10][10], int row, int col)
{
int k=1;
b[0][0]=row,b[0][1]=col;
for(int i=0;i<row;i++)
{
for(int j=0;j<col;j++)
{
if(a[i][j!=0])
{
b[k][0]=i;
b[k][1]=j;
b[k][2]=a[i][j];
k++;
b[0][2]=k-1;
}
}
}

printf("The compact matrix is :\n");
for(int i=0;i<k;i++)
{
for(int j=0;j<3;j++)
{
printf("%d\t",b[i][j]);
}
printf("\n");
}
}

void transpose (int b[10][10], int c[10][10], int row, int col)
{
int k=1;
c[0][0]=b[0][1];
c[0][1]=b[0][0];
c[0][2]=b[0][2];
int n=b[0][1];
int m=b[0][0];
int t=b[0][2];

for(int i=0;i<n;i++)
{
for(int j=1;j<=t;j++)
{
if(b[i][1]==t)
{
col=b[i][1];
c[k][0]=b[j][1];
c[k][1]=b[1][0];
c[k][2]=b[j][0];
k++;
printf("%d\t", b[i][j]);
}

}
}
printf("\n The transpose matrix is");
for(int i=0;i<n;i++)
{
for(int j=0;j<t;j++)
{
printf("%d\t",c[i][j]);
}
printf("\n");
}

void transpose_dis ( int b[10][10],int c[10][10], int row, int col)
{
int k=1,m,n;
printf("\n The transpose of matrix is : \n");
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
printf("%d\t",c[i][j]);
}
printf("\n");
}
}

int main()
{
int a[10][10],b[10][10],c[10][10];
int row,col;
printf("Enter the no of rows :");
scanf("%d",&row);
printf("Enter the no of column :");
scanf("%d",&col);
accept(a,b,row,col);
display(a,row,col);
compact(a,b,row,col);
transpose(a,b,row,col);
}

