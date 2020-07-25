//Check Complete Binary Tree Using Level Order Concept
#include<iostream>
#include<queue>
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
bool CheckCompleteBinaryTree(Node *root)
{
	if(root==nullptr)
	return false;
	
	queue<Node *>q;
	q.push(root);
	bool flag=false;
	while(!q.empty())
	{
		Node *ptr=q.front();
		q.pop();
		if(flag==true && (ptr->left||ptr->right))
		return false;
		
		if(ptr->left==nullptr && ptr->right!=nullptr)
		return false;
		
		if(ptr->left)
		q.push(ptr->left);
		else
		flag=true;
		
		if(ptr->right)
		q.push(ptr->right);
		else
		flag=true;
	}
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
//	root1->right->right->left=new Node(8);
	
	if(CheckCompleteBinaryTree(root1))
	cout<<"Yes";
	else
	cout<<"No";
}
