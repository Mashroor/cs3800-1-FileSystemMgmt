#include <iostream>
#include <ctime>
#include <vector>
#include <cstring>
#include <string>

#include "cs3800Proj1_file.h"
#include "cs3800Proj1_directory.h"

int main(){
    bool control = true;
    string input;
    directory currDir("root");

    while(control){
        cout << "user:~" << currDir.getPath();
        getline(cin, input);

        if(input == "pwd"){
            currDir.pwd();
        }
        if(input == "ls"){
            currDir.ls();
        }
        if(input == "mkdir"){
            currDir.mkdir("Sicko Mode");
        }

        if(input == "exit" || input == "quit"){
            control = false;
        }

    }
    return 0;
}