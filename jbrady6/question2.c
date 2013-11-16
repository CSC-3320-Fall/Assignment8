#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* John Brady
** CSc 3320
** Assignment 8
** Question 2
** This code does not work yet and I didn't even mean to upload it. I loathe having
** to use github to submit homework. I don't know how to remove the stupid file.
** So I'm going to try and fix it and then resubmit it later. 
*/

int main(int argc, char **args)
{
	FILE *theINPUT;
	theINPUT = fopen(args[1], "r");

	FILE *theOUTPUT;
	theOUTPUT = fopen("theOUTPUT.csv", "w");

	int counter = 0;
	char temp[4];
	char line[80];

	char tempCA[2];
	
	char currentX[7];	
	char previousX[7];
	
	char currentY[7];
	char previousY[7];

	char currentZ[8];
	char previousZ[8];

	char firstResidue[3];
	char secondResidue[3];
	

	if(argc<=1)
	{
		printf("Please enter a file to scan!!\n");
		exit(-1);
	}
	else
	{
	while(!feof(theINPUT))
	{
		fgets(line, sizeof(line),theINPUT);
		sscanf(&line[0], "&4s", temp);
		sscanf(&line[13], "&2s", tempCA);
		sscanf(&line[32], "&6s", currentX);
		sscanf(&line[40], "&6s", currentY);
		sscanf(&line[47], "&7s", currentZ);
		sscanf(&line[23], "&3s", firstResidue);

	if(((strcmp(temp, "ATOM")==0)||(strcmp(temp, "HETA")==0))&&(strcmp(tempCA, "CA")==0))
	{
		counter++;

		if(counter % 2 == 0)
		{
			float X1 = atof(currentX);
			float X2 = atof(previousX);
			
			float Y1 = atof(currentY);
			float Y2 = atof(previousY);
			
			float Z1 = atof(currentZ);
			float Z2 = atof(previousZ);

			float firstRes = atof(firstResidue);
			float secondRes = atof(secondResidue);
		
			float distance;
			distance = (pow((X1-X2),2) + pow((Y1-Y2),2) + pow((Z1-Z2),2));
		
			fprintf(theOUTPUT, "%s,%d,%d,%f\n","BALLS", firstRes, secondRes, distance);
		}//ends count if

		strcpy(previousX, currentX);
		strcpy(previousY, currentY);
		strcpy(previousZ, currentZ);
		strcpy(firstResidue, secondResidue);
	}//ends first if

	}//ends while
	}//ends else

	fclose(theINPUT);
	fclose(theOUTPUT);

}//ends main
