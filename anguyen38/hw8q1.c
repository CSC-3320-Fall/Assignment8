#include <stdio.h>
#include <string.h>

/*Aaron Nguyen
 *CSC 3320 T/TH 1pm - 2:15 pm
 *
 * Question 1 - # of ATOM and HETATM records.
 *
*/

int main(int argc, char **argv)
{
    int atoms = 0; //counter for amount of atom records
    int hetatm = 0; //counter for amount of hetatm records.
    char str2[100]={0x0}; //initilize to 0, storing 1st word in line
    char str[100]={0x0}; //initialize to 0, storing line of words.

    FILE *infile = fopen(argv[1], "r"); //open file supplied in arg 1
    if (infile == NULL) { //if file doesnt exist
        printf("Invalid file, please enter ./program_name file_name\n");
        return 0;
    }

    fseek(infile, 0, SEEK_SET); //search file from the beginning.

    while( fgets (str, sizeof(str), infile) != NULL ) { //get first line of words.
        sscanf(str, "%s", str2); //scan the first string in the line.
        if (strcmp(str2, "ATOM") == 0){ //compare if = ATOM.
        atoms++; //increment atom count
        }
        else if (strcmp(str2, "HETATM") == 0){ //compare if = HETATM
        hetatm++; //increment hetatm count.
        }

    }

    fclose(infile); //close the file.
    printf("There are %d ATOM records. \n", atoms); //print # of atoms
    printf("There are %d HETATM records. \n", hetatm); //print # of hetatm.
    return(0);
}

