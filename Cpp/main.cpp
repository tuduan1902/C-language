#include<iostream>
#include<stdlib.h>
using namespace std;
struct PHANSO {
	int t, m;
};

void rutGon(PHANSO& x);
PHANSO tinhTong(PHANSO a, PHANSO b);
int UCLN(int x, int y);
void nhapPS(PHANSO& x);
void xuatPS(PHANSO& x);

int main() {
	PHANSO a, b;
	nhapPS(a);
	nhapPS(b);
	PHANSO t = tinhTong(a, b);
	xuatPS(t);
	return 0;
}

int UCLN(int x, int y) {
	x = abs(x);
	y = abs(y);
	if (x * y == 0)
		return x + y;
	while (x != y) {
		if (x > y) {
			x = x - y;
		}
		else {
			y = y - x;
		}
	}
	return x;
}

void rutGon(PHANSO& x) {
	int uc = UCLN(x.t, x.m);
	x.t = x.t / uc;
	x.m = x.m / uc;
}

PHANSO tinhTong(PHANSO a, PHANSO b) {
	PHANSO tong;
	tong.t = a.t * b.m + a.m * b.t;
	tong.m = a.m * b.m;
	rutGon(tong);
	return tong;
}

void nhapPS(PHANSO &x) {
	cin >> x.t >> x.m;
}

void xuatPS(PHANSO& x) {
	cout << x.t << "/" << x.m;
}
