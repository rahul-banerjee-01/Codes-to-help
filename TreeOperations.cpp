#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
	int data;
	TreeNode* left;
	TreeNode* right;

    TreeNode()
    {
        left = NULL;
        right = NULL;
    }

    TreeNode(int x)
    {
        data = x;
        left = NULL;
        right = nullptr;
    }
};

TreeNode* create(int data)
{
    TreeNode *newn = new TreeNode();
    newn->data=data;
    newn->left=NULL;
    newn->right=NULL;
    return newn;
}

TreeNode* insert(TreeNode *root, int data)
{
    if(root==NULL)
    {
        TreeNode *newn = new TreeNode;
        newn->data=data;
        root=newn;
    }
    
    else
    {
        if (data < (root->data))
	    {
		    root->left = insert(root->left, data);
	    }
	    else if (data >= root->data)
	    {
		    root->right = insert(root->right, data);
	    }
    }
    return root;
}

void inorder(TreeNode *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

void preorder(TreeNode *root)
{
	if(root != NULL)
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(TreeNode *root)
{
	if(root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
	}
}


void search(TreeNode *root,int val)
{
	if(!root)
	{
		cout<<"\n\nNot Found.";
	}
	else
	{
		if(root->data==val)
		{
			cout<<"\n\n"<<val<<" found.";
			return;
		}
		else
		{
			if(root->data>val)
			{
				search(root->left,val);
			}
				
			if(root->data<val)
			{
				search(root->right,val);
			}
				
		}
	}
}

TreeNode *searchnode(TreeNode *root,int val)
{
	if(!root)
	{
		return NULL;
	}
	else
	{
		if(root->data==val)
		{
			return root;
		}
		else
		{
			if(root->data>val)
			{
				return searchnode(root->left,val);
			}
				
			if(root->data<val)
			{
				return searchnode(root->right,val);
			}
				
		}
	}
}

TreeNode *inorderPredecessor(TreeNode *root, int val)
{
	
	TreeNode* trav = searchnode(root,val)->left;
	while(trav->right!=NULL)
	{
		trav=trav->right;
	}
	return trav;
}

TreeNode *inorderSuccessor(TreeNode *root, int val)
{
	TreeNode* trav = searchnode(root,val)->right;
	while(trav->left!=NULL)
	{
		trav=trav->left;
	}
	return trav;
}

void del(TreeNode *root, int val)
{
	
	if(!searchnode(root,val)->left && !searchnode(root,val)->right)
		searchnode(root,val);
}


bool compareTree(TreeNode *root1, TreeNode *root2)
{
	if(root1 && !root2)
		return false;
	if(!root1 && root2)
		return false;

	bool flag = true;
	if(root1 != NULL && root2!=NULL)
	{
		if(root1->data != root2->data)
		{
			return false;
		}

		flag = compareTree(root1->left, root2->left);
		flag = compareTree(root1->right, root2->right);
	}

	return flag;
}

bool symmetricTree(TreeNode *root)
{
    return mirrorcheck(root->left,root->right);
}

bool checkroots(TreeNode *root1, TreeNode *root2)
{
    if(root1->data != root2->data)
        return false;
    
    return true;
}

bool mirrorcheck(TreeNode *root1, TreeNode *root2)
{
    
    


    return true;
}

void levelOrder(TreeNode *Root)
{
    vector<int> v;
    queue<TreeNode*> q;
    q.push(Root);

    while(!q.empty())
    {
        TreeNode* k =q.front();
        v.push_back(k->data);
        q.pop();
        if(k->left)
            q.push(k->left);
        if(k->right)
            q.push(k->right);
    }
    
    for(auto i:v)
        cout<<i<<" ";
}



main()
{
    TreeNode *root = new TreeNode(2);
    root->left =  new TreeNode(3);
    root->right = new TreeNode(3);

    levelOrder(root);

    cout<<"\n\n\n"<<(mirrorcheck(root)?"Mirror":"Non Mirror");
    




	// TreeNode *root = new TreeNode;
	// root=NULL;
	// queue<int> q;
	// int n;
	// cin>>n;

	// while(n--)
	// {
	// 	int x;
	// 	cin>>x;
	// 	q.push(x);
	// }
	// n=q.size();
	// while(n--)
	// {
	// 	root=insert(root,q.front());
	// 	q.pop();
	// }

	// TreeNode *root1 = new TreeNode;
	// TreeNode *root2 = new TreeNode;

	// root1=NULL;
	// root2=NULL;

	// int n;
	// cin>>n;

	// int i = 0;
	// while(i<n)
	// {
	// 	int x;
	// 	cin>>x;
	// 	root1=insert(root1,x);
	// 	i++;
	// }


	// i = 0;
	// while(i<n)
	// {
	// 	int x;
	// 	cin>>x;
	// 	root2=insert(root2,x);
	// 	i++;
	// }
	// cout<<"\n\nInOrders---\nTree1:\n";
	// inorder(root1);
	// cout<<"\nTree2:\n";
	// inorder(root2);

	// cout<<"\n\nPreOrders---\nTree1:\n";
	// preorder(root1);
	// cout<<"\nTree2:\n";
	// preorder(root2);

	// cout<<"\n\nPostOrders---\nTree1:\n";
	// postorder(root1);
	// cout<<"\nTree2:\n";
	// postorder(root2);

	// cout<<"\n\n\n"<<(compareTree(root1,root2)?"Same":"Different");
	// cout<<"\n\n\n";
	// inorder(root);
	// cout<<"\n";
	// preorder(root);
	// cout<<"\n";
	// postorder(root);

	// del(root,10);
	// cout<<"\n";
	//inorder(root);
	// cout<<endl<<"Predecessor: "<<inorderPredecessor(root,25)->data;
	// cout<<endl<<"Successor: "<<inorderSuccessor(root,25)->data;
	cout<<"\n";
}