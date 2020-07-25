#include<iostream>
#include<stack>
using namespace std;
class Node
{
	public:
	int key;
	Node *left;
	Node *right;
	
	Node(int key)
{
	
	this->key=key;
	this->left=nullptr;
	this->right=nullptr;	
	}	
};
int Height(Node *root)
{
	if(root==nullptr)
	return 0;
	
	return 1+max(Height(root->left),Height(root->right));
}
int main()
{
	Node *root1=nullptr;
	root1=new Node(15);
	root1->left=new Node(10);
	root1->right=new Node(20);
	root1->left->left=new Node(8);
	root1->left->right=new Node(12);
	root1->right->left=new Node(16);
	root1->right->right=new Node(25);
	
	cout<<Height(root1);
	
	
	
	
}
