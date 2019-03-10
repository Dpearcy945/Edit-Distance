
#include "editDistance.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//the constructors,  nothing to see hear
EditDistance::EditDistance()
{
	str1 = "A";
	str2 = "A";
}
EditDistance::EditDistance(string s1, string s2)
{
	
	if(s1.size() >= s2.size())
	{
	//the small one
	str1 = s2;
	//the big one
	str2 = s1;
	}
	if(s2.size() >= s1.size())
	{
	//the small one
	str1 = s1;
	//the big one
	str2 = s2;
	}
	str1.append("-");
	str2.append("-");
 	vector<int> *temp;
	int i, j;
	for(i = 0; str1[i] != '\0';i++)
	{	
		temp = new vector<int>;
		matrix.push_back(*temp);
		for(j = 0; str2[j] != '\0'; j++)
		{
			matrix[i].push_back(0);
		}
	}
	size1 = i;
	size2 = j;
}

//this calculates the distance
int EditDistance::calc_dist(char c1, char c2)
{
	//cout << "The begining of calc dist" << endl;
	if(c1 == c2){
		return 0;
	}
	if((c1 == '-')||(c2 == '-')){
		return 2;
	}
	else{ 
		return 1;
	}
}

//this does a single comparison of two chars
void EditDistance::comp_str_column(int limit)
{
	
	
	if(limit < size1-1)
	{comp_str_column(limit+1);}
	cout << "Column:" << limit << endl;

	comp_str(0, limit);
	cout << "column complete" << endl;
	

}
void EditDistance::comp_str(int row, int column)
{
	//cout << Row:" << row << endl;
	//int result = 0;
	if(row < size2-1)
	{	
		comp_str(row+1, column);
		//result = matrix[column][row];
		cout << " Row:" << row;
	}
	if((column == size1-1)&&(row == size2-1))//if there is nothing next to it #the last column
	{
		matrix[column][row] = 0;
		cout << " Row:" << row;
		//cout << "Result:" << matrix[column][row];
		//cout << "End of comp_str Result:" << result << endl;
	}
	else if(column == size1-1)//if there is nothing next to it #the last column
	{
		matrix[column][row] = matrix[column][row+1]+2;;
		//cout << "Result:" << matrix[column][row];
		//cout << "End of comp_str Result:" << result << endl;
	}
	else if(row == size2-1)//if there is nothing below it #the last row
	{
		matrix[column][row] = matrix[column+1][row]+2;;
		//cout << "Result:" << matrix[column][row];
		//cout << "End of comp_str Result:" << result << endl;
	}
	else//if its none of the above then lets get comparing
	{
		//compares which key is smaller as it progresses through the matrix
		if((matrix[column+1][row+1]+calc_dist(str1[column], str2[row]) < (matrix[column+1][row])+2)&&
			(matrix[column+1][row+1] < (matrix[column][row+1])+2))
		{
		matrix[column][row] = matrix[column+1][row+1]+calc_dist(str1[column], str2[row]);
		//cout << "Result:" << matrix[column][row];
		}//result
		else if(((matrix[column+1][row]+2) < matrix[column+1][row+1]+calc_dist(str1[column], str2[row]))&&
			((matrix[column+1][row]+2) < (matrix[column+1][row])+2))
		{
		matrix[column][row] = matrix[column+1][row]+2;
		//cout << "Result:" << matrix[column][row];
		}//result
		else
		{
		matrix[column][row] = matrix[column][row+1]+2;
		//cout << "Result:" << matrix[column][row];
		}
	}
	//cout << "End of comp_str Result:" << result << endl;
	//return result;
}
//derives the result string from memoization steps.
void EditDistance::dev_res()
{
	int i = 0;
	int j = 0;
	
	cout << "Edit Distance is: " << matrix[0][0] << endl;
	while(matrix[i][j] != matrix[size1-1][size2-1])
	{
		if((matrix[i][j] == matrix[i][j+1]+2))
		{
			//column stays the same
			//row
			cout << "-" << " " << str2[j] << " " << 2 << endl;
			j += 1;
		}
		else if((matrix[i][j] == matrix[i+1][j+1]+1))
		{
			cout << str1[i]<< " " << str2[j] << " " << 1 << endl;
			//column
			i += 1;
			//row
			j += 1;
		}
		else if((matrix[i][j] == matrix[i+1][j+1]))
		{
			cout << str1[i]<< " " << str2[j] << " " << 0 << endl;
			//column 
			i += 1;
			//row
			j += 1;
		}

	}

}