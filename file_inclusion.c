#include <stdio.h>
#include <string.h>
#include "file_inclusion.h"

void process_includes(FILE *fp, FILE *op)
{
    char line[200];
    char filename[100];
    int i, j;
    int ch;
    int found;

    while(fgets(line, sizeof(line), fp) != NULL)
    {
        if(strncmp(line, "#include", 8) == 0)
        {
            i = 8;
            j = 0;
            found = 0;

            /* Skip spaces and tabs */
            while(line[i] == ' ' || line[i] == '\t')
            {
                i++;
            }

            /* Check opening bracket */
            if(line[i] == '<')
            {
                i++;

                while(line[i] != '>' && line[i] != '\0' && j < 99)
                {
                    filename[j] = line[i];
                    j++;
                    i++;
                }

                if(line[i] == '>')
                {
                    found = 1;
                }
            }

            else if(line[i] == '"')
            {
                i++;
                while(line[i] != '"' && line[i] != '\0' && j < 99)
                {
                    filename[j] = line[i];
                    j++;
                    i++;
                }

                if(line[i] == '"')
                {
                    found = 1;
                }
            }
            filename[j] = '\0';

            if(found == 1)
            {
                FILE *header;
                header = fopen(filename, "r");

                if(header != NULL)
                {
                    while((ch = fgetc(header)) != EOF)
                    {
                        fputc(ch, op);
                    }
                    fclose(header);
                }
                else
                {
                    fputs(line, op);
                }
            }
            else
            {
                fputs(line, op);
            }
        }
        else
        {
            fputs(line, op);
        }
    }
}
