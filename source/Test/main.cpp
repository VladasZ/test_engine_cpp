
#include <iostream>
#include <functional>
#include <type_traits>

#include "RegistryKey.hpp"

#include "String.hpp"
#include "Log.hpp"

#include "Block.hpp"
#include "ExceptionCatch.hpp"

#include "Mappable.hpp"

#include "json.hpp"

using namespace std;

class TargetClass {

public:

	static void spes() {
		cout << "spes" << endl;
	}

protected:

	void helloww() {
		Log("hellooww");
	}
};





void test() {

	auto spes = TargetClass::spes;
	auto spe2s = &TargetClass::helloww;


	spes();
}

int main() {

	try {
		test();
	}
	catch (...)
	{
		Logvar(what());
	}

	return 0;
}
