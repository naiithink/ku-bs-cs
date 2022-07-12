#include<stdio.h>
#include<string.h>

struct Word {
    char word[21];
    int count;
};

int main(){
    char input[21];
    int i, last_word = 0, find = 0;
    struct Word data[20] = {0};
    scanf("%20s", input);

    while(strcmp(input, "exit") != 0){
        for (int i = 0; !find; i++)
        {
            if (last_word && !strcmp(input, data[i].word))
            {
                data[i].count++;
                find = 1;
            }
            else if (!last_word || i == last_word - 1)
            {
                strcpy(data[last_word].word, input);
                data[last_word].count = 1;
                last_word++;
                find = 1;
            }
        }
        find = 0;
        scanf("%20s", input);
    }

    printf("Output:\n");
    for(i=0;i<last_word;i++){
        printf("%s = %d\n", data[i].word, data[i].count);
    }
}