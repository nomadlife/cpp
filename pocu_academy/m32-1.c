#include <stdio.h>

int main()
{
    FILE* fp;
    fp = fopen("hello.txt", "r");

    char character;
    printf("C code \n");
    do
    {
        character = getc(fp);
        printf("%c", character);
    } while (character != EOF);

    fclose(fp);

}





