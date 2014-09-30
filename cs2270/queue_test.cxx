using namespace std;
#include <iostream>
#include <list>
//#include <cstdlib>
#include "queue.h"

int main()
{
	queue<int> iq;
	iq.push(1);
	iq.push(2);
	iq.push(3);
	iq.push(4);

	cout << "iq size: " << iq.size() << endl;
	cout << "Queue iq: " << iq << endl;
	cout << "Front of iq: " << iq.front() << endl;
	cout << "Back of iq: " << iq.back() << endl;

	queue<double> dq;
	dq.push(1.1);
	dq.push(2.2);
	dq.push(3.3);
	dq.push(4.4);

	cout << "dq size: " << dq.size() << endl;
	cout << "Queue dq: " << dq << endl;
	cout << "Front of dq: " << dq.front() << endl;
	cout << "Back of dq: " << dq.back() << endl;

	queue<char> cq;
	cq.push('a');
	cq.push('b');
	cq.push('c');
	cq.push('d');

	cout << "cq size: " << cq.size() << endl;
	cout << "Queue cq: " << cq << endl;
	cout << "Front of cq: " << cq.front() << endl;
	cout << "Back of cq: " << cq.back() << endl;


	return EXIT_SUCCESS;
}

