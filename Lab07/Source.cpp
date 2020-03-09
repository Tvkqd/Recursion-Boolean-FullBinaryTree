#include<iostream>
#include<string>
#include <sstream>
using namespace std;
//This struct stores information of a node
struct Node {
	int data;
	Node* nextLeft;
	Node* nextRight;
	Node* back;

	//Constructors
	Node() {
		nextLeft = NULL;
		nextRight = NULL;
		back = NULL;
	}
};


class Binary_Tree {
	Node* root;

public:
	Binary_Tree() {};
	Binary_Tree(Node* r) {
		root = r;
	}
	//Getters
	Node* get_root() { return root; }
	int root_data() { return root->data; }


	//Convert int output to string ouput
	string to_string(Node* root) {
		ostringstream os;
		if (root == NULL)
			os << "NULL\n";
		else
			os << root->data;
		return os.str();
	}

	//Output preorder traversal binarytree
	string pre_order(Node* local_root) {
		string result;
		if (local_root != NULL) {
			result += to_string(local_root);
			if (local_root->nextLeft != NULL) {
				result += " ";
				result += pre_order(local_root->nextLeft);
			}
			if (local_root->nextRight != NULL) {
				result += " ";
				result += pre_order(local_root->nextRight);
			}
		}
		return result;
	}

	//Return true/false for a binary tree is a full tree
	bool r_full(Node* local_root) {
		bool result = true;
		if (local_root != NULL) {
			if (local_root->nextLeft == NULL && local_root->nextRight != NULL)
				return false;
			if (local_root->nextRight == NULL && local_root->nextLeft != NULL)
				return false;

			result = result * r_full(local_root->nextLeft);
			if (!result)
				result = result * r_full(local_root->nextRight);
		}
		return result;
	}
};

//This function gets input for the tree
void get_data(Binary_Tree& tree) {

	int num;
	char choice;
	Node* temp = new Node;
	temp = tree.get_root();

	cout << "Enter data for binary tree" << endl;
	cout << "\t(L)-go to the left side" << endl;
	cout << "\t(R)-go to the right side" << endl;
	cout << "\t(P)-go back to parent node" << endl;
	cout << "\t(Q)-quit" << endl;
	cout << "(L/R/P/Q ?)==> ";
	cin >> choice;
	choice = tolower(choice);

	while (choice != 'q') {
		Node* newNode = new Node;
		switch (choice)
		{
		case 'l':
			cout << "Enter value: ";
			cin >> num;
			//Create new Node
			newNode->data = num;
			//Point the left to new Node
			temp->nextLeft = newNode;
			newNode->back = temp;
			temp = temp->nextLeft;
			break;
		case 'r':
			cout << "Enter value: ";
			cin >> num;
			//Create new Node
			newNode->data = num;
			//Point the right to new Node
			temp->nextRight = newNode;
			newNode->back = temp;
			temp = temp->nextRight;
			break;
		case 'p':
			delete newNode;
			//Go back the parent node
			if (temp->back != NULL) {
				temp = temp->back;
				cout << "You are at parent node" << endl;
			}
			else
				cout << "You are at the root" << endl;
			break;
		}
		//Continue entering data
		cout << "==> ";
		cin >> choice;
		choice = tolower(choice);
	}
}

//This function create root node
Node* foundation() {
	int num;
	Node* temp = new Node;
	cout << "First, enter the root data: ";
	cin >> num;
	temp->data = num;

	return temp;
}

int main() {

	//Input data for binary trees
	cout << "Enter data for tree 1" << endl;
	Binary_Tree tree1(foundation());
	get_data(tree1);
	cout << endl << "Enter data for tree 2" << endl;
	Binary_Tree tree2(foundation());
	get_data(tree2);
	//Output the trees
	cout << endl << "Preorder Traversal Tree 1: " << tree1.pre_order(tree1.get_root()) << endl;
	cout << "Preorder Traversal Tree 2: " << tree2.pre_order(tree2.get_root()) << endl;
	
	//Check if a binary tree is full
	if (tree1.r_full(tree1.get_root()))
		cout << "Tree 1 is full" << endl;
	else
		cout << "Tree 1 is not full" << endl;

	if (tree2.r_full(tree2.get_root()))
		cout << "Tree 2 is full" << endl;
	else
		cout << "Tree 2 is not full" << endl;
	
	system("pause");
	return 0;
}