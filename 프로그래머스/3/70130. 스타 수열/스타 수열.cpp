#include <bits/stdc++.h>
using namespace std;

int counting[500001], visited[500001];

int solution(vector<int> a) {
    memset(visited, -1, sizeof(visited));
    
    for(int i = 1; i < a.size(); i++) {
        if(a[i] == a[i - 1]) continue;
        if(i >= 2 && a[i] == a[i - 2] && visited[i - 2] == i - 1) continue;

        if(visited[i] == -1) counting[a[i]]++, visited[i] = i - 1;
        if(visited[i - 1] == -1) counting[a[i - 1]]++, visited[i - 1] = i;
    }

    return *max_element(counting, counting + 500001) * 2;
}