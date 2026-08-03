#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static char *read_all(FILE *stream);
static void analyze(const char *content);

int main(int argc, char *argv[])
{
    FILE *file = NULL;
    char *content = NULL;

    /* Read text from the terminal. */
    if (argc == 1)
    {
        printf("Enter text, then press Ctrl+Z and Enter when finished:\n");

        content = read_all(stdin);

        if (content == NULL)
        {
            fprintf(stderr, "Failed to allocate memory\n");
            return 1;
        }
    }
    /* Read text from a file. */
    else if (argc == 3 && strcmp(argv[1], "-f") == 0)
    {
        file = fopen(argv[2], "r");

        if (file == NULL)
        {
            perror("Error opening the file");
            return 1;
        }

        content = read_all(file);

        fclose(file);

        if (content == NULL)
        {
            fprintf(stderr, "Failed to allocate memory\n");
            return 1;
        }
    }
    else
    {
        fprintf(stderr, "Usage: %s [-f filename]\n", argv[0]);
        return 1;
    }

    analyze(content);

    free(content);

    return 0;
}

static char *read_all(FILE *stream)
{
    size_t capacity = 256;
    size_t length = 0;

    char *content = malloc(capacity);

    if (content == NULL)
    {
        return NULL;
    }

    int current;

    while ((current = fgetc(stream)) != EOF)
    {
        /*
         * Keep one extra byte available for
         * the terminating null character.
         */
        if (length + 1 >= capacity)
        {
            size_t newCapacity = capacity * 2;

            char *newContent = realloc(content, newCapacity);

            if (newContent == NULL)
            {
                free(content);
                return NULL;
            }

            content = newContent;
            capacity = newCapacity;
        }

        content[length] = (char)current;
        length++;
    }

    content[length] = '\0';

    return content;
}

static void analyze(const char *content)
{
    int wordsCount = 0;
    int letterCount = 0;
    int digitsCount = 0;
    int whitespaceCount = 0;
    int linesCount = 0;
    int punctuationCount = 0;
    int vowelsCount = 0;
    int consonantsCount = 0;
    int insideWord = 0;

    for (size_t i = 0; content[i] != '\0'; i++)
    {
        unsigned char current = (unsigned char)content[i];

        if (isspace(current))
        {
            whitespaceCount++;
        }

        if (isdigit(current))
        {
            digitsCount++;
        }

        if (isalpha(current))
        {
            char lower = (char)tolower(current);

            letterCount++;

            if (lower == 'a' ||
                lower == 'e' ||
                lower == 'i' ||
                lower == 'o' ||
                lower == 'u')
            {
                vowelsCount++;
            }
            else
            {
                consonantsCount++;
            }
        }

        if (isalnum(current))
        {
            if (!insideWord)
            {
                wordsCount++;
                insideWord = 1;
            }
        }
        else
        {
            insideWord = 0;
        }

        if (current == '\n')
        {
            linesCount++;
        }

        if (ispunct(current))
        {
            punctuationCount++;
        }
    }

    printf("\nAnalysis results:\n");
    printf("Count of words: %d\n", wordsCount);
    printf("Count of letters: %d\n", letterCount);
    printf("Count of whitespaces: %d\n", whitespaceCount);
    printf("Count of digits: %d\n", digitsCount);
    printf("Count of newlines: %d\n", linesCount);
    printf("Count of punctuation: %d\n", punctuationCount);
    printf("Count of vowels: %d\n", vowelsCount);
    printf("Count of consonants: %d\n", consonantsCount);
}