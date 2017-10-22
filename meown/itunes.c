#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "head.h"


int main() {
  printf("--------Initializing Song Library--------\n\n");
  //27 because we want the last one to be null
  struct song* songlib [27] = {0};

  print_lib(songlib);
  printf("\n--------Adding Songs--------\n\n");
  insert_order(songlib , "Feel It Still", "Portugal the Man");
  insert_order(songlib , "Houdini", "Foster the People");
  insert_order(songlib, "I Would Do Anything For You", "Foster the People");
  insert_order(songlib, "Under Cover of Darkness", "The Strokes");
  insert_order(songlib, "Is This It", "The Strokes");
  insert_order(songlib, "Helena Beat", "Foster the People");
  insert_order(songlib, "Countdown", "Beyonce");
  insert_order(songlib, "Last Nite", "The Strokes");
  insert_order(songlib, "1979", "The Smashing Pumpkins");
  //print_lib(songlib);
  insert_order(songlib, "Pink Lemonade", "The Wombats");

  print_lib(songlib);

  printf("\n\nFinding an artist: 'The Strokes'\n\n");
  print_list(find_artist(songlib, "The Strokes"));

  printf("\n\nFinding songs ONLY by 'The Strokes'\n\n");
  print_artist(songlib, "The Strokes");

  printf("\n\nFinding entries in 'J' index\n\n");
  print_letter(songlib, "j");

  printf("\n\nFinding entries in 'T' index\n\n");
  print_letter(songlib, "t");

  printf("\n\n--------Everyday I'm Shuffling--------\n\n");
  shuffle_lib(songlib);

  printf("\n\nRemoving 'Houdini' by Foster the People\n\n");
  remove_node(songlib, "Foster the People", "Houdini");
  print_lib(songlib);

  printf("\n\nRemoving 'Countdown' by Beyonce\n\n");
  remove_node(songlib, "Beyonce", "Countdown");
  print_lib(songlib);

 
  printf("\n\nRemoving all songs from library\n\n");
  free_lib(songlib);
  print_lib(songlib);

  

  return 0;
}
