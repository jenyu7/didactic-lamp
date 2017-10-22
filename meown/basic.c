//add headers!!

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

//finds the index of a letter in the alphabet
int index_of(char* s) {
  char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

  //finding the first occurence of the lowercase of the first character
  char *ptr = strchr(alphabet, tolower(*s));

  //find the address difference
  return ptr - alphabet;
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

//bad name
void print_first_char(struct song* lib[], char* first_char) {
  print_list(lib[index_of(first_char)]);
}

// void print_artist(struct song* lib[], char* artist) {
//   //respective alphabet list
//   struct song* current = lib[index_of(artist)];
//   while (current) {
//     if (strcmp(current->artist, artist)) {
//
//     }
//   }
// }


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

struct song* song_at(struct song* list, int n) {
  int count = 0;
  while(count != n) {
    list = list->next;
    count++;
  }
  return list;
}

int list_length(struct song* list) {
  int count = 0;
  while (list) {
    count++;
    list = list->next;
  }
  return count;
}
