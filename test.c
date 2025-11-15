#include <stdio.h>
// Print content of txt
int main()
{
    FILE *fptr;
    fptr = fopen("test.txt","r");

    if (fptr != NULL)
    {
        char line[100];
        while(fgets(line, 100, fptr))
            printf("%s", line);
        printf("\n");    
    } else{
        printf("test.txt does not exist");
    }



    fclose(fptr);
    
    return 0;
}