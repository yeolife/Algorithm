#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
#define x first
#define y second

int n, m, l;
int arr[53];

bool pram(int mid) {
  if (mid == 0)
    return true;

  int cnt = 0;
    
  for (int i = 1; i < n; i++) {
    if (arr[i] - arr[i - 1] <= mid || arr[i] - arr[i - 1] == 1)
      continue;

    cnt += (arr[i] - arr[i - 1]) / mid;
    if ((arr[i] - arr[i - 1]) % mid == 0)
      cnt--;
  }

  if (cnt >= m) {
    if (cnt == m)
      return false;
    return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  cin >> n >> m >> l;

  int tmp[53];
  for (int i = 0; i < n; i++)
    cin >> tmp[i];

  sort(tmp, tmp + n);

  int idx = 0;
  if (tmp[0] > 1) {
    arr[0] = 0;
    idx++;
  }

  for (int i = 0; i < n; i++)
    arr[i + idx] = tmp[i];

  if (arr[n - 1 + idx] < l) {
    arr[n + idx] = l;
    idx++;
  }

  n += idx;

  int lo = 0, hi = 1e9;
  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2;

    if (pram(mid))
      lo = mid;
    else
      hi = mid;
  }

    cout << hi;

  return 0;
}