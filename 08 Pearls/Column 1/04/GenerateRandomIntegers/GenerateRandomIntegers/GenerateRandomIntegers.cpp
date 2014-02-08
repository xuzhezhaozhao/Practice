#include <fstream>
#include <iostream>
#include <bitset>
using namespace std;

const int N = 1e4;
int main()
{
	ofstream fout("D:\\integers.txt", ios_base::out | ios_base::binary);
	if (!fout.is_open()) {
		cout << "Failed open file!" << endl;
	}
	
	for (int i = N; i > 0; i--) {
		fout.write( (char *)&i, sizeof(i));
	}
	fout.close();

	return 0;
}