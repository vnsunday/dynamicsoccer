#include "tree.h"
#include <math.h>
#include <algorithm>
using namespace dynsocc;
using namespace std;

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

class TreeTechnique
{
	public:
		/* Build: Using data structure to define parent-child relationshop of treenode */
		void parent_child_Establish()
		{
			int parent_id = 0;
			int child_id = 0;

			/*
			* Each node has Unique ID; 
			*/

			int n = 0;
			unsigned char* pMapBuffer;
			int MAX_PAIR = 0;

			pMapBuffer = (unsigned char*)malloc(MAX_PAIR*2);

			int i = 0;
			pMapBuffer[i << 2] = child_id;
			pMapBuffer[i << 2 + 1] = parent_id;	// Map Buffer

			// Add New 
			int nID = 0;			
			int layout[10];	// Ten level


			// Find cycle
			// Valid? 

			// TreeAddress
			free(pMapBuffer);
		}

		

		void dummy_arrange()
		{
			// Degree (20)
			struct Node
			{
				int data;
				double data1;

				int nchild;
				int loc_start[20];	// Relative position 
				int loc_end[20];	// Relative position
			};

			// 1st Element is the Root
			int const MAX_SIZE=100;
			int n;
			int loc_start[100];
			int loc_end[100];

			Node arr[100];
			// Initialize list
			arr[0].data = 0;
			arr[0].data1 = 0.0;

			arr[0].nchild = 4;
			arr[0].loc_start[0] = 0;
			arr[0].loc_end[0] = 10;

			// Degree 
			loc_start[0] = 0;	// The range of [Start, End)
			loc_end[0] = 100;
			// Lookup address
			int lookup[MAX_SIZE];
		}

		int fully_binary_init_layout(int n)
		{
			return (2 << (n+1) - 1);
		}

		int narrow_init_layout(int n)
		{
			/*
			 * 1 + x + x^2 + .. + x^(n-1) = (x^(n)-1)/(x-1)
			 */
			return 2 * (pow(1.5, (n)) - 1); // = 1 + 1.5 + 1.5^2 + ... + 1.5^(n-1)
											// = (1.5^n - 1)*2
		}

		int relayout(int layer, int curr_layout[])
		{
			// Current layout
			// Position which changes 

			layer = 0;	// layer change
			// int curr_layout[100];
			int nolayout;

			struct RelayoutNeed
			{
				int layer_index;		// layer that need extends
				int layer_size_curr;	// Current layer size 
				int current_layout[];	// Current layout size
			};

			int tree[100];		// Tree with container size = 100.
			int layout[100];	
			int n = 0;
			int m = 0;
			int sz = sizeof(tree)/sizeof(int);
			int nlayout;	// N-layout

			// Initialization layout 
			nlayout = 5;
			for (int i=0; i<nlayout;++i) 
			{
				layout[i] = 1 << i;
			}
			
			// Re-layout 
			int nlayout_needs = 2;
			layout[nlayout_needs] += 10;

			// int Add Node.
			int value;
			tree[0] = 0;
			
			return 0;
		}

		int remove_from_array(std::vector<int>& v, int idx)
		{
			if (idx >=0 && idx < v.size())
			{
				return 0;
			}

			return -1;
		}

		int vector_adjacentlist_tree()
		{
			int raw_data[1000];
			int tree_structure[2000];
			int CountEdge = 0;	// 
			int CountNode = 0;

			int arr[1000];
			int narr = 0;
			int stack[1000];
			int nstack = 0;

			/*********************************************************************************
			 *	Function-001: Is new Parent-Child relationship valid?
			 *		
			 *********************************************************************************/
            {
                bool isValid = true;
                int new_parent = 10;    //Any number
                int new_child = 11;     //Any ID;

                stack[nstack++] = new_parent;
                while (nstack > 0)  
                {
                    int element = stack[--nstack];
                    arr[narr++] = element;

                    for (int i=0; i<CountEdge;++i)
                    {
                        // A (Parent,Child) = (tree_structure[2*i], tree_structure[2*i+1])
                        // i << 1 = 2*i
                        if (tree_structure[i << 1 + 1] == new_child)
                        {
                            stack[nstack++] = tree_structure[i << 1];   // Add to stack
                        }
                    }
                }

                // Now arr contains every ancestor of new_parent
                // If new_child is in ancestor list => INVALID
                if (std::find(arr, arr + narr, new_child) != arr + narr)
                {
                    isValid = false;
                }

                printf("IsValid RelationShip %d\r\n", isValid);
            }
            
            /*********************************************************************************
			 *	Function-001: AddNewNode (IfValie)
			 *********************************************************************************/
            {
                
            }

			return 0;
		}
};

