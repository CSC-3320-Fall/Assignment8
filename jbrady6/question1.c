#include <stdio.h>
#include <stdlib.h>

/* John Brady
** CSC 3320
** Assignment 8
** Question #1 
*/



int main(int argc, char **args)
{
	FILE *fp;
	fp = fopen(args[1], "r");

	char temp[4];
	char line[80];
	int ATOM = 0;
	int HETA = 0;

	if(argc <= 1)
	{
		printf("Please enter a file to scan!!!\n");
		exit(-1);
	}
	else
	{
		while(!feof(fp))
		{
			fgets(line, sizeof(line), fp);
			sscanf(&line[0], "%4s", temp);
			if(strcmp(temp, "ATOM") == 0)
			{
				ATOM++;
			}
			if(strcmp(temp, "HETA") == 0)
			{
				HETA++;
			}
		}
	}
	printf("There are %d ATOM records.\nThere are %d HETATM records.\n", ATOM, HETA);
	fclose(fp);
}
