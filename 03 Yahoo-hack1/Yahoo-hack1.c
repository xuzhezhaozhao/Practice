#include <stdio.h>

#define SIZE 100000
#define MAX_INPUT_SIZE 1000

int getMthDigit(int A, int B, int M, int D);

int main()
{
	int n, A, B, M, D;
	int result[MAX_INPUT_SIZE];
	int i;
	scanf("%d", &n);
	fflush(stdout);
	for (i = 0; i < n; i++) {
		scanf("%d %d %d %d", &A, &B, &M, &D);
		fflush(stdout);
		result[i] = getMthDigit(A, B, M, D);
	}
	for (i = 0; i < n; i++) {
		printf("%d\n", result[i]);
	}
	return 0;
}

int getMthDigit(int A, int B, int M, int D)
{

	A = A % B;	/* 将A/B转换为真分式 */
	int loop[SIZE];
	int div[SIZE];
	int circle_len = 1;
	int loop_len = 0;
	int div_len = 0;
	int circle_flag = 0;
	int circle_first, circle_end;	/* 循环部分起始位和结束位 */
	int i;
	int m = 0;
	int count = 0;
	int index[SIZE];

	circle_first = circle_end = 0;

	div[0] = A;
	++div_len;
	while (1) {
		A = A * 10;		
		
		if (0 == A % B) {	/* 除尽，有限小数 */
			circle_flag = 0;
			if (0 != A) {
				loop[loop_len] = A / B;
				++loop_len;
			}
			break;
		}
		loop[loop_len] = A / B;
		++loop_len;

		/* 如果已找到第M个D，则返回 */
		if (D == A / B) {
			++m;
			if (m == M) {
				return loop_len;
			}
		}

		for (i = 0; i < div_len; i++) {
			if (A % B == div[i]) {		/* 循环小数 */
				circle_flag = 1;
				circle_first = i + 1;
				circle_end = div_len;
				break;
			}
		}
		if (circle_first > 0) {
			break;
		}
		div[div_len] = A % B;
		++div_len;
		A = A % B;
	}

	/* 有限小数 */
	if (0 == circle_flag) {
		for (i = 0; i < loop_len; i++) {
			if (D == loop[i]) {
				--M;
			}
			if (0 == M) {
				return (i + 1);
			}
		}
		if (0 == D) {
			return (loop_len + M);
		} else {
			return 0;
		}
	}

	/* 无限循环小数 */
	for (i = circle_first - 1; i <= circle_end - 1; i++) {
		if (D == loop[i]) {
			index[count] = i - circle_first + 2;
			++count;
		}
	}
	for (i = 0; i < circle_first - 1; i++) {
		if (D == loop[i]) {
			--M;
		}
		if (0 == M) {
			return i + 1;
		}
	}
	if (0 == count) {
		return 0;
	}
	circle_len = circle_end - circle_first + 1;
	if ((M % count) != 0) {
		return (circle_first - 1 + M / count * circle_len + index[M%count-1]);
	} else {
		return (circle_first - 1 + (M / count - 1) * circle_len + index[count-1]);
	}
}
