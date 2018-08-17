
#include <iostream>
#include <functional>
#include <type_traits>

#include "RegistryKey.hpp"

#include "String.hpp"
#include "Log.hpp"

#include "ExceptionCatch.hpp"

using namespace std;




void test() {
        
    Log("spesoperebesdhhel");
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
