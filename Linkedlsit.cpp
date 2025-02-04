/*Write a menu driven program in C or C++ to perform the following operations on single linked
list.
7.
(a) insert a node at the beginning of the list.
(b) insert a node at the end of the list.
(c) deletet a node from the beginning of the list.
(d) delete a node at the end of the list.
(e) display the whole list.
8.
(a) insert a node at the beginning of the list.
(b) delete a node at the end of the list.
(c) display the whole list.
(d) search an element x in the list.
(e) reverse the list.
*/





#include<iostream>
#include<stdlib.h>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node(int val){
			data=val;
			next=NULL;
		}
};


class Linkedlist{
	Node* head;
	public:
		Linkedlist(){
			head=NULL;
		}
		
		void insertAtBeg(int value){
			Node* newnode=new Node(value);
			
			newnode->next=head;
			head=newnode;
			return;
		}
		
		void insertAtEnd(int value){
			Node* newnode=new Node(value);
			if(!head){
				newnode=head;
				return;
			}
			Node* temp=head;
			while(temp->next){
				temp=temp->next;
			}
			temp->next=newnode;
			return;
		}
		void display(){
			Node* temp=head;
			if(!head){
				cout<<"The list is empty"<<endl;
				return;
			}
			while(temp){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<endl;
			return;
		}
		void delBeg(){
			if(!head){
				cout<<"The list is empty"<<endl;
				return;
			}
			Node* temp=head;
			head=head->next;
			delete (temp);
			cout<<"Deleted from begining"<<endl;
			return;
		}
		void delEnd(){
			if(!head){
				cout<<"The list is empty"<<endl;
				return;
			}
			Node* temp=head;
			if(temp->next== NULL){
				delete (temp);
				head=NULL;
				return;
			}
			while(temp->next->next){
				temp=temp->next;
			}
			delete (temp->next);
			temp->next=NULL;
			cout<<"Deleted from end"<<endl;
			return;
		}
		bool search(int val){
			if(!head){
				//cout<<"The list is empty"<<endl;
				return false;
			}
			Node* temp=head;
			while(temp){
				if(temp->data==val){
					return true;
				}
				temp=temp->next;
			}
			return false;
		}
		void reverse(){
			Node* p=head,*q,*r=NULL;
			while(p){
				q=p;
				p=p->next;
				q->next=r;
				r=q;
			}
			head=q;
		}
};


int main(){
	Linkedlist li;
	cout<<"Enter 0 for exit"<<endl;
	cout<<"Enter 1 for insert Begining"<<endl;
	cout<<"Enter 2 for insert End"<<endl;
	cout<<"Enter 3 for delete Begining"<<endl;
	cout<<"Enter 4 for delete End"<<endl;
	cout<<"Enter 5 for  search"<<endl;
	cout<<"Enter 6 for reverse"<<endl;
	cout<<"Enter 7 for display"<<endl;
	
	int p;
	while(1){
		cout<<"Enter your choice: ";
		cin>>p;
		switch(p){
			case 1:
				int data;
				cout<<"Enter your value: ";
				cin>>data;
				li.insertAtBeg(data);
				break;
			case 2:
				int data1;
				cout<<"Enter your value: ";
				cin>>data1;
				li.insertAtEnd(data1);
				break;
			case 3:
				li.delBeg();
				break;
			case 4:
				li.delEnd();
				break;
			case 5:
				int item;
				cout<<"Enter your value: ";
				cin>>item;
				if(li.search(item)){
					cout<<"Item present in list"<<endl;
				}
				else{
					cout<<"Item not present in list"<<endl;
				}
				break;
			case 6:
				li.reverse();
				break;
			case 7:
				li.display();
				break;
			case 0:
				exit(0);
			default:
				cout<<"Invalid input"<<endl;
				break;
		}
	}
}
