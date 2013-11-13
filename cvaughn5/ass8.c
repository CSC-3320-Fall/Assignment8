#include <stdio.h>
#include <string.h>
#include <math.h>
int part2();
void extracredit();
int main(int argc, char *argv[]){
        int filenumb,atoms=0,hetatms=0,resnum=0,oldresnum=0,cacount=0; //file count,atom/hetatm count, residue number current/previous
		char line[500],header[6]; //current line being read, ATOM/HET
		float loc[3]={0},oldloc[3]={0}; //arrays for current CA atoms location and previous CA atom
		float db1[3][50];
		
		for (filenumb=argc;filenumb >1;filenumb--){ //allows for multiple files to be read from arguments
			
			FILE *file1 = fopen(argv[filenumb-1], "r"); //open file for reading
			FILE *outputcsv = fopen("out.txt", "w");  //open output file for part 2
			while(feof(file1)==0){
				fgets(line,500, file1);
				sscanf(&line[0],"%6s",&header); //look for ATOM/HETATM
				
				if (strcmp(header,"ATOM")==0) {
					atoms++;
					cacount=part2(outputcsv,line,&loc,&oldloc,&resnum,&oldresnum,cacount,&db1); //run part 2
					
					
				}
				else if (strcmp(header,"HETATM")==0) {
					hetatms++;
					cacount=part2(outputcsv,line,&loc,&oldloc,&resnum,&oldresnum,cacount,&db1); //same as above
					
				}
			}
			printf("File %s Atom count = %d\n",argv[filenumb-1],atoms);
			printf("File %s HETAtom count = %d\n",argv[filenumb-1],hetatms);
			atoms=0;
			hetatms=0;
			extracredit(&db1);
		}
}

int part2(FILE *fp, char line[500],float (*location)[3],float (*oldlocation)[3],int *resnumb,int *oldresnumb,int count,float (*db1)[3][50])
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
		*oldlocation[0]=*location[0]; //copy new CA values to old for comparison
		*oldlocation[1]=*location[1];
		*oldlocation[2]=*location[2];
		(*db1)[0][count]=*location[0];
		(*db1)[1][count]=*location[1];
		(*db1)[2][count]=*location[2];
		*oldresnumb=*resnumb;
		return (count+1);
	}
	else return count;
}
 void extracredit(float (*db1)[3][50]){
	int i=0,j=0,max=0,distance=0;
	float difference[3]={0};
	FILE *file1 = fopen("bonus.xpm", "w");
	fprintf(file1,"static char * plaid[] = { \"50 50 8 1\",\n \"0 c #ffffff\",\"1 c #1b2246\", \"2 c #287A9C\"");
	fprintf(file1,", \"3 c #289C81\", \"4 c #289C5F\", \"5 c #389C28\", \"6 c #B9CD4B\", \"7 c #C79D34\", \"8 c #C83810\",\n");
	
	for (i=0;i<50;i++){
		fprintf(file1,"\"");
		for (j=0;j<50;j++){
		difference[0]=(*db1)[0][i]-(*db1)[0][j]; //find individual axis differences from previous CA atom
		difference[1]=(*db1)[1][i]-(*db1)[1][j];
		difference[2]=(*db1)[1][i]-(*db1)[1][j];
		distance=(sqrt(pow(difference[0],2)+pow(difference[1],2)+pow(difference[2],2)))/10;
		if (distance>max) max=distance;
		fprintf(file1,"%i ",distance);
		}
		fprintf(file1,"\",\n");
	}
	fprintf(file1,"};");
	
}


				