#include <stdio.h>
int main(int argc, char *argv[])
{
    FILE *p; 
    char buf[1000];
    int wordcount;
    p = fopen (argv[0], "r");
    fscanf(p);

    while (fgets(buf,1000, p)!=NULL)
    {
        if((strstr(buf,"ATOM" || "HETATM")) !=NULL){
            wordcount++;
        }
    }
    printf("%s", "There are ");
    printf("%d", wordcount);
    printf("%s", " occurances of HETATM and ATOM.");
    fclose(p);
    return 0;
}