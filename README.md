Assignment8
===========

CSC3320 Fall 2013 Assignment 8 - formatted IO 
=============================================

## due November 12 2013
## RWH
#Fun with (fs)printf, (fs)scanf and FILEs

Please use the file 4HKD.pdb from Dr. Harrison's area on snowball or redownload it from desire2learn.
- Show by writing the code that you can take a filename from the command line and open the file for reading.  Read the file and count the numbers of ATOM and HETATM records. We did something similar with awk or grep and wc, now do it in C.
- Read the file and calculate the distance between each successive pair of CA atoms. Associated with each ATOM/HETATM record is an atom name, a residue number and an x,y,z value - decode these and give the distance between CA 1 and CA 2, then CA 2 and CA 3 and so on. Output the results in a comma seperated file (CSV) with the two residue numbers and the distance seperated by commas.
- [extra credit] There is a relatively easy to use ascii format for graphics, known as Xpixmap or XPM. The entry in wikipedia is pretty accurate and it is well-described on line.  Write an XPM file describing the distances between each CA atom (the first row will be the distances between CA 1 and CA 1, ...., N, then the next row is CA 2 and CA 1, ....,N  until you get to CA N and CA 1,..., N. It will be symmetric). A fair number of graphics programs including the GIMP will read this as an image and allow you to convert to more "pure" image files. We just need the XPM file.

# Hints

Using fscanf(FILE *, char *, ...) can be problematic with complicated formats. It tends to treat the input as one long stream and doesn't hop from record to record if you don't use all the data on any one line.  Using fgets( char *, size_t, FILE *) and then sscanf(char *,char*,...) is a lot easier.  If you know where the data is in a highly regular line you can also use sscanf starting from somewhere down in the middle of a character array. (i.e. what does &line[30] mean?) Another way of saying this is that it is often easier to write:
```
fgets(line, sizeof(line),ip);
sscanf( &line[22]," %8.2f",&x);
```
than
```
fscanf(ip,"<horrible format> %8.2f<more horrible format things>",
                                      &(stuff),&x,&(more stuff));
```

It's also more secure to buffer the data in a character line.  A common security hole is
```
fscanf(ip," %s",line);
/* line is only 80 characters long - but the %s can go on forever */
```
instead of
```
fscanf(ip," %80s",line);
```
The string recovered from sscanf(raw_line," %s",line); is guarantied to be no longer than the size of the array raw_line.

Since you don't necessarily know the length of the file in advance, this is a good place to use a while loop and continue statements to skip unnecessary input.


