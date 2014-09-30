#include<cassert>    //provides assert
#include "bigInt.h"  //bigInt class
#include <iostream>  //we are adding ostream and istream
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;

//Default constructor
bigInt::bigInt()
{
	bigIntArray = new char[2]; // maybe new char[1]?
	bigIntArray[0] = '0';
	bigIntArray[1] = '\0';
	//a 2 element array with an initial value of zero and a NULL
	//character  ie: 0th element is 0 and 1st element is NULL
}

//"c_str" constructor
bigInt::bigInt(const char initialValue [])
{
	bigIntArray = new char[strlen(initialValue + 1)];
	strcpy(bigIntArray, initialValue);
	//make your bigInt array equal to this c_str
	//being passed in  (i.e. use strlen to allocate
	//memory (remember to add +1 to it though for the null character...
	// and strcpy to copy the stuff over (strcpy adds the null automatically)
}

//"integer" constructor
bigInt::bigInt(int initialValue)
{
	int number = initialValue;
	int digits = 0;
	if (number < 0) digits = 1; // remove this line if '-' counts as a digit
	while (number) {
	number /= 10;
	digits++;
	}
	bigIntArray = new char[digits + 1];
	sprintf(bigIntArray, "%i", initialValue);

	//use a loop to count the numberOfDigits in initial value
	//Allocate that memory and copy it over (that good ol divide
	//by 10 and modulo 10 thing
}

//"double" constructor
bigInt::bigInt (double initialValue)
{
	int intinitialValue = (int) initialValue;
	int number = (int) initialValue;
	int digits = 0;
	if (number < 0) digits = 1;
	while (number) {
		number /= 10;
		digits++;
	}
	bigIntArray = new char [digits + 1];
	sprintf(bigIntArray, "%i", intinitialValue);
	//very similar to the integer constructor strategy above
	//in fact you get this into an int and you can use the same
	//code...	
}

//Copy Constructor
bigInt::bigInt (const bigInt& toCopyFrom)
{
	bigIntArray = toCopyFrom.getBigIntArray();
}
	
	//use the getBigIntArray on toCopyFrom to set bigIntArray of you object
	//remember to delete bigIntArray of your object BEFORE setting it
	//or else you'll get a memory leak 


bigInt::~bigInt()
{
	delete[] bigIntArray;
}


//Returns a dynamically allocated copy to the bigIntArray
char* bigInt::getBigIntArray() const
{
	//Implemented to help you.
	//RETURNS A POINTER TO A COPY of our bigIntArray
	//with memory already allocated. You can set this 
	//to another char * etc.
	char* toReturn;
	toReturn = new char[strlen(bigIntArray)+1];
	strcpy(toReturn, bigIntArray);
	return toReturn;
}

//operator "="
void bigInt::operator = (const bigInt& toEqual)
{
	bigIntArray = toEqual.getBigIntArray();
	//use getBigIntArray on toEqual to set your int array to 
	//the intArray of toEqual	
}

//operator "=="
bool operator ==(const bigInt& firstInt, const bigInt& secondInt)	
{
	
	if (strcmp(firstInt.getBigIntArray(), secondInt.getBigIntArray()) == 0)
	{
		return true;
	}
	return 0;
	
	//check to see if the bigIntArray's are equal
	//you can use strcmp for this
}

//operator !=
bool operator !=(const bigInt &firstInt, const bigInt &secondInt)
{
	if (strcmp(firstInt.getBigIntArray(), secondInt.getBigIntArray()) != 0)
	{
		return true;
	}
	return false;
	//easy once you've done ==
}

//operator <
bool operator < (const bigInt &firstInt, const bigInt &secondInt)
{
	if(strlen(firstInt.getBigIntArray()) == strlen(secondInt.getBigIntArray()))
	{
		int rtnVal = strcmp(secondInt.getBigIntArray(), firstInt.getBigIntArray());
		if(rtnVal > 0)
		{
			return true;		
		} else {
			return false;
		}
	} else if(strlen(firstInt.getBigIntArray()) < strlen(secondInt.getBigIntArray()))
	{
		return true;	
	} else
	{
		return false;
	}
}

