
#include <iostream>
#include <functional>
#include <type_traits>

#include "RegistryKey.hpp"

#include "String.hpp"
#include "Log.hpp"

#include "Block.hpp"

using namespace std;

template <class T>
class ObjectsCounter {

public:

    static inline int created = 0;
    static inline int deleted = 0;

    static int exists() { return created - deleted; }


    ObjectsCounter() {
        created++;
    }

    virtual ~ObjectsCounter() {
        deleted++;
    }
};


int main() {


    return 0;
}