#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc == 1)
        return 1;

    char *expr = argv[1];
    int expr_len = strlen(expr);
    char paren[expr_len];

    char *temp = expr;
    char *head = &paren[0];
    char match = '\0';

    // printf("Expression: %s\n", argv[1]);

    while (*temp != '\0')
    {
        if (*temp == '('
            || *temp == '['
            || *temp == '{')
        {
            *head = *temp;
            head++;

            // fprintf(stderr, "Stack: %s\n", paren);
        }
        else
        {
            switch (*temp)
            {
                case ')':
                    match = '(';
                    break;
                case ']':
                    match = '[';
                    break;
                case '}':
                    match = '{';
                    break;
                default:
                    match = '\0';
            }

            if (match != '\0' && *(head - 1) == match)
            {
                *head = '\0';

                if (head != paren)
                    head--;
            }
            else if (match != '\0')
            {
                printf("NO\n");
                return 0;
            }

            // fprintf(stderr, "Stack: %s\t %c\n", paren, *temp);
        }

        temp++;
    }

    if (head == paren && *temp == '\0')
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
