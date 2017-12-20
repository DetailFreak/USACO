
/*
ID: vishsin1
LANG: C++14
TASK: transform
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void display(int *A,int n){
	cout << endl;
	for(int i =0 ;i<n ;++i){
		for (int j=0; j<n; ++j){
			cout << ((A[i*n +j]==1) ? ('@') : ('-'));
			cout << " ";
		}cout << endl;
	}
}

void transpose(int *A, int n){
	int temp = 0; 
	for(int i = 0; i < n; ++i){
		for (int j=0; j<i; ++j){
			temp = A[i*n + j];
			A[i*n + j] = A[j*n + i];
			A[j*n + i] = temp;
		}
	}
}

void flip(int* A,int n){
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n/2; ++j){
        	int temp = A[i*n + j];
        	A[i*n + j] = A[i*n + n-j-1];
        	A[i*n + n-j-1] = temp;
        }
}


void rotate(int* A, int n)
{
	transpose(A,n);
    flip(A,n);
}

void copy(int* src, int* dest, int n)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        	dest[i*n + j] = src[i*n + j];
}

int equals(int* A, int* B, int n)
{
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        	if (A[i*n + j] != B[i*n + j]) 
        		return 0;
    }
    return 1;
}

int main(){
	
	ofstream fout ("transform.out");
	ifstream fin ("transform.in");

	int n ;
	fin >> n;
	int *A = new int[n*n];
	int *B = new int[n*n];
	
	int *T[8];
	for(int i=0; i <8 ; ++i) T[i] = new int[n*n];
	
	char ch;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			fin >> ch;
			A[i*n + j] = (ch == '@') ? (1) : (0) ;
		}
	} 
	
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			fin >> ch;
			B[i*n + j] = (ch == '@') ? (1) : (0) ;
		}
	}

	copy(A,T[0], n);
	

	display(A, n);
	for(int t = 1; t < 8; ++t ){
		copy( T[ t - 1 ], T[ t ], n);
		
		if(t==4) 
		{
			copy(T[0],T[t],n);
			flip(T[t],n);
		}
		else rotate(T[t],n);
		
		display(T[t],n);

		if(equals(B,T[t],n)){
			fout << ((t>4)? ( 5 ) : ( t )) <<endl;
			return 0;
		} 
	}
	if (equals( B , A , n)) {
		fout << 6 << endl;
		return 0;
	}

	fout << 7 << endl;
	return 0;
}