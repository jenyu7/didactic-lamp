#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "head.h"
//#include "basic.c"
//#include "node.c"


int main() {
  printf("--------Creating Initial Playlist--------\n\n");
  struct song* songlib [26] = {0};

  print_lib(songlib);
  printf("\n--------Adding Songs--------\n\n");
  
  printf("\n--------Adding 'Houdini: Foster the People'--------\n\n");
  insert_order(songlib , "Houdini", "Foster the People");
  //print_lib(songlib);;
  
  printf("\n--------Adding 'I Would Do Anything For You: Foster the People'--------\n\n");
  insert_order(songlib, "I Would Do Anything For You", "Foster the People");
  
  printf("\n--------Adding 'Helena Beat: Foster the People'--------\n\n");
  insert_order(songlib, "Helena Beat", "Foster the People");
  
  printf("\n--------Adding 'Under Cover of Darkness: The Strokes'--------\n\n");
  insert_order(songlib, "Under Cover of Darkness", "The Strokes");
  //print_lib(songlib);
  
  printf("\n--------Adding 'Is This It: The Strokes'--------\n\n");
  insert_order(songlib, "Is This It", "The Strokes");
  print_lib(songlib);

  printf("\n\nFinding 'Foster the People'\n\n");
  find_artist(songlib, "Foster the People");
  print_lib(songlib);

  printf("\n\nFinding 'The Strokes'\n\n");
  find_artist(songlib, "The Strokes");
  print_lib(songlib);
  return 0;
}
