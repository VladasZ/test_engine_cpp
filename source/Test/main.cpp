
#include <iostream>
#include <functional>
#include <type_traits>

#include "RegistryKey.hpp"

#include "String.hpp"
#include "Log.hpp"

#include "Block.hpp"
#include "ExceptionCatch.hpp"

using namespace std;


void test() {

	Block spes = (double)5;

	Log(spes.getType());

	cout << spes.value<int>() << endl;
}

int main() {

	try
	{
		test();
	}
	catch (...)
	{
		Log(what());
	}

    return 0;
}
