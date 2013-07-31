#include <iostream>
#include <deque>

using namespace std;

const int MAX_SIZE = 9;		// �Ź���

struct Pos {
	Pos(int x, int y) : row(x), col(y) {};
	int row;
	int col;
};

typedef deque <Pos> qpos;
qpos Q;		// ��¼Ҫ�������ֵ�λ��

// �Ź������飬0��ʾ���Ҫ�������ֵ�λ��
int sudoku[MAX_SIZE][MAX_SIZE] = {
	{0, 0, 3, 0, 5, 0, 0, 0, 9},
	{0, 0, 0, 1, 0, 0, 0, 2, 5},
	{0, 8, 0, 0, 3, 7, 0, 0, 0},
	{0, 0, 0, 0, 0, 8, 0, 9, 7},
	{2, 0, 0, 0, 6, 0, 0, 0, 4},
	{9, 4, 0, 0, 0, 0, 8, 0, 1},
	{0, 0, 0, 6, 9, 0, 4, 0, 0},
	{8, 0, 0, 0, 0, 5, 0, 0, 0},
	{6, 0, 0, 0, 1, 0, 9, 0, 0},
};

void printSudoku()
{
	cout << "-------------------------" << endl;
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j <MAX_SIZE; j++) {
			if (j % 3 == 0) {
				cout << "| ";
			}
			cout << sudoku[i][j] << " ";
		}
		cout << "| ";

		cout << endl;
		if ( (i+1) % 3 == 0 ) {
			cout << "-------------------------" << endl;
		}
	}
}

bool check(Pos p, int n)
{
	int cur_row = p.row;
	int cur_col = p.col;
	// ��֤�����Ƿ�ϸ�
	for (int i = 0; i < MAX_SIZE; i++) {
		if (n == sudoku[i][cur_col] || n == sudoku[cur_row][i]) {
			return false;
		}
	}

	// ��֤�Ź��������޸�������
	int grid_row = ( cur_row / 3 ) * 3;
	int grid_col = ( cur_col / 3 ) * 3;
	for (int i = 0; i < 3; i++) {
		if (n == sudoku[grid_row][i + grid_col] || 
			n == sudoku[grid_row + i][grid_col]) {
			return false;
		}
	}

	return true;
}

bool place(qpos & Q)
{
	// �ݹ��������Ϊû��Ҫ�����������ֵ�λ��
	if (Q.empty()) {
		printSudoku();
		return true;
	}
	Pos cur(Q.front().row, Q.front().col);	// ��ǰ��Ҫ���õ�λ����Ϣ
	Q.pop_front();
	for (int i = 1; i <= 9; i++) {		// ��1��9��������
		if ( check(cur, i) ) {
			sudoku[cur.row][cur.col] = i;	// ��������i����ǰλ��
			if ( !place(Q) ) {		// ������һλ��
				// ��һλ�÷���ʧ�ܣ����ڵ�ǰλ�ó��Է�����һ��i
				sudoku[cur.row][cur.col] = 0;	// ����ǰλ��ֵ����
			} else {	// ��һλ�÷��óɹ�
				return true;
			}
		}
	}		
	Q.push_front(cur);	//��ǰλ�ò�����ô�������֣���һλ�ö��޷����óɹ���
				// ���²����λ����Ϣ��������һ������λ��
	return false;
}

int main()
{	
	// Q�б�����Ҫ�������ֵ�λ��
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			if (0 == sudoku[i][j]) {
				Q.push_back(Pos(i, j));
			}
		}
	}

	place(Q);

	return 0;
}