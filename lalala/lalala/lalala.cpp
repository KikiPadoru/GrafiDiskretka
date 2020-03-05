#include <iostream>
#include <vector>

using namespace std;


int main() {
	int kol;
	cout << "Koli4estvo Vershin ";
	cin >> kol;
	vector<char> buk(kol);
	vector <int> sun(kol);
	for (int i = 0; i < kol; i++) {
		cin >> buk[i];
		cin >> sun[i];
	}
	vector < vector <int>>mass(kol, vector <int>(kol));
	vector< int> la(kol * kol);
	int res = sun[0];
	int zn = 1;
	int y = 0;
	int z = 1;
	while (res > 0) {
		z = z - 1;
		y++;
		if (zn == y) {
			mass[0][y] = 1;
			res = res - 1;
			for (int r = 0; r < kol * kol && sun[y] != 0; r++) {
				if (la[r] == 0) {
					la[r] = y;
					break;
				}
			}
		}
		if (sun[y] >= 1) {
			z = sun[y] + 1;
			zn += sun[y] + 1;
		}
		else {
			if (z == 0) {
				zn++;
				z = 1;
			}
		}
	}
	for (int i = 0; la[i] != 0; i++) {
		int res = sun[la[i]];
		int zn = la[i] + 1;
		int y = la[i];
		vector <int> las(kol * kol);
		z = 1;
		while (res > 0) {
			z = z - 1;
			y++;
			if (zn == y) {
				mass[la[i]][y] = 1;
				res = res - 1;
				for (int r = 0; r < kol * kol && sun[y] != 0; r++) {
					if (las[r] == 0) {
						las[r] = y;
						break;
					}
				}
			}
			if (sun[y] >= 1) {
				z = sun[y] + 1;
				zn += sun[y] + 1;
			}
			else {
				if (z == 0) {
					zn++;
					z = 1;
				}
			}
		}
		if (la[i + 1] == 0) {
			for (int r = 0; r < kol * kol; r++)la[r] = las[r];
			i = 0;
		}
		if (la[0] == 0)break;

	}

	cout << "  ";
	for (int i = 0; i < kol; i++) cout << buk[i] << " ";
	cout << endl;
	for (int i = 0; i < kol; i++) {
		cout << buk[i] << " ";
		for (int j = 0; j < kol; j++) {
			cout << mass[i][j] << " ";
		}
		cout << endl;
	}
	cin >> kol;

}