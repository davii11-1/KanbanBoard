#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main()
{
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

