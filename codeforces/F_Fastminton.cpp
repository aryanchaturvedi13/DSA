#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string seq;
    if (!(cin >> seq)) return 0;
    pair<int,bool> ss = {0, true}, rs = {0, false};
    int sw = 0, rw = 0;
    auto go = [&](int a, int b) {
        return ((a >= 5 || b >= 5) && abs(a - b) >= 2) || a == 10 || b == 10;
    };

    for (char c : seq) {
        if (c == 'S' || c == 's') {
            if (sw >= 2 || rw >= 2) continue;
            (ss.second ? ss.first : rs.first)++;
            if (go(ss.first, rs.first)) {
                (ss.first > rs.first ? sw : rw)++;
                ss.first = rs.first = 0;
            }
        }
        else if (c == 'R' || c == 'r') {
            if (sw >= 2 || rw >= 2) continue;
            ss.second = !ss.second;
            rs.second = !rs.second;
            (ss.second ? ss.first : rs.first)++;
            if (go(ss.first, rs.first)) {
                (ss.first > rs.first ? sw : rw)++;
                ss.first = rs.first = 0;
            }
        }
        else if (c == 'Q' || c == 'q') {
            if (sw == 2 || rw == 2) {
                cout << sw << (sw == 2 ? " (winner)" : "") 
                     << " - " 
                     << rw << (rw == 2 ? " (winner)" : "") 
                     << '\n';
            } else {
                cout << sw << " (" << ss.first << (ss.second ? "*" : "") << ") - "
                     << rw << " (" << rs.first << (rs.second ? "*" : "") << ")\n";
            }
        }

    }

    return 0;
}
