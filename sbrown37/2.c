#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main( int argc, char **argv) {
	//printf("%s\n", argv[1]);

	FILE *inputFile;
	inputFile = fopen(argv[1], "r");

	FILE *outputFile;
	outputFile = fopen("output.csv", "w");


	int count = 0;
	char buffer[1000];

	char prevX[7];
	char currX[7];
	char prevY[7];
	char currY[7];
	char prevZ[8];
	char currZ[8];

	char currR[4];
	char prevR[4];

	while( fgets( buffer, sizeof(buffer), inputFile) != (char *)0) {
		//printf("%s", buffer);

		//match enough chars to uniquely identify ATOM and HETATM and CA
		if (((buffer[0]=='A' && buffer[1]=='T') || (buffer[0]=='H' && buffer[3]=='A')) 
			&& (buffer[13] == 'C' && buffer[14] == 'A')) {
			count++;

			//Grab x, y, and z values and residue number
			int i;
			
			for(i=0; i<6; i++)
				currX[i] = buffer[32+i];
			currX[7] = 0;

			for(i=0; i<6; i++)
				currY[i] = buffer[40+i];
			currY[7] = 0;
 
			for(i=0; i<7; i++)
				currZ[i] = buffer[47+i];
			currZ[8] = 0;

			for(i=0; i<3; i++)
				currR[i] = buffer[23+i];
			currR[4] = 0;
			//end grabbing xyz values
			//printf("%s %s %s\n", currX, currY, currZ);
			
			//apply to every other CA record
			//convert string to float
			if (count % 2 == 0) {
				float x1 = atof(currX);
				float x2 = atof(prevX);
				float y1 = atof(currY);
				float y2 = atof(prevY);
				float z1 = atof(currZ);
				float z2 = atof(prevZ);

				int r1 = atof(currR);
				int r2 = atof(prevR);

				//euclidean distance
				float d;
				d = sqrt(pow((x1-x2),2) + pow((y1-y2),2) + pow((z1-z2),2));

				fprintf(outputFile, "%d,%d,%f\n", r2, r1, d);
			}

			//copy current to prev
			//I was going to do this whole thing without string library
			//but I got lazy
			strcpy(prevX, currX);
			strcpy(prevY, currY);
			strcpy(prevZ, currZ);
			strcpy(prevR, currR);
		}
	}

	//close files
	fclose(inputFile);
	fclose(outputFile);
}