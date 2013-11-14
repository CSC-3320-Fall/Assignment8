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


typedef struct {
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
	FILE *input = fopen( argv[1], "r" );

	//If the file isn't found, print an error message and exit program
	if ( input == NULL )
        {
                perror ( "\nUnable to open file. Please try again.\n\n" );
                exit ( -1 );
        }

	//Allocate an array to take in the lines from file
	char line[1000];

	point ca1, ca2 = { 0.0 , 0.0 , 0.0 };

	int j = 1;

	while(fgets( line, sizeof(line), input ) != 0)
	{
		
		//if 3rd field is "CA", find and store ca2.x, ca2.y, ca2.z (field7-9) 
		//if ( ca2.x == 0.0 ) { ca2 = ca1; continue; }
			
		double k = Distance( ca1, ca2 );
		printf( "The distance between CA %d and CA %d is %d" , j , (j+1) , k );
		j++;		
	}
		
	fclose( input );	
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

