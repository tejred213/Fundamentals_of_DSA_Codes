#include <stdio.h>

void accept (int a[10][10], int row, int col)
{
int i,j;
printf("Enter the values of matrix");
for(i=0;i<row;i++)
{
for(j=0;j<col;j++)
{
scanf("%d\t",&a[i][j]);
}
}
}


void display (int a[10][10], int row, int col)
{
int i,j;

for(i=0;i<row;i++)
{
for(j=0;j<col;j++)
{
printf("%d\t",&a[i][j]);
}
printf("\n");
}
}

void add(int a[10][10], int b[10][10], int c[10][10], int row, int col)
{
int i,j;
printf("The addition of matrix is");
for(i=0;i<row;i++)
{
for(j=0;j<col;j++)
{
c[i][j]=a[i][j]+b[i][j];
}
}
}
void display_sum(int c[10][10], int row, int col)
{
int i,j;

for(i=0;i<row;i++)
{
for(j=0;j<col;j++)
{
printf("%d \t",&c[i][j]);
}
printf("\n")
}
}

int main()
{
int a[10][10], b[10][10], c[10][10];
int row,col;
printf("Enter row and column:\n");
scanf("%d%d",&row,&col);
accept(a,row,col);
display(a,row,col);
accept(b,row,col);
display(b,row,col);
}
