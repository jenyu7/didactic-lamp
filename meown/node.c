//add headers!!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"
#include "time.h"

//WRAPPER: Inserts songs in alphabetical order
//arranges by artists first, then songs
void insert_order(struct song* lib[], char* name, char* artist)
{
  //printf("%d\n", index_of(artist));
  lib[index_of(artist)] = insert_order_help(lib[index_of(artist)], name, artist);
}

//HELPER: inserts a song node in the correct alphabetical order
struct song* insert_order_help(struct song* list, char* name, char* artist)
{
  //printf("=====inserting %s by %s=====\n", name, artist);
  struct song* first = list;
  //Are there any songs yet?
  //if not, create a new one in the ll.
  if (!list)
  {
    //printf("creating first node\n");
    //printf("=====\n");
    return create_node(0, name, artist);
  }
  //Organize first by artist alphabetical order
  while(list->next && strcmp(artist, list->next->artist) > 0)
  {
    //printf("comp artists\n");
    list = list->next;
  }
  //If you run out of artists, and the new song has a different artist
  //than the last song
  if (!list->next && strcmp(artist, list->artist) != 0)
  {
    //printf("ran out of artists\n");
    list->next = create_node(0, name, artist);
    //printf("=====\n");
    return first;
  }
  //Not out of artists? Compare song name.
  while(list->next && strcmp(name, list->next->name) > 0)
  {
    //printf("comp names\n");
    list = list->next;
  }
  //if you are at the last node, and new song has a higher name than the
  //last node, add the new song to the end of the ll
  if (!list->next && strcmp(name, list->name) > 0)
  {
    //printf("adding at end of ll\n");
    list->next = create_node(0, name, artist);
    //printf("=====\n");
    return first;
  }
  //checks if song belongs at front of ll
  if (strcmp(name, list->name) < 0)
  {
    //printf("adding before first node\n");
    first = create_node(list, name, artist);
    //printf("=====\n");
    return first;
  }
  //printf("adding in between nodes\n");
  //all other cases
  struct song* tmp = list->next;
  list->next = create_node(tmp, name, artist);
  //printf("=====\n");
  return first;
}

//creates a song node, works like insert_front
struct song* create_node(struct song* next, char* name, char* artist)
{
  struct song* ret = (struct song*)malloc(sizeof(struct song));
  strcpy(ret->name, name);
  strcpy(ret->artist, artist);
  ret->next = next;
  return ret;
}


//Returns a pointer to the artist being searched
struct song* find_artist(struct song* lib[], char *artist){
  struct song* playlist = lib[index_of(artist)];
  while (playlist){
    if (strcmp(artist, playlist->artist) == 0)
    {
      return playlist;
    }
    playlist = playlist->next;
  }
  return playlist;
}

void shuffle_list(struct song* list) {
  if (list) {
    print_song(song_at(list,rand() % list_length(list)));
  }
  // -1 because index 3 would be null and we want it to print at least one
  // print_song(song_at(list,0));
  // if (list_length(list) != 1) {
    // int i = rand() % list_length(list);
  //   int count = 0;
  //   print_song(song_at(list, 0));
  // }
  // while(count < list_length(list) && current) {
  //   current = song_at(list, i);
  //   print_song(song_at(list, i));
  //   i = rand() % list_length(list);
  //   count++;
  // }
}


void shuffle_lib(struct song* lib[]) {
  srand(time(NULL));
  int i = rand() % 26; //0 to 25
  int prev = -1;
  while (i != 26) {
    if (prev != i) {
      // printf("%d\n", i);
      shuffle_list(lib[i]);
    }
    prev = i;
    i = rand() % 27; //0 to 26 where lib[26] is null
  }
}

//remove a node
void remove_node(struct song* lib[], char* artist, char* name)
{
  lib[index_of(artist)] = remove_node_help(lib[index_of(artist)], artist, name);
}

//removes a node in a list
struct song* remove_node_help(struct song* head, char* artist, char* name)
{
  struct song_node *rest;
  struct song_node *old_head;
  //if the node being removed is the head
  if (strcmp(head->artist, artist) == 0 && strcmp(head->name, name) == 0)
    {
    rest = head->next;
    free(head);
    return rest;
  }
  old_head = head;
  while (head->next)
  {
    if (strcmp(head->next->artist, artist) == 0 && strcmp(head->next->name, name) == 0)
    {
      rest = head->next->next;
      free(head->next);
      head->next = rest;
      return old_head;
    }
    head = head->next;
  }
  return 0;
}

void free_lib(struct song* lib[])
{
  int i = 0;
  while(i < 26)
    {
      lib[i] = free_lib_help(lib[i]);
      i ++;
    }
}

struct song* free_lib_help(struct song *ptr)
{
  struct song_node *old;
  while (ptr)
  {              
    old = ptr;
    ptr = ptr->next; 
    free(old);
  }
  return 0;
}

//trash pile
