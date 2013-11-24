// CSc 3320 T/Th 1:00pm
// Assignment 8.2

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    // Initialize variables
    char lines[100];      		// Array to hold each line
    char file[50];			// For the file name

    // These variables deal with the line columns
    char col0[20], col2[20], col3[20], col4[20];	// Column arrays
    float col6, col7, col8, col9;			// Column arrays
    int col1, col5;					// Column arrays	
    float x, y, z, distance;				// Calculation variables
    int residue;					// Calculation variables
    int count = 1;					// Counter for the while loop

    // Ask the user for the filename to search
    printf ("Please enter the file to read from: ");
    scanf ("%s", &file);

    // Open the file     
    FILE *ip;
    FILE *op;
    ip = fopen(file, "r");
    if (ip == NULL) 
        printf("The file does not exist.\n");
    
    // Open the output.csv file
    op = fopen("output.csv", "w");

    // Read in each line of Dr Harrison's file
    while (fgets(lines, sizeof(lines), ip) !=0) {
        // Per the instructions, use sscanf to check each line for ATOM, HETATM, and CA.
        // I got help on the scanning part but the synopsis is that we treat each column 
        // the same way that we would when writing bash scripts.  So read them in one at a 
        // time to their respective variables defined above, thus making it easy to manipulate them.
        sscanf(lines,"%s %d %s %s %s %d %f %f %f %f", &col0, &col1, &col2, &col3, &col4, &col5, &col6, &col7, &col8, &col9);
        // If it's ATOM or HETATM, and if the line is a CA line ...
        if (((strcmp (col0, "ATOM"))==0 || ((strcmp (col0, "HETATM"))==0)) && (strcmp(col2, "CA")==0)) {
            count++;  
	    // If this is the first row (count%2=0), read in the current row's values	
            if ((count % 2) == 0) { 
                x = col6;
		y = col7;
 		z = col8;
		residue = col5;
            } else {
                count++;
		// Calculate the distance and output it to the csv file
		distance = sqrt((pow((x-col6),2) + pow((y-col7),2) + pow((z-col8),2)));
                fprintf(op, "%d, %d, %f\n", residue, col5, distance);
		// Then swap my values so that distance is counted correctly during the next iteration
		x = col6;
	        y = col7;
                z = col8;
		residue = col5;
            }
        }
    }

    fclose (ip);
    fclose (op);

    return 0;           

}
