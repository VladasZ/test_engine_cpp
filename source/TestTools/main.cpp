
#include <iostream>

#include "Event.hpp"

using namespace std;

int main() {

    Event<int> event;


    event.subscribe([](int n) {

        cout << n << endl;
    });


    event(14);

    return 0;
}