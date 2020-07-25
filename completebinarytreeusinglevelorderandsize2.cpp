//Check Complete Binary Tree Using Level Order Concept
#include<iostream>
#include<vector>
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
bool CheckCompleteBinaryTree(Node *root,int i,int n)
{
	if(root==nullptr)
	return true;
	
	if((root->left && 2*i+1>=n) || !CheckCompleteBinaryTree(root->left,2*i+1,n))
	return false;
	
	if((root->right && 2*i+2>=n) || !CheckCompleteBinaryTree(root->right,2*i+2,n))
	return false;
	
	return true;
}
int Size(Node *root)
{
	if(root==nullptr)
	return 0;
	
	return 1+Size(root->left)+Size(root->right);	
}
int main()
{
	Node *root1=nullptr;
	root1=new Node(1);
	root1->left=new Node(2);
	root1->right=new Node(3);
	root1->left->left=new Node(4);
	root1->left->right=new Node(5);
	root1->right->left=new Node(6);
	root1->right->right=new Node(7);
	//root1->right->right->left=new Node(8);
	int n=Size(root1);
	if(CheckCompleteBinaryTree(root1,0,n))
	cout<<"Yes";
	else
	cout<<"No";
}
