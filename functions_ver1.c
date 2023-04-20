/*
 * This is the C file of all the functions I used in our main file.
 */

//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Including necessary head files.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//All functions about "List"
struct List* ListFind(struct List *p,char* name)
{
    struct List* cur = p;
    while(cur != NULL)
    {
        if(strcmp(cur->name,name) == 0)
        {
            return cur;
        }
        else
        {
            cur = cur->next;
        }
    }
    printf("Can't find list\n");
}

void Edit_list(struct List *p ,char* lastname ,char* newname)
{
    while(p != NULL)
    {
        if(strcmp(p->name,lastname) == 0)
        {
            strcpy(p->name, newname);
            return;
        }
        else
        {
            p = p->next;
        }
    }
}

struct List* Create_Node_List(char* name)
{
    struct List* newnode = malloc(sizeof(struct List));
    if (newnode == NULL)
    {
        printf("malloc fail\n");
    }
    else
    {
        strcpy(newnode->name, name);
        newnode->next = NULL;
        newnode->first_item = NULL;
    }
    return newnode;
}

void ListPushBack(struct List *p, char* name)
{
    struct List* newnode = Create_Node_List(name);

    if (p->next == NULL)
    {
        p->next = newnode;
    }
    else
    {
        struct List* cur = p;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = newnode;
    }
}

//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//All functions about "List"

struct Item* ItemFind(struct List *p,char* name)
{
    struct Item* cur = p->first_item;
    while(cur != NULL)
    {
        if(strcmp(cur->name,name) == 0)
        {
            return cur;
        }
        else
        {
            cur = cur->next;
        }
    }
    printf("Can't find the item\n");
}

void ItemPushBack(struct List *p, char* name)
{
    struct Item* newnode = Create_Node_Item(name);
    struct Item* item_name = p->first_item;
    if (item_name->next == NULL)
    {
        item_name->next = newnode;
        newnode->prev = item_name;
    }
    else
    {
        struct Item* cur = item_name;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = newnode;
        newnode->prev = cur;
    }
}

void Edit_item(struct List *p ,char* lastname ,char* newname)
{
    struct Item* list_name = p->first_item;
    while(list_name != NULL)
    {
        if(strcmp(list_name->name,lastname) == 0)
        {
            strcpy(list_name->name, newname);
            return;
        }
        else
        {
            list_name = list_name->next;
        }
    }
}

struct Item* Create_Node_Item(char* name)
{
    struct Item* newnode = malloc(sizeof(struct Item));
    if (newnode == NULL)
    {
        printf("malloc fail\n");
    }
    else
    {
        strcpy(newnode->name, name);
        newnode->next = NULL;
    }
    return newnode;
}

void Delete_item(struct List* p,struct Item* pos)
{
    struct Item* cur = p->first_item;
    while (cur->next != NULL)
    {
        if(strcmp(cur->name,pos->name) == 0)
        {
            break;
        }
        else
        {
            cur = cur->next;
        }
    }
    struct Item* prev = cur->prev;
    struct Item* nex = cur->next;
    if(nex != NULL)
    {
        nex->prev = cur->prev;
    }
    if(prev != NULL)
    {
        prev->next = cur->next;
    }
    else
    {
        p->first_item = nex;
    }
}

//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//All functions about the whole board
void printLinkedlist(struct List *p){
    struct List* ListName = p;
    while (ListName != NULL)
    {
        printf("%s\n", ListName->name);
        struct Item* item = ListName->first_item;
        while(item != NULL)
        {
            printf("    %s\n", item->name);
            item = item->next;
        }
        ListName = ListName->next;
    }
}
