#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_MAX 1000
#define STR_LEN 6

/*Copy the contents of the first 6 characters of the line to
 * a substring. Count the number of instances of ATOM and HETATM
 * strings in the document. Output to stdout.*/

int main(int argc, char *argv[])
{
        FILE *ip;
        if (argc != 2)
        {
                printf("usage: ./01 <filename>\n");
                exit(EXIT_FAILURE);
        }
        if (( ip = fopen(argv[1], "r")) == NULL)
        {
                printf("%s can't be opened.\n", argv[1]);
                exit(EXIT_FAILURE);
        }//code snippet from [King] ch22.

	char line[LINE_MAX];
	char substring[STR_LEN + 1];

	int count = 0;
	while(fgets(line, sizeof(line) , ip) != (char *)0){
			strncpy(substring, line, 6);
			if(strcmp(substring, "ATOM  ") == 0) count++;
			if(strcmp(substring, "HETATM") == 0) count++;
			
		}

    fclose(ip);
    printf("%d\n", count);
	return 0;
}