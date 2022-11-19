
/*
Question_1 : Create a function that returns size of the array.
Question_2 : Create a function that returns an array of dot product of two arrays.
Question_3 : Create a function that returns an sum of the two matrixes.
*/



#include<iostream>
using namespace std;


template<typename T,size_t ROW>
int *shapeArray(const T (&a)[ROW]);

template<typename A,typename B,size_t ROW_1,size_t ROW_2>
int **dotProduct(const A (&array1)[ROW_1],const B (&array2)[ROW_2]);

template<typename A,typename B,size_t ROW_1,size_t ROW_2>
int **sumMatrix(const A (&array1)[ROW_1],const B (&array2)[ROW_2]);


int main(){
	
	int arr1[4][3]={{7,2,4},{3,1,2},{9,3,7},{4,0,5}};
	int arr2[3][2]={{4,2},{5,7},{9,6}};
	
	int s1[3][3] = {{1,4,7},{2,5,8},{3,6,9}};
	int s2[3][3] = {{7,3,2},{9,4,1},{0,2,8}};
	

	// Question_1
	int *shapeArr1 = shapeArray(arr1);
	int rowArr1 = shapeArr1[0];
	int colArr1 = shapeArr1[1];
	cout<<"arr1.shape: "<<"( "<<rowArr1<<","<<colArr1<<" )"<<endl;
	
	puts("---------------------");
	
	
	//Question_2
	int **dotResult = dotProduct(arr1,arr2);

	for(int i=0;i<4;i++){
		for(int j=0;j<2;j++){
			cout<<dotResult[i][j]<< "\t";
		}
		cout<<"\n";
		}
	puts("---------------------");
	
		
	// Question_3 : 
	int **sumResult = sumMatrix(s1,s2);
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<sumResult[i][j]<< "\t";
		}
		cout<<"\n";
	}
	
	
}


// Question_1
template<typename T,size_t ROW>
int *shapeArray(const T (&array)[ROW]){
	int *shape = new int[2];
	shape[0] = ROW;		
	shape[1] = sizeof(array[0])/sizeof(array[0][0]);
	return shape;		//shape[0] -> row , shape[1] -> column
	
}

// Question_2
template<typename A,typename B,size_t ROW_1,size_t ROW_2>
int **dotProduct(const A (&array1)[ROW_1],const B (&array2)[ROW_2]){	// The function returns double pointer,which means returns 2-D array.
	
	int *shape1 = shapeArray(array1);
	const int row_1 = shape1[0];
	const int col_1 = shape1[1];
	
	
	int *shape2 = shapeArray(array2);
	const int row_2 = shape2[0];
	const int col_2 = shape2[1];
	

	if(col_1 == row_2){
		
		// Initialize result array to zero.
		int** dotArray = new int*[ROW_1];
		
		for(int i=0;i<row_1;i++){
			dotArray[i] = new int[col_2];
			for(int j=0;j<col_2;j++){	
				dotArray[i][j]=0;	
			}
		}

		// Dot product process	
	    for(int i = 0; i < row_1; ++i)
	        for(int j = 0; j < col_2; ++j)
	            for(int k = 0; k < col_1; ++k){
	                dotArray[i][j] += array1[i][k] * array2[k][j];
	            }
	    	
		return dotArray;
		
	}
	
	else{
		cout<<"Dimensions are incompatible!!";
		exit(0);
		
	}
	
}

// Question_3
template<typename A,typename B,size_t ROW_1,size_t ROW_2>
int **sumMatrix(const A (&array1)[ROW_1],const B (&array2)[ROW_2]){   // The function returns double pointer,which means returns 2-D array.
	
	int *shape1 = shapeArray(array1);
	const int row_1 = shape1[0];
	const int col_1 = shape1[1];
	
	
	int *shape2 = shapeArray(array2);
	const int row_2 = shape2[0];
	const int col_2 = shape2[1];
	
	if(row_1==row_2 && col_1==col_2){
		
		int** sumPtr = new int*[row_1];
		// Initialize result array to zero.
		for(int i=0;i<row_1;i++){
			sumPtr[i] = new int[col_2];
			for(int j=0;j<col_2;j++){
				
				sumPtr[i][j]=0;
				
			}
		}
		
		for(int i=0;i<row_1;i++){
			for(int j=0;j<col_1;j++){
				sumPtr[i][j] = array1[i][j] + array2[i][j];
			}
		}
		
		return sumPtr;
				
	}
	else{
		cout<<"The dimensions are not compatible!!"<<endl;
		exit(0);
	}	
	
}






