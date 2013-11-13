#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char **argv)
{

char buffer[1000];
int atom=0;
int hetatm=0;
char line[1000];
char tmp[40];
double x[1000];  double y[1000]; double z[1000]; double dx[500];double op1[3]; double op2[3];
int j=0;
while (fgets(buffer, sizeof(buffer), stdin )!= (char*) 0)
{
	 
		if(buffer[0]=='A' && buffer[1]=='T' && buffer[2]=='O')
			{
				//printf("%d",j);
			
				if(buffer[13]=='C'&&buffer[14]=='A'){
						
					int i;
					for(i=26; i<55;i++){
						tmp[i-26]=buffer[i];					
							atom++;
					}
				//printf("%s\n", tmp);
				sscanf(tmp, "%lf %lf %lf", &x[j], &y[j], &z[j]);
				op1[0]=x;op1[1]=y;op1[2]=z
				
				//printf("%lf\n %lf\n %lf\n", x[j], y[j], z[j]);				
				}
		else if(buffer[0]=='H' && buffer[1]=='E'&& buffer[2]=='T' && buffer[3]=='A'){ 
						if(buffer[13]=='C'&&buffer[14]=='A'){
					int i;
					for(i=26; i<60;i++){
						tmp[i-26]=buffer[i];					
					
					}
				sscanf(tmp, "%lf %lf %lf", &x[j], &y[j], &z[j]);
						hetatm++;}
							}
			     			}
						j++;
						
					
					
						}int k;
				for(k=1; k<49; k++){
					dx[k-1]=x[k-1]-x[k];
					//dx[k]=fabs(dx[k]);
					printf("%lf", x[0]);						
					
			
					}	}				
					


