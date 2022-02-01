#include <bits/stdc++.h>

using namespace std;

// to store a request pair with its index
struct Req{
    int left, right, idx;

    // increasing left (increasing right at tie)
    bool operator < (const Req &other) const {
        if (left == other.left) {
            return right < other.right;
        } return left < other.left;
    }
};

int main() {
    int n;
    cin >> n;

    vector<Req> requests;
    for (int i=0; i < n; i++) {
        Req r;
        cin >> r.left >> r.right;
        r.idx = i;
        requests.push_back(r);
    }

    // sort input
    sort(requests.begin(), requests.end());

    // Min-heap or pairs , pair.first is right element, pair.second is room number
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>  alloted;
    // room number
    int roomNum = 1;
    // to store requests' room numbers
    int rooms[n] = {0};

    for (int i=0; i < n; i++) {
        Req r = requests[i];
        if (alloted.size() == 0) {
            alloted.push(make_pair(r.right, roomNum));
            rooms[r.idx] = roomNum;
            roomNum++;
        } else {
            pair<int, int> top = alloted.top();
            // if request's arrival time is greater than the minimum departure time
            if (r.left > top.first) {
                alloted.pop();
                alloted.push(make_pair(r.right, top.second));
                rooms[r.idx] = top.second;
                // otherwise
            } else {
                alloted.push(make_pair(r.right, roomNum));
                rooms[r.idx] = roomNum;
                roomNum++;
            }
        }
    }

    cout << roomNum-1 << "\n";
    for (int i=0; i < n; i++) {
        cout << rooms[i] << " ";
    }
    cout << "\n";
}
