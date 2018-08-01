//
//  ExceptionCatch.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 6/26/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "ExceptionCatch.hpp"

using namespace std;

String what(const std::exception_ptr &eptr) {
    if (!eptr) { throw bad_exception(); }
    try { rethrow_exception(eptr); }
    catch (const exception  &e) { return e.what(); }
    catch (const string     &e) { return e; }
    catch (const char      * e) { return e; }
    catch (...) { return "Unknown exception."; }
}
