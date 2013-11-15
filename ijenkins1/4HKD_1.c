#include <stdio.h>
#include <iostream>

   int main()   //creating a main method

    {
      FILE *File;         /* My FILE will point to conents in File*/
       int record, nl = 0; /* Initializing my record ATOM and number of lines*/        int record2, nl2 =0;                    
     while((record = getchar()) = ATOM) { /* Finding the name  ATOM record*/  
       if record == "\n" } nl = nl +1;    /*If statement to find ATOM and*/
                                      /*HETATM records and counting the number*/
                                        /*   of lines the have.*/
  }  while((record2 = getchar()) = HETATM) {/* Finding name HETATM record*/
      if record2 == "\n" }  nl2 = n12 +1;   
     File = fopen("4HKD.pdb", "r");     /*Looking up contents in another file*/

     if (File != Null) /*If file is not empty then scanf and print out*/
       {                                  /*the number of lines in each*/     
          fscanf(File, "%s %d", ATOM, HETATM);
               printf("%s\n",nl,nl2);
              fclose(File);

     }

