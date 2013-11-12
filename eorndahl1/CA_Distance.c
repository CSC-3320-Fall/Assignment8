#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char** argv)
{
    FILE *f, *out;
    char scan[1000], c0[100], c2[100], c3[100], c4[100];
    int count = 0, c1, c5, residue;
    float c6, c7, c8, x, y, z, distance;
    
    f = fopen("/Users/eorndahl/HW8/4HKD.pdb" , "r");
    out = fopen("/Users/eorndahl/HW8/CSV.txt" , "w");
    
    while ( fgets(scan, sizeof(scan), f) !=NULL) { //scan line by line
        fscanf(f, "%s %d %s %s %s %d %f %f %f", &c0, &c1, &c2, &c3, &c4, &c5, &c6, &c7, &c8);
        //scan each column in to a variable.
        if(strcmp(c0, "ATOM") == 0 || strcmp(c0, "HETAM") == 0) //if ATOM / HETAM...
        {
            if(strcmp(c2, "CA") == 0) { //if third column is CA...
                if(count % 2 == 0) { //if this is the first of two take the first's row's values for later computation.
                    x = c6;
                    y = c7;
                    z = c8;
                    residue = c5;
                    count++;
                } else { //if second compute with first and current values.
//                  printf("x1 = %f x0 = %f\n y1 = %f y0 = %f\n z1 = %f z0 = %f\n", c6, x, c7, y, c8, z); //if you care to check equation values
                    distance = sqrt((pow((x - c6), 2) + pow((y - c7),2) + pow((z - c8), 2))); //cartesian x,y,z distance formula
                    fprintf(out, "%d, %d, %f\n", residue, c5, distance);
                    count++;
                    }

              }
         }
    }
    
    fclose(f);
    fclose(out);
    
return 0;
}
