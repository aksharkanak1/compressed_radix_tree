#include <stdio.h>

int findMaxCommonPoint(char *str1 , char *str2, uint32_t *off,uint8_t* NComm)
{
   uint32_t i =0;
   uint32_t len =0;  
    

   if(NULL == str1 || NULL == str2 || NULL == off)
      return -1;

   len = strlen(str1)<strlen(str2) ?strlen(str1):strlen(str2);

   if(str1[0] != str2[0])
   {
      *NComm =1;
      return 0;
   }
   
   for(i=0;i<len;i++)
   {
      if(str1[i] != str2[i])
          break ; 
   }
   *off =i;
   return  0;

}

void  freeTree(N*t)
{
     int i =0;
     if(NULL == t)
         return ;

     for(i=0;i<t->npU;i++)
     {
         freeTree(t->l[i]);
     }
     free(t);
}

void freeNode(N *n)
{
    if(NULL ==n)
       return ;

    free(n->l);
    free(n);

}

int freePtrListAndCreateNew(N *n)
{
    N ** t = NULL ;
    if(NULL == n)
       return -1 ;

    t= (N**) malloc(sizeof(N*) *MIN_NUM_PTR_IN_NODE);
    if(NULL != t)
    {
        memset (n->l , 0 , sizeof(N*) *MIN_NUM_PTR_IN_NODE);
        free(n->l);
        n->l=t;
        return 0;
    }
    else 
       return -1 ;
    
}

void printTree(N *t)
{
    int i =0;
    if(NULL == t)
    {
       return; 
    }

    printf("\n--------Node 0x%x--------------",t);
    printf("\n Str : %s",t->s);
    printf("\nNumber of Childrens  %u",t->npU);
    
    for(i=0;i<t->npU;i++)
    {
       printf("\n%d   0x%x",t->npU,t->[l]);
    }
    printf("\n------------------------------\n"); 
    
    for(i=0;i<t->npU;i++)
    {
       printTree(t->l[i]);  
    }
    
   return ;
      
}
