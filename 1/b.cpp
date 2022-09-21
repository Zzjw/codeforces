#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string> 
using namespace std;

using LL = long long;
const int N = 1e3+50;
char a[N];
inline bool isdigit(char a) {
	return a >= '0'&& a <= '9';
}
bool checkrc(char a[]) {
	if (a[0] != 'R') {
		return false;
	}
	if (!isdigit(a[1])) {
		return false;
	}
	for (int i = 2; a[i]; i++) {
		if (a[i] == 'C') {
			return true;
		}
	}
	return false;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
	scanf("%s", a);
		if (checkrc(a)) {
			int p;
			for (int i = 2; a[i]; i++) {
				if (a[i] == 'C') {
					p = i;
					break;
				}
			}
			int value = 0;
			for (int i = p+1; a[i]; i++) {
				value = value * 10 + a[i] - '0';
			}
			std::string output;
			while (value) {
				if (value % 26 == 0) {
					output += 'Z';
				} else {
					output += (value % 26 + 'A' - 1);
				}
				value = (value - 1) / 26;
			}
			reverse(output.begin(), output.end());
			for (int i = 1; a[i] != 'C'; i ++) output += a[i];
			printf("%s\n", output.c_str());
		} else {
			std::string value;
			int p = 0;
			for(int i = 0; !isdigit(a[i]);i++, p++) {
				value += a[i];
			}
//			reverse(value.begin(), value.end());
			int output = 0;
			for (char a : value) {
				output = output*26 + (a - 'A' + 1);
			}
			printf("R");
			for (int i = p; a[i]; i++) {
				printf("%c", a[i]);
			}
			printf("C%d\n", output);
		}
	}
} 
