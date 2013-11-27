#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[])
{
    if (argc != 2)
    {
        printf("You forgot to specify your input file.\n");
    }
    else
    {
    int count = 0, count2 = 0, count3 = 0;
    char input[200], one[20];
    
    FILE *file;
    file = fopen(argv[1] , "r");
    
    
    while ( fgets(input, 200, file) != 0)
    {
        fscanf(file, "%s ", one);
        
        if(strcmp(one, "ATOM") == 0 || strcmp(one, "HETATM") == 0)
        {
            count++;
        }
        if(strcmp(one, "ATOM") == 0)
        {
            count2++;
        }
        if(strcmp(one, "HETATM") == 0)
        {
            count3++;
        }
    }
    printf("Number of ATOM records is %d\n",count2);
    printf("Number of HETAM records is %d\n",count3);
    printf("Number of ATOM and HETAM records is %d\n",count);
    fclose(file);
    }
}
