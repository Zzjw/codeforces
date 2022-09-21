#include<cstdio>
using namespace std;
 
using LL = long long;
int main() {
	LL n,m,a;
	scanf("%lld%lld%lld", &n,&m,&a);
	printf("%lld\n", (n+a-1)/a * ((m+a-1)/a));
} 
