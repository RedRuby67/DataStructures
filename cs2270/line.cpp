// line.cpp

#include "line.h"

using namespace std;

line::line() 
{
	p1.set_x(-1);
	p1.set_y(0);
	p2.set_x(1);
	p2.set_y(0);
}

line::line(point pa) 
{
	p1.set_x(pa.get_x());
	p1.set_y(pa.get_y());
	p2.set_x(0);
	p2.set_y(0);
}

line::line(point pa, point pb)
{
	p1.set_x(pa.get_x()), p1.set_y(pa.get_y());
	p2.set_x(pb.get_x()), p2.set_y(pb.get_y());
}

line::line(const line& la)
{
	p1 = la.p1;
	p2 = la.p2;
}

	
double line::slope() const
{
	
	if (p1.get_x() == p2.get_x()) {
		cout << "Error. Slope is Infinity" << endl;
	}
	else if (p1.get_y() == p2.get_y()) {
		return 0;
	} else {
		return (p2.get_y() - p1.get_y()) / (p2.get_x() - p1.get_x());
	}	
	
}

void line::translate(double X, double Y)
{
	
	p1.translate(X, Y);
	p2.translate(X, Y);
}

void line::reflect_x()
{
	
	p1.reflect_x();
	p2.reflect_x();
			
}

void line::reflect_y()
{
	
	p1.reflect_y();
	p2.reflect_y();	
	
}

double line::intercept(line l1) const {
	return p1.get_y() - l1.slope() * p1.get_x();
}

double line::slope_and_intercept(line l1)
{
	m = l1.slope();
	c = p1.get_y() - l1.slope() * p1.get_x();
	b = p1.get_y();
	a = p1.get_x();
	return m;
	return c;
	return b;
	return a;
}

bool operator ==(const line &l1, const line &l2) 
{
	return (l1.slope() == l2.slope() 
			&& l1.intercept(l1) == l2.intercept(l2));
	//return (l1.slope_and_intercept(l1) == l2.slope_and_intercept(l2));
}

istream& operator >>(istream& ins, line& target) //IMPLEMENT THIS!!
{
	
	//UPDATE THIS FOR MUG LAB 2-- (hint it'd be ins>>target.<something>)
	//Remember we can use the private variable here because it's a friend
	ins >> target.x1 >> target.y1 >> target.x2 >> target.y2;
	return ins;
}


ostream& operator <<(ostream& outs, const line& source) //IMPLEMENT THIS!!
{  
	
	//UPDATE THIS FOR MUG LAB 2 (maybe outs<<source.<something>.....)
	//Remember we can use the private variable here because it's a friend
	outs << "y =" << source.m << "x" << "+" << source.c;
	outs << "y =" << source.b;
	outs << "x =" << source.a;
	return outs;
}
