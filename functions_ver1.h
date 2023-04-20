/*
 * This is the head file of all the functions I used in our main file.
 */

//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Definition of structs
struct List
{
    char name[20];
    struct List *next;
    struct List *prev;
    struct Item *first_item;
}List;

struct Item
{
    char name[20];
    struct Item *prev;
    struct Item *next;
}Item;

//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//All functions about "List"
struct List* ListFind(struct List *p,char* name);

void Edit_list(struct List *p ,char* lastname ,char* newname);

struct List* Create_Node_List(char* name);

void ListPushBack(struct List *p, char* name);

//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//All functions about "Item"
struct Item* ItemFind(struct List *p,char* name);

void ItemPushBack(struct List *p, char* name);

void Edit_item(struct List *p ,char* lastname ,char* newname);

void Delete_item(struct List* p,struct Item* pos);

struct Item* Create_Node_Item(char* name);

//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//All functions about the whole board
void printLinkedlist(struct List *p);


