//
//  count.c
//
//
//  Created by Mike Chen on 1/17/16.
//
//
#include "count.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Search_in_File(char *, char *,char *);

int main(int argc, char *argv[]) {
    if (argc!=4){printf("The number of arguments are incorrect\nPlease type the command correctly:\ncount <input-filename> <search-string> <output-filename>\n");
        return 0;
    }

    int result, errno,sizebyte;
    system("clear");
    
    //by having the result to determine if source file or output file is null.
    result = Search_in_File(argv[1], argv[2],argv[3]);
    if(result == -1) {
        perror("Error");
        printf("Error number = %d\n", errno);
        exit(1);
    }
    return(0);
}

int Search_in_File(char *fname2, char *str,char *outname2) {
    FILE *fp;
    FILE *op;
    int line_num = 1;
    int find_result = 0;
    char temp[100];
    int size;
    
    if((fp = fopen(fname2, "r")) == NULL) {
        printf("cannot open source file.");
        return(-1);
    }
    if((op = fopen(outname2,"w")) == NULL){
        printf("Cannot open target file.");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);    /* file pointer at the end of file */
    size = ftell(fp);   /* take a position of file pointer un size variable */
    printf("The size of given file is : %d byte\n", size);
    fprintf(op,"The size of given file is : %d byte\n", size);

    fseek(fp,0,SEEK_SET); /* let the pointer point to start of the file */
    while(fgets(temp, 100, fp) != NULL) {
        if((strstr(temp, str)) != NULL) {
            find_result++;
        }
    }
    
    if(find_result == 0) {
        printf("\nSorry, couldn't find a match.\n");
        fprintf(op,"\nSorry, couldn't find a match.\n");
        
    }else{
        printf("the shown time is %d.\n",find_result);
        fprintf(op,"the shown time is %d.\n",find_result);
    }
    
    //Close the file if still open.
    if(fp) {
        fclose(fp);
    }
    if(op){
        fclose(op);
    }
   	return(0);
}