TreeAdj::TreeAdj()
{
	_n_id2index = 0;
	_m_id2index_l[0] = 0;
	_m_id2index_r[0] = 0;
}

int TreeAdj::add_node(int parent_id, std::string name)   // Parent-ID < 0 => Adding a root node 
{
	/*========================================================
		Node management:
			+ NodeAddress:
				PhysicalAddress:	Index	(Access Physical memory)(Will change?)
				UniqueID:			AutoID	
			+ Manage:
				AutoID to Index mapping (Map: vector of R^2)
	 *========================================================*/

	// Is Parent ID valid?
	//	Performing Binary Searcheing
	int nL = 0;
	int nR = _n_id2index;
	int nMid = (nL + nR) / 2;
	int nFound = -1;

	// is adding a Root Node?
	if (parent_id < 0)
	{
		// Another Root Node is existed?
		if (_nRootID >= 0)
		{
			// ??
			throw "Root Node is existed";
		}
	}
	else
	{
		while (nL <= nR && nFound < 0)
		{
			int nValMid = _m_id2index_l[nMid];
			if (nValMid == parent_id)
			{
				nFound = nMid;
			}
			else if (parent_id < nValMid)
			{
				nR = nMid - 1;
			}
			else
			{
				nL = nMid + 1;
			}
		}

		if (nFound < 0)
		{
			// 
			throw "ParentID Invalid";
		}
	}
	

	// Vector of a Node 
	_auto_id++;
	int nID = _auto_id;		// Node Address
	int nIndex = _nNode;	// Node Address
	_nNode++;
	
	_vname[nIndex] = name;		
	_vid[nIndex] = _auto_id;

	
	

	// Add a mapping?
	// 1st element sastified:
	//		left[loc] >= new_key
	// Validation?
	//		
	int nInsertLoc = 0;
	while (nInsertLoc < _n_id2index && _m_id2index_l[nInsertLoc] < nID)
	{
		nInsertLoc++;	
	}

	if (nInsertLoc >= _n_id2index)	// Do not find => Insert at the end 
	{
		_m_id2index_l[_n_id2index] = nID;
		_m_id2index_r[_n_id2index] = nIndex;
		_n_id2index++;
	}
	else if (_m_id2index_l[nInsertLoc] == nID)		// Duplicate? => Replace
	{
		_m_id2index_r[_n_id2index] = nIndex;	// Replace
	}
	else
	{
		// Insert into right position 

		//1) Move everything 1-position forward
		for (int i = _n_id2index; i > nInsertLoc; i--)
		{
			_m_id2index_l[i] = _m_id2index_l[i - 1];
			_m_id2index_r[i] = _m_id2index_r[i - 1];
		}
		_n_id2index++;

		//2) Insert
		_m_id2index_l[nInsertLoc] = nID;
		_m_id2index_r[nInsertLoc] = nIndex;
	}

	// New Root Node
	if (parent_id < 0)
	{
		_nRootID = nID;
		return 0;

	}

	// Register Relationship Graph 
	// Insert one relationship record (new_L,new_R) = (parent_id, new_id).
	// 
	// Find the smallest Location (loc) where: 
	//		(vedgeL[loc] == new_L and vedgeR[loc]>=new_R)
	//		or
	//		(vedgeL[loc] >= new_L)
	nInsertLoc = 0;
	while (nInsertLoc < _n_edge &&
		(_v_edge_l[nInsertLoc] < parent_id
			||
			(_v_edge_l[nInsertLoc] == parent_id && _v_edge_r[nInsertLoc] < nID)))
	{
		nInsertLoc++;
	}

	if (nInsertLoc >= _n_edge)
	{
		// Append at the last position
		_v_edge_l[_n_edge] = parent_id;
		_v_edge_r[_n_edge] = nID;
		_n_edge++;
	}
	else
	{
		// Move everything one-position forward 
		for (int i = _n_edge; i > nInsertLoc; i--)
		{
			_v_edge_l[i] = _v_edge_l[i - 1];
			_v_edge_r[i] = _v_edge_r[i - 1];
		}
		_n_edge++;

		// Insert
		_v_edge_l[nInsertLoc] = parent_id;
		_v_edge_r[nInsertLoc] = nID;
	}
	
	return 0;
}


