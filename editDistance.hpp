#ifndef EDITDISTANCE_HPP
#define EDITDISTANCE_HPP


#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class EditDistance
{
public:
	//the constructors,  nothing to see hear
	EditDistance();
	EditDistance(string s1, string s2);
	//this calculates the distance
	int calc_dist(char c1, char c2);

	//this recursively runs to the back of the string
	void comp_str_column(int limit);

	//this recursively runs down the rows
	void comp_str(int row, int column);

	//derives the result string from memoization steps.
	void dev_res();

private:
	string str1;//the smallest string
	string str2; // the bigger string
	int size1;
	int size2;
	vector< vector< int > > matrix;
};

#endif