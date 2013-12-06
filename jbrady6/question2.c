/* John Brady
** CSc 3320
** Question 2
** Assignment 8
** Use gcc -o question2 question2.c -lm so the sqrt will work properly.
** It took me a while to figure out why sqrt wasn't being referenced correctly.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, char **args)
{

/*	These set variables. One variable is to READ the
	input file given. The next WRITE to the output file.
*/

FILE *theINPUT;
theINPUT = fopen(args[1], "r");//line 15

FILE *theOUTPUT;
theOUTPUT = fopen("theOUTPUT.csv", "w");


/*	These are all of my declared variables that will be used
	in the program while we're working inside the while loop.
*/ 

char temp[4];
char line[80];//makes a variable for each line to be read.


char currX[7];
char currY[7];
char currZ[8];
char currRes[4];


char prevX[7];
char prevY[7];
char prevZ[8];
char prevRes[4];

char tempCA[3]="CA";

//int counter = 0; This was used as a tester down below.

/*	This argc<=1 if statement just makes sure that
	there is an argument given to actually scan.
	I could've checked to make sure the file was empty
	and for other error messages but it wasn't actually
	required for this homework.
*/

if(argc<=1)
{
	printf("Please enter a file to scan!!!\n");
	return 0;//I had exit(-1) here but it kept giving me erros.
}//ends if argc

else
{/*	This while statement takes the input file and scans it until
	it finds a line that matches ATOM and CA or HETA and CA. Once
	two successive matches are found, it then prints the corresponding
	residue numbers and then calculates the X,Y,Z distance between
	the two. All the data is written to the output file.
 */

	int count = 1;//initializes a counter for the while loop.
	while(!feof(theINPUT))//scans through the input file until it reaches the end of the file.
	{/*	The next three lines take the file in line by line and
		then scan each line at the zero position and then at the 13th position and set those
		resulting strings into variables named temp and tempCA, respectively.
	 */

		fgets(line, sizeof(line), theINPUT);
		sscanf(&line[0], "%4s", temp);
		sscanf(&line[13], "%2s", tempCA);

if(((strcmp(temp,"ATOM")==0) && (strcmp(tempCA,"CA")==0)) || ((strcmp(temp,"HETA")==0) && (strcmp(tempCA, "CA")==0)))
		{/*	This if statement waits until a matching line is found
			and then stores the values.
		 */
			count++;//incrementer for count.

			/* These four lines take the current values as a source
			   and copies them into the destination which are the 
			   previous variables. 
			   char *strcpy(char *dest, const char *src)
				
			   The odd thing is that when I put these inside the next if statement
			   it didn't work properly. It seems to me that the scope would need
			   for the sscanf lines to actually set values to the current variables
			   before the previous variables could receive values but apparently not.
			   Oddly, it still worked and only worked correctly when it was outside
			   of that loop. So I only have them located here by trial and error. It
			   appears that the first pass through this, the previous variables are just
			   given the default value of zero and i'm not sure how to fix this. So the
			   first line of output is not correct. I had to add another if statement as 
			   a bit of a hack to not have the first incorrect line in the output file.
 			   The scope here is really messing with my mind and how the logic is 
			   supposed to work. It almost seems backwards and maybe that's a "c" 
			   thing i'm not aware of.
			*/
			strcpy(prevX, currX);
			strcpy(prevY, currY);
			strcpy(prevZ, currZ);
			strcpy(prevRes, currRes);


			if((count%2)==0)
			{/*	This if statement is used so when two matches are found, then the
				values are manipulated for the output. The sscanf lines here to
				set string values for each of the current variables. Then those
				values are converted to float values. Then those values are used
				to calculate the distance. Then the residue numbers and the distance
				between them are printed to the CSV output file.
			 */
				//counter++; This was only used to test something below.
	
				sscanf(&line[32], "%7s", currX);
				sscanf(&line[40], "%7s", currY);
				sscanf(&line[47], "%8s", currZ);
				sscanf(&line[23], "%4s", currRes);

				float X1 = atof(currX);
				float Y1 = atof(currY);
				float Z1 = atof(currZ);

				float X2 = atof(prevX);
				float Y2 = atof(prevY);
				float Z2 = atof(prevZ);

				int firstRes = atof(currRes);
				int secondRes = atof(prevRes);

				float distance = sqrt(pow((X1-X2),2) + pow((Y1-Y2), 2) + pow((Z1-Z2),2));

				if(count != 2)
				{/* This is here simply because I didn't know why the first line was getting
				    printed with incorrect output. So this is a bit of a hack to get the 
				    printing to start with the second line instead of the first. I even had
				    two put a count variable and counter variable in the printed output to see
				    what was going on but I removed them once it was working properly.
				 */
				fprintf(theOUTPUT, "%d,%d,%f\n", secondRes, firstRes, distance);
				}
			}//ends mod if
		}//ends big if header
	}//ends while
}//ends first else
/*	Close both files.
*/
fclose(theINPUT);
fclose(theOUTPUT);

}//ends main
