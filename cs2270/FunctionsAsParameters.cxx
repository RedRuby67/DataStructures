#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

template<class Item, class Process, class Parameter, class SizeType>
void process_array(Item array, Process function, Parameter argument, SizeType sizeOfArray);


void multiply_by(int &data, int multiplicant);
void pretty_print(int data, string decoration);


template <class Item, class SizeType >
void print_array(Item array[], SizeType size);

int main()
{
	int intArray[] = {1, 2, 3, 4, 5};

	cout << "Original intArray: " << endl;
	print_array(intArray, 5);
	process_array(intArray, multiply_by, 2, 5);
	cout << "Multiplied by 2: " << endl;
	print_array(intArray, 5);
	cout << endl << endl;

	cout << "3 stars on the left and on the right "<< endl <<  \n";
	process_array(intArray, pretty_print, " /// ", 5);

	return EXIT_SUCCESS;
}

template<class Item, class Process, class Parameter, class SizeType>
void process_array(Item array, Process function, Parameter argument, SizeType sizeOfArray)
{
	for(SizeType i=0; i < sizeOfArray; i++)
	{

		function(array[i], argument);
	}
}

void multiply_by(int &data, int multiplicant)
{
	data = data*multiplicant;
}
void pretty_print(int data, string decoration)
{
	cout << decoration << data << decoration << endl;
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
