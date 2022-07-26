
#include                    <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc,char **argv){

	char buffer[500];

	printf("\n\n\n\n");

	puts(argv[0]);

	printf("\n\n***Welcome to the HP-GCC HP39 Aplet Wizard!***");
	printf("\n\n\nThis tool is used to tell HP-GCC some information about your Aplet.");
	printf("\nIf you proceed, it will create a new HP39 Project file in the current folder. ");
	printf("\nAny existing project file in the current folder will be erased");
	printf("\n\n\nDo you wish to continue? (Y/N) >");


	gets(buffer);
	if(buffer[0]!='Y'&&buffer[0]!='y') return;

	FILE * output = fopen("hp39prj.dat","w");
	if(output==NULL){
	
		printf("\n\nERROR: Could not create a new project file");
		exit(0);//bail out
		}


	fputs("### DO NOT EDIT THIS FILE BY HAND\n",output);//paranonia

	printf("\n\nWhat is the name of your Aplet? Names should be fairly short (<15 characters).");
	printf("\nThe name is used in the APLET Menu, and on the splash screen.");
	printf("\n\nAplet Name>");
	gets(buffer);
	buffer[15]=0;//ensure its less then 15 chars
	fputs(buffer,output);

	fputs("\n",output);
	
	printf("\n\nWhat is your name? (<25 characters).");
	printf("\nThis is shown on the splash screen.");
	printf("\nYou could put some other message here, if you wish.");	
	printf("\n\nAuthor Name>");
	gets(buffer);
	buffer[25]=0;//ensure its less then 25 chars
	fputs(buffer,output);	
	
	fputs("\n",output);

	printf("\n\nYou can optionally put a picture on the splash screen.");
	printf("\nIt must be a black & white GROB (Graphics Object).");
	printf("\nYou can use a program like XnView to convert a GIF/BMP/JPG");	
	printf("\ninto a GROB file. \n\nDo you wish to insert a picture? (Y/N)  ");


	gets(buffer);
	if(buffer[0]!='Y'&&buffer[0]!='y'){
	
		fputs("N",output); //no picture
		goto exit;
	
	}

	fputs("Y\n",output); //a picture

	printf("\n\nWhat is the name of the picture file? \nIt must be in the current directory");
	printf("\n\nfile name>");
	gets(buffer);
	buffer[25]=0;//ensure its less then 25 chars
	fputs(buffer,output);	

	fputs("\n",output);
	
	printf("\n\nWhat is the X position of the picture? Please enter a number\n\nX Position>");
	gets(buffer);
	buffer[3]=0;//ensure its less then 3 chars
	fputs(buffer,output);

	fputs("\n",output);
	
	printf("\n\nWhat is the Y position of the picture? Please enter a number\n\nY Position>");
	gets(buffer);
	buffer[3]=0;//ensure its less then 3 chars
	fputs(buffer,output);
	
	
exit:

	printf("\n\nSetup is complete.\n\n");

	
	fclose(output);

}
