#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int n,m;
int arr[8];
vector<int> vec;
bool visited[8];

void bt(int cnt) {
    if(cnt==m) {
        for(auto b: vec)
            cout << b << ' ';
        cout << '\n';
        return;
    }
    int tmp=0;
    for(int i=0; i<n; i++) {
        if(visited[i] || tmp==arr[i]) continue;
        tmp=arr[i];
        visited[i]=1;
        vec.push_back(arr[i]);
        bt(cnt+1);
        visited[i]=0;
        vec.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    sort(arr,arr+n);
    bt(0);
}