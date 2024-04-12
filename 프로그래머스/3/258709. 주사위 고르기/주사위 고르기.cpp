#include <bits/stdc++.h>
using namespace std;

vector<int> v1, v2;
int n, n2;
vector<vector<int>> d;
long long dp1[501], dp2[501], dp11[501], dp22[501];
long long sum1[501], sum2[501];
long long mx = -1;
vector<int> ans;
void go(int depth, int idx) {
   if (depth >= n2) {
       
       v2.clear();
        for(int i = 0, j = 0; i < n; i++) {          
            if(v1[j] != i) v2.push_back(i);
            else j++;
        }
       
      dp1[0] = dp2[0] = 1;
      for (int i = 1; i <= 500; i++) {
         dp1[i] = dp2[i] = 0;
      }
      for (int i = 0; i < n2; i++) {
         for (int j = 0; j < 6; j++) {
            int num = d[v1[i]][j];
            for (int k = 500; k >= num; k--) {
               dp11[k] += dp1[k - num];
            }
            num = d[v2[i]][j];
            for (int k = 500; k >= num; k--) {
               dp22[k] += dp2[k - num];
            }
         }
         for (int j = 0; j <= 500; j++) {
            dp1[j] = dp11[j];
            dp2[j] = dp22[j];
            dp11[j] = dp22[j] = 0;
         }
      }
      for (int i = 1; i <= 500; i++) {
         sum2[i] = sum2[i - 1] + dp2[i];
      }
      long long tmax = 0;
      for (int i = 1; i <= 500; i++) {
         tmax += dp1[i] * sum2[i - 1];
      }
      if (mx < tmax) {
         mx = tmax;
         ans.clear();
         for (int i = 0; i < n2; i++)ans.push_back(v1[i] + 1);
      }
      return;
   }
    
    for(int i = idx; i < n; i++) {
        v1.push_back(i);        
        go(depth + 1, i + 1);
        v1.pop_back();
    }
}

vector<int> solution(vector<vector<int>> dice) {
   n = dice.size();
   n2 = n / 2;
   d = dice;
   go(0, 0);
   return ans;
}