#include <bits/stdc++.h>
 
using namespace std;
 
// to store result
vector<int> res;
 
// recursive function
void play(vector<int> v, int k) {
    if ((int) v.size() <= k) {
        if (v.size() == 1) {
            res.push_back(v[0]);
        } else {
            int tgtIdx = k % v.size();

            vector<int> sv;
            for (int i=tgtIdx+1; i < (int) v.size(); i++) {
                sv.push_back(v[i]);
            }
            res.push_back(v[tgtIdx]);
            for (int i=0; i < tgtIdx; i++) {
                sv.push_back(v[i]);
            }
            play(sv, k);
        }
    } else {
        if (k == 0) {
            for (int i=0; i < (int) v.size(); i++) {
                res.push_back(v[i]);
            }
        } else {
            // initialize a new vector
            vector<int> sv;
            int lastIdx = v.size();
     
            int rem = lastIdx % (k+1);
            if (rem != 0) {
                lastIdx -= rem;
                for (int i=0; i < rem; i++) {
                    sv.push_back(v[lastIdx + i]);
                }
            }
     
            for (int i=0; i < lastIdx; i++) {
                if ((i+1) % (k+1) != 0) {
                    sv.push_back(v[i]);
                } else {
                    res.push_back(v[i]);
                }
            }
            play(sv, k);
        }
    }
}
 
int main() {
    int n, k;
    cin >> n >> k;
 
    vector<int> v;
    for (int i=1; i <= n; i++) {
        v.push_back(i);
    }
 
    play(v, k);
 
    // print o/p
    for (int i=0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << "\n";
}
