#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "final_functions.h"

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
    return NULL;
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
        if(p->next == NULL)
        {
            p->next = newnode;
            newnode->prev = p;
        }
        else
        {
            struct List*cur = p;
            while (cur->next != NULL) {
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
    return NULL;
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

void ItemPushBack(struct List *p, char* name)
{
    struct Item* newnode = Create_Node_Item(name);
    struct Item* item_name = p->first_item;
    if(item_name->next == NULL)
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


int binary_file_check(char filename[30])
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

    if(     strcmp(str,".dat")==0 ||
            strcmp(str,".bin")==0 ||
            strcmp(str, ".jpg") == 0 ||
            strcmp(str, ".jpeg") == 0 ||
            strcmp(str, ".png") == 0 ||
            strcmp(str, ".gif") == 0 ||
            strcmp(str, ".bmp") == 0 ||
            strcmp(str, ".wav") == 0 ||
            strcmp(str, ".mp3") == 0 ||
            strcmp(str, ".mp4") == 0 ||
            strcmp(str, ".avi") == 0 ||
            strcmp(str, ".mov") == 0 ||
            strcmp(str, ".pdf") == 0 ||
            strcmp(str, ".doc") == 0 ||
            strcmp(str, ".docx") == 0 ||
            strcmp(str, ".xls") == 0 ||
            strcmp(str, ".xlsx") == 0 ||
            strcmp(str, ".ppt") == 0 ||
            strcmp(str, ".pptx") == 0) //If the file extension is one for a binary file we return True .i.e 1
    {
        binary = 1;
    }

    if(     strcmp(str,".txt")==0 ||
            strcmp(str, ".c") == 0 ||
            strcmp(str, ".h") == 0 ||
            strcmp(str, ".py") == 0 ||
            strcmp(str, ".cpp") == 0 ||
            strcmp(str, ".hpp") == 0 ||
            strcmp(str,".java") == 0 ||
            strcmp(str, ".js") == 0 ||
            strcmp(str, ".html") == 0 ||
            strcmp(str, ".css") == 0) //If the file extension isn't one for a binary file we return False .i.e 0
    {
        binary = 0;
    }

    return binary;
}

void Option_2(char filename[30], struct List *p)
{
    FILE * filePtr;
    int read_type;
    unsigned long long int len;
    char list_name[30];
    int found = 0;
    int found2 = 0;
    size_t bytes_read;
    char string[1024];
    size_t i=0;
    struct List * ListFinder;

    read_type = binary_file_check(filename); //Determines if the file is binary or not

    if(read_type==1) //Does a binary read if it's a binary file
    {
        filePtr = fopen(filename, "rb");
        if (filePtr == NULL)
        {
            printf("Error: failed to open the file %s\n", filename); // If the file isn't found we print an error
        }
        else
        {
            while((bytes_read = fread(&string[i], sizeof(char), 1, filePtr)) > 0) //Loop until fread reads no more elements
            {
                if(string[i] == ':') /*If the current character is a colon 
                                    * take all characters up to and including that point and take it as a list*/
                                       
                {
                    if(found2==0) //Gives the head pointer of the lists the information of the first list from the file
                    {
                        string[i+1] = '\0';
                        strcpy(p->name, string);
                        p->prev = NULL;
                        p->next = NULL;
                        p->first_item = NULL;
                        found2=1;
                    }
                    else //We then use the head pointer to add the remaining lists
                    {
                        ListPushBack(p, string);
                    }

                    ListFinder = ListFind(p,string); //Finds the pointer of the list added
                    found = 1;
                    memset(string, '\0', 1024); //Resets the string all to null terminators
                    i = 0; //Resets string index
                }
                else if(string[0] == '\t' && string[i] == '\0') /*If the string's first character is the tab character
                                                                 and the current character is the null terminator we take that string as a item*/
                {
                    if(found == 1) //Gives the head pointer of the items of that particular list the information from the file
                    {
                        ListFinder->first_item = malloc(sizeof(struct Item));
                        strcpy((ListFinder->first_item)->name, string);
                        (ListFinder->first_item)->next = NULL;
                        (ListFinder->first_item)->prev = NULL;
                        found = 0;
                    }
                    else //We then add the remaining items of that particular list using the head pointer
                    {
                        ItemPushBack(ListFinder, string);
                    }
                    memset(string, '\0', 1024); //Resets the string all to null terminators
                    i = 0; //Resets string index
                }
                else
                {
                    i += bytes_read; //If we encounter none of the two above conditions we move index by the amount of elements read
                }
            }
        }
        fclose(filePtr);
    }
    else //Does a non-binary read if it isn't a binary file
    {
        filePtr = fopen(filename, "r");
        if(filePtr == NULL) {
            printf("Error: failed to open the file %s\n", filename); // If the file isn't found we print an error
        }
        else
        {
            while(fgets(list_name,  30, filePtr)) //Loops until fgets can't receive anymore information from the file
            {

               len = strlen(list_name) - 1;
               list_name[len] = '\0'; //Removes the newline character

                if(list_name[len-1] == ':') //Search colon as that differentiates lists and items
                {
                    if(found2==0) //Gives the head pointer of the lists the information of the first list from the file
                    {
                        strcpy(p->name, list_name);
                        p->prev = NULL;
                        p->next = NULL;
                        p->first_item = NULL;
                        found2=1;
                    }
                    else //We then use the head pointer to add the remaining lists
                    {
                        ListPushBack(p, list_name);
                    }

                    ListFinder = ListFind(p,list_name); //Finds the pointer of the list added
                    found = 1;
                }
                else
                {
                    if(found == 1) //Gives the head pointer of the items of that particular list the information from the file
                    {
                        ListFinder->first_item = malloc(sizeof(struct Item));
                        strcpy((ListFinder->first_item)->name, list_name);
                        (ListFinder->first_item)->next = NULL;
                        (ListFinder->first_item)->prev = NULL;
                        found = 0;
                    }
                    else //We then add the remaining items of that particular list using the head pointer
                    {
                        ItemPushBack(ListFinder, list_name);
                    }
                }
            }
        }
        fclose(filePtr); //closes the file
    }

}



void freeAllMemory(struct List *p)
{
    if(p->next == NULL)
    {
        if(p->first_item->next == NULL)
        {
            free(p->first_item);
            free(p);

        }
        else if(p->first_item == NULL)
        {
            free(p);
        }
        else
        {
            struct Item* cur_item = p->first_item;
            while(cur_item->next != NULL)
            {
                cur_item = cur_item->next;
            }

            while (p->first_item->next != NULL) {
                struct Item *old_item = cur_item;
                cur_item = cur_item->prev;
                free(old_item);
            }
            free(p->first_item);
            free(p);
        }
    }
    else
    {
        struct List*cur = p;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }

        struct Item* cur_item = cur->first_item;
        while(cur_item->next != NULL)
        {
            cur_item = cur_item->next;
        }

    while(p->next != NULL) {

        while (cur->first_item->next != NULL) {
            struct Item *old_item = cur_item;
            cur_item = cur_item->prev;
            free(old_item);
        }
        free(cur->first_item);
        struct List* old_list = cur;
        cur = cur->prev;
        free(old_list);
    }
    free(p);

    }
}


void fprintLinkedlist(FILE * filePtr, struct List *p){
    struct List* ListName = p;
    while (ListName != NULL)
    {
        if(strcmp(ListName->name,"Blank") != 0) {
            fprintf(filePtr, "%s\n", ListName->name); //print list name to non-binary file

            struct Item *item = ListName->first_item; //Set pointer of type struct item as the first item of the current list

            while (item != NULL) {
                fprintf(filePtr, "\t%s\n", item->name); //print current item of the current list to the non-binary file
                item = item->next; //Set the item to the next item and repeat the process until there are no items left
            }
        }
        ListName = ListName->next; //Set it to the next list and repeat the process until there are no lists left
    }
}

void fwriteLinkedlist(struct List *p, FILE * filePtr){
    struct List* ListName = p;
    while (ListName != NULL)
    {
        if(strcmp(ListName->name,"Blank") != 0) {
            int len = strlen(ListName->name); //Obtain the length of the list name for the count parameter of fwrite
            fwrite(ListName->name, sizeof(char), len, filePtr); //print list name to binary file
            fwrite("\n", sizeof(char), 1, filePtr);
            struct Item *item = ListName->first_item; //Set pointer of type struct item as the first item of the current list
            while (item != NULL) {
                int len2 = strlen(item->name); //Obtain the length of the item name for the count parameter of fwrite
                fwrite("\t", sizeof(char), 1, filePtr);
                fwrite(item->name, sizeof(char), len2,
                       filePtr); //print current item of the current list to the binary file
                fwrite("\n", sizeof(char), 1, filePtr);
                item = item->next;  //Set the item to the next item and repeat the process until there are no items left

            }
        }
        ListName = ListName->next;  //Set it to the next list and repeat the process until there are no lists left
    }
}

void Option_5(char* filename, struct List *p)
{
    int write_type;
    FILE * filePtr;

    write_type = binary_file_check(filename); //Checks if the file is binary or not

    if(write_type == 1)
    {
        filePtr = fopen(filename, "wb"); //Does a binary write if it's binary
        if(filePtr != NULL)
        {
            fwriteLinkedlist(p, filePtr); //Writes board to binary file
        }
        else
        {
            printf("Error: failed to open the file %s\n", filename); // If the file isn't found we print an error
        }
        fclose(filePtr);
    }
    else
    {
        filePtr = fopen(filename, "w"); //Does a non-binary write if it's not binary
        if(filePtr != NULL)
        {
            fprintLinkedlist(filePtr, p); //Writes board to non-binary file
        }
        else
        {
            printf("Error: failed to open the file %s\n", filename); // If the file isn't found we print an error
        }
        fclose(filePtr);
    }
}
