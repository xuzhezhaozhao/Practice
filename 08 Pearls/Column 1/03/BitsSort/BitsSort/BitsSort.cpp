#include <iostream>
#include <bitset>
#include <fstream>
#include <cstdlib>
using namespace std;

const int N = 1e4 + 1;
bitset <N> bits;
int main()
{
	ifstream fin("D:\\integers.txt", ios_base::in | ios_base::binary);
	ofstream fout("D:\\SortedIntegers.txt", ios_base::out | ios_base::binary);
	if (!fin.is_open() || !fout.is_open()) {
		cout << "File open failed !" << endl;
		exit(-1);
	}
	int n;
	for (int i = 1; i < N; i++) {
		if ( fin.read( (char *)&n, sizeof(int) ) ) {
			bits.set(n);
		} else {
			cout << "read failed!" << endl;
			break;
		}
	}

	for (int i = 0; i < bits.size(); i++) {
		if (bits[i]) {
			fout << i << endl;
		}
	}

	fin.close();
	fout.close();

	return 0;
}