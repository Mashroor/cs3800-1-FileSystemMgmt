#include <iostream>
#include <sstream>
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
    istringstream ss(input);
	string token;

	vector<string> query;
	while(getline(ss, token, ' ')) {
		query.push_back(token);
	}
        if(query[0] == "pwd"){
            currDir.pwd();
        }
        if(query[0] == "ls"){
            currDir.ls();
        }
        if(query[0] == "mkdir"){
            currDir.mkdir(query[1]);
        }
        if(query[0] == "rm"){
            currDir.rmdir(query[1]);
        }

        if(query[0] == "exit" || query[0] == "quit"){
            control = false;
        }

    }
    return 0;
}