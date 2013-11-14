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
	
	while(fgets( line, sizeof(line), input) != 0)
	{
		//copy first 6 char to temp, compare and increment
		strncpy(hComp, line, 6);
		if( (strcmp(hComp, "HETATM")) == 0)
			hetatmCount++;
		
		//copy first 4 char to aComp, compare and increment
		strncpy(aComp, line, 4);
		if( (strcmp(aComp, "ATOM")) == 0)
			atomCount++;

		//printf("hComp: %s\n",hComp);		//tester
		//printf("aComp: %s\n",aComp);		//tester
		//printf("%s", line);			//tester
		
	}

		
	fclose(input);	

	printf("\n\tThe number of lines that start with \"ATOM\" is %d.", atomCount);
	printf("\n\n\tThe number of lines that start with \"HETATM\" is %d.\n\n", hetatmCount);

	return 0;




}
