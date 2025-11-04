#pragma once
#include <mutex>
#include <shared_mutex>
#include <string>

class Structur{
    int field0 = 0;
    int field1 = 0;
    int field2 = 0;

    // std::mutex m0;
    // std::mutex m1;
    // std::shared_mutex m2;

    std::mutex global_lock;

public:
    int read0();
    void write0(int val);
    int read1();
    void write1(int val);
    int read2();
    void write2(int val);

    std::string toString();
};