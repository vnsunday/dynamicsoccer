#include "tree.h"

using namespace dynsocc;

TreeEx::TreeEx()
{
    iData = 0;
    dData = 0.0;
    strData = "";

	 v = NULL;
}

int TreeEx::addNode(TreeEx e)
{
	if (v == NULL)
	{
		v = new std::vector<TreeEx>();
	}
    
	v->push_back(e);
	return 0;
}

void TreeEx::operator=(const TreeEx& t)
{
    iData = t.iData;
    strData = t.strData;
    dData = t.dData;
}

bool TreeEx::hasChild()
{
	return v != NULL && v->size() > 0;
}

const std::vector<TreeEx>* TreeEx::getVChild()
{
	return v;
}