//operator >
bool operator > (const bigInt &firstInt, const bigInt &secondInt)
{
	//Not too bad, think about it...
	if( strlen(firstInt.getBigIntArray()) == strlen(secondInt.getBigIntArray()) )
	{
		int rtnVal = strcmp(secondInt.getBigIntArray(), firstInt.getBigIntArray());
		if(rtnVal < 0)
		{
			return true;		
		} else {
			return false;
		}
	} else if( strlen(firstInt.getBigIntArray()) > strlen(secondInt.getBigIntArray()) )
	{
		return true;	
	} else {
		return false;
	}
}

/*
//operator <=
bool operator <=(const bigInt &firstInt, const bigInt &secondInt)
{
	if (strlen(firstInt.getBigIntArray()) > strlen(secondInt.getBigIntArray()) ||
		strcmp(firstInt.getBigIntArray(), secondInt.getBigIntArray()) > 0)
	{
		return false;
	} else {
	return true;
	}	
	return false;
	//if it's not greater than..
}
*/

//operator <=
bool operator <= (const bigInt &firstInt, const bigInt &secondInt)
{
	
	if( strlen(firstInt.getBigIntArray()) == strlen(secondInt.getBigIntArray()) )
	{
		int rtnVal = strcmp(firstInt.getBigIntArray(), secondInt.getBigIntArray());
		if(rtnVal <= 0)
		{
			return true;		
		} else 
		{
			return false;
		}
	} else if( strlen(firstInt.getBigIntArray()) < strlen(secondInt.getBigIntArray()) )
	{
		return true;	
	} else {
		return false;
	}
}

/*
//operator >=
bool operator >=(const bigInt &firstInt, const bigInt &secondInt)
{
	if (strlen(secondInt.getBigIntArray()) > strlen(firstInt.getBigIntArray()) ||
		strcmp(firstInt.getBigIntArray(), secondInt.getBigIntArray()) < 0)
	{
		return false;
	} else {
	return true;
	}	
	return false;
	//if it's not less than...
}
*/

//operator >=
bool operator >= (const bigInt &firstInt, const bigInt &secondInt)
{
	
	if( strlen(firstInt.getBigIntArray()) == strlen(secondInt.getBigIntArray()) )
	{
		int rtnVal = strcmp(firstInt.getBigIntArray(), secondInt.getBigIntArray());
		if(rtnVal >= 0)
		{
			return true;		
		} else 
		{
			return false;
		}
	} else if( strlen(firstInt.getBigIntArray()) > strlen(secondInt.getBigIntArray()) )
	{
		return true;	
	} else {
		return false;
	}
}

void bigInt::addsize()
{
	//cout << "This is initial bigIntArray: " << bigIntArray << endl;
	char* newbigIntArraySum = new char[strlen(bigIntArray) + 2];
	newbigIntArraySum[strlen(bigIntArray) + 1] = '\0';
	newbigIntArraySum[0] = '1';
	int ArraySumLen = strlen(bigIntArray);
	for (int i = 1; i < ArraySumLen + 1; i++) {
			newbigIntArraySum[i] = bigIntArray[i-1];
		}
	delete[] bigIntArray;
	bigIntArray = newbigIntArraySum;
	//cout << "This is bigIntArray: " << bigIntArray << endl;
}

void bigInt::subsize()
{
	//cout << "This is initial bigIntArray: " << bigIntArray << endl;
	char* newbigIntArraySum = new char[strlen(bigIntArray) - 2];
	newbigIntArraySum[strlen(bigIntArray) - 1] = '\0';
	//newbigIntArraySum[0] = '1';
	int ArraySumLen = strlen(bigIntArray);
	for (int i = 1; i < ArraySumLen + 1; i++) {
			newbigIntArraySum[i] = bigIntArray[i-1];
		}
	delete[] bigIntArray;
	bigIntArray = newbigIntArraySum;
	//cout << "This is bigIntArray: " << bigIntArray << endl;
}


