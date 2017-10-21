struct song {
  char name[256];
  char artist[256];
  struct song* next;
};

void print_lib(struct song* lib[]);
void find_artist(struct song* lib[], char* artist);
struct song* find_artist_help(struct song* list, char* artist);
struct song* find_song(struct song* playlist, char* song);
void add_song(char name[], char artist[]);
struct song* create_node(struct song* next, char* name, char* artist);
void insert_order(struct song* lib[], char* name, char * artist);
struct song* insert_order_help(struct song* list, char * name, char * artist);  

