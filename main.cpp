#include <iostream>
#include "Set.hpp"

using namespace std;

int main() {

    Set s1;

    s1.add(12);
    s1.add(19);
    s1.add(22);
    s1.add(19);

    Set s2;

    s2.add(12);
    s2.add(19);
    s2.add(22);

    s1.printAll();
    s2.printAll();

    Set U = s1.unionSet(s2);

    U.printAll();
}