// operator +
bigInt operator +(const bigInt &firstInt, const bigInt &secondInt)
{
	//make two temporary char* to hold the bigIntArray of firstInt and secondInt
    //you can use getBigIntArray (temp1 and temp2)
    char* temp1;
    char* temp2;
    temp1 = firstInt.getBigIntArray();
    temp2 = secondInt.getBigIntArray();
    char* bigIntArraySum; // array that will return
    int temp3len; // length of return array
    //int endflag = 0;
    
    //find out which one of these bigInts is bigger and make a third char*
    //array of that size to hold the result of our add (result)
    
    if (strlen(temp1) > strlen(temp2))
	{
		temp3len = strlen(temp1);
		bigIntArraySum = new char[temp3len + 1];
	
	} else {
		temp3len = strlen(temp2);
		bigIntArraySum = new char[temp3len + 1];
	}
	
	bigIntArraySum[temp3len + 1] = '\0';  
	
    //start at the final index of temp1 and temp2 and start adding them
    //index by index, placing them in result and decrementing their indexes (I 
    //had two index variables)
    //Remember to add a carry if the last sum was greater or equal to 10
	int index1 = strlen(temp1) - 1; int index2 = strlen(temp2) - 1;  // defined outside for loop
    int carry = 0;
	for (int i = temp3len - 1; i >= 0; i--) {
			int n1 = temp1[index1] - '0'; 
 			int n2 = temp2[index2] - '0';
 			--index1;
 			--index2;
 			if (n1 < 0) {
				n1 = 0;
			} if (n2 < 0) {
				n2 = 0;
			}
		
			int sum = n1 + n2 + carry; 
 			
 			if (sum > 9) {
				carry = 1;
			} else {
			carry = 0;
			}	
			
			//cout << "this is index1: " << index1 << endl;
			//cout << "this is index2: " << index2 << endl;
			//cout << "This is n1: " << n1 << endl;
			//cout << "This is n2: " << n2 << endl;
 			//cout << "this is sum: " << sum << endl;
 			
 			char current_digit = ( sum % 10 ) + '0'; 
 			
 			bigIntArraySum[i] = current_digit;

 }
 
	bigInt toReturn(bigIntArraySum);
	//cout << "this is size of bigIntArraySum: " << strlen(bigIntArraySum) << endl;			
	if (carry == 1) {
		toReturn.addsize();
	}
	
	return toReturn;
}

    //When the smaller numbers index is negative, then you only add
    //the bigger ones index to the carry and place this in the result
    
    //when you're done (ie index1 and index2 are negative) - if you have a 
    //carry you resize the result array and put a 1 in the front
    
    //finally you create a bigInt with that array and return it
    //before you do remember to deallocate any dynamic memory before the
    //ptr disappears


void bigInt::operator += (const bigInt& intToAdd)
{
	bigInt temp;
	temp = *this + intToAdd;
	delete[] bigIntArray;
	bigIntArray = temp.getBigIntArray();
	bigInt ToReturn(bigIntArray);
}


bigInt operator - (const bigInt&firstInt, const bigInt&secondInt)
{
	char* temp1; char* temp2;
	temp1 = firstInt.getBigIntArray();
	temp2 = secondInt.getBigIntArray();
	char* bigIntArrayDif;
	int temp3len;
	
	if (strlen(temp1) > strlen(temp2))
	{
		temp3len = strlen(temp1);
		bigIntArrayDif = new char[temp3len + 1];
	
	} else {
		temp3len = strlen(temp2);
		bigIntArrayDif = new char[temp3len + 1];
	}
	
	bigIntArrayDif[temp3len] = '\0';
	
	int index1 = strlen(temp1) - 1; int index2 = strlen(temp2) - 1;  // defined outside for loop
    int carry = 0;
	for (int i = temp3len - 1; i >= 0; --i) {
			int n1 = temp1[index1] - '0'; 
 			int n2 = temp2[index2] - '0';
 			--index1;
 			--index2;
 			if (n1 < 0) {
				n1 = 0;
			} if (n2 < 0) {
				n2 = 0;
			}
			
			int dif;
			if (n1 < n2) {
				dif = 10 + n1 - carry - n2;
				carry = 1; 
			} else {
				dif = n1 - carry - n2;
				carry = 0;
			}
			
			//cout << "this is index1: " << index1 << endl;
			//cout << "this is index2: " << index2 << endl;
			//cout << "This is n1: " << n1 << endl;
			//cout << "This is n2: " << n2 << endl;
 			//cout << "this is dif: " << dif << endl;
 			char current_digit = ( dif % 10 ) + '0'; 
 			
 			bigIntArrayDif[i] = current_digit;
	}
	
	bigInt toReturn(bigIntArrayDif);
	if (carry == 1) {
		toReturn.subsize();
	}
	
	
	
	return toReturn;
}
	

