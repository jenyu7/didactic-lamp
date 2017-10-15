#include <stdio.h>
#include <stdlib.h>

struct node{int i; struct node *next};

/*
Should take a pointer to a node struct and print out all of the data in the list
 */
void print_list(struct node *p)
{
  while(p)
    {
      printf("%d\n", p->i);
      p = p->next;
    }
}

/*
Should take a pointer to the existing list and the data to be added, create a new node and put it at the beginning of the list.
The second argument should match whatever data you contain in your nodes.
Returns a pointer to the beginning of the list.
 */
struct node * insert_front(struct node *p, int n)
{
  struct node *new_list = (struct node *)malloc(sizeof(struct node));
  new_list->next=p;
  new_list->i=n;
  return new_list;
}

/*
Should take a pointer to a list as a parameter and then go through the entire list freeing each node and return a pointer to the beginning of the list (which should be NULL by then).                
Don't forget to test out these various functions to ensure they work correctly.
 */
struct node * free_list(struct node *p)
{
  struct node *old_node;
  while(p)
    {
      old_node = p;
      p = p->next;
      free(old_node);
    }
  return p;
}

int main()
{
  printf("Create a linked list\n");
  struct node *ll = insert_front(NULL, 18);
  print_list(ll);
  printf("Add elements\n");
  ll = insert_front(insert_front(ll, 16), 14);
  print_list(ll);
  printf("Free me!!\n");
  free_list(ll);
  print_list(ll);
}
