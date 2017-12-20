/*
ID: vishsin1
LANG: C++14
TASK: dualpal
*/

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

int isPalindrome(string num){
	int digits = num.length();
	for(int i =0 ; i < digits/2; ++i)
		if (num [i] != num[digits-i-1])
			return 0;
	return 1;
}

string convertBase(int number, int base){
	string num_str;
	if (base != 10) {
	  while(number) 
	  {
	    num_str.push_back( ((number%base) >= 10) ? (number%base - 10 + 'A') :(number%base + '0')) ;
		number/=base;
	  } 
	  reverse(num_str.begin(), num_str.end());
	  return num_str;
	} 
	return to_string(number); 
}

int main(){
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");
	
	int N;
	int S;
	fin >> N >> S;
	int times = 0;
	for(int number = S+1; times < N && number < 100000; ++ number)
	{
	  int count = 0; 
	  for(int base = 2; base <= 10; ++ base)
	  {
		if(isPalindrome(convertBase(number, base))) count++;
	  	if (count == 2){
	  	  fout << number << endl;
	  	  times ++;
	  	  break;
	  	} 
	  } 
	}
	return 0;
}