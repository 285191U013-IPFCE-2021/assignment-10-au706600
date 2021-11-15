#include "linked_list.h"
/*
 * Linked list
 */

#include <stdio.h>		/* printf */
#include <stdlib.h>		/* malloc, free */
#include <assert.h>		/* assert */
#include <math.h>

/* functions to create lists */
node *make_node (int v, node * q)
{
  node *p = malloc (sizeof (node));
  p->value = v;

  if (q == &SENTINEL_node)
    p->next = &SENTINEL_node;
  else
    p->next = q;
  return p;
}

/* free all nodes in the list p */
void free_list (node * p)
{
  node *q = p;
  while (q != &SENTINEL_node)
    {
      node *t = q->next;
      free (q);
      q = t;
    }
}


/* print list to console */
void print_list (node * p)
{
    if (p == &SENTINEL_node)
    {
      return ("\n"); 
    } else {
      printf("&d", p -> value); 
      return (p -> next); 
    }
    }

int sum_squares (node * p)
{
    if (p ==&SENTINEL_node )
    {
      return 0; 
    }else {
      return (square(p -> value) + sum_squares(p -> next)); 
    }
}

node *map (node * p, int (*f) (int))
{
    // Add your code for excercise 3
    if (p == NULL)
    return NULL; 
    else 
    {
 node *item = malloc(sizeof(node));
    item->value = f(p->value);
    item->next = map(p->next, f);
    return item;
  }
}

int square (int x)
{
  return x * x;
}
