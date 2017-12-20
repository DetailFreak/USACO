/*
ID: vishsin1
LANG: C++14
TASK: namenum
*/
#include <iostream>
#include <string>
#include <fstream>
#include <math.h>

using namespace std;

int NumDigits(unsigned long long int x)  
{  
    return (x < 10 ? 1 :   
        (x < 100 ? 2 :   
        (x < 1000 ? 3 :   
        (x < 10000 ? 4 :   
        (x < 100000 ? 5 :   
        (x < 1000000 ? 6 :   
        (x < 10000000 ? 7 :  
        (x < 100000000 ? 8 :  
        (x < 1000000000 ? 9 :
        (x < 10000000000 ? 10 :
        (x < 100000000000 ? 11 :
        (x < 1000000000000 ? 12 :
        	13 ))))))))))));  
}


struct Key {
	char letter[3];
} key[12];

int hasLetter(int i, char c){
	return (toupper(key[i].letter[0]) == c || toupper(key[i].letter[1]) == c || toupper(key[i].letter[2]) == c) ? (1) : (0);
}

int main(){
	

	key[2].letter[0] = 'a'; key[2].letter[1] = 'b'; key[2].letter[2] = 'c';
	key[3].letter[0] = 'd'; key[3].letter[1] = 'e'; key[3].letter[2] = 'f';
	key[4].letter[0] = 'g'; key[4].letter[1] = 'h'; key[4].letter[2] = 'i';
	key[5].letter[0] = 'j'; key[5].letter[1] = 'k'; key[5].letter[2] = 'l';
	key[6].letter[0] = 'm'; key[6].letter[1] = 'n'; key[6].letter[2] = 'o';
	key[7].letter[0] = 'p'; key[7].letter[1] = 'r'; key[7].letter[2] = 's';
	key[8].letter[0] = 't'; key[8].letter[1] = 'u'; key[8].letter[2] = 'v';
	key[9].letter[0] = 'w'; key[9].letter[1] = 'x'; key[9].letter[2] = 'y';

	ifstream fdict ( "dict.txt" ), fin ("namenum.in");
	ofstream fout  ("namenum.out");

	unsigned long long int n;
	fin >> n;
	cout << n << endl;
	int digits = NumDigits(n);
	string name;

	int offset = 2;
	int first_digit = n / pow(10,(digits-1));

	cout << first_digit << endl;
	int numvalid = 0;

	while( fdict >> name ) 
	{
		if( name[0] > toupper(key[first_digit].letter[2]))
			break;
		
		if( name[0] < toupper(key[first_digit].letter[0]) ) 
			continue;

		bool is_valid_name = true;
		if (name.length() == digits){
					cout<<"\n"<<name<<' '<< key[first_digit].letter[0]<<endl;

			for( int letter_index = 0; letter_index < digits; ++ letter_index )
			{
				int current_digit = (n % (unsigned long long int)(pow(10, digits - letter_index))) / (unsigned long long int)(pow(10, digits - letter_index - 1));
				char current_letter = name[letter_index];
				cout << "current_letter:" << current_letter << " current_digit:" << current_digit << endl;
				if (! hasLetter (current_digit, current_letter)) 
					{is_valid_name = false;
					 break;}
			}
			if (is_valid_name)
				{
					++numvalid;
					fout <<  name << endl;
				} 
		} 
	}
	if (numvalid==0) fout << "NONE"<<endl;
	return 0;
}