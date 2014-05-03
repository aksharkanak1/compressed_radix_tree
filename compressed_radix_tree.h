/*
   Simple Patricia tree implementation
*/


#define CLEAR_PARENT_LIST_AND_ADD   0x01
#define APPEND_TO_PARENT_LIST       0x02


#define STR_PRESENT                 0x01
#define STR_NOT_PRESENT             0x01

#define MAX_STR_SIZE  100

#define MIN_NUM_PTR_IN_NODE 5
#define NUM_PTR_INC         5 

/*ERRORS*/
#define MEM_ALLOC_FAILURE 0x01
#define INVALID_INPUT     0x02
#define MEM_REALLOC_FAILURE	0x04

#define SAFE_FREE(x)  if(x)   \
                      {      \
                         free(x);  \
                         x=NULL; \
                      }

                   


typedef struct N  {
  char s[100];
  uint8_t np;
  uint8_t npU;
  struct N *l;
 };
