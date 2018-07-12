
#include <iostream>
#include <functional>
#include <type_traits>

#include "RegistryKey.hpp"

#include "String.hpp"
#include "Log.hpp"

#include "Block.hpp"

using namespace std;


template<class T>
struct ArrTest {


    static T array;

    using type = decltype(array[0]);

};

class NotString {

};

void test() {


    Block spes(false);
    Block spes2(5);
    Block spes3("sss"_s);
    Block spes4("rglica");

    cout << is_string_convertible<decltype("rglica")> << endl;

    for (auto st : spes3)
    {
        cout << st.get<String>() << endl;
    }


    cout << spes.get<bool>() << endl;
    cout << spes2.get<int>() << endl;
    cout << spes3.get<String>() << endl;
    cout << spes4.get<char *>() << endl;
}

int main() {

    try
    {
        test();

    }
    catch (String err)
    {
        Log(err);
    }



    return 0;
}