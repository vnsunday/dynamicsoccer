#ifndef DYNSOCC_FUNDAMENTAL_STDEX_TREE_H_
#define DYNSOCC_FUNDAMENTAL_STDEX_TREE_H_

#include <vector>
#include <string>
#include <queue>

namespace dynsocc
{
    struct TreeEx
    {   
        std::string strData;
        int iData;
        double dData;

        std::vector<TreeEx>* v;
        TreeEx();

        int addNode(TreeEx e);
        void operator=(const TreeEx& t);

		  bool hasChild();
		  const std::vector<TreeEx>* getVChild();
    };

    struct TreeVec;
	 typedef unsigned char TreeNodeAddr;
	 struct TreeVecNode
	 {
		 int myid;
		 int parentid;
		 std::vector<int> childid;

		 int data;
	 };

    // Tree based on vector
    struct ITreeVecTravesal
    {
        // Node => If you remove node from tree here => crash 
        virtual int onTravelNode(TreeVecNode& node) = 0;
    };

    // Definition of a Tree.
    struct TreeNodeAddress
	{
		 unsigned char a[10];	// Maximum 10 Tree Level
         int n;
         int myRaw;

         TreeNodeAddress()
         {
             n = 0;
         }
	};

    /* 
     * Implement a tree with:
     *  (1) Maximum 10 deep level
     */
    struct TreeVec
    {
        std::vector<TreeVecNode> data;      // Raw data
        TreeNodeAddress mapTrR[100];        // Map TreeAddress to RawData address
                                            // mapTrR: TreeAddress -> RawAddress)
        TreeNodeAddress addr001;
        unsigned char* buffer;

        TreeVecNode newNode()
        {
            TreeVecNode n1;
            n1.myid = data.size();
            n1.parentid = -1;
            n1.childid.clear();

            data.push_back(n1);
       }

        TreeVecNode newChildNode(int parentId)
        {
            TreeVecNode n1;
            n1.myid = data.size();
            n1.parentid = -1;
            n1.childid.clear();

            data.push_back(n1);


            // Relationship Between 
        }

        int removeNode(int nodeId)
        {
            // Remove ID => Recalculate whole ID? 
            // 
            int i = 0;
            data[i];

            return 0;
        }

        int getChild(int nodeId, std::vector<TreeVecNode>& vchild)
        {
            vchild.clear();
            int l01 = data.size();

            for (int i=0; i<l01; ++i)
            {
                
            }
            return 0;
        }

        // Think: remove node while travelling all node? 
        void travesalAllChildNode(TreeVecNode& node, ITreeVecTravesal* p)
        {
            // 
            // int a;
            // 
            int a[100];
            int n;
            n = 0;

            p->onTravelNode(node);

            std::queue<TreeVecNode> qnode;
            TreeVecNode n1 = qnode.front();

            for (unsigned int i=0; i<node.childid.size();++i)
            {
                qnode.push(data[node.childid[i]]);
            }
            
            while (qnode.size() > 0)
            {
                TreeVecNode trvnode;
                trvnode = qnode.front();
                qnode.pop();
                
                p->onTravelNode(trvnode);
                for (unsigned int i=0; i<trvnode.childid.size(); ++i)
                {
                    qnode.push(data[trvnode.childid[i]]);
                }
            }
        }
    };

	#define ADJTREE_MAX_NODE 100
	#define ADJTREE_MAX_EDGE 1000

    class TreeAdj
    {
		 
		/* 
			Primitive Operations: 
			+ Node LifeCycle 
				- Node Address:
					+ ID (Unique value) 
					+ Location (Physical location: index)
				- Manage Node List Data (vector Node)
				- Mange Node 
			+ Edge LifeCycle 

		 
		 */
        std::string _vname[ADJTREE_MAX_NODE];
        int _vid[ADJTREE_MAX_NODE];
		int _auto_id;
		int _nNode;

        int _v_edge_l[1000];
        int _v_edge_r[1000];
		int _n_edge;

