#include <bits/stdc++.h>
using namespace std;

int solution(int left, int right) {
    int answer = 0;
    
    for(int i = left; i <= right; i++) {
        int counting = 1;
        for(int j = 1; j <= i/2; j++) if(!(i%j)) counting++;
                
        if(counting&1) answer += -i;
        else answer += i;
    }
    
    return answer;
}