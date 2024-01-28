#include <bits/stdc++.h>
using namespace std;

int n,m,answer=0;
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
vector<vector<int> > vec(9,vector<int>(9,0));
vector<pair<int,int> > cctv;

void counting(vector<vector<int> > tmp) {
    int blindArea=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(tmp[i][j]==0)
                blindArea++;
            else if(blindArea>answer)
                return;
        }
    }
    answer=min(answer,blindArea);
}

vector<vector<int> > coloring(int cnt, int dist, vector<vector<int> > tmp) {
    dist%=4;
    int x,y;
    tie(x,y)=cctv[cnt];
    while(true) {
        x+=dx[dist];
        y+=dy[dist];
        if(x>=0 && y>=0 && x<n && y<m && tmp[x][y]!=6) {
            if(tmp[x][y]!=0)
                continue;
            tmp[x][y]=7;
        }
        else
            break;
    }
    return tmp;
}

void dfs(int cnt, vector<vector<int> > step) {
    if(cnt==cctv.size()) {
        counting(step);
        return;
    }
    vector<vector<int> > tmp;
    if(vec[cctv[cnt].first][cctv[cnt].second]==1) {
        // 상,하,좌,우
        for(int i=0; i<4; i++) {
            tmp=step;
            tmp=coloring(cnt,i,tmp);
            dfs(cnt+1,tmp);
        }
    }
    else if(vec[cctv[cnt].first][cctv[cnt].second]==2) {
        // 상하,좌우
        for(int i=0; i<2; i++) {
            tmp=step;
            tmp=coloring(cnt,i,tmp);
            tmp=coloring(cnt,i+2,tmp);
            dfs(cnt+1,tmp);
        }
    }
    else if(vec[cctv[cnt].first][cctv[cnt].second]==3) {
        // 상우,우하,하좌,좌상
        for(int i=0; i<4; i++) {
            tmp=step;
            tmp=coloring(cnt,i,tmp);
            tmp=coloring(cnt,i+1,tmp);
            dfs(cnt+1,tmp);
        }
    }
    // 좌상우,상우하,우하좌,하좌상
    else if(vec[cctv[cnt].first][cctv[cnt].second]==4) {
        for(int i=0; i<4; i++) {
            tmp=step;
            tmp=coloring(cnt,i,tmp);
            tmp=coloring(cnt,i+1,tmp);
            tmp=coloring(cnt,i+2,tmp);
            dfs(cnt+1,tmp);
        }
    }
    // 상하좌우
    else if(vec[cctv[cnt].first][cctv[cnt].second]==5) {
        step=coloring(cnt,0,step);
        step=coloring(cnt,1,step);
        step=coloring(cnt,2,step);
        step=coloring(cnt,3,step);
        dfs(cnt+1,step);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> vec[i][j];
            if(vec[i][j]>=1 && vec[i][j]<=5)
                cctv.push_back(make_pair(i,j));
            else if(vec[i][j]==0)
                answer++;
        }
    }
    dfs(0,vec);
    cout << answer;
}