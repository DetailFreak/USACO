
/*
ID: vishsin1
LANG: C++14
TASK: milk
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N, M;
	vector<pair<int,int>> price_amount;

	ifstream fin("milk.in");
	ofstream fout("milk.out");

	fin >> N >> M;

	for(int i = 0; i < M; ++i)
	{
		int a,b;
		fin >> a;
		fin >> b;
		price_amount.push_back(make_pair(a,b));
	}

	sort(price_amount.begin(), price_amount.end());

	int cost = 0;
	int quant = 0;

	for(int i = 0; i < M && quant < N ; ++i)
	{
		if (quant + price_amount[i].second > N) {
			cost += price_amount[i].first * ( N - quant );
			quant = N;
		}
		else {
			cost += price_amount[i].first * price_amount[i].second;
			quant += price_amount[i].second;
		}

	}

	fout << cost <<endl;
	return 0;
}