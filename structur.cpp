#include "structur.h"
#include <iostream>
#include <sstream>

using namespace std;

// int Structur::read0()
// {
//     lock_guard<mutex> block(m0);
//     return field0;
// }

// void Structur::write0(int val)
// {
//     lock_guard<mutex> block(m0);
//     field0 = val;
// }

// int Structur::read1()
// {
//     lock_guard<mutex> block(m1);
//     return field1;
// }

// void Structur::write1(int val)
// {
//     lock_guard<mutex> block(m1);
//     field1 = val;
// }

// int Structur::read2()
// {
//     shared_lock<shared_mutex> block(m2);
//     return field2;
// }

// void Structur::write2(int val)
// {
//     unique_lock<shared_mutex> block(m2);
//     field2 = val;
// }

// std::string Structur::toString()
// {
//     lock_guard<mutex> block0(m0);
//     lock_guard<mutex> block1(m1);
//     unique_lock<shared_mutex> block2(m2);

//     stringstream s;
//     s << "F0:" << field0 << ", F1:" << field1 << ", F2:" << field2 << endl;

//     return s.str();
// }


int Structur::read0() {
    lock_guard<mutex> block(global_lock);
    return field0;
}
void Structur::write0(int val) {
    lock_guard<mutex> block(global_lock);
    field0 = val;
}
int Structur::read1() {
    lock_guard<mutex> block(global_lock);
    return field1;
}
void Structur::write1(int val) {
    lock_guard<mutex> block(global_lock);
    field1 = val;
}
int Structur::read2() {
    lock_guard<mutex> block(global_lock);
    return field2;
}
void Structur::write2(int val) {
    lock_guard<mutex> block(global_lock);
    field2 = val;
}

string Structur::toString() {
    lock_guard<mutex> block(global_lock); 

    stringstream s;
    s << "F0:" << field0 << ", F1:" << field1 << ", F2:" << field2 << endl;
    return s.str();
}