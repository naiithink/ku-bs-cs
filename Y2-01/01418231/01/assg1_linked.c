#include <stdio.h>
#include <stdlib.h>

typedef struct binary_t
{
    int value : 1;
    int init : 1;
    struct binary_t *prev;
    struct binary_t *next;
}
binary_t;

binary_t *a_binary_t(const binary_t *);
void binary_t_insert(const int);
void print_binary_t(const binary_t *);

static binary_t *binary_out;

int main(int argc, char **argv)
{
    if (argc == 1)
        return 1;

    int is_signed = 0;
    int decimal_in = 0;
    int tmp = 0;
    // binary_t *binary_out;

    for (int argi = 1; argi < argc; ++argi)
    {
        tmp = decimal_in;
        binary_out = a_binary_t();
        decimal_in = (int) strtol(argv[argi], NULL, 10);

        while (buffer)
        {
            if (buffer & 1)
                binary_out_insert(1);
            else
                binary_out_insert(0);

            buffer >>= 1;
        }

        printf("Decimal in: %d\n", decimal_in);
        printf("Binary out: ");
        print_binary_t();
    }

    return 0;
}

binary_t *a_binary_t(const binary_t *binary_t_ptr)
{
    binary_t *res;
    binary_t *head;
    binary_t *prev;

    if (binary_t_ptr != NULL)
    {
        head = binary_t_ptr;
        prev = binary_t_ptr->prev;
    }

    while (head->prev != NULL)
    {
        head = res;
        prev = res->prev;
        head->init = 0;
        head->next = NULL;
        head->prev = NULL;
        head = prev;
    }

    return res;
}

void binary_out_insert(const int n)
{
    if (n < 0 || n > 1)
        exit(1);
}

void print_binary_t(const binary_t *binary_t_ptr)
{
    if (binary_t_ptr == NULL)
    {
        fprintf(stderr, "NULL");
        exit(1);
    }

    binary_t *head = binary_t_ptr;

    while (head->prev != NULL)
    {
        printf("%d", head->value);
        head = head->next;
    }
    printf("\n");
}