		int _nRootID;	// RootNode

		// Binary Tree - Mapping (AutoID - Index)
		int _m_id2index_l[1000];
		int _m_id2index_r[1000];
		int _n_id2index;

	public:
		TreeAdj();
        int add_node(int parent_id, std::string name);		// Parent-ID < 0 => Adding a root node 
		int new_node(std::string name);						// Node only, stand alone
		int get_node(int ID, std::string& data);
        int remove_node(int node_id);
		int move_node(int node_id, int new_parent_id);
		

        //
        // v_edge_l[i]=n
        // v_edge_r[i]=m
        //  => n is parent node of m.
        // 
        // Tree-ID.
        //  vid[1]=i => 

    private:
        int add_relation_ship(int parent_id, int child_id);

    };

	class algorithm
	{
	public: 
		template <typename T>
		static int binary_search(T* arr_sorted_asc, int nBegin, int nEnd, T val, int& nFound)
		{
			int nL = nBegin;
			int nR = nEnd;
			int nMid = (nL + nR) / 2;
			nFound = -1;
			T valMid;
			while (nL < nR && nFound < 0)
			{
				valMid = arr_sorted_asc[nMid];

				if (valMid == val)
				{
					nFound = nMid;
				}
				else if (valMid < val)
				{
                    nL = nMid + 1;
				}
                else 
                {
                    nR = nMid - 1;
                }
			}

			return 0;
		}

        template <typename T>
        static int binary_search(T* arr_sorted_asc, int nBegin, int nEnd, T val, int& nFoundBegin, int& nFoundEnd)
        {
            // Find every 
            int nL = nBegin;
            int nR = nEnd;
            int nMid = (nL + nR) / 2;
            int nFound = -1;
            nFoundBegin = -1;
            nFoundEnd = -1;

            // The 1st location 
            while (nL < nR && nFound < 0)
            {
                valMid = arr_sorted_asc[nMid];

                if (valMid == val)
                {
                    nFound = nMid;
                }
                else if (valMid < val)
                {
                    nL = nMid + 1;
                }
                else 
                {
                    nR = nMid - 1;
                }
            }


            if (nFound >=0)
            {
                nFoundBegin = nFound;
                nFoundEnd = nFound;


                while (nFoundBegin > nBegin && arr_sorted_asc[nFoundBegin-1] == val)  { nFoundBegin--;}
                while (nFoundEnd < nEnd-1 && arr_sorted_asc[nFoundEnd+1] == val ) { nFoundEnd++;}
            }
            
            return 0;
        }

        
		template<typename T>
		static int insert_into_sorted_asc(T* parr, int nBegin, int nEnd, T val, int& nPos)
		{
            // Pre-Requisite: parr is sorted asc (every i: p[i] <= p[i+1])
            // This function does not validate pre-requisite condition 
           
            // Find the 1st position (smallest) where 
            //      parr[pos] < val
            nPos = 0;
            while (nPos < nEnd && parr[nPos] >= val) { nPos++; }

            // Starting from nPos+1, move everything forward
            for (int i=nEnd; i> nPos;i--)
            {
                parr[i] = parr[i-1];
            }

            // Insert at nPos
            parr[nPos] = val;
            return 0;
		}

        template<typename T>
        static int insert_into_sorted_asc(T* parr, int nBegin, int nEnd, T val, int& nPos)
        {
            // Pre-requisite: parr is sorted desc (p[i] >= p[i+1], every i)
            // If the pre-requisite condition is not meet => the result will incorrect, 
            // This function does not validate pre-requisite condition.

            // Find the 1st position where val >= p[loc]
            nPos = nBegin;

            while (nPos < nEnd && (val < parr[nPos]))
            {
                nPos++;
            }

            // Starting from nPos+1, move everything forward 1step
            for (int i=nEnd;i>nPos;i--)
            {
                parr[i] = parr[i-1];
            }

            // Insert 
            parr[nPos] = val;
            return 0;
        }

                
	};
};


#endif