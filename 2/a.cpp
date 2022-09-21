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
 
int main() {
  freopen("../../1.in", "r", stdin);
  map<string, int> score;
 
  int n;
  cin >> n;
  int max_score = 0;
  string winner;
  vector<string> names;
  vector<int> scores;
  fo(i,1,n) {
    string name;
    int get_s;
    cin >> name >> get_s;
    score[name] += get_s;
    names.push_back(name);
    scores.push_back(get_s);
  }
  for (auto iter : score) {
    if (iter.second > max_score) {
      max_score = iter.second;
    }
  }
  map<string, int> get_score;
  vector<string> candidates;
  fo(i,0,n-1) {
    get_score[names[i]] += scores[i] ;
    if (get_score[names[i]] >= max_score) {
      candidates.push_back(names[i]);
    }
  }
  fo(i,0,int(candidates.size() - 1)) {
    if (score[candidates[i]] == max_score) {
      cout << candidates[i];
      return 0;
    }
  }
  return 0;
}
