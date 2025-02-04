/*Write a menu driven program in C or C++ to implement a priority queue using single linked
list and perform the following operations.
(a) isEmpty() is to check whether the queue is empty or not.
(b) insert() is to insert an item in the queue.
(c) del() is to delete an item from the queue.
(d) display() is to show the entire queue.
*/

#include<iostream>
#include<stdlib.h>
using namespace std;

class Node{
	public:
		int data;
		int priority;
		Node* next;
		Node(int value,int p){
			data=value;
			priority=p;
			next=NULL;
		}
};

class PQ{
	Node* front;
	public:
	PQ(){
		front=NULL;
	}
	
	void insert(int value,int p){
		Node* newnode=new Node(value,p);
		if(front==NULL || front->priority>p){
			newnode->next=front;
			front=newnode;
			return;
		}
		Node* temp=front;
		while(temp->next!=NULL && temp->priority<=p){
			temp=temp->next;
		}
		newnode->next=temp->next;
		temp->next=newnode;
	}
	
	void del(){
		if(!front){
			cout<<"Empty"<<endl;
			return;
		}
		Node* temp=front;
		front=front->next;
		delete temp;
		return;
	}
	void display(){
		if(!front){
			cout<<"Empty"<<endl;
			return;
		}
		Node* temp=front;
		while(temp){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
	bool isEmpty(){
		return (front==NULL);
	}
};


int main(){
	PQ pq;
	pq.insert(5,2);
	pq.insert(6,3);
	pq.insert(7,4);
	pq.insert(8,1);
	pq.display();
	pq.del();
	pq.display();
	return 0;
}
