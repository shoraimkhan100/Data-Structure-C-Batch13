#include<stdio.h>
#include<malloc.h>
struct node 
{
    struct node *pPrev;
    int iData;
    struct node *pNext;
};
void InsertFirst(struct node ** , struct node ** , int);
void InsertLast(struct node ** , struct node ** , int);
int DeleteFirst(struct node ** , struct node **);
void Display(struct node * , struct node *);
void DeleteAll(struct node ** ,struct node **);
int DeleteLast(struct node ** , struct node **);
int SearchFirstOccurance(struct node *,struct node * , int);
int SearchLastOccurance(struct node *,struct node * , int);
int SearchAllOccurance(struct node *,struct node * , int);
int CountNode(struct node *,struct node *);
void InsertAtPosition(struct node **,struct node **,int,int);
int DeleteAtPosition(struct node **,struct node **,int);
void Concatlist(struct node ** ,struct node ** , struct node ** ,struct node **);
void ConcatAtPosition(struct node ** ,struct node ** , struct node ** ,struct node **,int);
void PhysicalReverse(struct node ** ,struct node **);
void ReverseDisplay(struct node * ,struct node *);

int main(void)
{
    int iData;
    struct node *pFirst = NULL;
    struct node *pLast1 = NULL;
    struct node *pSecond = NULL;
    struct node *pLast2 = NULL;
    int iChoice;
    int iNo = 1;
    int iChoice2;

    while(iNo != 0)
    {
    printf("|->\n\n\tEnter 1. For Insert\n");        
    printf("\n\t|->1. InsertFirst\n\t|->2. InsertLast\n\t|->3. InsertAtPosition\n\t");
    
    printf("\n\n\tEnter 2. For Delete\n");
    printf("\n\t|->1. DeleteFirst\n\t|->2.DeleteLast\n\t|-> 3.DeleteAtpoistion\n\t");
    
    printf("\n\n\tEnter 3. For Occureance\n");
    printf("\n\t|->1.search First Occureance\n");
    printf("\t|->2. Search Last Occurance\n\t|->3. Seach All Ocuurance\n\t");

    printf("\n\tEnter 4. For Count\n");
    printf("\n\tEnter 5. For Reverse\n");
    printf("\n\tEnter 6. For Reverse Display\n");
    printf("\n\tEnter 7. For Second\n");
    printf("\n\tEnter 8. For Concat\n \t|->1.Concat list\n\t|->2.Concat At position\n");

    scanf("%d",&iChoice);
    
    if(iChoice < 0 || iChoice>8)
    {
        printf("Wrong..\n");
        continue;
    }
    if(iChoice == 0)
        break;
 
    printf("\n\tEnter the Your Choice for inside : ");
    scanf("%d",&iChoice2);
    
    if(iChoice2 < 0 || iChoice2>3)
    {
        printf("Wrong..\n");
        continue;
    }
    
    switch(iChoice)
    {
    case 1:
        switch(iChoice2)   
        {
        case 1:
            while(iNo != 0)
            {
                printf("\n\tEnter The Value for Insert First :");
                scanf("%d",&iNo); 
                InsertFirst(&pFirst,&pLast1,iNo);
                Display(pFirst,pLast1);//10 20 30
                printf("\n\tIf You Want to Stop then Enter(0) :");
                scanf("%d",&iNo);
            }
            break;    
                case 2:
                    while(iNo != 0)
                    {
                        printf("\n\tEnter The Value for Insert Last :");
                        scanf("%d",&iNo);
                        InsertLast(&pFirst,&pLast1,iNo);
                        Display(pFirst,pLast1);//10 20 30 40 50 60
                        printf("\n\tIf You Want to Stop then Enter(0) :");
                        scanf("%d",&iNo);
                    }
                    break;

                        case 3:
                        while(iNo != 0)
                        {
                        printf("Enter The Value for Insert At Position Value :");
                        scanf("%d",&iNo);
                        printf("Enter The Position : ");
                        scanf("%d",&iChoice);
                        InsertAtPosition(&pFirst,&pLast1,iNo,iChoice);
                        Display(pFirst,pLast1);//10 20 30 20 40 50 60
                        printf("\n\tIf You Want to Stop then Enter(0) :");
                        scanf("%d",&iNo);
                        }
                    break;
        }
        break;

    case 2:
            switch(iChoice2)
            {
                case 1:
                while(iNo != 0)
                {
                iData = DeleteFirst(&pFirst,&pLast1);
                    if(iData != -1)
                        printf("Deleted First Data is : %d\n",iData);//10
                Display(pFirst,pLast1);//20 30 40 50 60
                printf("\n\tIf You Want to Stop then Enter(0) :");
                scanf("%d",&iNo);
                }
                break;
            
                    case 2:
                    while(iNo != 0)
                    {
                    iData = DeleteLast(&pFirst,&pLast1);
                        if(iData != -1)
                            printf("Deleted Last Data is : %d\n",iData);//60
                    Display(pFirst,pLast1);//20 30 40 50
                    printf("\n\tIf You Want to Stop then Enter(0) :");
                    scanf("%d",&iNo);
                    }
                    break;

                        case 3:
                        while(iNo != 0)
                        {
                        printf("\n\tEnter the Poistion You Want To Delete : ");
                        scanf("%d",&iNo);
                        iData = DeleteAtPosition(&pFirst,&pLast1,iNo);
                            if(iData != -1)
                                printf("Deleted at position is : %d\n",iData);//40
                        Display(pFirst,pLast1);//20 30 20 50
                        printf("\n\tIf You Want to Stop then Enter(0) :");
                        scanf("%d",&iNo);
                        }
                        break;
        }    
    break;

    case 3:   
        switch(iChoice2)
        {
            case 1:
            while(iNo != 0)
            {
            printf("\n\tEnter the Search first occurance You Want To Search : ");
            scanf("%d",&iNo);
            iData = SearchFirstOccurance(pFirst,pLast1,iNo);
                if(iData != 0)
                    printf("First occurrence of %d found at : %d position\n",iNo,iData);//1
            printf("\n\tIf You Want to Stop then Enter(0) :");
            scanf("%d",&iNo);
            }
            break;

                case 2:
                while(iNo != 0)
                {
                printf("\n\tEnter the Search last occurance You Want To Search : ");
                scanf("%d",&iNo);
                iData = SearchLastOccurance(pFirst,pLast1,iNo);
                    if(iData != 0)
                        printf("Last occurrence of %d found at %d position\n",iNo,iData);
                printf("\n\tIf You Want to Stop then Enter(0) :");
                scanf("%d",&iNo);
                }
                break;
                
                    case 3:
                    while(iNo != 0)
                    {
                    printf("\n\tEnter the Search All occurance You Want To Search : ");
                    scanf("%d",&iNo);
                    
                    iData = SearchAllOccurance(pFirst,pLast1,iNo); // 2 times
                        printf("%d found %d times\n",iNo,iData); 
                    printf("\n\tIf You Want to Stop then Enter(0) :");
                    scanf("%d",&iNo);
                    }
                    break;
        }
    break;

    case 4:
        iData = CountNode(pFirst,pLast1);
            printf("Total nodes = %d\n",iData);//4
        break;
    
    case 5:
        Display(pFirst,pLast1);//20 30 20 50
        PhysicalReverse(&pFirst,&pLast1);
        Display(pFirst,pLast1);//50 20 30 20
        PhysicalReverse(&pFirst,&pLast1);
        Display(pFirst,pLast1);//20 30 20 50
        break;
    
    case 6:
        ReverseDisplay(pFirst,pLast1);//50 20 30 20
        Display(pFirst,pLast1);
        break;
    
    case 7:
        while(iNo != 0)
        {
        printf("\n\t Enter the Value for the Second node Insert Last : ");
        scanf("%d",&iChoice);
        InsertLast(&pSecond,&pLast2,iChoice);
        Display(pSecond,pLast2);
        printf("\n\tIf You Want to Stop then Enter(0) :");
        scanf("%d",&iNo);
        }
        break;
        
    case 8:
        switch(iChoice2)
        {
            case 1:
            Display(pFirst,pLast1);//20 30 20 50
            Display(pSecond,pLast2);//100 200 300
            Concatlist(&pFirst,&pLast1,&pSecond,&pLast2);
            Display(pFirst,pLast1);//20 30 20 50 100 200 300
            Display(pSecond,pLast2);//list is empty..
            break;
                
                    case 2:
                    while(iNo != 0)
                    {
                    printf("\n\tEnter the Poistion You Want to Enter :");
                    scanf("%d",&iChoice);
                    Display(pFirst,pLast1);//20 30 20 50 100 200 300
                    Display(pSecond,pLast2);//1000 2000 3000
                    ConcatAtPosition(&pFirst,&pLast1,&pSecond,&pLast2,iChoice);
                    Display(pFirst,pLast1);//20 30 20 50 100 200 300 1000 2000 3000
                    Display(pSecond,pLast2);//list is empty..
                    }
                break;
        }
        break;
    }

    printf("\n\tIf You Want to Continue (Enter 1) or Exit (Enter 0) :");
    scanf("%d", &iNo);

}

	if(iNo != 0)
	{
		printf("\n-------------------- ANSWER ^ Was --------------------\n\n");
		printf("\n****************************|***********************\n\n");
	
	}

    if(pFirst != NULL)
    {
        DeleteAll(&pFirst,&pLast1);
        pFirst=pLast1=NULL;
    }
    if(pSecond != NULL)
    {
        DeleteAll(&pSecond,&pLast2);
        pSecond =pLast2= NULL;
    }
    Display(pFirst,pLast1);
    Display(pSecond,pLast2);
    return 0;
}
void InsertFirst(struct node **ppHead, struct node **ppTail , int iNo)
{
    struct node *pNewNode = NULL;
    pNewNode = (struct node *)malloc(sizeof(struct node));

    if(NULL == pNewNode)
    {
        printf("memory allocation FAILED\n");
        return;
    }
    pNewNode->iData=iNo;
    if(NULL == *ppHead)
    {
        *ppHead=pNewNode;
        *ppTail=pNewNode;
        (*ppHead)->pPrev=*ppTail;
        (*ppTail)->pNext=*ppHead;
        return;
    }
   pNewNode->pNext=*ppHead;
    (*ppHead)->pPrev=pNewNode;
    *ppHead=pNewNode;
   (*ppTail)->pNext = *ppHead;
   (*ppHead)->pPrev = *ppTail;
}
void InsertLast(struct node **ppHead, struct node **ppTail , int iNo)
{
    struct node *pNewNode = NULL;
    pNewNode = (struct node *)malloc(sizeof(struct node));
    if(NULL == pNewNode)
    {
        printf("memory allocation FAILED\n");
        return;
    }
    pNewNode->iData = iNo;
    
    if(*ppHead == NULL)
    {
         *ppHead = pNewNode;
        *ppTail = pNewNode;
        (*ppTail)->pNext=*ppHead;
        (*ppHead)->pPrev=*ppTail;
        return;
    }
    (*ppTail)->pNext=pNewNode;
    pNewNode->pPrev=*ppTail;
    (*ppTail)=pNewNode;
    (*ppTail)->pNext = *ppHead;
    (*ppHead)->pPrev=*ppTail;
}
void DeleteAll(struct node **ppHead , struct node **ppTail)
{
    struct node *pTemp = NULL;

    (*ppTail)->pNext=NULL;
    while(*ppHead != NULL)
    {
        pTemp = *ppHead;
        *ppHead=pTemp->pNext;
        pTemp->pNext=pTemp->pPrev=NULL;
    free(pTemp);
    }
    pTemp=NULL;
}
void Display(struct node *pHead ,struct node *pTail)
{
    if(NULL == pHead)
    {
        printf("list is empty\n");
        return;
    }
    do
    {
      printf("|%d|->",pHead->iData);
      pHead=pHead->pNext;
    }     while(pHead != pTail->pNext);
    printf("\n");
}
int DeleteFirst(struct node **ppHead ,struct node **ppTail)
{
    int iDelData;

    if(NULL == *ppHead)
        return -1;

    iDelData=(*ppHead)->iData;
   
    if(*ppHead == (*ppTail))
    {   
        (*ppHead)->pNext=NULL;
        (*ppHead)->pPrev=NULL;
        free(*ppHead);
        *ppHead=*ppTail=NULL;
         return iDelData; 
    }
    *ppHead=(*ppHead)->pNext;
    (*ppHead)->pPrev->pNext=NULL;
    (*ppHead)->pPrev->pPrev=NULL;
    free((*ppHead)->pPrev);
    (*ppTail)->pNext=*ppHead;
    (*ppHead)->pPrev=*ppTail;
    return iDelData;
}
int DeleteLast(struct node **ppHead , struct node **ppTail)
{
    int iDelData;
    if(NULL == *ppHead)
        return -1;

    iDelData=(*ppTail)->iData;

    if(*ppHead == *ppTail)
    {
        (*ppHead)->pNext=(*ppHead)->pPrev=NULL;
        *ppHead=*ppTail=NULL;
        return iDelData;
    }
    
    
    *ppTail = (*ppTail)->pPrev;
    (*ppTail)->pNext->pNext=NULL;
    (*ppTail)->pNext->pPrev=NULL;
    
    free(((*ppTail)->pNext));
    (*ppTail)->pNext=*ppHead;
    (*ppHead)->pPrev=*ppTail;
    return iDelData;
}
int SearchFirstOccurance(struct node *pHead,struct node *pTail , int iKey)
{
    int iPos = 0;
    if(NULL == pHead)
        return -1;
    do{
        iPos++;
        if(iKey == pHead->iData)
            return iPos;
        pHead=pHead->pNext;
    }while(pHead != pTail->pNext);
    return 0;
}
int SearchLastOccurance(struct node *pHead,struct node *pTail , int iKey)
{
    int iPos = 0;
    int iCount = 0;
    if(NULL == pHead)
        return -1;
    do{
        iPos++;
        if(iKey == pHead->iData)
            iCount = iPos;
        pHead=pHead->pNext;
    }while(pHead != pTail->pNext);
    return iCount;
}
int SearchAllOccurance(struct node *pHead , struct node *pTail ,int iKey)
{
    
    int iCount = 0;
    
    do{
        if(iKey == pHead->iData)
            iCount++;
        pHead=pHead->pNext;
    }while(pHead != pTail->pNext);

    return iCount;
}
int CountNode(struct node *pHead,struct node *pTail)
{
    int iCount = 0;
    if(NULL == pHead)
        return 0;
    do{
        iCount++;
        pHead=pHead->pNext;
    }while(pHead!= pTail->pNext);
    return iCount;
}
void InsertAtPosition(struct node **ppHead,struct node **ppTail,int iNo , int iPos)
{
    int iCount = 0;

    struct node *pNewNode = NULL;
    struct node *pTemp = NULL;

    iCount = CountNode(*ppHead,*ppTail);
    printf("count of node is : %d\n",iCount);

    if(iPos<=0 || iPos>(iCount+1))
    {
        printf("position is invalid\n");
        return;
    }
    
    if(1 == iPos)
    {
        InsertFirst(ppHead , ppTail , iNo);
        return;
    }

    if(iPos == iCount+1)
    {
        InsertLast(ppHead,ppTail,iNo);
        return;
    }

    pNewNode=(struct node*)malloc(sizeof(struct node));
    
    if(NULL == pNewNode)
    {
        printf("memory allocation failed\n");
        return;
    }

    pNewNode->iData=iNo;
    pTemp=*ppHead;
    iCount=1;

    while(iCount<iPos-1)
    {
        pTemp=pTemp->pNext;
        iCount++;
    }
    pNewNode->pNext=pTemp->pNext;
    pTemp->pNext->pPrev=pNewNode;
    pTemp->pNext=pNewNode;
    pNewNode->pPrev=pTemp;
}
int DeleteAtPosition(struct node **ppHead1,struct node **ppHead2,int iPos)
{
    int iCount;
    struct node *pTemp1 = NULL;

    iCount =CountNode(*ppHead1,*ppHead2);

    if(iPos <= 0 || iPos>iCount)
    {
        printf("position is invalid\n");
        return -1;
    }
    if(1 == iPos)
       return DeleteFirst(ppHead1,ppHead2);

    if(iPos == iCount+1)
        return DeleteLast(ppHead1,ppHead2);

    pTemp1 = *ppHead1;
    iCount = 1;

    while(iCount<iPos)
    {
        iCount++;
        pTemp1= pTemp1->pNext;
    }
    iCount=pTemp1->iData;
    pTemp1->pPrev->pNext=pTemp1->pNext;
    pTemp1->pNext->pPrev=pTemp1->pPrev;
    pTemp1->pNext=pTemp1->pPrev=NULL;
    free(pTemp1);
    pTemp1=NULL;
    return iCount;
}
void Concatlist(struct node **ppHead1,struct node **ppTail1,struct node **ppHead2,struct node **ppTail2)
{
    if(NULL == *ppHead2)
        return;
    if(NULL == *ppHead1)
    {
        *ppHead1 = *ppHead2;
        *ppTail1=*ppTail2;
    }
    else
    {
        (*ppTail1)->pNext=*ppHead2;
        *ppTail1=*ppTail2;
        (*ppTail1)->pNext=*ppHead1;
        (*ppHead1)->pPrev=*ppHead2;
    }
    *ppHead2=*ppTail2=NULL;
}
void ConcatAtPosition(struct node **ppHead1,struct node **ppTail1,struct node **ppHead2,struct node **ppTail2 , int iPos)
{
    int iCount;
    struct node *pTemp =NULL;
    iCount = CountNode(*ppHead1,*ppTail1);
    if(iPos<=0 || iPos>iCount+1)
    {
        printf("position is INVALID\n");
        return;
    }
    if(NULL == *ppHead2)
        return;
    if(1 == iPos)
    {
        Concatlist(ppHead2,ppTail2,ppHead1,ppTail1);
        *ppHead1=*ppHead2;
        *ppTail1 = *ppTail2;
        return;
    }
    if(iPos == iCount+1)
    {
        Concatlist(ppHead1,ppTail1,ppHead2,ppTail2);
        return;
    }
    pTemp=*ppHead1;
    iCount=1;
    while(iCount<iPos-1)
    {
        iCount++;
        pTemp=pTemp->pNext;
    }
    (*ppTail2)->pNext=pTemp->pNext;
    (*ppTail2)->pNext->pPrev=*ppTail1;
    pTemp->pNext=*ppHead2;
    (*ppHead2)->pPrev=pTemp;
    *ppHead2=*ppTail2=NULL;
}
void PhysicalReverse(struct node **ppHead , struct node **ppTail)
{
    struct node *pPrev = *ppTail;
    struct node *pCurrent = *ppHead;
    struct node *pNext = NULL;
    if(NULL == *ppHead)
        return;
    while(pCurrent != NULL)
    {
        pNext=pCurrent->pNext;
        pCurrent->pNext=pPrev;
        pPrev=pCurrent;
        if(pCurrent==*ppTail)
            break;
        pCurrent=pNext;
    }
    *ppHead=*ppTail;
    *ppTail=pNext;
}
void ReverseDisplay(struct node *pHead,struct node *pTail)
{
    if(NULL == pHead)
    {
        printf("list is empty..\n");
        return;
    }
    PhysicalReverse(&pHead,&pTail);
    Display(pHead,pTail);
    PhysicalReverse(&pHead,&pTail);
}