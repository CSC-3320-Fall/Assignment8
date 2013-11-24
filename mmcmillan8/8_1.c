// CSc 3320 T/Th 1:00pm
// Assignment 8.1

#include <stdio.h>
#include <stdlib.h>

int main() {

    // Initialize variables
    char lines[100];      		// Array to hold each line
    char aryATOM[] = "ATOM";		// "ATOM"
    char aryHETATM[] = "HETATM";	// "HETATM"
    int  countATOM = 0, countHETATM = 0;// Counter varibles
    char file[50];			// For the file name
    char str[100];			// For the line comparison

    // Ask the user for the filename to search
    printf ("Please enter the file to read from: ");
    scanf ("%s", &file);

    // Open the file     
    FILE *ip;
    ip = fopen(file, "r");
    if (ip == NULL) 
        printf("The file does not exist.\n");
    
    // Read in each line of Dr Harrison's file
    while (fgets(lines, sizeof(lines), ip) !=0) {
        // Per the instructions, use sscanf to check each line for ATOM and HETATM and
        // increment counts where applicable
        sscanf(lines,"%s",str);
        if ((strcmp (aryATOM, str))==0) {
            countATOM++;
        }
        if ((strcmp (aryHETATM, str))==0) {
            countHETATM++;
        }
    }

    fclose (ip);

    // Print the results    
    printf ("The number of ATOM records is %d.", countATOM);
    printf ("\nThe number of HETATM records is %d.\n", countHETATM);

    return 0;           

}
