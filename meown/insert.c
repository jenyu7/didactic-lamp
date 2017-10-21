//inserts a song node at the front of a linked list
struct song* insert_front(struct song* curr_list, struct song* song) {
  song->next = curr_list;
  return song;
}

//inserts a song node in the correct alphabetical order
struct song* insert_order(struct song* songs, struct song* new_song) {
  //int ind = index_of(new_song->name[0]);
  //if(!songlist->next
  struct song* curr_song = (struct song *)malloc(sizeof(struct song*));
  curr_song = songs;
  //printf("Que pasa\n");
  while (curr_song && strcmp(new_song->artist, curr_song->artist) < 0) {;
    //ignore
    //printf("%d\n", *curr_song->name); //segfault here
    //printf("%d\n", *curr_song->artist); //segfault here
    //printf("%d\n", *curr_song->next); //segfault here

    curr_song = curr_song->next;
  }
  //insert, keep track of nodes in front and behind
  struct song *p = curr_song->next;
  curr_song->next =  new_song;
  new_song->next = p;
  songs = curr_song;
  return songs;
}

//Matches song title & artist
struct song* find(struct song*playlist, char *song_name, char *artist){
  while (playlist){
    if (strcmp(name, playlist->name) == 0 && strcmp(artist, playlist->artist) == 0)
      return playlist;
    playlist = playlist->next;
  }
  return 0;
}

//Matches an artist
struct song* find_song(struct song*playlist, char *artist){
  while (playlist){
    if (strcmp(artist, playlist->artist) == 0)
      return playlist;
    playlist = playlist->next;
  }
  return 0;
}
