struct List
{
    char name[30];
    struct List *next;
    struct List *prev;
    struct Item *first_item;
};

struct Item
{
    char name[30];
    struct Item *prev;
    struct Item *next;
};

void Option_2(char filename[30], struct List *p);

int binary_file_check(char filename[30]);

void printLinkedlist(struct List *p);

struct List* ListFind(struct List *p,char* name);

void Edit_list(struct List *p ,char* lastname ,char* newname);

void Delete_List(struct List* p,struct List* pos);

struct List* Create_Node_List(char* name);

void ListPushBack(struct List *p, char* name);

void freeAllMemory(struct List *p);
void Option_5(char* filename, struct List *p);

struct Item* ItemFind(struct List *p,char* name);

void ItemPushBack(struct List *p, char* name);

void Edit_item(struct List *p ,char* lastname ,char* newname);

void Delete_item(struct List* p,struct Item* pos);
