<#include stdio.h>
<#include stdlib.h>

/*gets the file by input */
void getFile(){
	Char *fileName;
	fprintf("%s", "Enter the file destination: ");
	scanf("%s", fileName);
	fopen(fileName, rt);
}
/*takes a character array as a parameter, if the first four characters are ATOM
return 1, else return 0*/
int countSent(Char *c){
for(int i=0; i<sizeOf(c); i++){
	if(c[0] =='A' && c[1] == 'T' && c[1] == 'O' && c[2] == 'M' )
		return 1;
	else
		return 0;
}
}

int main(){

getFile();
Char C;
int counter;

/*while not end of file, read the characters of the file one by one, if it reaches a newline,
put it into a temp character array and gives it to the countSent function, which is then stored into an int*/

while( c=getChar() != EOF){
	Char *temp;
	do
		temp += c;
	while(c =getChar() != "/n")
	counter += countSent();
}
printf("The number of lines with ATOM in it is %d", counter);
fclose();
}