#include <stdio.h>
#include <string.h>

#include "comment_removal.h"
#include "file_inclusion.h"
#include "macro_handler.h"

int main(int argc, char *argv[])
{
    FILE *fp, *op;

    char output[100];

    if(argc != 2)
    {
        printf("Usage: ./mypreprocessor filename.c\n");
        return 1;
    }

    if(strlen(argv[1]) >= 95)
    {
        printf("Filename is too long\n");
        return 1;
    }

    fp = fopen(argv[1], "r");

    if(fp == NULL)
    {
        printf("Unable to open input file\n");
        return 1;
    }

    strcpy(output, argv[1]);
    strcat(output, ".i");

    /* Step 1: Remove comments */

    op = fopen("temp_file.c", "w");

    if(op == NULL)
    {
        printf("Unable to create temporary file\n");
        fclose(fp);
        return 1;
    }

    remove_comments(fp, op);

    fclose(fp);
    fclose(op);

    /* Step 2: Process header files */

    fp = fopen("temp_file.c", "r");

    if(fp == NULL)
    {
        printf("Unable to open temporary file\n");
        return 1;
    }

    op = fopen("temp_include.c", "w");

    if(op == NULL)
    {
        printf("Unable to create temporary file\n");
        fclose(fp);
        return 1;
    }

    process_includes(fp, op);

    fclose(fp);
    fclose(op);

    /* Step 3: Process macros */

    fp = fopen("temp_include.c", "r");

    if(fp == NULL)
    {
        printf("Unable to open temporary file\n");
        return 1;
    }

    op = fopen(output, "w");

    if(op == NULL)
    {
        printf("Unable to create output file\n");
        fclose(fp);
        return 1;
    }

    process_macros(fp, op);

    printf("Preprocessing completed successfully\n");
    printf("Output file: %s\n", output);

    fclose(fp);
    fclose(op);

remove("temp_file.c");
remove("temp_include.c");

    return 0;
}
