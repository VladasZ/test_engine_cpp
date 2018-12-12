

#include "python_test.hpp"

//#include <iostream>
//#include <boost/python.hpp>
//#include <cstdlib> // setenv
//
//using namespace std;
//
//namespace python = boost::python;
//
//
//template <class T>
//auto to_python_list(const std::vector<T>& vector) {
//	python::list list;
//	for (const auto& obj : vector)
//		list.append(obj);
//	return list;
//}
//
//template <class T>
//auto to_vector(const python::list& list) {
//	std::vector<T> result;
//	for (int i = 0; i < len(list); ++i)
//		result.push_back(python::extract<T>(list[i]));
//	return result;
//}

void python_test() {
	// Allow Python to load modules from the current directory.
//	setenv("PYTHONPATH", ".", 1);
	// Initialize Python.
	//Py_Initialize();

	//try
	//{
	//	// >>> import MyPythonClass
	//	python::object my_python_class_module = python::import("Solve");

	//	// >>> dog = MyPythonClass.Dog()

	//	python::object arr = my_python_class_module.attr("print_arr")(to_python_list(std::vector<int> { 1, 2, 3, 4, 5 }));

	//	python::list list(arr);

	//	auto vec = to_vector<int>(list);


	//	for (auto n : vec)
	//		cout << n << endl;

	//	// >>> dog.bark("woof");
	//	//dog.attr("bark")("woof");
	//}
	//catch (const python::error_already_set&)
	//{
	//	PyErr_Print();
	//}

	// Do not call Py_Finalize() with Boost.Python.
}
