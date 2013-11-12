/*
 * "problem2.c" author: mark hays
 *	
 * CSC 3320, rwh, assignment 8, due Nov 12, 2013
 * program to calculate distances between consecutive Ca atoms in 4HKD file.
 * takes no args, prompts user for file path
 *		*turning it in as is to be guaranteed on time, may make it more efficient*
 *	ALSO: I only have done the distances, didn't do that other part...
 * and it only computes for ATOM records, not HETATM for now.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	char str[40];							//string for reading first string in line
	char line[100];							//char array for each line
	char atomName[20];						//char array for atom name
	
	char atom[5] = "ATOM";					
	char hetatm[7] = "HETATM";
	
	printf("Enter file path to read from: \n");
	char f[50];
	scanf("%s",&f);
	FILE *file = fopen(f,"r");
	
	float x[60];							//array of x coordinates
	float y[60];							//array of y coordinates
	float z[60];							//array of z coordinates
	char caAtoms[60][2];					//proportional to xyz arrays, just stores CA

	int k=0;	//array position counter
	
	while ( !feof(file) ) {
		fscanf(file,"%s%*[\n]",str);
		int i;
		
		for (i=0;i<sizeof(str);i++) {
			if ( str[i] != atom[i] ) 
				break;				//break messes it up...
			
			else if ( str[i] == '\0') { 
				fgets(line,sizeof(line),file);
				
				sscanf(&line[7],"%s",&atomName);			
				if ( atomName[0]=='C' && atomName[1]=='A' ) { 
	
					strcpy(caAtoms[k], atomName);
			
					sscanf(&line[22],"%8f",&x[k]);
					
					sscanf(&line[36],"%8f",&y[k]);
					
					sscanf(&line[43],"%8f",&z[k]);
					
					k++;
				}//endif
				
			}//end elif
			
/*		tried repeating process above for HETATM but couldn't get it quite right	*/
			
		}//endfor
		
	}//endwhile !feof

	/*calculate and print distance between each consecutive pair of Ca atoms*/
	
	int a=0;
	
	while ( (a+1) < k ) {
		
		if (caAtoms[a+1]==NULL)
			break;
		
		float x1,y1,z1;
		float distance;
		
		x1 = ( (x[a+1]-x[a]) * (x[a+1]-x[a] ) );
		y1 = ( (y[a+1]-y[a]) * (y[a+1]-y[a] ) );
		z1 = ( (z[a+1]-z[a]) * (z[a+1]-z[a] ) );
		
		distance = sqrt(x1 + y1 + z1);
		
		printf("Distance between CA %d and CA %d : %f \n",a+1,a,distance);
		a++;
	}
	
	fclose(file);
	
}

