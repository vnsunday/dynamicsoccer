#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include "app/fundamental/lib/mytree.h"
#include "app/fundamental/impl/statemachine/accumulator2.h"

using namespace std;

int f(int a)
{
	printf("HHH\r\n");
	return 1;
}

int main() {
	TreeNode<int,string> t(1, "HI");
	int (*pp)(int);

	int x;

	pp = &f;
	pp(1);

	CAccumulator2<int> acc(1);
	acc.start();
	int x2 = acc.step(2);

	int inputs[3] = { 5, 10, 15};
	vector<int> output;
	acc.transduce(&inputs[0], 3, output);

	printf("Next values = %d\r\n", x2);

	return 0;
}
