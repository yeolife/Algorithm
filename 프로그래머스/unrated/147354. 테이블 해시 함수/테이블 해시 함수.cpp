#include <bits/stdc++.h>

using namespace std;

int colume;

bool cmp(vector<int>& a, vector<int>& b) {
    if(a[colume] == b[colume])
        return a[0] > b[0];
    return a[colume] < b[colume];
} 

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    colume = col-1;
    
    sort(data.begin(), data.end(), cmp);
    
    int st = row_begin;
    int target = 0;
    
    for(int i = st-1; i < row_end; i++) {
        int sum = 0;
        for(int j = 0; j < data[i].size(); j++)
            sum += data[i][j]%(i+1);
        
        target ^= sum;
    }
    
    return target;
}