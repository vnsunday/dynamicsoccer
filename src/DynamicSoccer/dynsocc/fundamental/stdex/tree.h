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
    // Tree based on vector
    struct ITreeVecTravesal
    {
        // Node => If you remove node from tree here => crash 
        virtual int onTravelNode(TreeVecNode& node) = 0;
    };

	 struct TreeNodeAddress
	 {
		 unsigned char a[10];	// Maximum 10 Tree Level
         int n;

         TreeNodeAddress()
         {
             n = 0;
         }
	 };

	 typedef unsigned char TreeNodeAddr;

    struct TreeVecNode
    {
        int myid;
        int parentid;
        std::vector<int> childid;

        int data;
    };

    struct TreeVec
    {
        std::vector<TreeVecNode> data;      // Raw data
        TreeNodeAddress mapTrR[100];    // Map TreeAddress to RawData address
        

        
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
};


#endif