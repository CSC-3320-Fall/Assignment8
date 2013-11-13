/*Aaron Nguyen
 * CSC 3320 T/TH 1pm - 2:15 pm
 *
 * Question 2 - distance between ca
 *
 */

int main(int argc, char **argv)
{
    int r_num = 0; //residue number
    int dist = 0; //distance
    int i = 0;
    int  res[50] = {0}; // storing residue numbers
    char str3[100] = {0x0}; //coparing to CA value
    char str2[100]={0x0}; //initilize to 0, storing 1st word in line
    char str[100]={0x0}; //initialize to 0, storing line of words.

    FILE *infile = fopen(argv[1], "r"); //open file supplied in arg 1

    if (infile == NULL) { //if file doesnt exist
        printf("Invalid file, please enter ./program_name file_name\n");
        return 0;
    }
    FILE *csv_file = fopen("hw8q2.csv", "w+"); //writing output to .csv file

    fseek(infile, 0, SEEK_SET); //search file from the beginning.

    while( fgets (str, sizeof(str), infile) != NULL ) { //get first line of words.
        sscanf(str, "%s %d %s", str2, &r_num, str3); //scan the first string in the line.
        if (strcmp(str3, "CA") == 0){
        res[i++] = r_num; //store residue numbers in array
        }

    }

        for(int b = 1; b < 50; b++){
        dist = res[b] - res[b-1]; //substract residue 2-1 = distance, repeat
        fprintf(csv_file, "%d, %d, %d\n", res[b-1], res[b], dist); //res #1, residue #2, dist
        }
    fclose(csv_file); //close csv file
    fclose(infile); //close 4HKD.pdb
    return(0);
}
