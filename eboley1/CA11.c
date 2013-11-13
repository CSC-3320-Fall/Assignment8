#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//Defining wordcount to find occurences of CA
int wc(char* file_path, char* word){
	FILE *fp;
	int count = 0;
	int ch, len;
	int position[69];	
	int x=1;
	int q =0;	
	int z =1;

//Initialize fp
	if(NULL==(fp=fopen(file_path, "r")))
		return -1;

	len = strlen(word);
	printf("Distance Between:\n");
	for(x=1;;x++){
		int i;
	if(EOF==(ch=fgetc(fp))) break;
	if ((char)ch != *word) continue;
	for (i=1; i<len; ++i){
		if(EOF==(ch = fgetc(fp))) goto end;
		if((char)ch != word[i]){
			
			fseek (fp, 1, SEEK_CUR);
			goto next;
}
}

//When an occurence of CA is found, store position
++count;
position[q] =x;

//Print difference between positions of ordered CA records
if (q<1) 
printf("-----------------\n");
else if (q>0 && q<9)
printf("%d and %d,      %d\n", z,z-1, position[q]-position[q-1]);
else if(q>9) 
printf("%d and %d,    %d\n", z,z-1, position[q]-position[q-1]);
else
printf("%d and %d,     %d\n", z,z-1, position[q]-position[q-1]);


z++;
q++;

//If char does not match word[i]
next: ;
}
//At end of file
end:
	fclose (fp);
	return count;
}

int main (){
	int wordcount = 0;
	wordcount = wc("/home/local/GSUAD/eboley1/4HKD.pdb", "CA ");
	return 0;
}


