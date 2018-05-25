//
//#include <iostream>
//#include "Time.hpp"
//
//#include "FileManager.hpp"
//
//#include "Event.hpp"
//#include "Log.hpp"
//
//using namespace std;
//
//using SimpleEvent = Event<int, int>;
//
//SimpleEvent event([](auto, auto) { return true; });
//
//int main() {
//
// 
//    cout << FileManager::assetsDirectory() << endl;
//    cout << FileManager::workDirectory() << endl;
//
//    event.subscribe(new int(5), [](auto) {
//        Log("sps");
//    });
//
//    event(5);
//    event(5);
//    event(5);
//    event(5);
//
//
//    return 0;
//}