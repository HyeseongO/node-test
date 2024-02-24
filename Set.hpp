/*
Name : Hyeseong Oh 
Team : Yehwan Lee, Jennifer Lee
Team code : YL7HO3JL9
*/
#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <iostream>

using namespace std;
class Set {
    private: 
    int* elements;
    int capacity;
    int size;
    void increaseCapacity() {
        if (size == capacity) {
            int* newArray = new int [capacity * 2];
            capacity = capacity * 2;
            for (int i = 0; i < size; i++) {
                newArray[i] = elements[i];
            }
            delete [] elements;
            elements = newArray;
        }
    }
    int indexOf(int value) {
        for (int i = 0; i < size; i++) {
            if (elements[i]==value) {
                return i;
            }
        }
        return -1;
    }

    public: 
    Set() {
        capacity = 10;
        elements = new int[capacity];
        size = 0;
        }
    ~Set() {
        delete [] elements;
    }
    void add(int value) {
        increaseCapacity();
        int contain = 0;
        for(int i = 0; i < size; i++) {
            if (elements[i] == value) {
                contain++;
            }
        }
        if (contain == 0) {
            elements[size] = value;
            size++;
        }
    }
    void remove(int value) {
        int remove_num = 0;
        for (int i = 0; i < size; i++) {
            if (elements[i]==value) {
                elements[i]=elements[i+1];
                remove_num++;
            }
        }
        size -= remove_num;
    }
    bool contains(int value) {
        int contain_num = 0;
        for (int i = 0; i < size; i++) {
            if (elements[i]==value) {
                contain_num++;
            }
        }
        if (contain_num == 0) {
            return false;
        }
        else {
            return true;
        }
    }
    int getSize() {
        return size;
    }
    void printAll() {
        cout << "{"; 
        for (int i = 0; i < capacity; i++) {
            cout << elements[i] << ","; 
        }
        cout << "}" << endl;
    }
    bool isEmpty() {
        if (size==0) {
            return true;
        }
        else {
            return false;
        }
    }
    Set unionSet(Set& otherSet) {
        Set newSet = Set();
        for (int i = 0; i < size; i++) {
            newSet.add(elements[i]);
        }
        for (int i = 0; i < otherSet.size; i++) {
            newSet.add(otherSet.elements[i]);
        }
        return newSet;
    }
    Set intersectionSet(Set& otherSet) {
        Set newSet = Set();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < otherSet.size; j++) {
                if (elements[i]==otherSet.elements[j]) {
                    newSet.add(elements[i]);
                }
            }
        }
        return newSet;
    }
    Set differenceSet(Set& otherSet) {
        Set newSet = Set();
        for (int i = 0; i < size; i++) {
            if (!otherSet.contains(elements[i])) {
                newSet.add(elements[i]);
            }
        }
        return newSet;
    }

};
#endif
