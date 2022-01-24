#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    // calculate length of string
    int n = s.length();
    
    string alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int count[26] = {0};

    // get the counts of each alphabet in input string
    for (int i = 0; i < n; i++) {
        count[s[i] - 'A']++;
    }


    string result = "";
    int odd_count = 0;
    char odd_val = 'z';
    int odd_freq = 0;

    // iterate over counts
    for (int i=0; i < 26; i++) {
        // ignore 0 counts
        if (count[i] != 0) {
            // if even, 
            if (count[i] % 2 == 0) {
                // append half of it to the result
                for (int j=0; j < count[i]/2; j++) {
                    result += alphabets[i];
                }
                // if odd,
            } else {
                // if there was already some alphabet that was odd, NO SOLUTION
                if (odd_count == 1) {
                    cout << "NO SOLUTION\n";
                    return 0;
                }
                // get the odd char, its count and increment the odd count
                odd_val = alphabets[i];
                odd_freq = count[i];
                odd_count++; }
        }
    }

    // print the even characters with even counts, half 
    for (int i=0; i < (int) result.length(); i++) {
        cout << result[i];
    }

    // if there's any odds, print em
    if (odd_count == 1) {
        for (int i=0; i < odd_freq; i++) {
            cout << odd_val;
        }
    }

    // print the other half of evens in reverse order
    for (int i=result.length()-1; i >= 0 ; i--) {
        cout << result[i];
    }
}
