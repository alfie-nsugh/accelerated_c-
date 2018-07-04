#include <iostream>
#include <algorithm>
#include <iomanip>
#include <ios>
#include <stdexcept>
#include <string>
#include <vector>
#include <fstream>
#include <list>
#include "grade.h"
#include "Student_info.h"

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


int main()
{

	list<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	ifstream inFile;
	inFile.open("D:\\projects\\grades\\text.txt");
	if(!inFile)
		cout << "Unable to open file text.txt";
	
	while(read_file(inFile, record))
		students.push_back(record);
		

	extract_fails(students);

	for(list<Student_info>::size_type i = 0; i != students.size(); ++i){
		list<Student_info>::iterator iter = students.begin();
		cout << iter->name;
		iter++;
	}
	return 0;

}

