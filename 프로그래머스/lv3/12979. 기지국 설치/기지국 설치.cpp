#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> stations, int w) {
    int answer = 0;
    bool flag = false;
    
    // 모든 아파트 탐색을 위한 마지막 값 입력
    if(stations.back() != n) {
        stations.push_back(n);
        flag = true;
    }
    
    int prev = -w;
    for(int i = 0; i < stations.size(); i++) {
        int wifi = 2*w+1;
        
        // 두 아파트 간 전파되지 않은 거리
        int remain = stations[i] - prev - 2*w - 1;
        
        // 마지막 값이 더미라면 아직 전파되지 않았음
        if(flag && i == stations.size()-1) remain += w+1;
        
        prev = stations[i];
        
        if(remain <= 0) continue;
        
        answer += (remain + wifi - 1) / wifi;
    }

    return answer;
}