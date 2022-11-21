#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;                        //Data of the node
    struct node *nextptr,*value,*data;    //Address of the next node
}*head;

void insertList(int n);  // function to insert elements in list
void deleteList(int n);  // function to delete elements in list
void displayList();         // function to display the list
void lenlist();
void sortlist();
void reverseList();

int main()
{
	int option=0;
printf("\n\n Linked List : To create and display Singly Linked List :\n");
printf("-------------------------------------------------------------\n");
head = (struct node *)malloc(sizeof(struct node));
while (option <7)
{
	printf("\nOptions\n");
    printf("1 : Insert into Linked List \n");
    printf("2 : Delete from Linked List \n");
    printf("3 : Display Linked List\n");
    printf("4 : Display Reversed List\n");
    printf("5 : Display Sorted List\n");
    printf("Others : Exit()\n");
    printf("Enter your option:");
    scanf("%d", &option);
    switch (option)
    {
      case 1:
        insertNodeList();
        break;
      case 2:
        deleteNodeList();
        break;
      case 3:
        reverseList();
        break;
      case 4:
    	lenlist();
    	break;
      case 5:
    	sortlist();
    	break;
      case 6:
    	displayList();
    	break;
      default:
    	break;
    }
    return 0;
}
void createList(struct node *H)
{
    struct node *fnNode, *tmp;
    int num, i,n;
    head = (struct node *)malloc(sizeof(struct node));

    if(head == NULL) //check whether the fnNode is NULL and if so no memory allocation
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
// reads data for the node through keyboard

        printf(" Input data for node 1 : ");
        scanf("%d", &num);
        head->num = num;
        head->nextptr = NULL; // links the address field to NULL
        tmp = head;
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

void insertNodeList(struct node *H)
{
	int data;
	struct node *tmp, *firstnode,*head;
	printf("\n Enter the element for insertion of list : \n");
	scanf("%d",&data);
	head = (struct node *)malloc(sizeof(struct node));
	tmp->value=data;
	if (firstnode ==0)
	{
		firstnode=tmp;
	}
	else
	{
		head->nextptr=tmp;
	}
	tmp->nextptr =0;
	head=tmp;
	fflush(stdin);
}
void deleteNodeList(struct node *H)
{
	int num,i,pos;
	struct node *tmp, *fnNode , *prevnode;
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

void reverseList(struct node *H)
{
	struct node *prevnode,*curr,*future;
	prevnode=NULL;
	curr=H->nextptr;
	while(curr!=NULL)
	{
		future=curr->nextptr;
		curr->nextptr=prevnode;
		prevnode=curr;
		curr=future;
	}
	head->nextptr=prevnode;
}

int lenlist(struct node *H)
{
	int i;
	struct node *curr;
	curr=H->nextptr;
	while(curr!=NULL)
	{
		i++;
		curr=curr->nextptr;
	}
	return(i);
}
void sortList(struct node *H)
{
	int i,j;
	struct node *prevnode,*curr,*tmp;
	int lenlist=len(H);
	for (i=1;i<len;i++)
			{
				prevnode=H;
				curr=H->nextptr;
				for (j=0;j<len-i;j++)
					{
						tmp=curr->nextptr;
					}
				if(curr->data>tmp->data)
				{
					prevnode->nextptr=tmp;
					curr->nextptr=tmp->nextptr;
					tmp->nextptr=curr;
					prevnode=tmp;
				}
				else
				{
					prevnode=curr;
					curr=curr->nextptr;
				}
			}
}

void mergeList(struct node *H)
{

}
void displayList(struct node *H)
{
    struct node *tmp;
    if(head == NULL)
    {
        printf(" List is empty.");
    }
    else
    {
        tmp = head;
        while(tmp != NULL)
        {
            printf(" Data = %d\n", tmp->num);		// prints the data of current node
            tmp++;
            tmp = tmp->nextptr;                     // advances the position of current node
        }
    }
}
}
