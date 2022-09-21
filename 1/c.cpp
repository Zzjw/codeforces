#include<cstdio>
#include<iostream>
#include<cmath>
#include<map>
#include<vector>
#include<set>
#include<string>
#define fo(i,j,k) for(auto i=(j); i<=(k); ++i)
using namespace std;
using ll = long long;

const double eps = 1e-6;
const double Pi = 3.1415926535897;

double angle(double a, double b, double c) {
  return acos((a * a + b * b - c * c) / (2 * a * b));
}

struct node{
	double x, y;
}a[3];
double len(int P, int Q) {
	node p = a[P];
	node q = a[Q];
	return sqrt((p.x-q.x) * (p.x-q.x) + (p.y-q.y) * (p.y-q.y));
}

double gcd(double a, double b, double mid) {
	if (fabs(b) < mid) {
		return a;
	}
	ll times = a/b;
	return gcd(b, a - times * b, mid);
}

ll get_n(double mid, const vector<double>& value) {
	double r_gcd = gcd(gcd(value[0], value[1], mid), gcd(value[1], value[2], mid), mid);
	return ll(value[0] / r_gcd) + ll(value[1] / r_gcd) + ll(value[2] / r_gcd);
}

int main() {
	freopen("../../1.in", "r", stdin);
	fo(i,0,2) {
		scanf("%lf%lf", &a[i].x, &a[i].y);
	}
	
	vector<double> angles;
	fo(i,0,2) {
		int pre = (i + 2) % 3;
		int next = (i + 1) % 3;

		angles.push_back(2 * angle(len(pre, i), len(i, next), len(pre, next)));
	}
//	printf("%lf %lf %lf\n", angles[0], angles[1], angles[2]);

	double l = 1e-4;
	double r = 1;
	while (r - l > eps) {
		double mid = (l + r) / 2;
		if (get_n(mid, angles) > 100) {
			l = mid;
		} else {
			r = mid;
		}
	}

	int chose = 1;
	if (len(0,2) < len(0,1)) {
		// avoid chose right angle
		chose = 2;
	}
	double one_line = len(0,chose);
	double one_angle = 2*angle(len(0,3-chose), len(chose,3-chose), one_line);
	double R_angle = (Pi - one_angle) / 2.0;
	double R = sin(R_angle) / sin(one_angle) * one_line;
	ll n = get_n(l, angles);

	printf("%lf\n", n * sin(2.0 * Pi / n) / 2 * R * R);
	return 0;
} 
