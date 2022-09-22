#include<cstdio>
#include<iostream>
#include<cmath>
#include<map>
#include<vector>
#include<set>
#include<string>

#define fo(i,j,k) for(auto i = (j); i <= (k); ++i)
#define fd(i,j,k) for(auto i = (j); i >= (k); --i)
#define lowbit(x) ((x) & (-x))
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int N = 1e3+10;
ll a[N][N];
ll dp[N][N];
int n;
int dir[2][2] = {{0, -1}, {-1, 0}};
char dir_s[3] = "RD";
int from[2][N][N];

ll cal(ll ori, ll value) {
  ll cnt = 0;
  while(ori % value == 0) {
    ori /= value;
    cnt ++;
  }
  return cnt;
}
ll get(ll value, int idx) {
  fo(i,0,n) fo(j,0,n) dp[i][j] = 32ll * 1000 * 1000;
  dp[1][1] = cal(a[1][1], value);
  fo(i,1,n) {
    fo(j,1,n) {
      if (a[i][j] == 0 || (i==1 && j==1)) {
        continue;
      }
      if (dp[i-1][j] < dp[i][j-1]) {
      	from[idx][i][j] = 1;
	  } else {
      	from[idx][i][j] = 0;
	  }
      dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + cal(a[i][j], value);
    }
  }
  return dp[n][n];
}

void print(int idx, ll x, ll y) {
  if (x == 1 && y == 1) {
    return;
  }
  print(idx, x + dir[from[idx][x][y]][0], y + dir[from[idx][x][y]][1]);
  printf("%c", dir_s[from[idx][x][y]]);
}

int main() {
  freopen("../../1.in", "r", stdin);
  scanf("%d",&n);
  bool has_zero = 0;
  int zero_x, zero_y;
  fo(i,1,n) {
    fo(j,1,n) {
      scanf("%d", &a[i][j]);
      if (a[i][j] == 0) {
        has_zero = true;
        zero_x = i, zero_y = j;
      }
    }
  }

  ll ans1 = get(2,0);
  ll ans2 = get(5,1);
  ll ans3;
  if (has_zero) {
    ans3 = 1;
  } else {
    ans3 = 32ll * 1000 * 1000;
  }

  if (ans1 <= ans2 && ans1 <= ans3) {
    printf("%lld\n", ans1);
    print(0,n,n);
  } else if (ans2 <= ans1 && ans2 <= ans3) {
    printf("%lld\n", ans2);
    print(1,n,n);
  } else {
    printf("%lld\n", ans3);
    fo(i,1,zero_x-1) printf("D");
    fo(i,1,zero_y-1) printf("R");
    fo(i,zero_x,n-1) printf("D");
    fo(i,zero_y,n-1) printf("R");
  }
  return 0;
}
