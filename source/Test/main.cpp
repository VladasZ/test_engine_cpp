
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

class Obj : public Mappable<Obj> {

public:

	int something;

	static const auto properties() {
		return std::make_tuple(
			PROPERTY(something, Obj, 46464646)
		);
	}
};

class TestClass : public Mappable<TestClass> {

public:

	int index;
	string name;
	vector<int> array;
	Obj object;

	static const auto properties() {
		return std::make_tuple(
			PROPERTY(index,  TestClass, 616),
			PROPERTY(name,   TestClass, "default name"),
			PROPERTY(array,  TestClass, vector<int>({ 1, 2, 3, 4, 5 })),
			PROPERTY(object, TestClass, Obj())
		);
	}
};


int main() {

	try
	{
		auto object = TestClass::parse_string("{ \"index\" : 5, \"name\" : \"hello\", \"array\" : [ 4, 4, 4, 4 ], \"object\" : { \"something\" : 777 } }");
		Logvar(object.index);
		Logvar(object.name);
		Logvar(object.array[0]);
		Logvar(object.object.something);
	}
	catch (...)
	{
		Logvar(what());
	}


	return 0;
}
