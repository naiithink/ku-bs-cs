#include <iostream>
using namespace std;

typedef struct Word_ {
    string word;
    int count;
} Word;

int main() {
    string input;
    int i, last_word = 0, find = 0;
    Word data[20];

    while (true) {
        cin >> input;
        if (input == "exit") {
            break;
        }

        for (int i = 0, find = 0; !find; i++)
        {
            if (input == data[i].word)
            {
                data[i].count++;
                find = 1;
            }
            else if (!last_word || i == last_word - 1)
            {
                if (last_word)
                    i++;
                data[i].word = input;
                data[i].count = 1;
                last_word++;
                break;
            }
        }
    }

    cout << "Output:" << endl;
    for (int i = 0; i < last_word; i++)
        cout << data[i].word << " = " << data[i].count << endl;

    return 0;
}