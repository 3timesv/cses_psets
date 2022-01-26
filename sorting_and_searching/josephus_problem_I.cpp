#include <bits/stdc++.h>

using namespace std;

// to store result
vector<int> res;

// recursive function
void play(vector<int> v) {
    // if size of input is 1, just add only element to the result
    if (v.size() == 1) {
        res.push_back(v[0]);
        // otherwise
    } else {
        // initialize a new vector
        vector<int> sv;
        int lastIdx = v.size();

        // if the size of current vector is odd, 
        //      add the last element of current vector as first element of new vector and 
        //      reduce the index by 1 (bcz now there's one less element to add)
        if (v.size() % 2 != 0) {
            sv.push_back(v[lastIdx-1]);
            lastIdx--;
        }

        // add odd indices elements to new vector and even indices elements to result
        for (int i=0; i < lastIdx; i++) {
            if ((i+1) % 2 != 0) {
                sv.push_back(v[i]);
            } else {
                res.push_back(v[i]);
            }
        }

        // recurse on new vector
        play(sv);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> v;
    for (int i=1; i <= n; i++) {
        v.push_back(i);
    }

    play(v);

    // print o/p
    for (int i=0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << "\n";
}
