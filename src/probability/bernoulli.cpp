#include <stdlib.h>

int combination(int k, int n) {
	// 
	int ret = 1;
	for (int i=k+1; i<=n; i++) {
		ret = ret * i;
	}

	for (int i=1; i<=n-k;i++) {
		ret = ret / i;
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	return 0;
}