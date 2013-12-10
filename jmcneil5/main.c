#include<stdio.h>
#include<math.h>

int main(int nArgs, char *args[]){

//check that there are enough arguments in the command call
if (nArgs != 2){
	printf("file argument needed.\n");
	return -1;
}

FILE *target = fopen(args[1], "r");

//chech that the file opened correctly
if (target == 0){
	printf("Error opening file!\n");
	return -1;	
}

char input[1024];
int atom = 0;
int heta = 0;

float cax[300];
float cay[300];
float caz[300];
int can[300];
int index = 0;

//Read through each line...
while ( fgets(input, sizeof(input), target) != NULL ){
	int flag = 0;
	if ( input[0] == 'A' && input[1] == 'T' && input[2] == 'O' && input[3] == 'M'){
		atom++; //... and count the number of atom records...
		flag = 1;
	}
	if ( input[0] == 'H' && input[1] == 'E' && input[2] == 'T' && input[3] == 'A'){
                heta++; //... and count the number of hetatm records.
		flag = 1;
        }
	if (input[13] == 'C' && input[14] == 'A' && flag == 1){
		sscanf( &input[23], "%3i", &can[index] );
		sscanf( &input[32], "%f %f %f", &cax[index], &cay[index], &caz[index] );
		index++;
	}
}
fclose(target);

//Open a new text document to print CA results after calculating
FILE *output;
output = fopen("cadistances.csv", "w");
int i = 0;
float distance[300];

while (can[i+1] != 0){ //if can[i+1] == 0, there is no entry after this index and no comparison can be made
	float sqx = (cax[i+1] - cax[i]) * (cax[i+1] - cax[i]);
	float sqz = (caz[i+1] - caz[i]) * (caz[i+1] - caz[i]);
	float sqy = (cay[i+1] - cay[i]) * (cay[i+1] - cay[i]);
	
	float sqa = sqx + sqz;
	float sqb = sqy;
	float sqc = sqa + sqb;

	distance[i+1] = (float)sqrt((double)(sqc)); //<< ... putting the double variable into the sqrt function causes a reference error.
	fprintf(output, "%i,%i,%3f\n", can[i], can[i+1], distance[i+1] );
	i++;
}
fclose(output);

//Results
printf( "%i ATOM records.\n%i HETATM records.\n%i CA records.\nCA atom distances recorded in cadistances.csv.\n", atom, heta, index );
}
