#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

vector<string> split_deprecated(const string& s)
{
	vector<string> ret;
	typedef string::size_type string_size;
	string_size i = 0;

	//invariant: we have processed characters [original value of i, i)
	while (i != s.size()){
		// ignore leading blanks
		// invariant: characters in range [original i, current i)
	while (i != s.size() && isspace(s[i]))
		++i;

	// find end of next word
	string_size j = i;
	// invariant: none of the characters in range [original j, current j)
	while (j != s.size() && !isspace(s[j]))
		j++;
		// if we found some nonwhitespace characters
		if(i != j){
			//copy from s starting at i and taking j-i chars
			ret.push_back(s.substr(i, j - i));
			i = j;
		}
	}
	return ret;
}

bool space(char c){
	return isspace(c);
}

bool not_space(char c){
	return !isspace(c);
}

vector<string> split(const string& str){
		typedef string::const_iterator iter;
		vector<string> ret;

		iter i = str.begin();
		while(i != str.end()){
			//ignore leading blanks
			i = find_if(i, str.end(), not_space);

			//find end of next word
			iter j = find_if(i, str.end(), space);

			//copy the characters in [i,j)
			if(i != str.end())
				ret.push_back(string(i,j));
			i = j;
		}
		return ret;
}
