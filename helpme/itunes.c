#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct song {
  char name[256];
  char artist[256];
  struct song* next;
};

void print_list(struct song* list);
struct song* find_artist(char artist[]);
struct song* find_song(char song[]);
struct song* find_first_song(char artist[]);
void add_song(char name[], char artist[]);

int index_of(char* s) {
  char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

  //finding the first occurence of the lowercase of the first character
  char *ptr = strchr(alphabet, tolower(s));

  //find the address difference
  int index = ptr - alphabet;
  return index;
}

void print_list(struct song* list) {
  while (list) {
    printf("%s: %s\n", list->artist, list->name);
    list = list->next;
  }
  printf("NULL\n");
}

struct song* insert_front(struct song* curr_list, struct song* song) {
  song->next = curr_list;
  return song;
}

struct song* insert_order(struct song* songs[], struct song* new_song) {  
  int ind = index_of(new_song->name[0]);
  struct song* curr_song = (struct song *)malloc(sizeof(struct song*));
  curr_song = songs[ind];
  printf("Que pasa\n");
  while (curr_song != 0 && strcmp(new_song->artist, curr_song->artist) < 0) {
     printf("entered loop\n");
     printf("%d\n", strcmp(new_song->artist, curr_song->artist));
     
     curr_song = curr_song->next;
     //printf("Didn't eff up yet\n");
   }
   curr_song = insert_front(curr_song, new_song);
   songs[ind] = curr_song;
   return songs;
}


int main() {
  printf("--------Creating Initial Playlist--------\n\n");
  struct song* songlist[26];
  struct song* songptr = songlist;
  int i;
  for (i = 0; i < 3; i ++)
    {
      songlist[i] = (struct song *)calloc(1 ,sizeof(struct song));
      printf("%s\n", &songlist[i]);
    }
  
  printf("\n--------Songs--------\n\n");
  printf("....'Feel It Still' by Portugal the Man....\n");
  struct song* song1 = (struct song *)malloc(sizeof(struct song));
  strcpy(song1->name, "Feel It Still");
  strcpy(song1->artist, "Portugal the Man");

  printf("....'Houdini' by Foster the People....\n");
  struct song* song2 = (struct song*)malloc(sizeof(struct song));
  strcpy(song2->name, "Houdini");
  strcpy(song2->artist, "Foster the People");

  printf("....'I Would Do Anything For You' by Foster the People....\n");
  struct song* song3 = (struct song*)malloc(sizeof(struct song));
  strcpy(song3->name, "I Would Do Anything For You");
  strcpy(song3->artist, "Foster the People");

  printf("\n--------Adding Songs--------\n\n");
  printf("Hello?\n");
  songptr  = insert_order(songlist, song2);
  // playlist = insert_order(playlist, song3);
  //print_list(playlist);
  print_list(&songptr);
  return 0;
}
