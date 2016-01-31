//
//  count2.c
//  
//
//  Created by Mike Chen on 1/17/16.
//
//
#include "count2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define BUFFSIZE 1024


    int Search_in_File(char *, char *,char *);
    int SizeofFile(char *,char *);

int main(int argc, char *argv[]) {
    int result, errno,sizebyte;
    system("clear");
    
    result = Search_in_File(argv[1], argv[2],argv[3]);
    if(result == -1) {
        perror("Error");
//        fprintf(op,"Error");
        printf("Error number = %d\n", errno);
//        fprintf(op,"Error number = %d\n", errno);
        exit(1);
    }
    sizebyte=SizeofFile(argv[1],argv[3]);

    return(0);
}



int SizeofFile(char *fname,char *outname){
    FILE *fp;
    FILE *op;
    fp=fopen(fname,"r");
    op=fopen(outname,"w");
    int size;
    fseek(fp, 0, 2);    /* file pointer at the end of file */
    size = ftell(fp);   /* take a position of file pointer un size variable */
    printf("The size of given file is : %d byte\n", size);
    fprintf(op,"The size of given file is : %d byte\n", size);
    return size;
//    fclose(fp);
    }

int Search_in_File(char *fname2, char *str,char *outname2) {
    FILE *fp2;
    FILE *op2;
    int line_num = 1;
    int find_result = 0;
       char temp[100];

    if((fp2 = fopen(fname2, "r")) == NULL) {
        printf("cannot open source file.");
        return(-1);
    }
    if((op2 = fopen(outname2,"w")) == NULL){
        printf("Cannot open target file.");
//        fprintf(op2,"Cannot open target file.");
        exit(1);
    }
    
  
//
   
    while(fgets(temp, 100, fp2) != NULL) {
        if((strstr(temp, str)) != NULL) {
            find_result++;
        }
    }
    
    if(find_result == 0) {
        printf("\nSorry, couldn't find a match.\n");
        fprintf(op2,"\nSorry, couldn't find a match.\n");

    }else{
        printf("the shown time is %d.\n",find_result);
        fprintf(op2,"the shown time is %d.\n",find_result);
    }
    
    //Close the file if still open.
    if(fp2) {
        fclose(fp2);
    }
    if(op2){
        fclose(op2);
    }
   	return(0);
}


