
/*
ID: vishsin1
LANG: C++14
TASK: palsquare
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
	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");
	
	int base;
	fin >> base;

	for(int number=1; number<=300; ++number){
		if(isPalindrome(convertBase(number*number, base)))
			fout << convertBase(number,base) << " " << convertBase(number*number, base)<<endl;
	}
	return 0;
}