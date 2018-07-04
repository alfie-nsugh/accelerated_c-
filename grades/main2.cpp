#include <iostream>
#include <algorithm>
#include <iomanip>
#include <ios>
#include <stdexcept>
#include <string>
#include <vector>
#include <fstream>
#include <list>
#include <cctype>
#include <cstdlib>
#include "grade.h"
#include "Student_info.h"
#include "split.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::max;

using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;
using std::list;
using std::ifstream;
using std::isalpha;
using std::stod;

int main()
{

	list<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	ifstream inFile;
	inFile.open("text.txt");
	if(!inFile)
		cout << "Unable to open file text.txt";
	
	double x;
	string line;
	while(getline(inFile, line)){
		vector<string> v(split(line));	
		for(vector<string>::size_type i = 0; i !=v.size(); ++ i){
			record.name = v[i];
			record.midterm = stod(v[i + 1]);
			record.final = stod(v[i + 2]);
			for(vector<string>::size_type j = i+3; j!=v.size()&& !isalpha(v[j][0]); ++j){
				record.homework.push_back(stod(v[j]));		
				i = j;
			}
			students.push_back(record);
			record.homework.clear();
		}	
		inFile.close();
	}
	list<Student_info>::iterator iter = students.begin();

	for(list<Student_info>::size_type i = 0; i != students.size(); i++){
		cout << iter->name << iter->midterm << iter->final << endl;
		for(vector<Student_info>::size_type j = 0; j != iter->homework.size();
						++j)
			cout << iter->homework[j] << endl;
		cout << '\n' << endl;
		iter++;
	}
	return 0;


}

