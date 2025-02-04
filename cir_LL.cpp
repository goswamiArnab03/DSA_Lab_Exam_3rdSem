/*Write a menu driven program in C or C++ to perform the following operations on circular linked
list.
(a) insert a node at the beginning of the list.
(b) delete a node at the end of the list.
(c) display the whole list.
(a) insert a node at the end of the list.
(b) deletet a node from the beginning of the list.
(c) display the whole list.
*/

#include<iostream>
#include<stdlib.h>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node(int value){
			data=value;
			next=NULL;
		}
};

class CLL{
	Node* last;
	public:
		CLL(){
			last=NULL;
		}
		void insertBeg(int value){
			Node* newnode=new Node(value);
			if(!last){
				newnode->next=newnode;
				last=newnode;
				cout<<"Inserted at Beg"<<endl;
				return;
			}
			newnode->next=last->next;
			last->next=newnode;
			cout<<"Inserted at Beg"<<endl;
			return;
		}
		
		void insertEnd(int value){
			Node* newnode=new Node(value);
			if(!last){
				newnode->next=newnode;
				last=newnode;
				cout<<"Inserted at End"<<endl;
				return;
			}
			newnode->next=last->next;
			last->next=newnode;
			last=newnode;
			cout<<"Inserted at End"<<endl;
		}
		void display(){
			if(!last){
				cout<<"empty"<<endl;
				return;
			}
			Node* temp=last;
			temp=temp->next;
			while(temp!=last){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<temp->data<<" "<<endl;
		}
		void delEnd(){
			if(!last){
				cout<<"empty"<<endl;
				return;
			}
			if(last->next==last){
				last=NULL;
				delete last;
				return;
			}
			Node* temp=last;
			temp=temp->next;
			while(temp->next!=last){
				temp=temp->next;
			}
			temp->next=last->next;
			delete last;
			last=temp;
		}
		void delBeg(){
			if(!last){
				cout<<"empty"<<endl;
				return;
			}
			if(last->next==last){
				last=NULL;
				delete last;
				return;
			}
			Node* temp=last;
			temp=temp->next;
			last->next=temp->next;
			delete temp;
		}
		
};
int main(){

	CLL li;
	cout<<"Enter 0 for exit"<<endl;
	cout<<"Enter 1 for add Begining"<<endl;
	cout<<"Enter 2 for add End"<<endl;
	cout<<"Enter 3 for display"<<endl;
	cout<<"Enter 3 for delete end"<<endl;
	cout<<"Enter 3 for delete beg"<<endl;
	while(1){
		cout<<"Enter your queary";
		int p;
		cin>>p;
		switch(p){
			case 1:
				cout<<"Element";
				int data;
				cin>>data;
				li.insertBeg(data);
				break;
			case 2:
				cout<<"Element";
				int data1;
				cin>>data1;
				li.insertEnd(data1);
				break;
			case 3:
				li.display();
				break;
			case 4:
				li.delEnd();
				break;
			case 5:
				li.delBeg();
				break;
			case 0:
				exit(0);
		}
	}
}
