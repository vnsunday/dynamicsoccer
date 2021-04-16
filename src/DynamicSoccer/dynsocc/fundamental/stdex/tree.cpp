#include "tree.h"
#include <math.h>
#include <algorithm>
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
