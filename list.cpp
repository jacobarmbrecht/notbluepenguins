#include "list.h"

void insert(llist** list, void* val)
// Head insert
{
        llist* mynode = (llist*) malloc(sizeof(llist));
        mynode->val = val;
        mynode->next = NULL;
        if (!*list)
        {
                *list = mynode;
        }
        else
        {
                mynode->next = *list;
                *list = mynode;
        }
}

void* remove(llist** list)
// Head remove
{
        llist* mynode;
        void* val;
        if (!*list)
        {
                return NULL;
        }
        else
        {
                mynode = *list;
                *list = mynode->next;
                val = mynode->val;
                free(mynode);
                return val;
        }
}
