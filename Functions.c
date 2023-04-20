#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Functions.h"

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
            (p->next)->prev = p;
        }
        else
        {
            struct List*cur = p;
            while (cur->next != NULL) {
                cur = cur->next;
                }
            cur->next = newnode;
            (cur->next)->prev = cur;

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

    if(strcmp(str,".dat")==0 || strcmp(str,".bin")==0) //If the file extension is one for a binary file we return True .i.e 1
    {
        binary = 1;
    }

    if(strcmp(str,".txt")==0) //If the file extension isn't one for a binary file we return False .i.e 0
    {
        binary = 0;
    }

    return binary;
}

void Option_2(char filename[50], struct List *p)
{
    FILE * filePtr;
    int read_type;
    unsigned long long int len;
    unsigned long long int len2;
    char list_name[30];
    char buffer[100];
    char str[30];
    int i = 0;
    int indx=0;
    int found = 0;
    int found1 = 0;
    int found2 = 0;
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

            while(fread(buffer, sizeof(char), 1, filePtr))
            {

//                fread(list_name, sizeof(char), 1, filePtr);

                len = strlen(buffer) - 1;

                if(buffer[len-1] == ':')
                {
                    if(found2 == 0)
                    {
                        buffer[len] = '\0';
                        strcpy(p->name, buffer);
                        p->prev = NULL;
                        p->next = NULL;
                        p->first_item = NULL;
                        printf("%s-first\n", p->name);
                        found2 = 1;

                    }
                    else
                    {
                        list_name[len] = '\0';
                        ListPushBack(p, list_name);
                        ListFinder = ListFind(p,list_name);
                        printf("%s\n", ListFinder->name);
                    }
                    found1 = 1;
                }

                if(list_name[i] == '\t')
                {
                    found = 1;
                }

                if(found == 1 && list_name[i] != ' ')
                {
                    str[indx++] = list_name[i];
                }
                else
                {
                    if(found1 == 1)
                    {
                        len2 = strlen(str) - 1;
                        str[len2] = '\0';
                        ListFinder->first_item = malloc(sizeof(struct Item));
                        strcpy((ListFinder->first_item)->name, str);
                        (ListFinder->first_item)->next = NULL;
                        (ListFinder->first_item)->prev = NULL;
                        found1 = 0;
                        printf("%s - first\n",(ListFinder->first_item)->name);
                    }
                    else
                    {
                        len2 = strlen(str) - 1;
                        str[len2] = '\0';
                        ItemPushBack(ListFinder, str);
                        struct Item* itemfinder = ItemFind(ListFinder, str);
                        printf("%s\n", itemfinder->name);
                        indx = 0;
                        found = 0;
                    }
                }
                i++;

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

void Option_3(struct List *p){
    char str[30];
    int choice = 0;
    struct List *data;
    struct Item *bool;
    char str2[30];
    char str3[30];

    while (choice != 4) {
        printf("\nOptions:\n");
        printf("1. Edit an item\n");
        printf("2. Add a new item\n");
        printf("3. Delete an item\n");
        printf("4. Return to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);



        while (choice < 1 || choice > 4) {
            printf("\nOptions:\n");
            printf("1. Edit an item\n");
            printf("2. Add a new item\n");
            printf("3. Delete an item\n");
            printf("4. Return to main menu\n");

            printf("You have inputted an unavailable option\n");
            printf("Enter your choice again: ");
            scanf("%d", &choice);
        }

        fflush(stdin); //Clears input buffer, so it can accept string input through fgets
        switch(choice)
        {
            case 1:
                printf("\nEnter the name of the list to edit: ");
                fgets(str, 30, stdin); //Asks for the name of the list where we're editing items and receives input through fgets
                str[strlen(str)-1] = '\0'; //Removes the newline character
                data = ListFind(p, str); //Finds the pointer to the list where we're editing items

                if (data != NULL) //If the list found we proceed with the item editing process
                {
                    printf("\nEnter the name of the item to edit: ");
                    fgets(str3, 30, stdin); //Asks for the name of the item we're editing and receives input through fgets
                    str3[strlen(str3)-1] = '\0'; //Removes the newline character
                    bool = ItemFind(data, str3); //Finds the pointer to the item we want to edit

                    if (bool != NULL)  //If the item to be edited is found we then proceed to the editing the item
                    {
                        printf("\nEnter new name for item '%s': ", str3);
                        fgets(str2, 30, stdin); //Asks for the name of the item to replace the to be edited item and receives input through fgets
                        str2[strlen(str2)-1] = '\0'; //Removes the newline character
                        Edit_item(data, str3, str2); //Replaces the old item with the new item
                    }
                }
                break;
            case 2:
                printf("\nEnter the name of the list to edit: "); //Asks for the name of the list where we're editing items
                fgets(str, 30, stdin); // receives input through fgets
                str[strlen(str)-1] = '\0'; //Removes the newline character
                data = ListFind(p, str); //Finds the pointer to the list where we're adding items

                if (data != NULL) //If the list exits we proceed with the insertion process
                {
                    printf("\nEnter the name of the new item: "); //Asks for the name of the item to be added
                    fgets(str2, 30, stdin); // receives input through fgets
                    str2[strlen(str2)-1] = '\0'; //Removes the newline character
                    ItemPushBack(data, str2); //Adds the new item for the given list
                }
                break;
            case 3:
                printf("\nEnter the name of the list to edit: "); //Asks for the name of the list where we're deleting items
                fgets(str, 30, stdin); // receives input through fgets
                str[strlen(str)-1] = '\0'; //Removes the newline character
                data = ListFind(p, str); //Finds the pointer to the list where we're deleting items

                if (data != NULL) //If the list exits we proceed with the deletion process
                {
                    printf("\nEnter the name of the item to delete: ");
                    fgets(str2, 30, stdin); // receives input through fgets
                    str2[strlen(str2)-1] = '\0'; //Removes the newline character
                    bool = ItemFind(data, str2);

                    if (bool != NULL) //If the item exists we delete the item
                    {
                        Delete_item(data, bool); //Deletes the selected item
                    }
                }
                break;
            default:
                break; //To ensure there isn't any unwanted outputs when the user selects "Quit"
        }
    }
}


void Option_4(struct List *p) {
    char str[30];
    int choice = 1;
    struct List* data;
    char str2[30];


    while(choice != 4) {
        printf("\nOptions:\n");
        printf("1. Edit the name of a list\n");
        printf("2. Add a new list\n");
        printf("3. Delete a list\n");
        printf("4. Return to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        while (choice < 1 || choice > 4) {
            printf("\nOptions:\n");
            printf("1. Edit the name of a list\n");
            printf("2. Add a new list\n");
            printf("3. Delete a list\n");
            printf("4. Return to main menu\n");

            printf("You have inputted an unavailable option\n");
            printf("Enter your choice again: ");
            scanf("%d", &choice);
        }

        fflush(stdin); //Clears input buffer, so it can accept string input through fgets
        switch(choice) {
            case 1:
                printf("\nEnter the name of the list to edit: "); //Asks for the list we want to edit and receives input through fgets
                fgets(str, 30, stdin); // receives input through fgets
                str[strlen(str)-1] = '\0'; //Removes the newline character
                data = ListFind(p,str); //Finds the pointer to the list we want to edit

                if(data != NULL) //If the list is found we procced with the editing process
                {
                    printf("\nEnter new name for list '%s': ", str); //Asks for the new list name
                    fgets(str2, 30, stdin); // receives input through fgets
                    str2[strlen(str2)-1] = '\0'; //Removes the newline character
                    Edit_list(data,str,str2); //Replaces the selected list with the new list
                }
                break;
            case 2:
                printf("\nEnter the name of the new list: "); //Asks for the list we want to add
                fgets(str2, 30, stdin); // receives input through fgets
                str2[strlen(str2)-1] = '\0'; //Removes the newline character
                ListPushBack(p,str2); //Adds the new list to the board
                break;
            case 3:
                printf("\nEnter the name of the list to delete: "); //Asks for the list we want to delete
                fgets(str, 30,stdin); // receives input through fgets
                str[strlen(str)-1] = '\0'; //Removes the newline character
                data = ListFind(p,str); //Finds the pointer to the list where we're deleting items

                if(data != NULL) //If the list is found we proceed with the deletion process
                {
                    Delete_List(p,data); //Deletes the selected list
                }
                break;
            default:
                break; //To ensure there isn't any unwanted outputs when the user selects "Quit"
        }
    }
}

void fprintLinkedlist(FILE * filePtr, struct List *p){
    struct List* ListName = p;
    while (ListName != NULL)
    {
        fprintf(filePtr, "%s\n", ListName->name); //print list name to non-binary file
        struct Item* item = ListName->first_item; //Set pointer of type struct item as the first item of the current list
        while(item != NULL)
        {
            fprintf(filePtr, "\t%s\n", item->name); //print current item of the current list to the non-binary file
            item = item->next; //Set the item to the next item and repeat the process until there are no items left
        }
        ListName = ListName->next; //Set it to the next list and repeat the process until there are no lists left
    }
}

void fwriteLinkedlist(struct List *p, FILE * filePtr){
    struct List* ListName = p;
    while (ListName != NULL)
    {
        int len = strlen(ListName->name); //Obtain the length of the list name for the count parameter of fwrite
        fwrite(ListName->name, sizeof(char), len, filePtr); //print list name to binary file
        fwrite("\n",sizeof(char), 1, filePtr);
        struct Item* item = ListName->first_item; //Set pointer of type struct item as the first item of the current list
        while(item != NULL)
        {
            int len2 = strlen(item->name); //Obtain the length of the item name for the count parameter of fwrite
            fwrite("\t", sizeof(char), 1, filePtr);
            fwrite(item->name, sizeof(char), len2, filePtr); //print current item of the current list to the binary file
            fwrite("\n",sizeof(char), 1, filePtr);
            item = item->next;  //Set the item to the next item and repeat the process until there are no items left

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

