#ifndef BIGINT_H
#define BIGINT_H
#include <iostream>

class bigInt
{
	public:
	//constructors
	//default sets it to 0 with an array of size 1
	bigInt(); 
	//passes in a char array to initialize value
	bigInt(const char initialValue []); 
	//passes in an integer
	bigInt (int initialValue); 
	//passes in a double
	bigInt (double initialValue); 
	//copy constructor
	bigInt (const bigInt& toCopyFrom);
	//destructor
	~bigInt();
	
	//Getter
	//returns a pointer to a COPY of our array of char*'s
	char* getBigIntArray() const;
	
	//operators += -=
	void operator += (const bigInt& intToAdd); 
	void operator -= (const bigInt& intToSubtract);
	void operator =(const bigInt& toEqual);
	void operator *= (const bigInt& intToMultiply);
	
	void addsize();
	void subsize();
	
	
	//nonmember friends istream and ostream
	friend std::istream& operator >>(std::istream& ins, bigInt& target);//
    friend std::ostream& operator <<(std::ostream& outs, const bigInt& source);//
	//friend bigInt& operator-- (bigInt&);
	
	private:
	//numDigits-- returns current number of digits
	
	//private members
	char* bigIntArray; //where all our numbers reside	
	int index1; int index2;
};

//NONMEMBERS
//operator+
bigInt operator +(const bigInt &firstInt, const bigInt &secondInt); 
//operator-
bigInt operator -(const bigInt &firstInt, const bigInt &secondInt);	
//operator*
bigInt operator *(const bigInt &firstInt, const bigInt &secondInt);	
//operator==
bool operator ==(const bigInt &firstInt, const bigInt &secondInt);	
//operator !=
bool operator !=(const bigInt &firstInt, const bigInt &secondInt);
//operator <=
bool operator <=(const bigInt &firstInt, const bigInt &secondInt);
//operator >=
bool operator >=(const bigInt &firstInt, const bigInt &secondInt);
//operator <
bool operator <(const bigInt &firstInt, const bigInt &secondInt);
//operator >
bool operator >(const bigInt &firstInt, const bigInt &secondInt);

#endif
