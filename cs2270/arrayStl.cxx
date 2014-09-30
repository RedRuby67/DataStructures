#include <iostream>
#include <stack>
#include <vector>
#include <queue> 
using namespace std;

int main() {
	stack <int> hello;
	hello.push(5);
	hello.push(2);
	int x = hello.top();
	cout << x << endl;
	
 priority_queue <int> mypq;

  mypq.push(30);
  mypq.push(100);
  mypq.push(25);
  mypq.push(40);

  std::cout << "Popping out elements...";
  while (!mypq.empty())
  {
     std::cout << ' ' << mypq.top();
     mypq.pop();
  }
  std::cout << '\n';
	}
