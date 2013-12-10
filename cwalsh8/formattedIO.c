#include <stdio.h>

int main(int argc, char **argv) {

FILE *fp;
char line[80];
char word[4];
int howMuchAtoms;
int howMuchHeta;
fp = fopen(argv[1], "r");

fgets(line, sizeof(line),fp);
sscanf(&line[0], "%4s", word);
if (word == "ATOM") {
howMuchAtoms++;
}
else if (word == "HETA") {
howMuchHeta++;
}
fclose(fp);
printf("ATOM: %d \n HETA: %d", howMuchAtoms, howMuchHeta);
}
