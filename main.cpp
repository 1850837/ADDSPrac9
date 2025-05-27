#include "DocumentManager.h"
#include <iostream>

int main(){
    DocumentManager a;

    a.addDocument("To Kill A Mockingbird", 1, 3);
    std::cout << a.search("To Kill A Mockingbird") << "\n";

    return 0;
}