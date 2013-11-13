#include <stdio.h>
#include <string.h>
#include <math.h>
void part2();
int main(int argc, char *argv[]){
        int filenumb,atoms=0,hetatms=0,resnum=0,oldresnum=0; //file count,atom/hetatm count, residue number current/previous
		char line[500],header[6]; //current line being read, ATOM/HET
		float loc[3]={0},oldloc[3]={0}; //arrays for current CA atoms location and previous CA atom
		
		
		for (filenumb=argc;filenumb >1;filenumb--){ //allows for multiple files to be read from arguments
			
			FILE *file1 = fopen(argv[filenumb-1], "r"); //open file for reading
			FILE *outputcsv = fopen("out.txt", "w");  //open output file for part 2
			while(feof(file1)==0){
				fgets(line,500, file1);
				sscanf(&line[0],"%6s",&header); //look for ATOM/HETATM
				
				if (strcmp(header,"ATOM")==0) {
					atoms++;
					part2(outputcsv,line,&loc,&oldloc,&resnum,&oldresnum); //run part 2
					oldloc[0]=loc[0]; //move new data to replace last entry
					oldloc[1]=loc[1];
					oldloc[2]=loc[2];
					oldresnum=resnum;
					
				}
				else if (strcmp(header,"HETATM")==0) {
					hetatms++;
					part2(outputcsv,line,&loc,&oldloc,&resnum,&oldresnum); //same as above
					oldloc[0]=loc[0];
					oldloc[1]=loc[1];
					oldloc[2]=loc[2];
					oldresnum=resnum;
				}
			}
			printf("File %s Atom count = %d\n",argv[filenumb-1],atoms);
			printf("File %s HETAtom count = %d\n",argv[filenumb-1],hetatms);
			atoms=0;
			hetatms=0;
		}
}

void part2(FILE *fp, char line[500],float (*location)[3],float (*oldlocation)[3],int (*resnumb),int *oldresnumb)
{
	float difference[3],distance; 
	char ab[3]; //atom type to check for CA
	sscanf(&line[13],"%3s",&ab);
	if (strcmp(ab,"CA")==0){
		sscanf(&line[32],"%f",location[0]); //x 
		sscanf(&line[40],"%f",location[1]); //y
		sscanf(&line[47],"%f",location[2]); //z
		sscanf(&line[8],"%4i",resnumb); //residue number
		difference[0]=*location[0]-*oldlocation[0]; //find individual axis differences from previous CA atom
		difference[1]=*location[1]-*oldlocation[1];
		difference[2]=*location[2]-*oldlocation[2];
		distance=sqrt(pow(difference[0],2)+pow(difference[1],2)+pow(difference[2],2)); //find distance
		fprintf(fp,"%i,%i,%f\n",*oldresnumb,*resnumb,distance); //write to file
		
	}
}

				