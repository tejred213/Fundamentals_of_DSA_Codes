#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;                        //Data of the node
    struct node *nextptr,*value;    //Address of the next node
}*stnode;

void createNodeList(int n);  // function to create the list  //warning
void insertNodeList(int n);  // function to insert elements in list
void deleteNodeList(int n);  // function to delete elements in list
void displayList();         // function to display the list

int main()
{
    int option=0;
printf("\n\n Linked List : To create and display Singly Linked List :\n");
printf("-------------------------------------------------------------\n");

while (option <5)
{
	printf("\nOptions\n");
    printf("1 : Insert into Linked List \n");
    printf("2 : Delete from Linked List \n");
    printf("3 : Display Linked List\n");
    printf("Others : Exit()\n");
    printf("Enter your option:");
    scanf("%d", &option);
    switch (option)
    {
      case 1:
        insertNodeList();   //error
        break;
      case 2:
        deleteNodeList();   //error
        break;
      case 3:
        displayList();
        break;
      default:
    	break;
    }
    return 0;
}
void createNodeList(int n)
{
    struct node *fnNode, *tmp;
    int num, i;
    stnode = (struct node *)malloc(sizeof(struct node));

    if(stnode == NULL) //check whether the fnNode is NULL and if so no memory allocation
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
// reads data for the node through keyboard

        printf(" Input data for node 1 : ");
        scanf("%d", &num);
        stnode->num = num;
        stnode->nextptr = NULL; // links the address field to NULL
        tmp = stnode;
// Creating n nodes and adding to linked list
        for(i=2; i<=n; i++)
        {
            fnNode = (struct node *)malloc(sizeof(struct node));
            if(fnNode == NULL)
            {
                printf(" Memory can not be allocated.");
                break;
            }
            else
            {
                printf(" Input data for node %d : ", i);
                scanf(" %d", &num);

                fnNode->num = num;      // links the num field of fnNode with num
                fnNode->nextptr = NULL; // links the address field of fnNode with NULL

                tmp->nextptr = fnNode; // links previous node i.e. tmp to the fnNode
                tmp = tmp->nextptr;
            }
        }
    }
}

void insertNodeList(int n)
{
	int data;
	struct node *tmp, *firstnode,*headnode;
	printf("\n Enter the element for insertion of list : \n");
	scanf("%d",&data);
	stnode = (struct node *)malloc(sizeof(struct node));
	tmp->value=data;
	if (firstnode ==0)
	{
		firstnode=tmp;
	}
	else
	{
		headnode->nextptr=tmp;
	}
	tmp->nextptr =0;
	headnode=tmp;
	fflush(stdin);
}
void deleteNodeList(int n)
{
	int num,i,pos;
	struct node *tmp, *fnNode , *prevnode;    //warning
	printf("\n Enter position for delete element :\n");
	scanf("%d",&pos);
	if (pos>0 && pos <=num)
	{
		if(pos ==1)
		{
			tmp = tmp->nextptr;
			fnNode=tmp;
			printf("Deleted Successfully");
		}
		else
		{
			while(tmp!= NULL)
			{
				if(i==(pos-1))
				{
					prevnode->nextptr = tmp->nextptr;
					if(i==(num-1))
					{
						fnNode=prevnode;
					}
					printf("\n Deleted Successfully \n \n");
					break;
				}
				else
				{
					i++;
					prevnode=tmp;
					tmp=tmp->nextptr;
				}
			}
		}
	}
	else
	{
		printf("Invalid Position");
	}
}
void displayList()
{
    struct node *tmp;
    if(stnode == NULL)
    {
        printf(" List is empty.");
    }
    else
    {
        tmp = stnode;
        while(tmp != NULL)
        {
            printf(" Data = %d\n", tmp->num);		// prints the data of current node
            tmp++;
            tmp = tmp->nextptr;                     // advances the position of current node
        }
    }
}
}
