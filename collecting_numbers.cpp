#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];

    int num;
    for (int i=0; i < n; i++) {
        cin >> num;
        a[num-1] = i;
    }

    int res = 1;
    for (int i=1; i < n; i++) {
        if (a[i] < a[i-1]) {
            res++;
        }
    }
    cout << res << "\n";


    //    TIME LIMIT EXCEEDED
//    int curr = 1;
//    int count = 0;
//    while (curr < n) {
//        for (int i=0; i < n; i++) {
//            if (curr == a[i]) {
//                curr++;
//            }
//        }
//        count++;
//    }
//    cout << count << "\n";
}
