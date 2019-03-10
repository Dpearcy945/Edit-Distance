//Donovan Pearcy

#include <SFML/System.hpp>
#include <cstdlib>
#include <string>
#include <iostream>
#include "editDistance.hpp"
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
	sf::Clock clock;       
    sf::Time t;
	

	string str1;
	string str2;

	cin >> str1;
	cin >> str2;

	cout << str1 << endl;
	cout << str2 << endl;

	EditDistance mat1(str1, str2);
	
	mat1.comp_str_column(0);
	mat1.dev_res();



	t = clock.getElapsedTime(); 
	cout << "Execution time is " << t.asSeconds() << " seconds \n";
	
	return 0;
}