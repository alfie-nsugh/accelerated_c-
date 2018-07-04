#include <iostream>
#include <vector>
#include <cctype>
#include "split.h"
#include "framing.h"

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main(){
	string s;

	//read and split each line of input
	while(getline(cin, s)){
		vector<string> v = split(s);
		v = frame(v);
		vector<string> u(v);
		for(vector<string>::size_type i = 0; i < 5;i++)
			v = hcat(v,u);

		//write each word in v
		for(vector<string>::size_type i = 0; i != v.size(); ++i)
			cout << v[i] << endl;
	}
	return 0;
}
