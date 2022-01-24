#include <bits/stdc++.h>

using namespace std;

int main() {

    char currChar;
    int maxCount;
    int currCount; 

    string seq;
    cin >> seq;

    currChar = seq[0];
    currCount = 1;
    maxCount = 1;

    for (int i=1; i < seq.size(); i++) {
        if (seq[i] == currChar) {
            currCount++;
        }
        else {
            currChar = seq[i];
            currCount = 1;
        }

        if (currCount > maxCount) {
            maxCount = currCount;
        }
    }
    cout << maxCount << "\n";
}
