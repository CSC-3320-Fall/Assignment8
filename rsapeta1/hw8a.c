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
	//Initialize the counting variables
	int atomCount, hetatmCount;
	atomCount = hetatmCount = 0;


	//If an extra argument isn't given, provide the user with the proper usage
	if( argc != 2)
	{
		printf("\nImproper usage.\nProper usage: %s exampleFile.txt\n\n", argv[0]);
		exit(-1); 
	}

	
	//Opens a file from the command line argument provided by user	
	FILE *input = fopen(argv[1], "r");


	//If the file isn't found, print an error message and exit program
	if ( input == NULL )
        {
                perror ( "Unable to open file. Please try again.\n\n" );
                exit (-1);
        }


	//Allocate an array to take in the lines from file
	char line[80], substr[6];	

	
	while (fgets (line, 80, input) != NULL)
	{ 
		if( strcmp("ATOM ", line) == 0 )
			atomCount++;
		if( strcmp("HETATM ", line) == 0 )
			hetatmCount++;
		else printf("%s", line);
	}
		
	fclose(input);	

	printf("\nThe number of occurences of ATOM is %d.", atomCount);
	printf("\n\nThe number of occurences of HETATM is %d.\n\n", hetatmCount);

	return 0;




}
