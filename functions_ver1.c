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
        newnode->prev = NULL;
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
        newnode->prev = p;
    }
    else
    {
        struct List* cur = p;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = newnode;
        newnode->prev = cur;
    }
}

void Delete_List(struct List* p,struct List* pos)
{
    struct List* cur = p;
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
    struct List* prev = cur->prev;
    struct List* nex = cur->next;
    if(nex != NULL)
    {
        nex->prev = cur->prev;
    }
    else
    {
        prev->next = NULL;
    }
    if(prev != NULL)
    {
        prev->next = cur->next;
    }
    else
    {
        nex->prev = NULL;
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
    if (item_name == NULL)
    {
        p->first_item = newnode;
    }
    else if (item_name->next == NULL)
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
        newnode->prev = NULL;
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
    int count = 0;
    printf("------------------------------------------\n");
    struct List* ListName = p;
    while (ListName != NULL)
    {
        if(count == 0)
        {
            count++;
            ListName = ListName->next;
            continue;
        }
        printf("%s\n", ListName->name);
        struct Item* item = ListName->first_item;
        while(item != NULL)
        {
            printf("    %s\n", item->name);
            item = item->next;
        }
        ListName = ListName->next;
    }
    printf("------------------------------------------\n");
}

//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//All functions about file
int binary_file_check(char filename[])
{
    int found=0;
    int len;
    int indx = 0;
    len = strlen(filename);
    char str[len];
    int binary=0;

    for(int i=0; i < len; i++)
    {
        if(filename[i] == '.') //Fullstop is found
        {
            found = 1;
        }

        if(found == 1) //We then obtain the file extension for later comparison
        {
            str[indx] = filename[i];
            indx+=1;
        }
    }

    str[indx] = '\0'; //Ends the string with the null terminator

    if(strcmp(str,".dat")==0) //If the file extension is one for a binary file we return True .i.e 1
    {
        binary = 1;
    }

    if(strcmp(str,".txt")==0) //If the file extension isn't one for a binary file we return False .i.e 0
    {
        binary = 0;
    }

    return binary;
}

void LoadFile(char filename[20],struct List* list)
{
    FILE * filePtr;
    int read_type;

    read_type = binary_file_check(filename); //Determines if the file is binary or not

    if(read_type==1) //Does a binary read if it's a binary file
    {
        if ((filePtr = fopen(filename, "rb")) == NULL)
        {
            printf("Error: could not open file %s\n", filename); // If the file isn't found we print an error
        }
        else
        {
            char row[20];
            fgets(row,20,filePtr);
            row[strcspn(row, "\n")] = 0; //Delete enter
            strcpy(list->name, row);
            struct List* CurList = list;
            while (fgets(row,20,filePtr) != NULL)
            {
                row[strcspn(row, "\n")] = 0; //Delete enter
                if(strchr(row,'\t') != NULL) // if there is a "tab" which means it is item
                {
                    /*
                     * Delete \t from row.
                     */
                    int k = 0;
                    for (int i = 0; row[i]!='\0'; i++)
                    {
                        if (row[i] != '\t'){
                            row[k++] = row[i];
                        }
                    }
                    row[k] = '\0';
                    ItemPushBack(CurList,row);
                }
                else
                {
                    ListPushBack(CurList,row);
                    CurList = CurList->next;
                }

            }
        }
    }
    else //Does a non-binary read if it isn't a binary file
    {
        if ((filePtr = fopen(filename, "r")) == NULL)
        {
            printf("Error: could not open file %s\n", filename); // If the file isn't found we print an error
        }
        else
        {
            char row[20];
            fgets(row,20,filePtr);
            row[strcspn(row, "\n")] = 0; //Delete enter
            strcpy(list->name, row);
            struct List* CurList = list;
            while (fgets(row,20,filePtr) != NULL)
            {
                row[strcspn(row, "\n")] = 0; //Delete enter
                if(strchr(row,'\t') != NULL) // if there is a "tab" which means it is item
                {
                    /*
                     * Delete \t from row.
                     */
                    int k = 0;
                    for (int i = 0; row[i]!='\0'; i++)
                    {
                        if (row[i] != '\t'){
                            row[k++] = row[i];
                        }
                    }
                    row[k] = '\0';
                    ItemPushBack(CurList,row);
                }
                else
                {
                    ListPushBack(CurList,row);
                    CurList = CurList->next;
                }

            }
        }
    }
    fclose(filePtr);
}

void write_as_file(struct List* list)
{
    FILE* F ;
    F = fopen("Test.dat","wb+");
    struct List* curList = list;
    while(curList != NULL)
    {
        if(strcmp(curList->name, "Blank") == 0)
        {
            curList = curList->next;
            continue;
        }
        fprintf(F,"%s\n\t",curList->name);
        struct Item* curItem = curList->first_item;
        while (curItem != NULL)
        {
            if(curItem->next ==NULL)
            {
                fprintf(F,"%s\n",curItem->name);
                break;
            }
            fprintf(F,"%s\n\t",curItem->name);
            curItem = curItem->next;
        }
        curList = curList->next;
    }
    fclose(F);
}

