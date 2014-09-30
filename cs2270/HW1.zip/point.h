// point.h
#ifndef POINT_H_
#define POINT_H_

#include <iostream>

class point
{
	friend class line;
	public:
		point();  // comment out due to ambiguity?
		point(double x_in, double y_in);
		point( const point &pa); // copy constructor
		double get_x() const; // make const for line class
		double get_y() const;
		void set_x(double X);
		void set_y(double Y);
		void translate(double X, double Y);
		void scale(double m);
		void reflect_x();
		void reflect_y();
		void rotate(double r);
		void operator = (const point &pa);
		//for cin
		friend std::istream& operator >>(std::istream& ins, point& target);
		// for cout
		friend std::ostream& operator <<(std::ostream& outs, const point& source);
		
		
	private:
		double x; // x coordinate of this point
		double y; // y coordinate of this point
};

//NONMEMBERS
bool operator ==(const point &p1, const point &p2);


#endif
