#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Functions.h"

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

void LoadFile(char filename[20])
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
//        else
//        {
/*              else is currently commented out because we require a linked list to
                load the information of the file into */
//        }
    }
    else //Does a non-binary read if it isn't a binary file
    {
        if ((filePtr = fopen(filename, "r")) == NULL)
        {
            printf("Error: could not open file %s\n", filename); // If the file isn't found we print an error
        }
//        else
//        {
/*              else is currently commented out because we require a linked list to
                load the information of the file into */
//        }
    }

}