#include <iostream>
#include "fileforgeneration.h"
#include "structur.h"
#include <thread>
#include <fstream>
#include <chrono>
#include <vector>
#include <string>
#include <sstream>
#include <format>

using namespace std;

Structur shared_structure;

void work_for_thread(const string &files){
    ifstream file(files);
    if(!file.is_open()){
        cerr << "cant open file" << endl;
        return;
    }

    string line;
    while(getline(file, line)){
        stringstream s(line);
        string comand;
        s >> comand;

        if(comand == "read"){
            int field_index;
            s >> field_index;
            if(field_index == 0){
                shared_structure.read0();
            }
            else if(field_index == 1){
                shared_structure.read1();
            }
            else if(field_index == 2){
                shared_structure.read2();
            }
        }
        else if(comand == "write"){
            int field_index;
            int value;
            s >> field_index >> value;
            if(field_index == 0){
                shared_structure.write0(value);
            }
            else if(field_index == 1){
                shared_structure.write1(value);
            }
            else if(field_index == 2){
                shared_structure.write2(value);
            }
        }
        else if(comand == "string"){
            shared_structure.toString();
        }
    }
}

void test_file(int num_of_threads, const string &name_of_file, string description){
    cout << "\nTest: " << description << ", " << num_of_threads << " threads" << endl;

    vector<thread> threadds;

    auto start = chrono::high_resolution_clock::now();

    for(int i = 1; i <= num_of_threads; i++){
        string file_name = name_of_file + "_" + to_string(i) + ".txt";
        threadds.emplace_back(work_for_thread, file_name);
    }

    for(auto &t: threadds){
        t.join();
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << format("Execution time: {:.5f} s\n", duration.count()) << endl;
}

int main(){
    generator generator;
    generator.generate_all_files(generator::DEFAULT_OPS_COUNT);

    vector<int> thread_count = {1, 2, 3};

    for(int n: thread_count){
        test_file(n, "commands_A", "a) for a sequence of actions whose frequencies meet the condition: ");
    }

    for(int n: thread_count){
        test_file(n, "commands_B", "b) for a sequence of actions where all frequencies are equal;");
    }

    for(int n: thread_count){
        test_file(n, "commands_C", "c) for a sequence of actions whose frequencies do not correspond very much to the condition and are not equal");
    }

    return 0;
}