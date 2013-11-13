#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 80
#define COL_1 8

int main(int argc, char *argv[])
{
  // Reading item 
  char line[MAX_LEN + 1]; //raw_line
  FILE *fp, *fp_out;//pointer to the file
  fp = fopen ("../4HKD.pdb", "r"); // open the file
  //fp_out = fopen("out.csv","w+"); // output file in CSV format.
  char col_1[COL_1 + 1], col_2[10]; // columns
  int tmp;
  
  while (fgets(line, sizeof(line), fp) != NULL)
  {
          
         sscanf(line,"%s", col_1);//formating the raw_line from the file 
         if (strncmp(col_1,"ATOM", 4) == 0)
         {// comparing the items
         //printf("%8.2d\n",tmp);//?
         sscanf(&line[sizeof(col_1)], " %d %s" ,&tmp, col_2);
         
                                    if (strncmp(col_2,"CA",2)==0)
                                    { 
                                       printf("%s\n", col_2);
                                    }                        
         }
         else if (strncmp(col_1,"HETATM", 6) == 0)
         {
                   if (strncmp(col_2,"CA",2)==0)
                   {                                       
                       printf("%s\n", col_2);
                   }    
         }
  }
  
  
  
  
   
  fclose(fp); // closing the file
  
  system("PAUSE");	
  return 0;
}


