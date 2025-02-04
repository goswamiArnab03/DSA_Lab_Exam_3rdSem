/*Write a program in C or C++ to sort a given array using insertion sort algorithm. Show
the number of comparison required for a given input.*/

#include<bits/stdc++.h>
using namespace std;

void insertion(int arr[],int n){
	for(int i=1;i<n;i++){
		int key=arr[i];
		int j=i-1;
		while(j>=0 && arr[j]>key){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}

void display(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}

int main(){
	int arr[5]={5,3,9,7,1};
	insertion(arr,5);
	display(arr,5);
	return 0;
}
