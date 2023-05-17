#include <bits/stdc++.h>
using namespace std;

/*

0 = gold
1 = silver

- involves bits (2^0, 2^1, 2^2, ..., 2^n)

find (l1, r1) and (l2, r2)
(1 <= l1, r1 <= n) and (r1 - l1 + 1) >= floor(n / 2) -> more than half
(1 <= l2, r2 <= n) and (r2 - l2 + 1) >= floor(n / 2) -> more than half

1, 2, 3, ..., (n / 2), (n / 2 + 1), ..., (n - 1), n

- at least 1 number in (l1, r1) and (l2, r2) must be different
- ranges can overlap with each other

goal: 
let t = s[l1:r1] and w = s[l2:r2]
f(t) = f(w) * k
basically, f(t) should be a multiple of f(w)

*/

void test_case(int& tc) {
	int n;
	string s;
	cin >> n >> s;
	int pos = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			pos = i + 1;
			break;
		}
	}
	if (pos == 0) {
		cout << "1 " << n - 1 << " 2 " << n;
	} else if (pos < n - n / 2 + 1) {
		cout << pos << " " << n << " " << pos + 1 << " " << n;
	} else {
                // A single left shift multiplies a binary number by 2
		cout << "1 " << pos << " 1 " << pos - 1 << "\n";
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
		test_case(tc);
}
