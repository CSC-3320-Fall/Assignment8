/*

Make sure to compile with "gcc hw8b.c -lm" for math functionality

Richard Sapeta 001-88-0246
Harrison TR 1:00
Assignment 8

*/



#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct point
{
	double x;
	double y;
	double z;
} point;

double Distance( point ca1 , point ca2 );

int main( int argc, char *argv[] )
{

	//If an extra argument isn't given, provide the user with the proper usage
	if( argc != 2 )
	{
		printf( "\nImproper usage.\n\nProper usage: %s exampleFile.txt\n\n" , argv[0] );
		printf( "Please try again.\n\n" );
		exit( -1 ); 
	}

	//Opens a file from the command line argument provided by user	
	FILE *input = fopen( argv[1] , "r" );
	FILE *output = fopen( "output.csv" , "w" );

	//If the file isn't found, print an error message and exit program
	if ( input == NULL )
        {
                perror ( "\nUnable to open file. Please try again.\n\n" );
                exit ( -1 );
        }

	// Allocate an array to take in the lines and tokens from file
	char line[1000];
	char *token, *tmp;
	point ca1 = { 0 , 0 , 0 }, ca2;

	int j = 0;

	while( fgets( line, sizeof(line), input ) != 0 )
	{
		/* strtok takes a initial input, sets line in memory, sets token
		// equal to the first token. Call strtok on a NULL pointer, 
		// and it will pull subsequent tokens. */
		
		token = strtok( line, " " );			// 1st token in strtok...
		
		
		token = strtok( NULL , " " );			// 2nd token
		if( token == NULL ) { continue; }		// If empty, skip line

		token = strtok( NULL , " " );			// 3rd token!!!
                if( token == NULL ) { continue; }		// If empty, skip line
    

		
		// If 3rd field is "CA", find and store ca2.x, ca2.y, ca2.z (field7-9) 
		
		if ( (strcmp( token , "CA" )) == 0 )		// atom = 3rd column
		{
	
	                token = strtok( NULL , " " );                    // 4th token...
	      	        token = strtok( NULL , " " );                    // 5th token...
                	token = strtok( NULL , " " );                    // 6th token...

	                token = strtok( NULL , " " );                    // 7th token!!!
			ca2.x = atof ( token );				 // x = 7th token

			token = strtok( NULL , " " );                    // 8th token!!!
			ca2.y = atof ( token );				 // y = 8th token

	                token = strtok( NULL , " " );                    // 9th token!!!
			ca2.z = atof ( token );				 // z = 9th token


		/* On initial run, ca1 will be (0,0,0). Therefore, to make a special
		// case for the intial run of the loop, the program checks for 0. If
		// so, set ca1 [distance is calculated with ca2-ca1] equal to ca2
		// and skip the distance calculation and print statement. */
			
			if ( ca1.x == 0 ) 
			{ ca1 = ca2; continue; }	
			 
		// If not initial run, calculate distance and print statement
			
		double k = Distance( ca1 , ca2 );
		fprintf( output, "%g," , k );
				
		}
	}

	fclose(input);	
	return 0;

}

double Distance( point ca1, point ca2 )
{
	double tempx = ca2.x - ca1.x;
	tempx = tempx * tempx; 
	
	double tempy = ca2.y - ca1.y;
	tempy = tempy * tempy;

	double tempz = ca2.z - ca1.z;
	tempz = tempz * tempz;

	double temp = tempx + tempy + tempz;
	double distance = sqrt( temp );

	return distance;
}

