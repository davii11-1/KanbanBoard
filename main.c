#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Functions.h"


int main()
{
    int choice=1;
    char filename[50];
    int len;
    int prev;
    int i=0;
    struct List *FileListNodePtr = malloc(sizeof(struct List));

    //Initialize the example board
    struct List* list1 = malloc(sizeof(struct List));
    strcpy(list1->name, "Bro:");
    list1->prev = NULL;
    struct Item* item1_1 = malloc(sizeof(struct Item));
    strcpy(item1_1->name, "Oculus Pro");
    struct Item* item1_2 = malloc(sizeof(struct Item));
    strcpy(item1_2->name, "Oculus Quest 1");
    item1_1->next = item1_2;
    item1_2->next = NULL;
    item1_1->prev = NULL;
    item1_2->prev = item1_1;
    list1->first_item = item1_1;

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
    list2->prev = list1;
    list1->prev = NULL;
    list1->next = list2;
    list2->next = list3;
    list3->next = list4;
    list4->next = NULL;


    while(choice != 6) //Terminates when the quit option is selected
    {
        printf("\nMain Menu:\n");
        printf("1. Display board\n");
        printf("2. Load board from a file\n");
        printf("3. Edit list\n");
        printf("4. Edit Board\n");
        printf("5. Save board to a file\n");
        printf("6. Quit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);


        while(choice < 1 || choice > 6) //Ensures that input is one of the 6 options
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
            printf("\n");

        }
        if(i%2 == 0 && choice == 2 || choice == 1) //Makes sure we are using the right board for option 3,4 or 5
        {
            prev = choice;
            i++;
        }
        fflush(stdin); //Clears input buffer, so it can accept string input through fgets

        switch(choice)
        {
            case 1:
                printf("\n");
                printLinkedlist(list1); //prints the template board to user
                break;
            case 2:
                printf("\nEnter filename: ");
                fgets(filename,20,stdin); //Takes input of filename
                len = strlen(filename)-1;
                filename[len] = '\0'; //Removes the newline character
                Option_2(filename,FileListNodePtr); //Loads file into new board
                printLinkedlist(FileListNodePtr);
                break;
            case 3:
                if(prev == 1) //Uses template board if 1 was the last choice between 1 and 2
                {
                    Option_3(list1); //Function to edit items in a given list
                }
                else if(prev==2)  //Uses loaded board if 2 was the last choice between 1 and 2 in the template board
                {
                    Option_3(FileListNodePtr); //Function to edit items in a given list in the file loaded board
                }
                else //Uses template board by default if the last choice between 1 and 2 isn't either 1 or 2
                {
                    Option_3(list1);  //Function to edit items in a given list in the template board
                }
                break;
            case 4:
                if(prev == 1) //Uses template board if 1 was the last choice between 1 and 2
                {
                    Option_4(list1); //Function to edit the lists on the template board
                }
                else if(prev == 2) //Uses loaded board if 2 was the last choice between 1 and 2
                {
                    Option_4(FileListNodePtr); //Function to edit the lists on the file loaded board
                }
                else //Uses template board by default if the last choice between 1 and 2 isn't either 1 or 2
                {
                    Option_4(list1); //Function to edit the lists on the template board
                }
                break;
            case 5:
                printf("\nEnter filename: ");
                fgets(filename,20,stdin); //Takes input of filename
                len = strlen(filename)-1;
                filename[len] = '\0'; //Removes the newline character

                if(prev == 1) //Uses template board if 1 was the last choice between 1 and 2
                {
                    Option_5(filename, list1); //Function to write template board to file
                }
                else if(prev==2) //Uses loaded board if 2 was the last choice between 1 and 2
                {
                    Option_5(filename, FileListNodePtr); //Function to write file loaded board to file
                }
                else //Uses template board by default if the last choice between 1 and 2 isn't either 1 or 2
                {
                    Option_5(filename, list1); //Function to write template board to file
                }
                break;
            default:
                break; //To ensure there isn't any unwanted outputs when the user selects "Quit"
        }

    }

    return 0; //Terminates the program
}