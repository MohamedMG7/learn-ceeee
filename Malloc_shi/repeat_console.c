#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 265

int main(){
    char *buf = malloc(BUFFER_SIZE * sizeof(char)); 
    
    if(buf == NULL){
        printf("memory allocation failed");
        return 1;
    }

    printf("Enter Text: ");

    if(fgets(buf, BUFFER_SIZE, stdin) != NULL){
        buf[strcspn(buf,"\n")] = '\0';
        printf("you entered %s\n", buf);
    }

    free(buf);
    buf = NULL;
    return 0;
}