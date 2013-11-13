#include <stdio.h>
#include <stdlib.h>
#include <math.h>




int main(int argc, char **argv) {
	char buffer[1000];
	int atom=0;
	int hetatm=0;
	//char line[1000];
	char tmp[40];
	double x[1500];  double y[1500]; double z[1500]; double dx[750];//double op1[3]; double op2[3];
	int j = 0;
	while (fgets(buffer, sizeof(buffer), stdin )!= (char*) 0) {
		if(buffer[0]=='A' && buffer[1]=='T' && buffer[2]=='O') {
			if(buffer[13]=='C'&&buffer[14]=='A') {
				int i;
				for(i=26; i<55;i++) {
					tmp[i-26]=buffer[i];					
					atom++;
				}
				sscanf(tmp, "%lf %lf %lf",&x[j], &y[j], &z[j]);
			//	printf("match % 2d: x = %lf; y = %lf; z = %lf;\n", j, x[j], y[j], z[j] );
				j++;
			}
		}
		else if(buffer[0]=='H' && buffer[1]=='E'&& buffer[2]=='T' && buffer[3]=='A') {
			if(buffer[13]=='C'&&buffer[14]=='A') {
				int i;
				for(i=26; i<60;i++) {
					tmp[i-26]=buffer[i];					
				}
				sscanf(tmp, "%lf %lf %lf", &x[j], &y[j], &z[j]);
				hetatm++;
				//printf("match % 2d: x = %lf; y = %lf; z = %lf;\n", j, x[j], y[j], z[j] );
				j++;
			}
		}
	}
	int k;
	//for( k=0; k<j; k++ ) { printf("match % 2d: x = %lf; y = %lf; z = %lf;\n", k, x[k], y[k], z[k] ); }
	for( k=0; k<j-1; k++){
		dx[k]=x[k]-x[k+1];
		dx[k]=fabs(dx[k]);
		printf( "CA%d & CA%d= %lf,", k+1,k+2, dx[k]);
	}
	return 0;
}				
			
