#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
    FILE *ip;
    char line[100];
    int atomcount = 0, hetatmcount = 0;
    
    ip = fopen(argv[1] , "r");
    
    while (fgets(line, sizeof(line), ip) !=NULL) {
        fscanf(ip,"%80s",line);
        if(strcmp(line, "ATOM") == 0) {
            atomcount++;
         }
        if(strcmp(line, "HETATM") == 0) {
            hetatmcount++;
        }
    }
    
    fclose(ip);
    printf("Number of ATOM records is %d.\n", atomcount);
    printf("Number of HETATM records is %d.\n", hetatmcount);
}
