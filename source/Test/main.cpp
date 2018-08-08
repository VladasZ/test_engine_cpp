
#include <iostream>
#include <functional>
#include <type_traits>

#include "RegistryKey.hpp"

#include "String.hpp"
#include "Log.hpp"

#include "ExceptionCatch.hpp"

#include "Mappable.hpp"

#include "Json.hpp"

using namespace std;


struct SpesoStructorec {
    int a = 0;
    int b = 20;
};

CONVERT(SpesoStructorec)
{
    static auto properties() {
        std::make_tuple(
            PROPERTY(a, 500),
            PROPERTY(b, 100500)
        );
    }
};

void test() {
    
    auto structorec = SpesoStructorec();
    
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
