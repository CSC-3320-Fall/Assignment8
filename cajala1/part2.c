#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char * argv[])
{
    if (argc != 3)//check number of arguments
    {
        printf("You forgot to specify your input or output file");
    }
    else //continue on
    {
    int count = 0, two = 0, six = 0, residue = 0;
    float seven = 0, eight = 0, nine = 0, x, y, z, distance;
    char input[200], one[20], three[20], four[20], five[20];
    
    FILE *file, *output;
    file = fopen(argv[1] , "r"); //get arguments from command line
    output = fopen(argv[2] , "w");
    
    while ( fgets(input, 200, file) != 0) //read one line at a time
    {
        fscanf(file, "%s %d %s %s %s %d %f %f %f", one, &two, three, four, five, &six, &seven, &eight, &nine); //split up input
        
        if(strcmp(one, "ATOM") == 0 || strcmp(one, "HETATM") == 0) //check if conditions are right
        {
            if(strcmp(three, "CA") == 0)
            {
                if(count < 1) //load values for the first time around
                {
                    residue = six;
                    x = seven;
                    y = eight;
                    z = nine;
                    count++;
                }
                
                else 
                {
                    distance = sqrt((pow((x - seven), 2) + pow((y - eight), 2) + pow((z - nine), 2)));
                    fprintf(output , "%d, %d, %f\n", residue , six , distance);
                    count++;
                    residue = six; //load values after righting to file
                    x = seven;
                    y = eight;
                    z = nine;
                }
                
            }
        }
    }
    
    fclose(file);
    fclose(output);
    }
}

