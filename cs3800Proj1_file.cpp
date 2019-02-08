#include "cs3800Proj1_file.h"
using namespace std;

file::file(string name){
            fileName = name;
            path = path + name + "/";

            auto start = chrono::system_clock::now();
            auto end = chrono::system_clock::now();
            chrono::duration<double> elapsed_seconds = end-start;
            time_t end_time = chrono::system_clock::to_time_t(end);
            
            timestamp = ctime(&end_time);


            userName = "root";

            fileSize = 69;

            permissions = "rwxrwxrwx";


}