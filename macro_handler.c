#include <stdio.h>
#include <string.h>
#include "macro_handler.h"

void process_macros(FILE *fp, FILE *op)
{
    char line[500];
    char name[50][50];
    char value[50][100];
    char argument[50][50];

    char actual[50];
    char result[500];
    char temp[500];
    int count = 0;
    int i, j, k;

    while(fgets(line, sizeof(line), fp) != NULL)
    {
        /* Read macro definitions */
        if(strncmp(line, "#define", 7) == 0)
        {
            if(strchr(line, '(') != NULL)
            {
                sscanf(line, "#define %[^ (](%[^)]) %[^\n]",
                       name[count],
                       argument[count],
                       value[count]);
            }
            else
            {
                sscanf(line, "#define %s %s",
                       name[count],
                       value[count]);

                argument[count][0] = '\0';
            }
            count++;
        }
        else
        {
            /* Process each macro */
            for(i = 0; i < count; i++)
            {
                if(argument[i][0] == '\0')
                {
                    /* Simple macro */
                    while(strstr(line, name[i]) != NULL)
                    {
                        char *ptr = strstr(line, name[i]);
                        strcpy(temp, ptr + strlen(name[i]));
                        *ptr = '\0';

                        strcpy(result, line);
                        strcat(result, value[i]);
                        strcat(result, temp);
                        strcpy(line, result);
                    }
                }

                else
                {
                    /* Function-like macro */
                    while(strstr(line, name[i]) != NULL)
                    {
                        char *ptr = strstr(line, name[i]);
                        if(ptr[strlen(name[i])] != '(')
                        {
                            break;
                        }

                        ptr = ptr + strlen(name[i]) + 1;
                        j = 0;

                        while(*ptr != ')' && *ptr != '\0' && j < 49)
                        {
                            actual[j] = *ptr;
                            j++;
                            ptr++;
                        }

                        actual[j] = '\0';
                        if(*ptr != ')')
                        {
                            break;
                        }

                        strcpy(temp, ptr + 1);
                        ptr = strstr(line, name[i]);
                        *ptr = '\0';
                        strcpy(result, line);

                        /* Replace argument in macro value */
                        k = 0;
                        while(value[i][k] != '\0')
                        {
                            if(value[i][k] == argument[i][0])
                            {
                                strcat(result, actual);
                            }
                            else
                            {
                                j = strlen(result);
                                result[j] = value[i][k];
                                result[j + 1] = '\0';
                            }
                            k++;
                        }

                        strcat(result, temp);
                        strcpy(line, result);
                    }
                }
            }
            fputs(line, op);
        }
    }
}
