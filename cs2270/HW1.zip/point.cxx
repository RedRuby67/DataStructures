// point.cpp

#include "point.h"
using namespace std;


point::point()
{
	x = 0;
	y = 0;
}


point::point(double x_in, double y_in)
{
	x = x_in;
	y = y_in;
} 

point::point(const point &pa)
{
	x = pa.x;
	y = pa.y;
}

double point::get_x() const {
	return x;
}

double point::get_y() const {
	return y;
}

void point::set_x(double X) {
	x = X;
}

void point::set_y(double Y) {
	y = Y;
}

void point::translate(double X, double Y)
{
	x += X;
	y += Y;
}

void point::scale(double m)
{
	x = x * m;
	y = y * m;
}

void point::reflect_x()
{
	x = x;
	y = -y;	
}

void point::reflect_y()
{
	x = -x;
	y = y;	
}

#include <math.h>
void point::rotate(double r)
{
	double old_x = x;
	x = x * cos(r) - y * sin(r);
	y = old_x * sin(r) + y * cos(r);
}

bool operator ==(const point &p1, const point &p2) 
{
	return ( p1.get_x() == p2.get_x() && 
			p2.get_y() == p2.get_y() );
}
	
void point::operator = (const point &pa) 
{
	x = pa.x;
	y = pa.y;
}


istream& operator >>(istream& ins, point& target) //IMPLEMENT THIS!!
{
	
	//UPDATE THIS FOR MUG LAB 2-- (hint it'd be ins>>target.<something>)
	//Remember we can use the private variable here because it's a friend
	ins >> target.x >> target.y;
	return ins;
}


ostream& operator <<(ostream& outs, const point& source) //IMPLEMENT THIS!!
{  
	
	//UPDATE THIS FOR MUG LAB 2 (maybe outs<<source.<something>.....)
	//Remember we can use the private variable here because it's a friend
	outs << "(" << source.x << "," << source.y << ")";
	return outs;
}

