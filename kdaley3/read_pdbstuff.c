#include <stdio.h>
#include <stdlib.h>
#define false 0
#define true 1

int open_file(FILE** fd, const char* filename){
	*fd=fopen(filename, "r");
	fseek(*fd, 0, SEEK_END);
	int size=ftell(*fd);
	fseek(*fd, 0, SEEK_SET);
	return size;
}
int read_line(char** line, FILE* fd, int size){
	if(*line==NULL || ftell(fd)==0){
		*line=malloc(size);
	}
	return fgets(*line, 1024, fd);
}
typedef struct{
	int r;
	float x, y, z;
} point3d;
int read_calcium_record(char* line, point3d** point){
		char tmp[1][500];
		int s=0;
		char* subline=NULL;
		int r=0;
		char rstr[200];
		float  x, y, z, dummy;
		if(strstr(line,"ATOM")==line || strstr(line, "HETATM")==line){
			if(subline=strstr(line, "CA")){
		 	s=sscanf(subline,"%s %s %s %d %lf %lf %lf %lf %lf %s %lf %lf %lf %lf %s"	,tmp, tmp, tmp, &r, &x, &y, &z, &dummy, &dummy, &tmp, &dummy, &dummy, &dummy, &dummy, &tmp);
			printf("\n%d\n",r);
				if(s>7){
					point[0]->r=r;
					point[0]->x=x;
					point[0]->y=y;
					point[0]->z=z;
			#ifndef DEBUG_OFF
				//printf("%s\n",line);
				//printf("%f %f %f", point->x, point->y, point->z);
			#endif
				return true;
				}
			}
		}
		return false;
}
float dist(point3d x, point3d y){
	float dx=x.x-y.x;
	float dy=x.y-y.y;
	float dz=x.z-y.z;
	return sqrt(dx*dx+dy*dy+dz*dz);
}


int main(int argc, char** argv){
	FILE* fd;
	int fsize=open_file(&fd, argv[1]);
	point3d* point_array=malloc(fsize/4*sizeof(float));
	memset(point_array,0, fsize/4*sizeof(float));
	point3d* point=point_array, *point0=NULL;
	int i=0;
	char* line=NULL;
	printf("residue1, residue2, distance\n");
	while(read_line( &line, fd, fsize)){
		if(read_calcium_record(line, &point)){
			if(point0) {
				printf("%d, %d, %f \n", (*point0).r, (*point).r, dist(*point, *point0));
			}
			point0=point;
			point+=sizeof(point);

			++i;
		}
	}
	printf("\n there are %d total records. \n", i);
	fclose(fd);
	return 0;
}

