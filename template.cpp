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


// 余弦定理，求c的对的角，弧度制
double angle(double a, double b, double c) {
  return acos((a * a + b * b - c * c) / (2 * a * b));
}