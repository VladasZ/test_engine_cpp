
#include <iostream>

#include "Bitwise.hpp"

using namespace std;

struct Test {

	uint64_t num = 3;
};

int main() {

	Test t;


	cout << bitwise::to_number(t) << endl;

	auto t2 = bitwise::set_byte(t, 2, 1);

	cout << bitwise::to_number(t2) << endl;


  cout << "Test OK" <<endl;

  return 0;
}
