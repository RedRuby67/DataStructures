// line.cxx

#include "line.h"
#include "point.h"
using namespace std;

line::line() 
// set points to (-1,0) and (1,0)
{
	p1.set_x(-1);
	p1.set_y(0);
	p2.set_x(1);
	p2.set_y(0);
}

line::line(point pa) 
// takes one input point, other is (0,0)
{
	p1.set_x(pa.get_x());
	p1.set_y(pa.get_y());
	p2.set_x(0);
	p2.set_y(0);
}

line::line(point pa, point pb) 
{
	p1.set_x(pa.get_x());
	p1.set_y(pa.get_y());
	p2.set_x(pb.get_x()); 
	p2.set_y(pb.get_y());
}

line::line(const line& la)
{
	p1 = la.p1;
	p2 = la.p2;
}

	
double line::slope() const
{
	double m;
	/*
	if (p1.get_x() == p2.get_x()) {
		return Inf;
		//cout << "Error. Slope is Infinity" << endl;
	}
	else if (p1.get_y() == p2.get_y()) {
		return m = 0;
	} else {
		return m = (p2.get_y() - p1.get_y()) / (p2.get_x() - p1.get_x());
	}	
	*/
	// (y2 -y1) / (x2 - x1)
	return m = (p2.get_y() - p1.get_y()) / (p2.get_x() - p1.get_x());
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
	double c;
	return c = l1.p1.get_y() - l1.slope() * l1.p1.get_x();
}

double line::slope_and_intercept(line l1)
{
	//m = l1.slope();
	//c = p1.get_y() - l1.slope() * p1.get_x();
	b = l1.p1.get_y();
	a = l1.p1.get_x();
	//return m;
	//return c;
	return b;
	return a;
}

bool operator ==(const line &l1, const line &l2) 
{
	return (l1.slope() == l2.slope() 
			&& l1.intercept(l1) == l2.intercept(l2));
	//return (abs(l1.slope()-l2.slope())<.0000001 
	//&& abs(l1.intercept()-l2.intercept())<.00001);
	//return (l1.slope_and_intercept(l1) == l2.slope_and_intercept(l2));

}

void line::operator = (const line &l1) 
{
	p1 = l1.p1;
	p2 = l1.p2;
}

istream& operator >>(istream& ins, line& target) //IMPLEMENT THIS!!
{
	
	//UPDATE THIS FOR MUG LAB 2-- (hint it'd be ins>>target.<something>)
	//Remember we can use the private variable here because it's a friend
	ins >> target.p1 >> target.p2;
	return ins;
}


ostream& operator <<(ostream& outs, const line& source) //IMPLEMENT THIS!!
{  
	
	//UPDATE THIS FOR MUG LAB 2 (maybe outs<<source.<something>.....)
	//Remember we can use the private variable here because it's a friend
	point p1 = source.p1;
	point p2 = source.p2;
	if (p1.get_x() == p2.get_x()) {
		outs << "x = " << p1.get_x();
	} else if (source.slope() == 0.0) {
		outs << "y = " << p1.get_y();
	} else {
	outs << "y = " << source.slope() << " x " << " + " << source.intercept(source);
}	
	return outs;
}
