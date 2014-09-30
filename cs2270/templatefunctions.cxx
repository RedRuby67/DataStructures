#include <iostream>
#include <cstdlib>
#include "bigInt.h"

using namespace std;

void print_int_array(int array[], size_t size)
{
	for(size_t i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

void print_double_array(double array[], size_t size)
{
	for(size_t i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

template<class Item, class SizeType>
void print_array(Item array[], SizeType size)
{
	for(SizeType i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

template <class Item, class SizeType>
Item return_double(Item array[], SizeType element)
{
	return array[element] + array[element];
}


int main()
{
	int intArray[] = {1, 2, 3, 4, 5};
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	char charArray[] = {'a', 'b', 'c', 'd', 'e'};

	cout << "\n Print my integer array! " << endl;
	print_int_array(intArray, 5);

	cout<<"\n Print my double array!" << endl;
	print_double_array(doubleArray, 5);

	cout<< "\n Print my character array! Oh crap, I don't want to write another function..." << endl;
	print_array(charArray, 5);
	cout<< "\n Oh boy, will that work for my int array too?! " << endl;
	print_array(intArray, 5);
	cout<< "\n double arrays?" << endl;
	print_array(doubleArray, 5);
	cout << "\n Goodness, templates are rad." << endl;

	bigInt bigIntArray[] = {"123123123123123123123", "456456456456", "789789789789"};
	cout << "\n bigInt too?! How relevant!" << endl;
	print_array(bigIntArray, 3);

	cout << "\n I want to double this number: " << bigIntArray[2] << endl;
	cout << return_double(bigIntArray, 2) << endl;

	cout << "\n Just to drive it home, watch how it works with ints! Double this: "<< doubleArray[2] << endl;
	cout << return_double(doubleArray, 2) << endl;

	return EXIT_SUCCESS;
}