void bigInt::operator -= (const bigInt& intToSubtract)
{
	bigInt temp;
	temp = *this - intToSubtract;
	delete[] bigIntArray;
	bigIntArray=temp.getBigIntArray();
	
	//If you've done minus, this should be easy
	//you can even use the this ptr.
}


// operator *
bigInt operator *(const bigInt &firstInt, const bigInt &secondInt)
{
	//make two temporary char* to hold the bigIntArray of firstInt and secondInt
    //you can use getBigIntArray (temp1 and temp2)
    char* temp1;
    char* temp2;
    temp1 = firstInt.getBigIntArray();
    temp2 = secondInt.getBigIntArray();
    char* bigIntArrayMul; // array that will return
    int temp3len; // length of return array
    //int endflag = 0;
    
    //find out which one of these bigInts is bigger and make a third char*
    //array of that size to hold the result of our add (result)
    
    if (strlen(temp1) > strlen(temp2))
	{
		temp3len = strlen(temp1);
		bigIntArrayMul = new char[temp3len + 1];
	
	} else {
		temp3len = strlen(temp2);
		bigIntArrayMul = new char[temp3len + 1];
	}
	
	bigIntArrayMul[temp3len + 1] = '\0';  
	
    //start at the final index of temp1 and temp2 and start adding them
    //index by index, placing them in result and decrementing their indexes (I 
    //had two index variables)
    //Remember to add a carry if the last sum was greater or equal to 10
	int index1 = strlen(temp1) - 1; int index2 = strlen(temp2) - 1;  // defined outside for loop
    int carry = 0;
	for (int i = temp3len - 1; i >= 0; i--) {
			int n1 = temp1[index1] - '0'; 
 			int n2 = temp2[index2] - '0';
 			--index1;
 			--index2;
 			if (n1 < 0) {
				n1 = 0;
			} if (n2 < 0) {
				n2 = 0;
			}
		
			int mul = (n1 * n2) + carry; 
 			
 			if (mul > 9) {
				carry = mul / 10;
			} else {
				carry = 0;
			}	
			
			//cout << "this is index1: " << index1 << endl;
			//cout << "this is index2: " << index2 << endl;
			//cout << "This is n1: " << n1 << endl;
			//cout << "This is n2: " << n2 << endl;
 			//cout << "this is sum: " << sum << endl;
 			
 			char current_digit = ( mul % 10 ) + '0'; 
 			
 			bigIntArrayMul[i] = current_digit;

 }
 
	bigInt toReturn(bigIntArrayMul);

	if (carry == 1) {
		toReturn.addsize();
	}

	return toReturn;
}

void bigInt::operator *= (const bigInt& intToMultiply)
{
	bigInt temp;
	temp = *this * intToMultiply;
	delete[] bigIntArray;
	bigIntArray = temp.getBigIntArray();
	bigInt ToReturn(bigIntArray);
}


//ostream is implemented for you
ostream& operator <<(ostream& outs, const bigInt& source)
{  
	outs << source.bigIntArray;
	return outs;
}

//istream is implemented for you 
std::istream& operator >>(std::istream& ins, bigInt& target)
{
	delete [] target.bigIntArray;
	string hello;
	ins >> hello;
	bigInt temp(hello.c_str());
	target.bigIntArray=temp.getBigIntArray();
    return ins;
}

