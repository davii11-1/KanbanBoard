#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice=1;
    FILE * filePtr;

    while(choice != 6) //Terminates when the quit option is selected
    {
        printf("Menu:\n");
        printf("1. Display board\n");
        printf("2. Load board from a file\n");
        printf("3. Edit list\n");
        printf("4. Edit Board\n");
        printf("5. Save board to a file\n");
        printf("6. Quit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        while(choice < 1 || choice > 6)
        {
            printf("\nEnter your choice again (1-5): ");
            scanf("%d", &choice);
        }

        switch(choice)
        {
            case 1:
                //Function to display template board
                break;
            case 2:
                //Function to load a board from a file
                break;
            case 3:
                //Function to edit list
                break;
            case 4:
                //Function to edit board
                break;
            default:
                //Function to save board to a file
                break;
        }

    }


}