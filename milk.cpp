/*
ID: vishsin1
LANG: C++14
TASK: milk2
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Node{
	Node *next;
	Node *prev;
	int a;
	int b;

} *head = NULL;

	ofstream fout ("milk2.out");
	ifstream fin ("milk2.in");

Node* new_node(int a,int b){
	Node *node = new Node; node->a = a; node->b = b; node->prev = node->next = NULL;
	return node;
}

void insert(int a, int b)
{
	if(!head) {
		head = new_node(a, b);
		return;
	}
	for ( Node* it = head; it!=NULL; it=it->next )
	{	
		if (it->a >= a && it->b >= b && it->a <= b ){ ////////// <-[]  
			it->a = a;
			break;
		} 
		else if (it->a <= a && it->b <=b && it->b >= a){////  []->
			it->b = b;
			
			while(it->next && it->b >= it->next->a)	///////////  [ []x []x ... ]->
			{	
				if(it->next->b > it->b) it->b = it->next->b;

				it->next = it->next->next;	
				if(it->next) 
					it->next->prev = it;
			}

			break;
		} 
		else if (it->a >= a && it->b <= b){	///// <-[]->
			//fout<<"\textended node:("<<it->a<<','<<it->b <<") -> ("<<a<<','<<b<<")\n";
			it->a = a;
			it->b = b;
		} 
		else if (it->a <= a && it->b >= b) {
			//fout<<"\tskipped\n";
			break;
		 }
		else if ( (it->b < a && !it->next) || (it->b < a && it->next->a > b ) ) { ////// ->+[]
			//fout<<"\tadded node:("<<a<<','<<b <<")\n";
			Node* temp = it->next;
			it->next = new_node(a,b);
			it->next->prev = it;
			it->next->next = temp;
			if (temp)
			 temp->prev = it->next;
			break;
		} 
		else if (it->a > b && !it->prev){ ////// []+<-
			//fout<<"\textended node:("<<a<<','<<b <<")\n";
			it->prev = new_node(a,b);
			it->prev->next = it;
			head = it->prev;
			break;
		} 
	}
}
int main()
{

	int t;
	int m,n;
	fin >> t;
	int i = t;
	while(i--){
		fin >> m >> n;
		insert(m,n);
	}	
	int max_cont = 0 ;
	for(Node* it = head; it != NULL; it = it->next){
		int cont = it->b - it->a;
		//cout<<" b:"<<it->b<<" a:"<<it->a<<" cont:"<<cont<<endl;
		if (cont > max_cont)
			max_cont = cont;
	}
	int max_disc = 0;
	for(Node* it = head; it->next != NULL; it = it->next){
		int disc = it->next->a - it->b;
		//cout<<" next->a:"<<it->next->a<<" b:"<<it->b<<" disc:"<<disc<<endl;
		if (disc > max_disc)
			max_disc = disc;

	}
	fout << max_cont <<' '<< max_disc <<endl;
	return 0;
}