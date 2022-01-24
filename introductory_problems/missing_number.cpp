#include <bits/stdc++.h>


using namespace std;

int main() {
    int n;
    cin >> n;
    int numbers[n-1];
    for (int i=0; i < n-1; i++) {
        cin >> numbers[i];
    }
    sort(numbers, numbers + n-1);

    for (int i=1; i < n+1; i++) {
        if ((i != numbers[i-1]) || (i > n-1)) {
            cout << i;
            break;
        }
    }
}
