#include<stdio.h>
#include<stdlib.h>

#define LINE_SIZE 50

/* read data from an ASCII file and save the data to a new file in a binary format
 *    obtain the filenames to be read and written from command line  */

//struct 
typedef struct _FileData
{
	int intNumber;
	double floatNumber;
    	char AsciiToBinery[LINE_SIZE];
}FileData;
 

int main(int argc, char *argv[])
{	
	FileData asciiFile;
        int index=0;
	FILE *inFile;
        FILE *outFile;

        inFile = fopen(argv[1], "r");  // get afile name from comandline then open a file  in read mode


        if (inFile == NULL)   // check the given infile name if it is open properly/exist
         {

                 printf("Error opening file\n");    // if not give error message and exit
                exit(1);
         }

        outFile = fopen(argv[2], "wb+");  // get a file name from comandline then Open a file in writing binary mode  for writing

        if (outFile == NULL)     // Check the given outfile name if it  open correctly/existed
         {
                  printf("Error opening file\n");    // if not give error message and exit
                  exit(1);
         }

	while(fgets(asciiFile.AsciiToBinery, LINE_SIZE, inFile)!= NULL){

		if(index==0){
	        sscanf(asciiFile.AsciiToBinery,"%d",&asciiFile.intNumber);
		}

		else if(index==1){
		sscanf(asciiFile.AsciiToBinery,"%lf",&asciiFile.floatNumber);
		}

		else{
			fwrite(&asciiFile, sizeof(FileData), 1, outFile);
			index=-1;
		}
		
		index++;
	}


        fclose(inFile);         //close inFile
        fclose(outFile);        //close outFile

     return 0;
 }


