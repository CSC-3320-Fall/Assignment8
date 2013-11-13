// Jarrod Vega
#include <stdio.h>
#include <string.h>
int main()
{
	FILE *pFile;
	char mystring [100];
	char str [20];
	//Test search words
	char testATOM [] = "ATOM";
	char testHETATM [] = "HETATM";
	//keep count of how may and each word in the file
	int ca = 0;
	int ch = 0;
	//when to end file
	int n = 0;
	
	pFile = fopen ("4HKD.pdb" , "r");
	//check to make sure there is a file
	if (pFile == NULL) perror ("Error opening file");
	else {
		//do while loop to seach each line for key word
		do {
		//fgets takes the first line and sends it to and array
		fgets (mystring , 100 , pFile);
		//sscanf seaches the array for the first sign of a string
		sscanf (mystring , "%s",str );
		//if statements to compare key words to seaches worrds and increment if found
		if((strcmp (testATOM,str)) == 0){ca++;}
		if((strcmp (testHETATM,str)) == 0){ch++;}
		//printf (" ATOM -> %d\n",ca);
		//printf (" HETATM -> %d\n",ch);
		
		n++;
		} while (n != 1164);
		//out put findings
		printf (" ATOM -> %d\n",ca);
		printf (" HETATM -> %d\n",ch);

	fclose (pFile);	
}	
	return 0;

}
