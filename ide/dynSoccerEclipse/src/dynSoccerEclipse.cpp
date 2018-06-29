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
#include "app/fundamental/impl/number/SNumber.h"
#include "app/fundamental/impl/test/CNumberTest.h"
#include "app/test/CTestMITStateMachine.h"

using namespace std;

int f(int a)
{
	printf("HHH\r\n");
	return 1;
}

int testStateMachine()
{
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

	Delay<int> smDelay(99);
	Delay<int> smDelay2(22);
	vector<int> vCascadeOut;
	int inputCascade[] = { 3, 8, 2, 4, 6, 5 };

	int t;

	smDelay.start();
	smDelay2.start();
	MITSMCascade<int,int,int,int,int> cascade_Delay(&smDelay, &smDelay2);

	cascade_Delay.start();
	cascade_Delay.transduce(inputCascade, 6, vCascadeOut);

	printf("Casecase Delay\r\n");
	Console::log(vCascadeOut);

	/*
	smDelay.start();
	smDelay2.start();
	MITSMCascade<int, int> cascadeDelay(&smDelay, &smDelay2);
	

	cascadeDelay.start();
	cascadeDelay.transduce(inputCascade, 6, vCascadeOut);
	Console::log(vCascadeOut);

	Delay<int> smDelay3(99);
	Delay<int> smDelay4(22);
	vector<int> vCascadeOut2;
	int inputCascade2[] = { 3, 8, 2, 4, 6, 5 };

	smDelay3.start();
	smDelay4.start();
	MITSMCascade2<int,int> cascadeDelay2(&smDelay3, &smDelay4);
	cascadeDelay2.start();
	cascadeDelay2.transduce(inputCascade2, 6, vCascadeOut2);
	Console::log(vCascadeOut2);
	*/

	return 0;
}

int main() {
	CNumberTest test;
	test.runTest("../../../test/test_number.txt");

	SNumber s1("10");
	SNumber s2("113");

	SNumber s3 = s1 + s2;
	cout << s3.rawData().number_ << endl;

	CTestMITStateMachine testMsm;
	testMsm.runTest();

	testStateMachine();
	return 0;
}
