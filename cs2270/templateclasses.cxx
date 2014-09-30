#include <iostream>
#include <cstdlib>
#include "bag.h"
#include "bigInt.h"
using namespace std;

int main()
{
	bag<bigInt> b_bag;
	bag<char> c_bag;
	bag<int> i_bag;
	bag<double> d_bag;

	b_bag.insert("123123123");
	
	return EXIT_SUCCESS;

}
