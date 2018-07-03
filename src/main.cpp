#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "app/fundamental/impl/statemachine/sm.h"

int main(int argc, char const *argv[])
{
	MITSM<int,int,int>* p = NULL;
	MITSM<int,int,int> p2(0);
	MITSM<double, double, double>* pD = NULL;

	p = &p2;
	p->step(0);

	SMEx sm2;
	int a = sm2.step<int>(2);

	printf("Test2  LLL %d;\r\n", a);
	return 0;
}