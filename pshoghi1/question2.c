#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10

int main(int argc, char *argv[])
{
  
  char str1[MAX_LEN +1];
  FILE *fp;//pointer to the file
  fp = fopen (argv[1], "r"); // open the file
  
   int res= 0; // check for the end of the file
   int ATOM_counter = 0,HETATM_counter = 0; // counters

   res = fscanf(fp, "%10s", str1); // reading the file as the initialization process.
   
   while (res != -1)
   { 
             if (strncmp(str1,"ATOM", 4) == 0)
             {// comparing the items
                       ATOM_counter++;                        
             } 
             else if (strncmp(str1,"HETATM", 6) == 0)
             {
                   HETATM_counter++; // counting
             }
             
             res = fscanf(fp, "%10s", str1);
   }

   printf("ATOM # %d - HETATM # %d\n",ATOM_counter,HETATM_counter );
   fclose(fp); // closing the file

  system("PAUSE");	
  return 0;
}


