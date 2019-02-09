#include <iostream>
#include <sstream>
#include <ctime>
#include <chrono>
#include <vector>
#include <cstring>
#include <string>

#include "cs3800Proj1_file.h"
#include "cs3800Proj1_directory.h"

int main(){
    bool control = true;
    string input;
    directory currDir("root");
    directory* currDirPtr = &currDir;

    while(control){
    cout << "user:~" << currDirPtr->getPath();
    getline(cin, input);
    istringstream ss(input);
	string token;

	vector<string> query;
	while(getline(ss, token, ' ')) {
		query.push_back(token);
	}
        if(query[0] == "cd"){
            if(query[1] == ".."){
                if(currDirPtr->getDirectoryName() == "root"){
                    cout << "cant do that shit faggot\n";
                }

            }else{
                //currDirPtr->cd()
            }
        }
        if(query[0] == "pwd"){
            currDirPtr->pwd();
        }
        if(query[0] == "ls"){
            if(query[1] == "-l"){
                currDirPtr->ls_l();
            }else{
                currDirPtr->ls();
            }
        }
        if(query[0] == "mkdir"){
            currDirPtr->mkdir(query[1]);
        }
        if(query[0] == "touch"){
            currDirPtr->touch(query[1]);
        }
        if(query[0] == "rm"){
            currDirPtr->rmdir(query[1]);
        }
        if(query[0] == "chmod"){
            currDirPtr->chmod(query[1], query[2]);
        }
        if(query[0] == "exit" || query[0] == "quit"){
            control = false;
        }

    }
    return 0;
}