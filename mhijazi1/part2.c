#include<stdio.h>
#include<math.h>

int main(int nArgs, char *args[]){

if(nArgs!=2)
{
	printf("%s","No File or Too many arguments specifided\n");
	return -1;
}

FILE *read = fopen(args[1],"r");
int nAtom=0;
int nHeta=0;
int index=0;
char input[300];

float cax[300];
float cay[300];
float caz[300];
int can[300];


while ( fgets(input, sizeof(input), read) != NULL ){
	int f=0;
	if ( input[0] == 'A' && input[1] == 'T' && input[2] == 'O' && input[3] == 'M'){
		f=1;
	}
	if ( input[0] == 'H' && input[1] == 'E' && input[2] == 'T' && input[3] == 'A'){
		f=1;
        }
	if (input[13] == 'C' && input[14] == 'A' && f == 1){
		sscanf( &input[23], "%3i", &can[index] );
		sscanf( &input[32], "%f %f %f", &cax[index], &cay[index], &caz[index] );
		index++;
	}

}
fclose(read);

FILE *output;
output = fopen("CAdist.csv", "w");
float distance[300];

for(int i = 0; can[i+1] !=0; i++){
/* distence between two xyz points is:	
	xd = x2-x1
	yd = y2-y1
	zd = z2-z1 
	Distance = SquareRoot(xd*xd + yd*yd + zd*zd)*/
	float x = (cax[i+1] - cax[i]) * (cax[i+1] - cax[i]);
	
	float z = (caz[i+1] - caz[i]) * (caz[i+1] - caz[i]);
	
 	float y = (cay[i+1] - cay[i]) * (cay[i+1] - cay[i]);
	
	float final = (x+z)+y;

	distance[i+1] = (float)sqrt((double)(final));
	fprintf(output, "%i,%i,%3f\n", can[i], can[i+1], distance[i+1] );
}
fclose(output);
printf("%s\n","Done! Check CAdist.csv for results");
return 0;
}
