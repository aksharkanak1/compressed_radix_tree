#include <stdio.h>

#define FULL_ONES  0xFFFFFFFF

N*allocNode(uint8_t ptrListSize)
{
    N*t = NULL;
    t = (N*)malloc(sizeof N);
    if(NULL != t)
       memset(t,0,sizeof(N));
    else 
       return t;

    t->l = malloc(sizeof(N) *ptrListSize)
    if(NULL != t->l)
    {
       memset(t->l,0,sizeof(N) *ptrListSize);
       t->np = ptrListSize;
    }
    else 
    {
       free(t);
       t = NULL ;
       return t; 
    }
    return t ;

}


int CreateNodeAddToParent(char *str,N*lp,uint32_t nptr, N*p,uint32_t flags, uint32_t *err)
{
   N*t2 =NULL ;
   N *t3 =NULL ;
   
   if(NULL == str || NULL == p || NULL == err)
   {
       *err = INVALID_INPUT;
       return -1;
    } 
 
   if(NULL !=lp)
      t2 = allocNode(nptr);
   else 
      t2 = allocNode(MIN_NUM_PTR_IN_NODE);
   if(NULL == t2)
   {
      *err |= MEM_ALLOC_FAILURE;
      SAFE_FREE(t2);
      return -1;
    }
    strcpy(t2->s,str);
    if(NULL !=lp)
    {
      memcpy(t2->l,lp,sizeof(N*)*nptr);
      t2->np=nptr;
    }
    if(flags & CLEAR_PARENT_LIST_AND_ADD)
    {
      SAFE_FREE(p->l);
      freePtrListAndCreateNew(p);
      p->l[0]=t2;
      p->npU++;

    }
    else 
    {
       if(p->npU >=p->np)
       {
          t3= realloc(p->l,(sizeof(N)*(p->np))+(sizeof(N)*NUM_PTR_INC));
          if(NULL == t3)
          {
             *err|=MEM_REALLOC_FAILURE;
             return -1; 
          }
          p->l = t3;
          p->np +=NUM_PTR_INC; 
      }
      p->l[p->npU] = t2;
      p->npU++;
    }
    return 0;
}
/**/

int insertStr(char *s , N *n)
{
    N *c = NULL ;
    N*p = NULL ;
    N *t = NULL;
    N *t2= NULL ;
    uint32_t  idx = FULL_ONES; 
    unit32_t len = 0;
    uint8_t NComm =0;
    uint32_t err =0;
    int retVal =0;

    if(NULL ==s)
        return -1;

   len = strlen(s);

   while (len > 0)
   {
      for(i=0;i<c->np;i++)
      {
         t=c->l[i];
         findMaxCommonPoint(&s[idx],t->s,&idx,&NComm);
         /*case 1 , the strInNode and pasredStr have nothing in common*/
         if(1 == NComm)
         {
            continue;
         }
         /*strInNode == parsedStr*/ 
         else if (0==NComm && t->s[idx+1] == '\0' && s[idx+1] == '\0')
         {
            len-=len-strlen(t->s);
            break;
         }
         /*strInNode is < then pasredStr , but is fully present in parsedStr*/ 
         if(0==NComm && t->s[idx+1] == '\0'&& s[idx+1] !=0) 
         {
               len-=strlen(t->s);
               s +=strlen(t->s);
               p = c;
               c = t;
               break;
         }
        /*partial strInNode is present in parsedStr*/
         if(0 == NComm && t->s[idx+1] != '\0' && s[idx+1] != '\0')
         {
               /*Create a new node which will be having the unmatched part from the StrInNode*/
              retVal =CreateNodeAddToParent(&s[idx+1],c,&err );
              if(0 != retVal)
              {
                  break;
              }	
              /*Create a node which will be having the unmatched part from the parsedStr*/		

         }
      }
   }

}


int searchStr(N *t , char *str, uint8_t* found)
{
    uint32_t off =0;
    uint8_t Ncomm =0;
    if(NULL == t || NULL == str)
       return -1 ;

    if(1 == *found)
        return 0;

    for(i=0;i<n->npU;i++)
    {
        findMaxCommonPoint(str,n->l[i]->s,&off,&Ncomm);
        if(1 == Ncomm)
            return 0;
    
        if(strlen(str) == off+1)
        {
             *found =1 ;
              return 0;
        }
       else 
       {
           search(n->l[i],str[off+1],found);
       }
   
    }
    return 0; 
}
