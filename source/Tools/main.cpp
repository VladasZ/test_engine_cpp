
#include <iostream>
#include <functional>
#include <type_traits>

#include "RegistryKey.hpp"

#include "String.hpp"
#include "Log.hpp"

using namespace std;



struct X {
    String toString() const { return " tipergles "; }
};

struct Y : public X {};

int main() {

    cout << X() << endl;

    return 0;
}