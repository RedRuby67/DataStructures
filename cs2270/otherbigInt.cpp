#include<cassert>//provides assert
#include "bigInt.h" //big int class
#include <iostream> //we are adding ostream and istream
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;

bigInt::bigInt()
{
	//a 1 element array with an initial value of zero
	bigIntArray= new char [2];
	bigIntArray[0]='0';
	bigIntArray[1]='\0';
}

bigInt::bigInt(const char initialValue [])
{
	bigIntArray= new char[strlen(initialValue)+1];
	strcpy(bigIntArray, initialValue);
}

bigInt::bigInt(int initialValue)
{
	int number=initialValue;
	int digits = 0;
    if (number < 0) digits = 1; // remove this line if '-' counts as a digit
    while (number) {
        number /= 10;
        digits++;
    }
    bigIntArray=new char[digits+1];
	sprintf(bigIntArray, "%i", initialValue);
	
}

bigInt::bigInt (double initialValue)
{
	int newInitialValue= initialValue;
	int number=newInitialValue;
	int digits = 0;
    if (number < 0) digits = 1; // remove this line if '-' counts as a digit
    while (number) {
        number /= 10;
        digits++;
    }
    bigIntArray=new char[digits+1];
	sprintf(bigIntArray, "%i", newInitialValue);
}

bigInt::bigInt (const bigInt& toCopyFrom)
{
	bigIntArray= toCopyFrom.getBigIntArray();
}

char* bigInt::getBigIntArray() const
{
	char *toReturn;
	toReturn=new char[strlen(bigIntArray)];
	strcpy(toReturn, bigIntArray);
	return toReturn;
}

void bigInt::operator = (const bigInt& toEqual)
{
	if (this==&toEqual)
		return;
		
	delete [] bigIntArray;
	bigIntArray=toEqual.getBigIntArray();
}


bigInt operator +(const bigInt &firstInt, const bigInt &secondInt)
{
	
	char* temp1;
	//strcpy(temp1, firstInt.getBigInt());
	temp1=firstInt.getBigIntArray();
	char* temp2;
	temp2=secondInt.getBigIntArray();
	char* result;
	//strcpy(temp2, secondInt.getBigInt());
	if(strlen(temp1)>strlen(temp2))
	{
		//cout<<"STRLEN: "<<strlen(temp1)<<endl;
		int lameTemp=strlen(temp1)+1;
		result= new char [lameTemp];
		strcpy(result,temp1);
		//cout<<"RESULT STRLEN: "<<strlen(result)<<endl;
	}
	else
	{
		int lameTemp2= strlen(temp2)+1;
		result= new char [lameTemp2];
		strcpy(result,temp2);
	}
	
	int endFlag=0;
	//start at strlen and go back
	int firstIndex=strlen(temp1)-1;
	int secondIndex=strlen(temp2)-1;
 	int resultIndex= strlen(result)-1;
 	//cout<<"\n RESULT INDEX: "<<resultIndex<<endl;
 	//cout<<"RESULT LENGTH: "<<strlen(result)<<endl;
 	int carry=0;
 	//int fun=0;
	while(endFlag==0)
	{
	//	cout<<"\n FIRST "<<temp1[firstIndex]<<" Second "<<temp2[secondIndex]<<" RESULT "<<result[resultIndex]<<endl;
		
		int temp=0;
		//check if Indexes are negative
		if (firstIndex<0 && secondIndex>=0)
		{
			temp= (temp2[secondIndex]-'0')+carry;
			
		}
		else if (firstIndex>=0 && secondIndex<0)
		{
			temp= (temp1[firstIndex]-'0')+carry;
		
		}
		else
		{
			temp=(temp1[firstIndex]-'0')+(temp2[secondIndex]-'0')+carry;
		}
	//	cout<<"TEMP: "<<temp;
		if ((temp/10)>0)
			{
				carry=1;
				char* toCopy= new char [1];
				sprintf(toCopy, "%i", temp%10);
				result[resultIndex]=toCopy[0];
				delete [] toCopy;
				//result[resultIndex]=temp%10;
			//	cout<<"RESULT AT INDEX: "<<result[resultIndex];
			}
			else
			{
			//	cout<<"\n IN THE OTHER!"<<endl;
				carry=0;
				char* toCopy= new char [1];
				sprintf(toCopy, "%i", temp);
				result[resultIndex]=toCopy[0];
				delete [] toCopy;
			//	cout<<"RESULT AT INDEX: "<<result[resultIndex];
			//	cout<<"RESULT AT INDEX+1: "<<result[resultIndex+1]<<endl;
			}
			firstIndex--;
			secondIndex--;
			resultIndex--;
			if(firstIndex<0 && secondIndex<0)
			{
				endFlag=1;
			}
	}
	
	if (carry==1)
	{
		char* newResult= new char [strlen(result)+2];
		newResult[strlen(result)+1]='\0';
		newResult[0]='1';
		//cout<<"STRLEN RESULT: "<<result<<endl;
		int resultlen = strlen(result);
		for (int i=0; i<resultlen; i++)
		{
			newResult[i+1]=result[i];
		}
		//cout<<"\n NEW RESULT: "<<newResult<<endl;
		
		delete[] result;
		result=newResult;
	}
	
	bigInt toReturn(result);
	//cout<<"\n RESULT:"<<result<<endl;
	return toReturn;
}



void bigInt::operator += (const bigInt& intToAdd)
{
	bigInt temp;
	temp=*this+intToAdd;
	delete [] bigIntArray;
	bigIntArray=temp.getBigIntArray();
}

ostream& operator <<(ostream& outs, const bigInt& source)
{  
	outs<<source.bigIntArray;
	return outs;
}

bigInt::~bigInt()
{
	delete [] bigIntArray;
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
	return 0;
	//easy once you've done ==
}

//operator <
bool operator <(const bigInt &firstInt, const bigInt &secondInt)
{
	if (strcmp(firstInt.getBigIntArray(), secondInt.getBigIntArray()) < 0 ||
	strlen(secondInt.getBigIntArray()) > strlen(firstInt.getBigIntArray()))
	{
		return true;
	}
	return 0;
	//Not too bad, think about it...
}

//operator >
bool operator >(const bigInt &firstInt, const bigInt &secondInt)
{
	if (strcmp(firstInt.getBigIntArray(), secondInt.getBigIntArray()) > 0 ||
	strlen(firstInt.getBigIntArray()) > strlen(secondInt.getBigIntArray()))
	{
		return true;
	}
	return 0;
	//you've done equals and <, so this should be easy
}

//operator <=
bool operator <=(const bigInt &firstInt, const bigInt &secondInt)
{
	if (strcmp(firstInt.getBigIntArray(), secondInt.getBigIntArray()) > 0 ||
	strlen(firstInt.getBigIntArray()) > strlen(secondInt.getBigIntArray()))
	{
		return false;
	} else {
	return true;
	}	
	return 0;
	//if it's not greater than..
}

//operator >=
bool operator >=(const bigInt &firstInt, const bigInt &secondInt)
{
	if (strcmp(firstInt.getBigIntArray(), secondInt.getBigIntArray()) < 0 ||
	strlen(secondInt.getBigIntArray()) > strlen(firstInt.getBigIntArray()))
	{
		return false;
	} else {
	return true;
	}	
	return 0;
	//if it's not less than...
}

std::istream& operator >>(std::istream& ins, bigInt& target)
{
	delete [] target.bigIntArray;
	string hello;
	ins>>hello;
	bigInt temp(hello.c_str());
	target.bigIntArray=temp.getBigIntArray();
    return ins;
}