int TreeAdj::new_node(std::string name)						// Node only, stand alone
{
	_auto_id++;
	int nID = _auto_id;
	int nIndex = _nNode;
	_nNode++;

	_vname[nIndex] = name;

	// Register mapping (ID,Index)
	int nInsertLoc = 0;

	while (nInsertLoc < _n_id2index && ( _m_id2index_l[nInsertLoc] <nID))
	{
		nInsertLoc++;
	}

	// Reach the end
	if (nInsertLoc >= _n_id2index)
	{
		_m_id2index_l[_n_id2index] = nID;
		_m_id2index_r[_n_id2index] = nIndex;
		_n_id2index++;
	}
	else if (_m_id2index_l[nInsertLoc] == nID)	// Duplicate(??)
	{
		_m_id2index_r[nInsertLoc] = nIndex;		// Replacement
	}
	else
	{
		// Move everything 1 slot forward (starting from nInsertLoc+1)
		for (int i = _n_id2index; i > nInsertLoc; i--)
		{
			_m_id2index_l[i] = _m_id2index_l[i - 1];
			_m_id2index_r[i] = _m_id2index_r[i - 1];
		}
		_n_id2index++;

		// Insert 
		_m_id2index_l[nInsertLoc] = nID;
		_m_id2index_r[nInsertLoc] = nIndex;
	}

	return 0;
}

int TreeAdj::get_node(int ID, std::string& data)
{
	// Binary Search
	int nL = 0;
	int nR = _n_id2index;
	int nMid = (nL + nR) / 2;
	int nVal; // 
	int nFound = -1;

	while (nL < nR && nFound < 0)
	{
		nVal = _m_id2index_l[nMid];

		if (nVal == ID)
		{
			nFound = nMid;
		}
		else if (nVal < ID)
		{
			nR = nMid - 1;
		}
		else
		{
			nL = nMid + 1;
		}
	}

	if (nFound >= 0)
	{
		int nIndex = _m_id2index_r[nFound];
		data = _vname[nIndex];
		return 0;
	}
	else
	{
		return 1;
	}
}

int TreeAdj::remove_node(int node_id)
{
	/*
		1. Remove node_id
		2. Remove every descendants 
	 */

	int nID = node_id;

	int nL = 0;
	int nR = _n_id2index;
	int nMid = 0;
	int nFindIndex = -1;

	algorithm::binary_search(_m_id2index_l, 0, _n_id2index, node_id, nFindIndex);

	// Find every Edge, where is children of 
	// Starting with n1
	//	Ending with n1
	int nLower, nHigher;
	algorithm::binary_search(_v_edge_l, 0, _n_edge, node_id, nLower, nHigher);

	if (nLower >= 0)
	{
		// binary map 
	}

	// Starting from, n1, n2 && 
	// Find every children 
	dvqueue<int> q1(100);
	vector<int> v1;
	q1.enqueue(node_id);

	int nnode;

	while (!q1.empty())
	{
		assert(q1.dequeue(nnode)==0);
		v1.push_back(nnode);

		algorithm::binary_search(_v_edge_l, 0, _n_edge, nnode, nLower, nHigher);

		if (nLower>=0)
		{
			for (int i=nLower; i<=nHigher;++i)
			{
				q1.enqueue(_v_edge_r[i]);
			}
		}
	}

	return 0;
}

int TreeAdj::move_node(int node_id, int new_parent_id)
{
	return 0;
}