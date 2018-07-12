
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


class Kec : public ObjectsCounter<Kec> {

public:

    string name;

    Kec(const string &name) : name(name) {

    }
};

int main() {

    Kec k("spec");
    Kec k2("spec");
    Kec k3("spec");
    Kec k4("spec");
    Kec k5("spec");
    Kec k6("spec");
    Kec k7("spec");

    auto k8 = new Kec("spec");

    cout << Kec::exists() << endl;


    delete k8;


    cout << Kec::exists() << endl;


    return 0;
}