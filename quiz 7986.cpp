#include<iostream>

using namespace std;

class TreeNode {
public:
	int value;
	TreeNode * left;
	TreeNode * right;

	TreeNode() {
		value = 0;
		left = NULL;
		right = NULL;
	}
	TreeNode(int v) {
		value = v;
		left = NULL;
		right = NULL;
	}
};

class BST {
public:
	TreeNode * root;
	BST() {
		root = NULL;
	}


	TreeNode* insertRecursive(TreeNode *r, TreeNode *new_node)
	{
		if (r == NULL)
		{
			r = new_node;
			cout << "Insertion successful" << endl;
			return r;
		}

		if (new_node->value < r->value)
		{
			r->left = insertRecursive(r->left, new_node);
		}
		else if (new_node->value > r->value)
		{
			r->right = insertRecursive(r->right, new_node);
		}
		else
		{
			cout << "No duplicate values allowed!" << endl;
			return r;
		}
		return r;
	}
	void testFunction(){
		//code here
		//print Tree leafs Nodes inside this function
		//by calling printLeafs(Tree* root);
		printLeaf( root);
		SecondLargestdepth(root);
		//Print Second Largest depth of Tree inside this function
		//by calling int SecondLargestdepth (Tree* root);
	}
	void printLeaf(TreeNode* root){
		//code here
		if (root->left == NULL&&root->right == NULL)
		{
			cout << root->value << " ";
		}
		printLeaf(root->left);
		printLeaf(root->right);
		//print Tree leafs Nodes inside this function
	}
	int SecondLargestdepth(TreeNode* node){
		//code here
		if (root == NULL)
			return -1;
		else {
			int lheight = SecondLargestdepth(root->left);
			int rheight = SecondLargestdepth(root->right);

			if (lheight > rheight)
			{
				return (lheight + 1);
			}
				
			else 
				return (rheight + 1);
		}
		//Print Second Largest depth of Tree inside this function
		//Return Second Largest depth of Tree
	}

};

int main() 
{
	BST obj;
	int option, val;

	do {
		cout << "What operation do you want to perform? " <<
			" Select Option number. Enter 0 to exit." << endl;
		cout << "1. Insert Node" << endl;
		cout << "2. Height of Tree" << endl;
		cout << "3. Clear Screen" << endl;
		cout << "4. Test function" << endl;
		cout << "0. Exit Program" << endl;

		cin >> option;
		//Node n1;
		TreeNode * new_node = new TreeNode();

		switch (option) {
		case 0:
			break;
		case 1:
			cout << "INSERT" << endl;
			cout << "Enter VALUE of TREE NODE to INSERT in BST: ";
			cin >> val;
			new_node->value = val;
			obj.root = obj.insertRecursive(obj.root, new_node);
			cout << endl;
			break;
		case 2:
			cout << "TREE HEIGHT" << endl;
			cout << "Height : " << obj.SecondLargestdepth(obj.root) << endl;
			break;
		case 3:
			system("cls");
			break;
		case 4:
			obj.testFunction();
			break;
		default:
			cout << "Enter Proper Option number " << endl;
		}

	} while (option != 0);

	return 0;
} 
