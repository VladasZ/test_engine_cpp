//
//  NonCopyable.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 19/01/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

template <class T>
class StaticClassInfo;
#define STATIC_GET_TYPE(Type) StaticClassInfo<decltype(Type)> _foo;

#define FOR(n) for (int i = 0; i < (n); i++)

#define MAX(container, comp)  (*max_element((container).begin(), (container).end(), (comp)))
#define MIN(container, comp)  (*min_element((container).begin(), (container).end(), (comp)))

#define MMAX(container, type, comp) MIN((container), [] (type v1, type v2) {\
return type comp < type comp;\
})comp;
