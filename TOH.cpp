//Write a program to implement Tower of Hanoi Problem.
#include<iostream>
using namespace std;
void toh(int n,string source,string help,string destiny){
	if(n==1){
		cout<<"move "<<n<<"disk from"<<source<<" to "<<destiny<<endl;
		return;
	}
	toh(n-1,source,destiny,help);
	cout<<"move "<<n<<"disk from"<<source<<" to "<<destiny<<endl;
	toh(n-1,help,source,destiny);
	
}

int main(){
	cout<<"Enter no of disks: ";
	int n;
	cin>>n;
	toh(n,"Source","Helper","Destiny");
	return 0;
}
