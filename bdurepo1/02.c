#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "02.h"

#define LINE_MAX 1000

float euclidean_distance(point a, point b){
	return sqrtf( pow((b.x-a.x),2.0) + pow((b.y-a.y),2.0) + pow((b.z-a.z),2.0));
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
	
	FILE *op = fopen("./out.csv", "w");
	
	/*Initialize a point and create a line buffer
	 * typedef struct point {long resn; float x; float y; float z; bool located;  } point;
	 */
	char line[LINE_MAX];
	point current;
	point previous;
	char field_one[6];
	char field_three[4];
	float measurement;
	int count = 0;
	
	while(fgets(line, LINE_MAX, ip) != (char *)0){
		
		/*Get field values. Parse marker represents the a pointer to a index in the line buffer.*/
		strncpy(field_one, line, 6);
		char *parse_marker = &line[13];
		strncpy(field_three, parse_marker, 3);
		
		/*Confirm that field one is either a ATOM or a HETATM and field three is a CA.*/
		if((strcmp(field_one, "ATOM  ") == 0 \
			|| strcmp(field_one, "HETATM") == 0 )  \
			&& strncmp(field_three, "CA", 2) == 0){
				
				count++;	
					/*If the first point is unset, the initialize it.*/
					
					point current = { strtol(&line[23], &parse_marker, 10),
						strtof(parse_marker, &parse_marker),
						strtof(parse_marker, &parse_marker),
						strtof(parse_marker, &parse_marker)};
						
					if (count % 2 == 0 ){
						//printf("current x: %f  previous x: %f \n", current.x, previous.x );
						euclidean_distance(previous, current);
						fprintf(op ,"%d, %d, %f\n", previous.resn, current.resn, euclidean_distance(current, previous) );
					}
					previous = current;		
		}
	}
    fclose(ip);
    fclose(op);
	return 0;
}