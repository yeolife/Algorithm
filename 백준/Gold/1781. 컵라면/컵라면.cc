#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

bool cmp(pii &a, pii &b) {
    if (a.first == b.first)
        return a.second > b.second;
    return a.first > b.first;
}

pii board[200001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

int n, ans = 0;
cin >> n;

priority_queue<int> pq;

int a, b;
for (int i = 0; i < n; i++) {
    cin >> a >> b;

    board[i] = {a, b};
}

sort(board, board + n, cmp);

int idx = 0;
int deadline = board[idx].first;
for (int i = deadline; i >= 1; i--) {
    while (idx < n && board[idx].first >= i) {
        pq.push(board[idx].second);
        idx++;
    }

    if (!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }
}

cout << ans << '\n';

return 0;
}