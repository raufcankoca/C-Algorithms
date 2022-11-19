/* 
Question_1 : Find the maximum number of the integer array
Question_2 : Sort the array ascending
Question_3 : Find the largest N numbers.
Question_4 : Find the sum of all numbers

*/


#include<iostream>

#define SIZE 10
#define N 6

using namespace std;

int max(int array[]);
int* AscendingSort(int array[]);
int* getLargestElements(int array[]);
int* DescendingSort(int array[]);


int main(){

	int arr[SIZE] = {28,14,69,55,41,12,78,17,23,34};             
	
	// Question_1 Test
	int max_val = max(arr);
	cout<<"Max value: "<<max_val<<endl;
	
	// Question_2 Test
	int *ptr = AscendingSort(arr);
	cout<<"Sorted Array:";
	
	for(int i=0;i<SIZE;i++){
		cout<<ptr[i]<< " ";
	}
	cout<<"\n";
	
	// Question_3 Test
	int *ptr2 = DescendingSort(arr);
	cout<<"Reverse Sorted Array:";
	
	for(int i=0;i<SIZE;i++){
		cout<<ptr2[i]<< " ";
	}
	cout<<"\n";
	
	// Question_4 Test
	int *largestPtr = getLargestElements(arr);
	cout<< "Largest "<< N <<" elements: ";
	
	for(int i=0;i<N;i++){
		cout<<largestPtr[i]<< " ";
	}
	
	
	
}



int max(int array[]){           		// Be careful pass an array,don't forget to initialize size
	int max = array[0]; 				// Initialize first array to maximum
	
	
	for(int i=1; i<SIZE; i++){
		if(array[i]>max){
			max = array[i];
		}
	}
	return max;
	
	
	
	
}

int* AscendingSort(int array[]){		// The function returns address of array.Actually, we create a function that returns array.
	
	static int sortedArray[SIZE];
	int temp;
	
	
	for(int i=0;i<SIZE-1;i++){
		for(int j=0;j<SIZE-1;j++){
			if(array[j]>array[j+1]){
				
				temp = array[j+1];
				array[j+1] = array[j];
				array[j] = temp;
				
			}
		}
	}
	
	for(int i=0;i<SIZE;i++){
		sortedArray[i] = array[i];
	}
	
	return sortedArray;

}

int* DescendingSort(int array[]){		// The function returns address of array.Actually, we create a function that returns array.
	
	static int sortedArray[SIZE];
	int temp;
	
	
	for(int i=0;i<SIZE-1;i++){
		for(int j=0;j<SIZE-1;j++){
			if(array[j]<array[j+1]){
				
				temp = array[j+1];
				array[j+1] = array[j];
				array[j] = temp;
				
			}
		}
	}
	
	for(int i=0;i<SIZE;i++){
		sortedArray[i] = array[i];
	}
	
	return sortedArray;

}



int* getLargestElements(int array[]){
	
	static int largestNumbers[N];
	int *sortedArray = DescendingSort(array);
	
	for(int i=0;i<N;i++){
		largestNumbers[i] = sortedArray[i];
	}
	
	return largestNumbers;
	
}
