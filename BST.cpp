/*Write a menu driven program in C or C++ to perform the following operations on Binary Search
Tree.
21>
(a) insert a node.
(b) inorder traversal.
(c) preorder traversal.
(d) search an given key.
(e) Find the smallest element.
22>
(a) insert a node.
(b) inorder traversal.
(c) postorder traversal.
(d) Find the largest element.
(e) Count the total number of nodes.
23>
(a) insert a node.
(b) inorder traversal.
(c) Count the total number of external nodes.
(d) Count the total number of internal nodes.
(e) Determine the height of the tree.
24>
(a) Create a binary search tree
(b) inorder traversal.
(c) Delete items from the tree.
*/

#include<iostream>
#include<stdlib.h>
using namespace std;

class Node{
	public:
		int data;
		Node* lchild;
		Node* rchild;
		Node(int value){
			data=value;
			lchild=NULL;
			rchild=NULL;
		}
};

class BST{
	Node* root;
	public:
		BST(){
			root=NULL;
		}
		Node* getroot(){
			return root;
		}
		
		void insert(int value){
			Node* newnode=new Node(value);
			if(!root){
				root=newnode;
				return;
			}
			Node* temp=root;
			Node* parent=NULL;
			while(temp){
				parent=temp;
				if(temp->data>value){
					temp=temp->lchild;
				}
				else{
					temp=temp->rchild;
				}
			}
			if(parent->data>value){
				parent->lchild=newnode;
			}
			else{
				parent->rchild=newnode;
			}
		}
		void inOrder(Node* r){
			if(r!=NULL){
				inOrder(r->lchild);
				cout<<r->data<<" ";
				inOrder(r->rchild);
			}
		}
		
		void preOrder(Node* r){
			if(r!=NULL){
				cout<<r->data<<" ";
				preOrder(r->lchild);
				preOrder(r->rchild);
			}
		}
		
		void postOrder(Node* r){
			if(r!=NULL){
				postOrder(r->lchild);
				postOrder(r->rchild);
				cout<<r->data<<" ";
			}
		}
		int totalNode(Node* r){
			if(!r)return 0;
			else{
				return (totalNode(r->lchild)+totalNode(r->rchild)+1);
			}
		}
		int interNode(Node* r){
			if(!r)return 0;
			else if(r->lchild==NULL && r->rchild==NULL)return 0;
			else return(interNode(r->lchild)+interNode(r->rchild)+1);
		}
		int exterNode(Node* r){
			if(!r)return 0;
			else if(r->lchild==NULL && r->rchild==NULL)return 1;
			else return(exterNode(r->lchild)+interNode(r->rchild));
		}
		int height(Node* r){
			if(!r){
				return 0;
			}
			int lh,rh;
			lh=height(r->lchild);
			rh=height(r->rchild);
			if(lh>rh)return lh+1;
			else return rh+1;
		}
		bool search(int key){
			if(!root){
				return false;
			}
			Node* temp=root;
			while(temp){
				if(temp->data==key){
					return true;
				}
				else if(temp->data>key){
					temp=temp->lchild;
				}
				else{
					temp=temp->rchild;
				}
			}
			return false;
		}
		void smallest(){
			if(!root){
				cout<<"Empty"<<endl;
				return;
			}
			Node* temp=root;
			Node* parent=NULL;
			while(temp){
				parent=temp;
				temp=temp->lchild;
			}
			cout<<"The smallest is: "<<parent->data<<endl;;
			return;
			
		}
		void largest(){
			if(!root){
				cout<<"Empty"<<endl;
				return;
			}
			Node* temp=root;
			Node* parent=NULL;
			while(temp){
				parent=temp;
				temp=temp->rchild;
			}
			cout<<"The largest is: "<<parent->data<<endl;;
			return;
			
		}
		void remove(int key){
			if(!root){
				cout<<"empty"<<endl;
				return;
			}
			Node* x=root;
			Node* parent=NULL;
			while(x!=NULL && x->data!=key){
				parent=x;
				if(x->data>key)x=x->lchild;
				else x=x->rchild;
			}
			if(!x){
				cout<<"Data is not present"<<endl;
				return;
			}
			if(x->lchild==NULL || x->rchild==NULL){
				Node* ptr;
				if(x->lchild==NULL)ptr=x->rchild;
				else ptr=x->lchild;
				if(!parent){
					delete root;
					root=ptr;
					return;
				}
				else{
					if(x==parent->lchild)parent->lchild=ptr;
					else parent->rchild=ptr;
					delete x;
					return;
				}
			
			}
			Node* succ=x->rchild;
			Node* psucc=NULL;
			while(succ->lchild){
				psucc=succ;
				succ=succ->lchild;
			}
			x->data=succ->data;
			if(!psucc)x->rchild=succ->rchild;
			else psucc->lchild=succ->rchild;
			delete succ;
			return; 
		}
		
};




int main(){
	BST b;
	cout<<"Enter 0 for exit"<<endl;
	cout<<"Enter 1 for insert"<<endl;
	cout<<"Enter 2 for inorder"<<endl;
	cout<<"Enter 3 for preorder"<<endl;
	cout<<"Enter 4 for postorder"<<endl;
	cout<<"Enter 5 for total node"<<endl;
	cout<<"Enter 6 for internal node"<<endl;
	cout<<"Enter 7 for external node"<<endl;
	cout<<"Enter 8 for height"<<endl;
	cout<<"Enter 9 for search"<<endl;
	cout<<"Enter 10 for smallest"<<endl;
	cout<<"Enter 11 for largest"<<endl;
	
	
	int p;
	while(1){
		cout<<"Enter your choice: ";
		cin>>p;
		switch(p){
			case 1:
				int value;
				cout<<"Enter value: ";
				cin>>value;
				b.insert(value);
				break;
			case 2:
				b.inOrder(b.getroot());
				break;
			case 3:
				b.preOrder(b.getroot());
				break;
			case 4:
				b.postOrder(b.getroot());
				break;
			case 5:
				cout<<"Total nodes: "<<b.totalNode(b.getroot())<<endl;
				break;
			case 6:
				cout<<"internal nodes: "<<b.interNode(b.getroot())<<endl;
				break;
			case 7:
				cout<<"external nodes: "<<b.exterNode(b.getroot())<<endl;
				break;
			case 8:
				cout<<"Height: "<<b.height(b.getroot())<<endl;
				break;
			case 9:
				int key;
				cout<<"Enter key:";
				cin>>key;
				if(b.search(key))cout<<"Item found"<<endl;
				else cout<<"Item not found"<<endl;
				break;
			case 10:
				b.smallest();
				break;
			case 11:
				b.largest();
				break;
			case 12:
				int key1;
				cout<<"Enter key:";
				cin>>key1;
				b.remove(key1);
				break;
				
			case 0:
				exit(0);
		}
	}
	
}
