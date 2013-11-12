#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *file;
	//handle any errors while opening the file	
	if ( argc != 2 )
	{
		printf( "usage: %s filename", argv[0] );
	}
	else if ((file = fopen(argv[1], "r")) == NULL)
    	{
		perror("Error opening file");
		return(-1);
	}
	else
	{
		//various variables
		char str[100], substr[6];
        	int count1 = 0, count2 = 0, count3 = 0;
		//read from the file line by line
		while(fgets(str, 100, file) != NULL)
		{
			//increment the appropriate variables
			strncpy(substr, str, 6);
			if(strcmp(substr, "ATOM  ")==0 || strcmp(substr, "HETATM")==0)
				count1++;
			if(strcmp(substr, "ATOM  ")==0)
				count2++;
			if(strcmp(substr, "HETATM")==0)
				count3++;
		}
		fclose(file);
		//print the results
		printf("Number of ATOM files: %d\nNumber of HETATM files: %d\nNumber of ATOM and HETATM files: %d\n",count2,count3,count1);
		return 0;
	}
}
