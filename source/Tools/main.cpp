
#include <iostream>
#include <functional>
#include <type_traits>

#include "RegistryKey.hpp"

#include "String.hpp"
#include "Log.hpp"

#include "Block.hpp"

using namespace std;



struct X {
    String toString() const { return " tipergles "; }
};

struct Y : public X {};


class NotStringAtAll {


};

int main() {


    Block spes(true);
    Block spes2(5);
    Block spes3("sss"_s);
    Block spes4("rglica");

   // Block spes5(NotStringAtAll());

    cout << Block::is_supported<int> << endl;
    cout << Block::is_supported<bool> << endl;
    cout << Block::is_supported<String> << endl;
    cout << Block::is_supported<const char *> << endl;
    cout << Block::is_supported<NotStringAtAll> << endl;


    return 0;
}