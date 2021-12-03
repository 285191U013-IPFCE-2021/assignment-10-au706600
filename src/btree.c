#include "btree.h"

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>


struct tree_node * Insert (int x, struct tree_node *t)
{
  {
  if (Empty(t))
  {
    struct tree_node *leaf = malloc(sizeof(struct tree_node));
      leaf->item=x;
      leaf->left=NULL;
      leaf->right=NULL;

    t->left=leaf;
    t->right=leaf;

  }
  if (Empty(t)==false)
  {
  struct tree_node* current = t->left;
  bool isinsert = false;

  while (isinsert==false)
  {

  if (current->item>x)
  {
    if (current->left!=NULL)
    {
      current=current->left;
    }
    else
    {
      struct tree_node *leaf = malloc(sizeof(struct tree_node));
      isinsert=true;
      current->left=leaf;
      leaf->item=x;
      leaf->left=NULL;
      leaf->right=NULL;
    }
  } 
  if (current->item<x)
  {
    if (current->right!=NULL)
    {
      current=current->right;
    }
    else
    {
      struct tree_node *leaf = malloc(sizeof(struct tree_node));
      isinsert=true;
      current->right=leaf;
      leaf->item=x;
      leaf->left=NULL;
      leaf->right=NULL;
    }
  }
  }
  return NULL;
}
}

struct tree_node * Remove (int x, struct tree_node *t)
{
   struct tree_node *current = t;
  struct tree_node *forcurrent = t;
  struct tree_node *root = t;
  struct tree_node *forroot = t;

  
  

  // find pointeren til x værdien

  int i=0;

  while (i==0)
  {

    if (current->item==x)
    {
      i=1;
    }
  
    if (current->item>x)
    {
      forcurrent=current;
      current=current->left;
    }
    
    if (current->item<x)
    {
      forcurrent=current;
      current=current->right;
    }
  }

  if (current->left==NULL && current->right==NULL)
  {
    if (forcurrent->item<x)
    {
      forcurrent->right=NULL;
    }
    else if (forcurrent->item>x)
    {
      forcurrent->left=NULL;
    }
    free (current);
    
  }

  if (current->left !=NULL && current->right==NULL)
  {

    if (forcurrent->item>x)
    {
      forcurrent->left=current->left;
    }

    else if (forcurrent->item<x)
    {
      forcurrent->right=current->left;
    }
  free (current);
  return 0;
  }

  if (current->left==NULL && current->right!=NULL)
  {
    if (forcurrent->item>x)
    {
      forcurrent->left=current->right;
    }
    if (forcurrent->item<x)
    {
      forcurrent->right=current->right;
    }
  free (current);
  return 0;
  }

  if (current->left!=NULL && current->right!=NULL)
  {

    root=current->left;

      if (root->right==NULL)
      {
        current->item=root->item;
        current->left=root->left;
        free (root);
      }
      if (root->right!=NULL)
      {
        while (root->right!=NULL)
        {
          forroot=root;
          root=root->right;
        }
    
        forroot->right=root->left;
        current->item=root->item;
        free (root);
      }
 }
}

int Contains (int x, struct tree_node *t)
{

  {

  while (1)
  {
    if (t==NULL)
    {
      return false;
    }

    if (t->item==x)
    {
      return 1;
    }
    

    if (t->item>x)
    {
      t=t->left;
    }
    
    if (t->item<x)
    {
      t=t->right;
    }
  }
return 0;
}


struct tree_node * Initialize (struct tree_node *t)
{
  struct tree_node *root = malloc(sizeof(struct tree_node)); 
  root -> item = 0; 
  root -> right = NULL; 
  root -> left = NULL;  

return root; 
}

int Empty (struct tree_node *t)
{
  // test if empty
  if (t -> right == NULL && t -> left == NULL ){
    return 1; 
  }else {
    return 0; 
  }
  }
}

int Full (struct tree_node *t)
{
  //linked list can't be full.  
}

