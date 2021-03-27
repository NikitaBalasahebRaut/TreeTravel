//program to travel the binary search tree

#include<stdio.h>
#include<stdlib.h>

typedef int BOOL;
#define TRUE 1
#define FALSE 0

struct Node
{
	int data;
	struct Node *lchild;
	struct Node *rchild;
};

typedef struct Node NODE;
typedef struct Node* PNODE;
typedef struct Node** PPNODE;

void Insert(PPNODE Root,int iValue)
{
   PNODE newn = NULL;
   PNODE temp = *Root;   
   
   newn = (PNODE)malloc(sizeof(NODE));
   newn->data = iValue;
   newn->lchild = NULL;
   newn->rchild = NULL;
   
   if(*Root == NULL)
   {
	   *Root = newn;
   }
   else
   {
	   while(1)
	   {
		   if(temp->data == iValue)
		   {
			   printf("Element already present:Unable to insert\n");
			   free(newn);
			   break;
		   }
		   if(iValue < (temp->data))
		   {
			   if((temp->lchild) == NULL)
			   {
				  temp->lchild = newn;
                  break;				  
			   }
			   temp = temp->lchild;
		   }
		   else if(iValue > (temp->data))
		   {
			   if((temp->rchild) == NULL)
			   {
				   temp->rchild = newn;
				   break;
			   }
			   temp = temp->rchild;
		   }
	   }

   }
     
}

BOOL Search(PNODE Root,int iValue)
{
  while(Root != NULL)
  {
     if(Root->data == iValue)
	 {
		 break;
	 }
	 if(iValue < Root->data)
	 {
		 Root = Root->lchild;
	 }
	 else
	 {
		 Root = Root->rchild;
	 }
  }

  if(Root == NULL)
  {
      return FALSE;
  }
  else
  {
	  return TRUE;
  }
	
}

void Inorder(PNODE Root)
{
	if(Root != NULL)
	{
		Inorder(Root->lchild);
		printf("%d\t",Root->data);
		Inorder(Root->rchild);
	}
}

void Preorder(PNODE Root)
{
	if(Root != NULL)
	{
	printf("%d\t",Root->data);
	Preorder(Root->lchild);
	Preorder(Root->rchild);
	}
}

void Postorder(PNODE Root)
{
	if(Root != NULL)
	{
		Postorder(Root->lchild);
		Postorder(Root->rchild);
		printf("%d\t",Root->data);
	}
}

int main()
{
	PNODE First = NULL;
	int iNo = 0;
	BOOL bRet = FALSE;
	int choice = 1;      //set 1 otherwise program not run consider bydefault 0
	
	while(choice != 0)
	{
		printf("Enter your choice\n");
		printf("1 : Insert into Binary search tree\n");
		printf("2 : search the element in binary search tree\n");
		printf("3 : Inorder display\n");
		printf("4 : preorder display\n");
		printf("5 : postorder display\n");
		printf("0 : Exit the applica\n");
		
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
			        	printf("Enter number to insert\n");
	                    scanf("%d",&iNo);
	                    Insert(&First,iNo);
						break;
	        case 2:
			          	printf("Enter element to search\n");
	                    scanf("%d",&iNo);
	                    bRet = Search(First,iNo);
						if(bRet == TRUE)
						{
							printf("Element is there in BST\n");
						}
						else
						{
							printf("There is no element in BST\n");
						}
						break;
		case 3:
		                Inorder(First);
						break;
	    case 4:
		                Preorder(First);
						break;
		case 5:
		                Postorder(First);
						break;
		default:
		                printf("Wrong choice\n");
						
		}
	}
	return 0;
}

/*

output


D:\ProgramTopicWise\DS\TreeTravel>myexe
Enter your choice
1 : Insert into Binary search tree
2 : search the element in binary search tree
3 : Inorder display
4 : preorder display
5 : postorder display
0 : Exit the applica
1
Enter number to insert
25
Enter your choice
1 : Insert into Binary search tree
2 : search the element in binary search tree
3 : Inorder display
4 : preorder display
5 : postorder display
0 : Exit the applica
1
Enter number to insert
56
Enter your choice
1 : Insert into Binary search tree
2 : search the element in binary search tree
3 : Inorder display
4 : preorder display
5 : postorder display
0 : Exit the applica
1
Enter number to insert
56
Element already present:Unable to insert
Enter your choice
1 : Insert into Binary search tree
2 : search the element in binary search tree
3 : Inorder display
4 : preorder display
5 : postorder display
0 : Exit the applica
1
Enter number to insert
47
Enter your choice
1 : Insert into Binary search tree
2 : search the element in binary search tree
3 : Inorder display
4 : preorder display
5 : postorder display
0 : Exit the applica
4
25      56      47      Enter your choice
1 : Insert into Binary search tree
2 : search the element in binary search tree
3 : Inorder display
4 : preorder display
5 : postorder display
0 : Exit the applica
4
25      56      47      Enter your choice
1 : Insert into Binary search tree
2 : search the element in binary search tree
3 : Inorder display
4 : preorder display
5 : postorder display
0 : Exit the applica
2
Enter element to search
12
There is no element in BST
Enter your choice
1 : Insert into Binary search tree
2 : search the element in binary search tree
3 : Inorder display
4 : preorder display
5 : postorder display
0 : Exit the applica
2
Enter element to search
56
Element is there in BST
Enter your choice
1 : Insert into Binary search tree
2 : search the element in binary search tree
3 : Inorder display
4 : preorder display
5 : postorder display
0 : Exit the applica
0
Wrong choice

*/