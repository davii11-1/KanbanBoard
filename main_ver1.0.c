#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

<<<<<<< HEAD
int main()
{
    //Initialize the example board
    struct List* list1 = malloc(sizeof(struct List));
    strcpy(list1->name, "Bro:");
    list1->prev = NULL;
=======
void MainMenu();
void Edit_List_Menu();
void Example_Board(struct List* start_list);
void Edit_Item_Menu();
void Edit_Item_Choice(struct List* list);
void Edit_List_Choice(struct List* list);

int choice = 0;


int main()
{
    setvbuf(stdout, NULL, _IONBF, 0);
    struct List* list2 = malloc(sizeof(struct List));
    list2->next = NULL;
    list2->first_item = NULL;
    struct List* list1 = malloc(sizeof(struct List));
    list1->next = list2;
    list1->prev = NULL;
    list1->first_item = NULL;
    strcpy(list1->name, "Blank");
    list2->prev = list1;
    char str[35];

    while(choice != 6) //Terminates when the quit option is selected
    {
        MainMenu();
        scanf("%d", &choice);

        while(choice < 0 || choice > 6) //Ensures that input is one of the 6 options
        {
            printf("\n1. Display board\n");
            printf("2. Load board from a file\n");
            printf("3. Edit list\n");
            printf("4. Edit Board\n");
            printf("5. Save board to a file\n");
            printf("6. Quit\n");

            printf("\nYou inputted an unavailable option\n");
            printf("Enter your choice again (1-6): ");
            scanf("%d", &choice);
        }

        switch(choice)
        {
            case 1:
                choice = 0;
                //Initialize the example board
                Example_Board(list2);
                printLinkedlist(list1);
                break;
            case 2:
                choice = 0;
                printf("\nEnter filename: ");
                scanf("%s",str); //Takes input of filename
                LoadFile(str,list2); //Function to load a board from a file
                printLinkedlist(list1);
                break;
            case 3:
                choice = 0;
                printf("\nEnter the name of the list to edit: ");
                scanf("%s",str); //Takes input of list
                if(ListFind(list2,str) == NULL)
                {
                    break;
                }
                else if (strcmp(ListFind(list2,str)->name, str) == 0 )
                {
                    choice = 0;
                    Edit_Item_Choice(list2);
                }
                else
                {
                    break;
                }

            case 4:
                choice = 0;
                Edit_List_Choice(list2);
                break;
            case 5:
                choice = 0;
                write_as_file(list1);
                break;
            default:
                break;
        }

    }
    printLinkedlist(list1);
    return 0;
}

void Edit_Item_Choice(struct List* list)
{
    char old_name[20];
    char new_name[20];
    while (choice != 4)
    {
        Edit_Item_Menu();
        switch(choice)
        {
            case 1:
                //Edit an item in the list
                printf("Enter the name of the list to edit: ");
                fgets(old_name,20,stdin);
                old_name[strcspn(old_name, "\n")] = 0;
                printf("Enter the new name for item ' %s ': ",old_name);
                fgets(new_name,20,stdin);
                new_name[strcspn(new_name, "\n")] = 0;
                Edit_list(list,old_name,new_name);
                choice = 0;
                break;
            case 2:
                printf("Enter the name of new item:");
                fgets(new_name,20,stdin);
                new_name[strcspn(new_name, "\n")] = 0;
                ItemPushBack(list,new_name);
                choice = 0;
                break;
            case 3:
                printf("Enter the name of the item to delete: ");
                fgets(new_name,20,stdin);
                new_name[strcspn(new_name, "\n")] = 0;
                Delete_item(list,ItemFind(list,new_name));
                break;
            default:
                break;
        }
    }
}

void Edit_List_Choice(struct List* list)
{
    char old_name[20];
    char new_name[20];
    while (choice != 4)
    {
        Edit_List_Menu();
        switch(choice)
        {
            case 1:
                printf("Enter the name of the list to edit: ");
                fgets(old_name,20,stdin);
                old_name[strcspn(old_name, "\n")] = 0;
                if (ListFind(list,old_name) == NULL)
                {
                    break;
                }
                printf("Enter the new name for list ' %s ': ",old_name);
                fgets(new_name,20,stdin);
                new_name[strcspn(new_name, "\n")] = 0;
                Edit_list(list,old_name,new_name);
                choice = 0;
                break;
            case 2:
                // Add a new list
                printf("Enter the name of new list:");
                fgets(new_name,20,stdin);
                new_name[strcspn(new_name, "\n")] = 0;
                ListPushBack(list,new_name);
                choice = 0;
                break;
            case 3:
                //delete a list
                printf("Enter the name of the list to delete: ");
                fgets(new_name,20,stdin);
                new_name[strcspn(new_name, "\n")] = 0;
                Delete_List(list, ListFind(list,new_name));
                break;
            default:
                break;
        }
    }
}

void MainMenu()
{
    printf("Menu:\n");
    printf("1. Display board\n");
    printf("2. Load board from a file\n");
    printf("3. Edit list\n");
    printf("4. Edit Board\n");
    printf("5. Save board to a file\n");
    printf("6. Quit\n");
    printf("Enter your choice (1-6):");
}

void Edit_Item_Menu()
{
    printf("\nOptions:\n");
    printf("1. Edit an item\n");
    printf("2. Add a new item\n");
    printf("3. Delete an item\n");
    printf("4. Return to main menu\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);
    fgetc(stdin);
}

void Edit_List_Menu()
{
    printf("\nOptions:\n");
    printf("1. Edit the name of a list\n");
    printf("2. Add a new list \n");
    printf("3. Delete a list\n");
    printf("4. Return to main menu\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);
    fgetc(stdin);
}

void Example_Board(struct List* start_list)
{
    strcpy(start_list->name, "Bro:");
>>>>>>> 3dcc862e7508d03c9dff5e3ee3adb03d4ef3d9a8
    struct Item* item1_1 = malloc(sizeof(struct Item));
    strcpy(item1_1->name, "Oculus Pro");
    struct Item* item1_2 = malloc(sizeof(struct Item));
    strcpy(item1_2->name, "Oculus Quest 1");
    item1_1->next = item1_2;
    item1_2->next = NULL;
    item1_1->prev = NULL;
    item1_2->prev = item1_1;
<<<<<<< HEAD
    list1->first_item = item1_1;
=======
    start_list->first_item = item1_1;
>>>>>>> 3dcc862e7508d03c9dff5e3ee3adb03d4ef3d9a8

    struct List* list2 = malloc(sizeof(struct List));
    strcpy(list2->name, "Dante:");
    struct Item* item2_1 = malloc(sizeof(struct Item));
    strcpy(item2_1->name, "Oculus Quest 1");
    struct Item* item2_2 = malloc(sizeof(struct Item));
    strcpy(item2_2->name, "3070 RTX");
    item2_1->next = item2_2;
    item2_2->next = NULL;
    item2_1->prev = NULL;
    item2_2->prev = item2_1;
    list2->first_item = item2_1;

    struct List* list3 = malloc(sizeof(struct List));
    strcpy(list3->name, "Tim:");
    struct Item* item3_1 = malloc(sizeof(struct Item));
    strcpy(item3_1->name, "Oculus Quest 2");
    item3_1->next = NULL;
    item3_1->prev = NULL;
    list3->first_item = item3_1;

    struct List* list4 = malloc(sizeof(struct List));
    strcpy(list4->name, "Nick:");
    struct Item* item4_1 = malloc(sizeof(struct Item));
    strcpy(item4_1->name, "3070 RTX");
    item4_1->next = NULL;
    item4_1->prev = NULL;
    list4->first_item = item4_1;

    list4->prev = list3;
    list3->prev = list2;
<<<<<<< HEAD
    list2->prev = list1;
    list1->prev = NULL;
    list1->next = list2;
    list2->next = list3;
    list3->next = list4;
    list4->next = NULL;

    printLinkedlist(list1);
    Edit_list(list1,"Bro:","BROOO:");
    printf("*----------------------*\n");
    printLinkedlist(list1);
    ListPushBack(list4, "list5:");
    printf("*----------------------*\n");
    printLinkedlist(list1);
    printf("*----------------------*\n");
    Edit_item(list1,"Oculus Pro","WOCAO OP!");
    printLinkedlist(list1);
    printf("*----------------------*\n");
    ItemPushBack(list4,"NEW_item");
    printLinkedlist(list1);
    printf("*----------------------*\n");
    Delete_item(list4, ItemFind(list4,"NEW_item"));
    printLinkedlist(list1);
}

=======
    list2->prev = start_list;

    start_list->next = list2;
    list2->next = list3;
    list3->next = list4;
    list4->next = NULL;
}
>>>>>>> 3dcc862e7508d03c9dff5e3ee3adb03d4ef3d9a8
