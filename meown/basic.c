//add headers!!

#include <ctype.h>
#include <stdio.h>
#include "head.h"

//finds the index of a letter in the alphabet
int index_of(char* s) {
  char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

  //finding the first occurence of the lowercase of the first character
  char *ptr = strchr(alphabet, tolower(*s));

  //find the address difference
  int index = ptr - alphabet;
}

void print_song(struct song* song) {
  printf("%s: %s\n", song->artist, song->name);
}

void print_list(struct song* list) {
  print_list_end(list, 0);
}

void print_list_end(struct song* list, struct song* end)
{
  while(list != end) {
    if (!list){}
    else
      {
	print_song(list);
	list = list->next;
      }
  }
}

void print_lib(struct song* lib[]) {
  int i = 0;
  while(i < 26) {
    print_list(lib[i]);
    i++;
  }
}

int list_length(struct song* list) {
  int count = 0;
  while (list) {
    count++;
    list = list->next;
  }
  return count;
}

struct song* song_at(struct song* list, int n) {
  int count = 0;
  while(count != n) {
    list = list->next;
    count++;
  }
  return list;
}

//prints songlist after finding a specified artist
//NOTE: Does not print the rest of the library, just the ll in the letter
//the artist's name starts with
void print_artist(struct song* lib[], char* artist)
{
  print_artist_help(find_artist(lib, artist), artist);
}

void print_artist_help(struct song* list, char * artist)
{
  struct song* end = create_node(list->next, list->name, list->artist);
  //printf("%p, %p\n", end, list);
  while(end)
    {
      if (strcmp(artist, end->artist)!=0)
	{
	  end->next = 0;
	  break;
	}
      end = end->next;
    }
  
  print_list_end(list, end);
}

void print_letter(struct song* lib[], char* letter)
{
  print_list(lib[index_of(letter)]);
}

void shuffle_list(struct song* list) {
  struct song* current = (struct song*)malloc(sizeof(struct song));
  srand(time(NULL));
  //-1 because index 3 would be null and we want it to print at least one
  int i = rand() % list_length(list);
  int count = 0;
  while(count < list_length(list) && current) {
    current = song_at(list, i);
    print_song(song_at(list, i));
    i = rand() % list_length(list);
    count++;
  }
}

//doesn't work
void shuffle_lib(struct song* lib[]) {
  srand(time(NULL));
  int i = rand() % 2;
  int prev = -1;
  while (i != 2) {
    shuffle_list(lib[i]);
    //27 because lib[26] is null and we need that to stop the loop
    prev = i;
    i = rand() % 3;
    printf("@@@@@@@@@@@ i = %d\n", i);
  }
}
