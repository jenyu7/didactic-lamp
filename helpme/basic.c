//finds the index of a letter in the alphabet
int index_of(char* s) {
  /*
  char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
  
  //finding the first occurence of the lowercase of the first character
  char *ptr = strchr(alphabet, tolower(*s));

  //find the address difference
  int index = ptr - alphabet;
  */
  s = tolower(s);
  return s[0] - 'a';
}

//prints a linked list
void print_lib(struct song* lib[]) {
  int i = 0;
  struct song* list;
  while (lib[i]) {
    list = lib[i];
    while(list)
      {
	printf("%s: %s\n", list->artist, list->name);
	//printf("bug\n");
	list = list->next;
      }
    i ++;
  }
  printf("NULL\n");
}
