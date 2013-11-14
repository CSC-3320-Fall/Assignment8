/*

I will be fixing this code until I have it working and will complete
question 2 and submit them both asap. I am submitting this to show that I have 
been working at it. Thank you.

Richard Sapeta 001-88-0246
Harrison TR 1:00
Assignment 8

*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	//If an extra argument isn't given, provide the user with the proper usage
	if( argc != 2)
	{
		printf("\nImproper usage.\n\nProper usage: %s exampleFile.txt\n\n", argv[0]);
		printf("Please try again.\n\n");
		exit(-1); 
	}

	//Opens a file from the command line argument provided by user	
	FILE *input = fopen(argv[1], "r");

	//If the file isn't found, print an error message and exit program
	if ( input == NULL )
        {
                perror ( "\nUnable to open file. Please try again.\n\n" );
                exit (-1);
        }

	//Allocate an array to take in the lines from file
	char line[1000];	

        //Initialize the counting variables
        int atomCount, hetatmCount;
        atomCount = hetatmCount = 0;
	
	//Strings to compare to HETATM and ATOM, respectively
	char hComp[6];        
        char aComp[4];

	// The strings the program is searching for
	char atom[5] = "ATOM ";
	char hetatm[6] = "HETATM";

	// Every run of while gets a new line from the file
	while(fgets( line, sizeof(line), input) != 0)
	{
		// copy first 6 char to hComp, firs 4 to aComp
		strncpy(hComp, line, 6);
		strncpy(aComp, line, 5);

		// self-explanatory
		if( (strcmp(hComp, hetatm)) == 0)
			hetatmCount++;
		if( (strcmp(aComp, atom)) == 0)
			atomCount++;
	}

	fclose(input);	

	printf("\n\tThe number of lines that start with \"ATOM\" is %d.", atomCount);
	printf("\n\n\tThe number of lines that start with \"HETATM\" is %d.\n\n", hetatmCount);

	return 0;
}
