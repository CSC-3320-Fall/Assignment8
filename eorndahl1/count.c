#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
    FILE *f;
    char scan[1000];
    int count = 0;
    
    f = fopen("/Users/eorndahl/HW8/4HKD.pdb" , "r");
    
    while ( fgets( scan, sizeof(scan), f) !=NULL) {
        fscanf(f,"%10s",scan);
        if(strcmp(scan, "ATOM") == 0 || strcmp(scan, "HETAM") == 0) {
            count++;
         }
    }
    fclose(f);
    printf("The number of ATOM / HETATM records is %d.\n", count);
}
