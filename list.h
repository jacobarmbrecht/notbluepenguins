#ifndef LIST_H
#define LIST_H

typedef struct llist
{
        struct llist* next;
        void* val;
} llist;

#endif /* LIST_H */
