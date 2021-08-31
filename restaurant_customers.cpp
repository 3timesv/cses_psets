#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> events;

    pair<int, int> arrival;
    pair<int, int> leaving;
    for (int i=0; i < n; i++) {
        cin >> arrival.first;
        arrival.second = 1;
        cin >> leaving.first;
        leaving.second = -1;

        events.push_back(arrival);
        events.push_back(leaving);
    }

    sort(events.begin(), events.end());

    int count=0;
    int maxCount = 0;

    for (int i=0; i < 2*n; i++) {
        count += events[i].second;
        if (count > maxCount) {
            maxCount = count;
        }
    }
    cout << maxCount << "\n";
}
