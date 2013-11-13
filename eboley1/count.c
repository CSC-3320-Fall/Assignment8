#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Create wordcount function
int wc(char* file_path, char* word){
	FILE *fp;
	int count = 0;
	int ch, len;

//Initialize fp
	if(NULL==(fp=fopen(file_path, "r")))
		return -1;

	len = strlen(word);
	
//Execute loop until end of file
	for(;;){
		int i;
	if(EOF==(ch=fgetc(fp))) break;
	if ((char)ch != *word) continue;
	for (i=1; i<len; ++i){
		if(EOF==(ch = fgetc(fp))) goto end; 	

//If current char does not match, move on to next char. i resets on next pass through for loop to search for first character in word.
		if((char)ch != word[i]){
			fseek (fp, 1, SEEK_CUR);
			goto next;
}
}
//If ch==*word
++count;
//Executes when no match
next: ;
}
//At end of file
end:
	fclose (fp);
	return count;
}
//Wordcount on 4HKD.pdb for ATOM and HETATM
int main (){
	int wordcount = 0;
	int wordcount2 =0;

	wordcount = wc("/home/local/GSUAD/eboley1/4HKD.pdb", "ATOM ");
	wordcount2 = wc("/home/local/GSUAD/eboley1/4HKD.pdb", "HETATM ");
	printf ("Number of ATOM records: %d\nNumber of HETATM records: %d\n", wordcount-5, wordcount2);
	return 0;
}

