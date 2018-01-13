#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include "app/fundamental/lib/mytree.h"
#include "app/fundamental/impl/statemachine/accumulator2.h"
#include "app/fundamental/impl/statemachine/CAccumulator.h"
#include "app/fundamental/impl/statemachine/Gain.h"
#include "app/fundamental/impl/statemachine/abc_acceptor.h"
#include "app/fundamental/impl/statemachine/MIT_Example.h"
#include "app/util/Console.h"

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

	vector<double> voutput;
	double inputs[] = { 5, 10, 15};

	CAccumulator acc(1);
	acc.start();
	acc.transduce(inputs, 3, voutput);

	Console::log(voutput);

	double input_gain_[] = { 1.1, -2, 100, 5};
	vector<double> vGain;
	Gain<double> smG(3);
	smG.start();
	smG.transduce(input_gain_, 4, vGain);

	Console::log(vGain);

	char abcInput[] = {'a', 'b', 'c', 'a', 'b', 'c', 'a', 'a', 'b'};
	vector<bool> vABC;
	ABC abcSM;
	abcSM.start();
	abcSM.transduce(abcInput, 9, vABC);

	Console::log(vABC);

	char updownInput[] = {'u', 'u', 'u', 'd', 'd', 'u'};
	vector<int> vUD;
	UpDown smUD(0);
	smUD.start();
	smUD.transduce(updownInput, 6, vUD);
	Console::log(vUD);

	return 0;
}
