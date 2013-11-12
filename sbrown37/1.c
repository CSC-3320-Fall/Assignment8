#include <stdio.h>
#include <stdlib.h>

int main( int argc, char **argv) {
	//printf("%s\n", argv[1]);

	FILE *fp;
	fp = fopen(argv[1], "r");

	int count = 0;
	char buffer[100];

	while( fgets( buffer, sizeof(buffer), fp) != (char *)0) {
		//printf("%s", buffer);

		//match enough chars to uniquely identify ATOM and HETATM
		if ((buffer[0]=='A' && buffer[1]=='T') || (buffer[0]=='H' && buffer[3]=='A'))
			count++;
	}

	printf("Number of ATOM and HETATM records is: %d\n", count);
}