#include <bits/stdc++.h>

using namespace std;

int root[10001];
int selling[10001];

void find(int child, int money) {
    if(child == 0) return;
    
    int div = money * 0.1;
    
    if(div == 0) {
        selling[child] += money;
        return;
    }
    
    selling[child] += money - div;
    
    return find(root[child], div);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    map<string, int> mp;
    
    for(int i = 1; i <= enroll.size(); i++)
        mp[enroll[i-1]] = i;
    
    for(int i = 1; i <= enroll.size(); i++) {
        if(referral[i-1] == "-")
            root[mp[enroll[i-1]]] = 0;
        else
            root[mp[enroll[i-1]]] = mp[referral[i-1]];
    }
    
    for(int i = 0; i < seller.size(); i++)
        find(mp[seller[i]], amount[i] * 100);
    
    for(int i = 1; i <= enroll.size(); i++)
        answer.push_back(selling[i]);
    
    return answer;
}