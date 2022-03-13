#include <iostream>
using namespace std;

int main() {
    int n = 0;
    int cnt = 0;

    cin >> n;

    while (n)
    {
        if (n % 2)
            n -= 1;
        else
            n /= 2;
        cnt++;
    }

    cout << cnt << '\n';

    return 0;
}