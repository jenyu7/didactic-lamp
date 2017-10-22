//inserts a song node at the front of a linked list


//add headers!!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

//triggered by this bracket format


struct song* insert_front(struct song* list, char* name, char* artist)
{
  return create_node(list, name, artist);
}

void insert_order(struct song* lib[], char* name, char* artist)
{
  //printf("%d\n", index_of(artist));
  lib[index_of(artist)] = insert_order_help(lib[index_of(artist)], name, artist);
}

//inserts a song node in the correct alphabetical order
struct song* insert_order_help(struct song* list, char* name, char* artist)
{
  printf("=====inserting %s by %s=====\n", name, artist);
  struct song* first = list;
  if (!list)
    {
      printf("creating first node\n");
      printf("=====\n");
      return create_node(0, name, artist);
    }
  while(list->next && strcmp(artist, list->next->artist) > 0)
    {
      printf("comp artists\n");
      list = list->next;
    }
  if (!list->next && strcmp(artist, list->artist) != 0)
    {
      printf("ran out of artists\n");
      list->next = create_node(0, name, artist);
      printf("=====\n");
      return first;
    }
  while(list->next && strcmp(name, list->next->name) > 0)
    {
      printf("comp names\n");
      list = list->next;
    }
  if (!list->next)
    {
      if (strcmp(name, list->name) > 0)
	{
	  printf("adding at end of ll\n");
	  list->next = create_node(0, name, artist);
	  printf("=====\n");
	  return first;
	}
    }
  if (strcmp(name, list->name) < 0)
    {
      printf("adding before first node\n");
      first = create_node(list, name, artist);
      printf("=====\n");
      return first;
    }
  printf("adding in between nodes\n");
  struct song* tmp = list->next;
  list->next = create_node(tmp, name, artist);
  printf("=====\n");
  return first;
}

struct song* create_node(struct song* next, char* name, char* artist)
{
  struct song* ret = (struct song*)malloc(sizeof(struct song));
  strcpy(ret->name, name);
  strcpy(ret->artist, artist);
  ret->next = next;
  return ret;
}


void find_artist(struct song* lib[], char* artist)
{
  lib[index_of(artist)] = find_artist_help(lib[index_of(artist)], artist);
}

//Matches an artist
struct song* find_artist_help(struct song*playlist, char *artist){
  while (playlist){
    if (strcmp(artist, playlist->artist) == 0)
      {
	return playlist;
      }
    playlist = playlist->next;
  }
  return playlist;
}



//trash pile
 /*
  if (!list->next && strcmp(artist, list->artist) !=0)
    {
      if (strcmp(artist, list->artist) > 0)
	{
	  printf("artist:adding at end of node\n");
	  list->next = create_node(0, name, artist);
	  printf("=====\n");
	  return first;
	}
      printf("artist:adding at front of node\n");
      first = create_node(list, name, artist);
      printf("=====\n");
      return first;
    }
  if (strcmp(artist, list->next->artist) != 0)
    {
      if (strcmp(artist, list->artist) < 0)
	{
	  printf("artist:adding before first node\n");
	  first = create_node(list, name, artist);
	  printf("=====\n");
	  return first;
	}
      printf("artist:adding in between nodes\n");
      struct song* tmp = list->next;
      list->next = create_node(tmp, name, artist);
      printf("=====\n");
      return first;
      
    }
  */
