#include <stdio.h>
#include <stdlib.h>

#define buff_size 1000


void WriteToFile();
void ReadFromFile();


int main(){
    WriteToFile();
    ReadFromFile();
    return 0;
}

void WriteToFile(){
    FILE *file = fopen("content.txt","a");

    if(file == NULL){
        printf("Error writing to file");
    }

    fputs("This is the WriteToFile Function Writing\n",file);

    fclose(file);

    // return 0;
}

void ReadFromFile(){
    size_t capacity = 256; // total allocate
    size_t length = 0; // current

    char *buff = malloc(capacity);

    FILE *file = fopen("content.txt","r");

    if(file == NULL){
        printf("the ReadFromFile Function has a problem reading this fi\n");
    }

    int ch;

    while ((ch = fgetc(file)) != EOF)
    {
        if (length + 1 >= capacity)
        {
            size_t new_capacity = capacity * 2;

            char *new_buff = realloc(buff, new_capacity);

            if (new_buff == NULL)
            {
                printf("Could not expand the buffer.\n");

                fclose(file);
                free(buff);
                return;
            }

            buff = new_buff;
            capacity = new_capacity;
        }

        buff[length] = (char)ch;
        length++;
    }

    buff[length] = '\0';

    printf("File content:\n%s\n", buff);
    printf("Length: %zu\n", length);
    printf("Capacity: %zu\n", capacity);

    fclose(file);
    free(buff);
}