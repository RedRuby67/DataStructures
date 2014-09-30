// line.h

#ifndef LINE_H_
#define LINE_H_

#include <iostream>
#include "point.h"
//#include "point.cpp"

class line
{
	friend class point;
	public:
		line();
		line(point pa);
		line(point pa, point pb);
		line(const line& la); // copy constructor
		double slope() const;
		void translate(double X, double Y);
		void reflect_x();
		void reflect_y();
		double intercept(line l1) const;
		double slope_and_intercept(line l1);
		void operator = (const line &l1);
		
		//for cin
		friend std::istream& operator >>(std::istream& ins, line& target);
		// for cout
		friend std::ostream& operator <<(std::ostream& outs, const line& source);
		
	private:
		point p1;
		point p2;
		double m;
		double a;
		double b;
		double c;
		double x1;
		double x2;
		double y1;
		double y2;
	
};

bool operator ==(const line &l1, const line &l2);


#endif
