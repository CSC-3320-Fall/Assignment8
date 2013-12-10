#include<stdio.h>

int main(int nArgs, char *args[]){

if(nArgs!=2)
{
	printf("%s","No File or Too many arguments specifided\n");
	return -1;
}

FILE *read = fopen(args[1],"r");
int nAtom=0;
int nHeta=0;
char input[300];

while ( fgets(input, sizeof(input), read) != NULL ){
	if ( input[0] == 'A' && input[1] == 'T' && input[2] == 'O' && input[3] == 'M'){
		nAtom++;
	}
	if ( input[0] == 'H' && input[1] == 'E' && input[2] == 'T' && input[3] == 'A'){
                nHeta++;
        }
}
fclose(read);

printf("Number of ATOMS: %i, Number of HETATM: %i\n", nAtom,nHeta);
return 0;
}
