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

int MinValueNode(PNODE Root)
{
	PNODE current = Root;
	
	while(current->left != NULL)
	{
		current = current->left;
		return current;
	}	
}
PNODE Delete(PPNODE Root,int iValue)
{
	if(Root == NULL)
	{
		 return Root;
	}
	if(iValue < (*Root)->data)
	{
		(*Root)->lchild = Delete((*Root)->lchild,iValue);
	}
	else if(iValue > (*Root)->data)
	{
		(*Root)->rchild = Delete((*Root)->rchild,iValue);
	}
	else
	{
		//node with only one child or no child
		if((*Root)->lchild == NULL)
		{
			PNODE temp = (*Root)->rchild;
			free(Root);
			return temp;
		}
		else if((*Root)->rchild == NULL)
		{
			PNODE temp = (*Root)->lchild;
			free(Root);
			return temp;
		}
		
		// node with two children
		PNODE temp = MinValueNode((*Root)->rchild);
		
		//copy the inorder successor content to this node
		Root->data = temp->data;
		
		//delete the inorder suceesor
		(*Root)->rchild = Delete((*Root)->rchild,temp->data);
	}
		return Root;
	
}
int main()
{
	                    PNODE First = NULL;
	                    int iNo = 0;
	                    BOOL bRet = FALSE;
	
	                    printf("Enter number to insert\n");
	                    scanf("%d",&iNo);
	                    Insert(&First,iNo);
						
					    printf("Enter number to insert\n");
	                    scanf("%d",&iNo);
	                    Insert(&First,iNo);
						
			            printf("Enter number to insert\n");
	                    scanf("%d",&iNo);
	                    Insert(&First,iNo);
						
			            printf("Enter number to insert\n");
	                    scanf("%d",&iNo);
	                    Insert(&First,iNo);
						
					    printf("Enter number to insert\n");
	                    scanf("%d",&iNo);
	                    Insert(&First,iNo);
	       
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
						
						printf("Enter number to delete from BST");
						scanf("%d",&iNo);
						Delete(&First,iNo);
						
return 0;
}