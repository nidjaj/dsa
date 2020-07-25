//Symmetric Structure
#include<iostream>
#include<vector>
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
bool Equal(Node *X,Node *Y)
{
	if(X==nullptr && Y==nullptr)
	return true;
	
	return (X && Y)	&& (X->key==Y->key)&&((Equal(X->left,Y->left) && Equal(X->right,Y->right)) || 
	(Equal(X->left,Y->right)&&Equal(X->right,Y->left)));
}
void PreOrder(Node *root)
{
	if(root==nullptr)
	return;
	
	printf("%d\t",root->key);
	PreOrder(root->left);
	PreOrder(root->right);
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
	root1->right->right->left=new Node(8);
	Node *root2=nullptr;
	root2=new Node(1);
	root2->left=new Node(3);
	root2->right=new Node(2);
	root2->left->left=new Node(7);
	root2->left->left->left=new Node(8);
	root2->left->right=new Node(6);
    root2->right->left=new Node(5);
	root2->right->right=new Node(4);

	PreOrder(root1);
	printf("\n");
	if(Equal(root1,root2))
	cout<<"Yes";
	else
	cout<<"No";
	
	
	
}
