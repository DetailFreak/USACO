
/*
ID: vishsin1
LANG: C++14
TASK: barn1
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ifstream fin("barn1.in") ;
  ofstream fout("barn1.out") ;

  int M,S,C ;
  fin >> M >> S >> C ;
  
  int c[201];
  for (int i = 0; i < C; ++i) 
      fin >> c[i];
  sort(c,c+C);

  int d[201];
  for (int i = 0; i < C-1; ++i)
  	d[i] = c[i+1] - c[i] - 1;
  d[C-1] = 0;

  int boards = C;
  int differ = 0;
  int non_cow_stalls_covered = 0;
  bool flag = (boards <= M);
  while( differ < S-1 && !flag){
  	for (int i = 0; (i < C-1) && !flag ; ++i)
  		if (differ == d[i]){
  			boards -= 1;
  			non_cow_stalls_covered += differ;
  			flag = (boards <= M);
  			d[i] = 0;
  		}

   // 	cout << "D: (" ;
  	// for( int i = 0; i < C; ++i){
  	// 	cout << d[i]; if(i<C-1) cout <<", ";
  	// }
  	// cout << ")";
  	// cout << endl;
  	++differ;
  }
  fout << non_cow_stalls_covered + C << endl;
  return 0;
}
