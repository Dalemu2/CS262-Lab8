#include<stdio.h>
#include<stdlib.h>

#define LINE_SIZE 50

/* read data from a binary file and save the data to a new file in ASCII format
 obtain the filenames to be read and written from command line parameters. 
*/


// struct 
typedef struct _FileData
{
    int intNumber;
    double floatNumber;
    char BineryToAscii[LINE_SIZE];
} FileData;


int main(int argc, char *argv[])
{

        FileData asciiFile;	// 
        FILE *inFile;
        FILE *outFile;

 inFile = fopen(argv[1], "rb");  // get afile name from comandline then open a file  in read mode


        if (inFile == NULL)   // check the given infile name if it is open properly/exist
         {

                 printf("Error opening file\n");    // if not give error message and exit
                exit(1);
         }

        outFile = fopen(argv[2], "w+");  // get a file name from comandline then Open a file in writing binary mode  for writing

        if (outFile == NULL)     // Check the given outfile name if it  open correctly/existed
         {
                  printf("Error opening file\n");    // if not give error message and exit
                  exit(1);
     	}


while(fread(&asciiFile,sizeof(FileData),1,inFile)!=0){		// read binary file 

		fprintf(outFile,"%d\n",asciiFile.intNumber);  // write int value on file
		fprintf(outFile,"%0.3lf\n",asciiFile.floatNumber);  // write floating number on file
    		fprintf(outFile,"%s",asciiFile.BineryToAscii);	// write string on file
}
	
	fclose(inFile);         //close inFile
        fclose(outFile);        //close outFile
     return 0;
 }


