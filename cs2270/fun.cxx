//FUN WITH POINTERS!!

#include <iostream>
using namespace std;

void funtimes1 (int* hello);
void funtimes2 (int* hello);
void funtimes3 (int* hello);
void funtimes4 (int* hello, int &toPointTo);
void funtimes5 (int* &hello, int &toPointTo);

int main()
{
	int x=10;
	
	//PART 1
	
	cout<<"The value of x: "<< x <<endl;
	cout<<"The address of x: "<< &x <<endl;
	//cout<<"This is invalid, will lead to a compile error btw because x isn't a pointer: "<< *x <<endl;
	
	//PART1
	
	//Part2
	
	int* p1;
	p1 = &x;
	cout << "This is ampy x: " << &x <<endl;
	cout << "This is p1: " << p1 << endl;
	cout << "notice the variable p1 holds the variable x's memory location" << endl;
	
	//Part2
	
	//Part3
	
	int* p1;
	p1 = &x;
	cout << "This is x's value: " << x << endl;
	cout << "This is value inside the memory location p1 is pointing to; ie we dereference p1 by using the * operator " 
	<< *p1 <<endl;
	
	//Part3
	
	//Part 4
	int z=10; int y=12;
	int *p1, *p2;
	p1=&z;
	p2=&y;
	*p1=*p2;
	cout<<"This is the address of p1: "<<p1<<endl;
	cout<<"This is the address of p2: "<<p2<<endl;
	cout<<"This is the value of p1: "<<*p1<<endl;
	cout<<"This is the value of p2: "<<*p2<<endl;
	
	//Part 4
	
	//Part 5
	int z=10; int y=12;
	int* p1 = &z;
	int* p2 = &y;
	p1=p2;
	cout<<"This is the address of p1: "<<p1<<endl;
	cout<<"This is the address of p2: "<<p2<<endl;
	cout<<"This is the value of p1: "<<*p1<<endl;
	cout<<"This is the value of p2: "<<*p2<<endl;
	
	//Part 5
	
	//Part 6

	int z=10; 
	int y=12;
	int* p1;
	int* p2;
	p1 = &z;
	p2 = &y;
	//at this point p2 has the value of 12
	p1=p2;
	*p1=45;
	cout<<"This is the address of p1: "<<p1<<endl;
	cout<<"This is the address of p2: "<<p2<<endl;
	cout<<"This is the value of p1: "<<*p1<<endl;
	cout<<"This is the value of p2: "<<*p2<<endl;
	
	//Part 6
	
	//Part 7
	
	int* p = NULL;
	cout<<"This is the memory location of p: "<<p<<endl;
	cout<<"Getting the value at this location will probably cause a runtime error "<<*p<<endl;
	
	//Part 7
	
	//Part 8
	
	int* p; 
	p = &x; //remember x=10
	funtimes1(p);
	cout<<"This is the address of p "<<p<<endl;
	cout<<"This is the value of p "<<*p<<endl;
	cout<<"This is the value of x "<<x<<endl;
	
	//Part 8
	
	//Part 9

	int* p = &x; //remember x=10
	funtimes2(p);
	cout<<"This is the address of p "<<p<<endl;
	cout<<"This is the value of p "<<*p<<endl;
	cout<<"This is the value of x "<<x<<endl;

	//Part 9
	
	//Part 10
/*	int* p = &x; //remember x=10
	funtimes3(p);
	cout<<"This is the address of p "<<p<<endl;
	cout<<"This is the value of p "<<*p<<endl;
	cout<<"This is the value of x "<<x<<endl;
*/
	//Part 10
	
	//Part 11
	/*
	int* p = &x; //remember x=10
	int y=11;
	cout<<"This is the address of p before funtimes4    "<<p<<endl;
	funtimes4(p, y);
	cout<<"This is the address of p after funtimes4 "<<p<<endl;
	*/
	//Part 11
	
	//Part 12
/*	int* p = &x; //remember x=10
	int y=11;
	cout<<"This is the address that p points to before funtimes5    "<<p<<endl;
	funtimes5(p, y);
	cout<<"This is the address that p points to after funtimes5 "<<p<<endl;
*/	
	//Part 12
	
	
}	
/*
//Pointer examples using Mug
	Mug *p1;
	Mug hello; //(terrible naming convention)
	p1 = &hello;
	(*p1).getFillAmount();
	p1->getFillAmount();

*/
void funtimes1 (int  *hello)
{
	*hello=*hello+10;
}

void funtimes2 (int  *hello)
{
	++*hello;
}

void funtimes3 (int *hello)
{//I actually don't know what the hell goes on with this
//just realize you have to be careful when working with pointers
//(*hello)++ increments but *hello++ does not...has to do with
//operator precendence
	
	(*hello)++;
	
}

void funtimes4 (int* hello, int &toPointTo)
{
	hello=&toPointTo;
}

void funtimes5 (int* &hello, int &toPointTo)
{
	hello=&toPointTo;
}
