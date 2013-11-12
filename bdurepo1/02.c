#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "02.h"


#define LINE_MAX 1000


float euclidean_distance(point a, point b){
	return sqrtf( pow((b.x-a.x),2.0) + pow((b.y-a.y),2.0) + pow((b.z-a.z),2.0));
}

point set_point(bool located){
	point a = { 0,0.0,0.0,0.0, located };
	return a;
}

int main(int argc, char *argv[])
{
	/*Test if we can open a file to be parsed.*/
	FILE *ip;
	if (argc != 2)
	{
			printf("usage: ./02 <filename>\n");
			exit(EXIT_FAILURE);
	}
	if (( ip = fopen(argv[1], "r")) == NULL)
	{
			printf("%s can't be opened.\n", argv[1]);
			exit(EXIT_FAILURE);
	}
	/*Check if an output file exists*/
	FILE *op = fopen("./output.csv", "r");
	if (op == NULL)
	{
		op = fopen("./out.csv", "w");
	}
	
	/*Initialize a point and create a line buffer
	 * typedef struct point {long resn; float x; float y; float z; bool located;  } point;
	 *  */
	char line[LINE_MAX];
	point p0 = set_point(false);
	
	while(fgets(line, LINE_MAX, ip) != (char *)0){
		
		char field_one[6];
		char field_three[4];
		
		/*Get field values. Parse marker represents the a pointer to a index in the line buffer.*/
		strncpy(field_one, line, 6);
		char *parse_marker = &line[13];
		strncpy(field_three, parse_marker, 3);
		
		/*Confirm that field one is either a ATOM or a HETATM and field three is a CA.*/
		if((strcmp(field_one, "ATOM  ") == 0 \
			|| strcmp(field_one, "HETATM") == 0 )  \
			&& strncmp(field_three, "CA", 2) == 0){
					
					/*If the first point is unset, the initialize it.*/
					if(p0.located == false){
						point p0 = { strtol(&line[23], &parse_marker, 10),
							strtof(parse_marker, &parse_marker),
							strtof(parse_marker, &parse_marker),
							strtof(parse_marker, &parse_marker), true };
							///TODO: need to initialize second point after seting first continue;
							printf("X: %f , Y: %f  Z: %f \n", p0.x, p0.y, p0.z);
							continue;
					}
					
					/*Initialize the second point.*/
						point p1 = { strtol(&line[23], &parse_marker, 10),
							strtof(parse_marker, &parse_marker),
							strtof(parse_marker, &parse_marker),
							strtof(parse_marker, &parse_marker), true };
							printf("X: %f , Y: %f  Z: %f \n", p1.x, p1.y, p1.z);
							printf("\n\n");
					
					
					//printf("X: %f - %f, Y: %f - %f Z: %f - %f \n", p0.x, p1.x, p0.y, p1.y, p0.z, p1.z);
						
					//float measurement = euclidean_distance(p0, p1);
					//printf("%f\n", measurement);
					
					
					/*Reinitialize the values of the second point to be 
					 * that of the first point. */	
					//p1 = p0;
					//p0 = set_point(false);		
			
		}
			
	}
    fclose(ip);
	return 0;
}
