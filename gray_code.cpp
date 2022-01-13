#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    // start with n=1
    vector<string> oldV = {"0", "1"};
    vector<string> newV;

    // create new vector from old vector
    for (int i=1; i < n; i++) {
        // append "0" to oldV
        for (int j=0; j < (int) oldV.size(); j++) {
            string e = "0" + oldV[j];
            newV.push_back(e);
        }

        // append "1" to reversed oldV
        for (int k=(int) oldV.size()-1; k >= 0; k--) {
            string e = "1" + oldV[k];
            newV.push_back(e);
        }
        oldV.clear();
        oldV = newV;

        newV.clear();
    }

    // print 
    for (int i=0; i < (int) oldV.size(); i++) {
        cout << oldV[i] << "\n";
    }
}
