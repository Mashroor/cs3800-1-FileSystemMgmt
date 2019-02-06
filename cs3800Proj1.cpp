#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

#include "cs3800Proj1_file.h"
#include "cs3800Proj1_directory.h"

int main(){
    bool control = true;
    string input;
    directory root("root");

    while(control){
        cout << "user:~" << root.getPath();
        cin >> input;

        if(input == "ls"){
            cout << "poggers lel" << endl;
        }


        if(input == "exit" || input == "quit"){
            control = false;
        }

    }
    return 0;
}