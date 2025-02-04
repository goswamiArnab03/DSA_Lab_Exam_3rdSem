/*Write a menu driven program in C or C++ to implement a Circular Queue using array and
perform the following operations.
(a) isF ull() function to check whether the Circular Queue is full or not.
(b) isEmpty() function to check whether the Circular Queue is empty or not.
(c) insert(item) function to insert an element item in the Circular Queue.
(d) delete() function to read and remove an element from the Circular Queue.
(e) display() function to display the entire Circular Queue.*/

#include<iostream>
#include<stdlib.h>
#define MAX 100
using namespace std;

class Queue{
	int arr[MAX],front,rear;
	public:
		Queue(){
			front=rear=-1;
		}
		bool isFull(){
			return ((front==0 && rear==MAX-1) || ((rear+1)%MAX==front));
		}
		bool isEmpty(){
			return front==-1;
		}
		void insert(int item){
			if(isFull()){
				cout<<"The queue is full"<<endl;
				return;
			}
			if(front==-1){
				front=rear=0;
				arr[rear]=item;
				return;
			}
			rear=(rear+1)%MAX;
			arr[rear]=item;
			return;
		}
		void del(){
			if(isEmpty()){
				cout<<"queue is empty"<<endl;
				return;
			}
			cout<<"Element "<<arr[front]<<" deleted successfully"<<endl;
			if(front==rear){
				front=rear=-1;
			}
			else{
				front=(front+1)%MAX;
			}
			
			return;
		}
		void display(){
			if(isEmpty()){
				cout<<"queue is empty"<<endl;
				return;
			}
			cout<<"Queue is: ";
			int f=front,r=rear;
			if(f<=r){
				while(f<=r){
					cout<<arr[f]<<" ";
					f++;
				}
			}
			else{
				while(f<=MAX-1){
					cout<<arr[f]<<" ";
					f++;
				}
				f=0;
				while(f<=r){
					cout<<arr[f]<<" ";
					f++;
				}
			}
			
			cout<<endl;
		}
};

int main(){
	Queue q;
	cout<<"Enter 0 for exit"<<endl;
	cout<<"Enter 1 for isfull"<<endl;
	cout<<"Enter 2 for isempty"<<endl;
	cout<<"Enter 3 for insert element"<<endl;
	cout<<"Enter 4 for delete element"<<endl;
	cout<<"Enter 5 for display"<<endl;
	int p;
	while(1){
		cout<<"Enter your choice";
		cin>>p;
		switch(p){
			case 1:
				if(q.isFull()){
					cout<<"The queue is full"<<endl;
				}
				else{
					cout<<"The queue is not full"<<endl;
				}
				break;
			case 2:
				if(q.isEmpty()){
					cout<<"The queue is empty"<<endl;
				}
				else{
					cout<<"The queue is not empty"<<endl;
				}
				break;
			case 3:
				int ele;
				cout<<"Enter element to insert";
				cin>>ele;
				q.insert(ele);
				break;
			case 4:
				q.del();
				break;
			case 5:
				q.display();
				break;
			case 0:
				exit(0);
			default:
				cout<<"Invalid input!";
				break; 
		}
	}
}
