/*Write a program in C or C++ to sort a given array using selection sort algorithm. Show
the number of comparison required for a given input.*/


#include<iostream>
using namespace std;

void swap(int arr[],int i,int j){
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
	return;
}


void display(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}

void selection(int arr[],int n){
	int comp=0,i,j;
	for(i=0;i<n-1;i++){
		int minindex=i;
		for(j=i+1;j<n;j++){
			if(arr[j]<arr[minindex]){
				minindex=j;
			}
		}
		if(minindex!=i){
			swap(arr,i,minindex);
			comp++;
		}
	}
	cout<<"No of comp"<<comp<<endl;
	display(arr,n);
}



int main(){
	int arr[6]={50,60,10,30,20,40};
	selection(arr,6);
	return 0;
}
