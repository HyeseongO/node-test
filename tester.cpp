/**
 * DO NOT MODIFY
*/
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../00_include/doctest.h"
#include "hidden_tests_02.hpp"
#include "Set.hpp"

TEST_CASE("Set insertion test cases") {
    Set mySet;

    // Test case for inserting a single element
    mySet.add(10);
    CHECK(mySet.getSize() == 1);
    CHECK(mySet.contains(10) == true);

    // Test case for inserting multiple unique elements
    mySet.add(20);
    mySet.add(30);
    mySet.add(40);
    CHECK(mySet.getSize() == 4);
    CHECK(mySet.contains(20) == true);
    CHECK(mySet.contains(30) == true);
    CHECK(mySet.contains(40) == true);

    // Test case for inserting duplicate elements
    mySet.add(10); // Trying to insert an element that already exists
    CHECK(mySet.getSize() == 4); // Size should remain the same
    CHECK(mySet.contains(10) == true); // Element should still be in the set
}

TEST_CASE("Set remove test case") {
    Set mySet;

    // Insert elements into the set
    mySet.add(10);
    mySet.add(20);
    mySet.add(30);
    mySet.add(40);
    mySet.add(50);

    // Remove an existing element
    mySet.remove(30);
    CHECK(mySet.getSize() == 4);
    CHECK(mySet.contains(30) == false); // Element should no longer be in the set

    // Remove a non-existing element
    mySet.remove(15); // Trying to remove an element that doesn't exist
    CHECK(mySet.getSize() == 4); // Size should remain the same
}

TEST_CASE("Set edge cases for insert and remove") {
    Set mySet;

    // Edge case: Inserting elements into an empty set
    mySet.add(10);
    CHECK(mySet.getSize() == 1);
    CHECK(mySet.contains(10) == true);

    // Edge case: Removing an element from a single-element set
    mySet.remove(10);
    CHECK(mySet.getSize() == 0);
    CHECK(mySet.contains(10) == false);

    // Edge case: Removing an element from an empty set
    mySet.remove(20); // Trying to remove from an empty set
    CHECK(mySet.getSize() == 0); // Size should remain 0

    // Inserting multiple elements into the set
    mySet.add(30);
    mySet.add(40);
    mySet.add(50);
    mySet.add(60);

    // Edge case: Inserting at the beginning of the set
    mySet.add(20);
    CHECK(mySet.getSize() == 5);
    CHECK(mySet.contains(20) == true);

    // Edge case: Inserting at the end of the set
    mySet.add(70);
    CHECK(mySet.getSize() == 6);
    CHECK(mySet.contains(70) == true);

    // Edge case: Removing from the beginning of the set
    mySet.remove(20);
    CHECK(mySet.getSize() == 5);
    CHECK(mySet.contains(20) == false);

    // Edge case: Removing from the end of the set
    mySet.remove(70);
    CHECK(mySet.getSize() == 4);
    CHECK(mySet.contains(70) == false);
}

TEST_CASE("Remove from an empty set test case") {
    Set mySet;

    // Attempt to remove an element from an empty set
    mySet.remove(10); // Trying to remove from an empty set
    CHECK(mySet.getSize() == 0); // Size should remain 0
    CHECK(mySet.contains(10) == false); // Element should not be in the set
}

TEST_CASE("Set resizing after many inserts test case") {
    Set mySet;

    // Insert a large number of elements to trigger resizing
    for (int i = 0; i < 1000; ++i) {
        mySet.add(i * 10);
    }

    // Check the size after inserting many elements
    CHECK(mySet.getSize() == 1000);

    // Verify elements were successfully inserted
    for (int i = 0; i < 1000; ++i) {
        CHECK(mySet.contains(i * 10) == true);
    }
}

TEST_CASE("Set unionSet test case") {
    Set setA;
    Set setB;

    // Insert elements into setA
    setA.add(10);
    setA.add(20);
    setA.add(30);

    // Insert elements into setB
    setB.add(20);
    setB.add(40);
    setB.add(50);

    // Calculate the union of setA and setB
    Set unionSet = setA.unionSet(setB);

    // Check the size and elements in the union set
    CHECK(unionSet.getSize() == 5);
    CHECK(unionSet.contains(10) == true);
    CHECK(unionSet.contains(20) == true);
    CHECK(unionSet.contains(30) == true);
    CHECK(unionSet.contains(40) == true);
    CHECK(unionSet.contains(50) == true);
}

TEST_CASE("Set intersectionSet test case") {
    Set setA;
    Set setB;

    // Insert elements into setA
    setA.add(10);
    setA.add(20);
    setA.add(30);

    // Insert elements into setB
    setB.add(20);
    setB.add(30);
    setB.add(40);

    // Calculate the intersection of setA and setB
    Set intersection = setA.intersectionSet(setB);

    // Check the size and elements in the intersection set
    CHECK(intersection.getSize() == 2);
    CHECK(intersection.contains(20) == true);
    CHECK(intersection.contains(30) == true);
    CHECK(intersection.contains(10) == false); // Not in the intersection
    CHECK(intersection.contains(40) == false); // Not in the intersection
}

TEST_CASE("Set differenceSet test case") {
    Set setA;
    Set setB;

    // Insert elements into setA
    setA.add(10);
    setA.add(20);
    setA.add(30);
    setA.add(40);

    // Insert elements into setB
    setB.add(20);
    setB.add(30);
    setB.add(50);

    // Calculate the difference between setA and setB
    Set difference = setA.differenceSet(setB);

    // Check the size and elements in the difference set
    CHECK(difference.getSize() == 2);
    CHECK(difference.contains(10) == true);
    CHECK(difference.contains(40) == true);
    CHECK(difference.contains(20) == false); // In setA but also in setB
    CHECK(difference.contains(30) == false); // In setA but also in setB
    CHECK(difference.contains(50) == false); // In setB but not in setA
}
