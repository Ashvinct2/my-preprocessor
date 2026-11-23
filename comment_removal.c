#include <stdio.h>
#include "comment_removal.h"

void remove_comments(FILE *fp, FILE *op)
{
    int ch, next;
    while((ch = fgetc(fp)) != EOF)
    {
        if(ch == '/')
        {
            next = fgetc(fp);

            /* Single-line comment */
            if(next == '/')
            {
                while((ch = fgetc(fp)) != EOF && ch != '\n')
                {
                }

                if(ch == '\n')
                {
                    fputc('\n', op);
                }
            }

            /* Multi-line comment */
            else if(next == '*')
            {
                int prev = 0;
                while((ch = fgetc(fp)) != EOF)
                {
                    if(ch == '\n')
                    {
                        fputc('\n', op);
                    }

                    if(prev == '*' && ch == '/')
                    {
                        break;
                    }
                    prev = ch;
                }
            }

            /* Normal slash */
            else
            {
                fputc('/', op);
                if(next != EOF)
                {
                    fputc(next, op);
                }
            }
        }
        else
        {
            fputc(ch, op);
        }
    }
}
