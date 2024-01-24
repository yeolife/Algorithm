#include <stdio.h>
#include <algorithm>

int n, arr[22][22];
bool cur[22];
int ans = 1e9;

void func(int k, int s0, int s1){
    if(k == n){
        ans = std::min(ans, std::abs(s0 - s1));
        return;
    }

    int t0 = 0, t1 = 0;
    for(int i = 0; i < k; i++){
        if(cur[i]) t1 += arr[i][k];
        else t0 += arr[i][k];
    }

    func(k + 1, s0 + t0, s1);
    cur[k] = true;
    func(k + 1, s0, s1 + t1);
    cur[k] = false;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int k;
            scanf("%d", &k);
            if(i > j) arr[j][i] += k;
            else arr[i][j] += k;
        }
    }
    func(0, 0, 0);
    printf("%d", ans);
}