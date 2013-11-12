#include <stdio.h>
#include <stdlib.h>

/* "Problem1.c" - author: Mark Hays
 *  CSC 3320, rwh, assignment 8 due November 12, 2013
 *	This program is used to calculate how many HETATM and ATOM records are in the
 *	4KHD file provided by Dr. Harrison. Runs without args, asks user for file path.
 *		*first attempt, may try to make it more efficient later*
 */

int main() {
	
	/*Declaring search strings and setting count integers for each to zero*/
	char str1[] = "ATOM";
	int atomCount = 0;
	
	char str2[] = "HETATM";
	int hetatmCount = 0;
	
	/*get user input for file, didn't want to deal with args yet*/
	printf("Enter file path to read from: \n");
	char f[50];
	scanf("%s",&f);
	FILE *file = fopen(f,"r");
	
	char str[40];	/* string to be evaluated as first string in each line in loops*/
	
	/* I know this is probably quite inefficient, but did 2 separate loops for
	 * each count (ATOM & HETATM), */
	while ( !feof(file)) {
		fscanf(file,"%s%*[^\n]",str);		//got "%s%*[^\n]" from StackOverflow
		int i;
		
		for(i=0;i<sizeof(str);i++) {
			
			if ( str[i]!=str1[i] )		
				break;
			else if (str[i]=='\0')		/* if '\0' was reached, str = ATOM */
				atomCount++;
				
		}
	}
	
	/*go back to beginning of file*/
	rewind(file);
	
	while ( !feof(file)) {
		fscanf(file,"%s%*[^\n]",str);
		int i;
		
		for(i=0;i<sizeof(str);i++) {
			
			if ( str[i]!=str2[i] )
				break;
			else if (str[i]=='\0')		/* if '\0' was reached, str = HETATM */
				hetatmCount++;		
			
		}
	}
	
	printf("ATOM records: %d\n",atomCount);
	printf("HETATM records: %d\n",hetatmCount);

	
	fclose(file);
}