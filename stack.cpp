#include <iostream>
#include <cassert>
#include <cstdio>
#include "stack.h"
#include <string>

using namespace std;

int main() {
	Stack<int> s(1);
	s.push(1);
	s.dump();
	s.pop();
	s.pop();	
	return 0;
}
