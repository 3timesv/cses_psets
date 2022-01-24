#include <bits/stdc++.h>

using namespace std;

vector<string> perm(string in) {
    // if string's length is 0 or 1, return as it is
    if (in.length() <= 1) {
        vector<string> v = {in};
        return v;
    } else {
        // vector to store result
        vector<string> result;

        // set to store visited characters, to avoid same entries in the result
        set<char> visited;

        // for each character in the string
        for (int i=0; i < (int) in.length(); i++) {
            char current = in[i];

            // if character is already visited, skip it
            if (visited.count(current)) {
                continue;
            }

            // get the rest of the string (except current character)
            string rem = in.substr(0, i) + in.substr(i+1);

            // get the permutations of the remaining string
            vector<string> subs = perm(rem);

            // add current character at the prefix of permutations of the remaining string
            for (int i=0; i < (int) subs.size(); i++) {
                result.push_back(current + subs[i]);
            }

            // current character is visited now
            visited.insert(current);
        }
        return result;
    }
}

int main() {
    string input;
    cin >> input;

    vector<string> perms = perm(input);

    // sort the result in alphabetical order
    sort(perms.begin(), perms.end());

    // display
    cout << perms.size() << "\n";
    for (int i=0; i < (int) perms.size(); i++) {
        cout << perms[i] << "\n";
    }
}
