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
    bool found;
    string input;
    directory currDir; 
    currDir.setName("/");
    directory* currDirPtr = &currDir;

    while(control){
    cout << "user:~/";
    getline(cin, input);
    istringstream ss(input);
	string token;

	vector<string> query;
	while(getline(ss, token, ' ')) {
		query.push_back(token);
	}
    if(!query.empty()){
            if(query[0] == "cd"){
                found = false;
                if(query[1] == ".."){
                    if(currDirPtr->getParent() == nullptr){
                        found = true;
                    }
                    else{
                            if(currDirPtr->getParent() != nullptr){
                                currDirPtr = currDirPtr->getParent();
                                found = true;
                            }
                    }
                }else{
                    for(int i = 0; i < currDirPtr->getSize(); i++){
                        if(query[1] == currDirPtr->getDirectoryVect()[i]->getDirectoryName()){
                            currDirPtr = currDirPtr->cd(query[1], currDirPtr);
                            found = true;
                        }
                    }
                }
                if(!found){
                    cout << "-mash: cd: " 
                         << query[1] 
                         << ": No such directory" 
                         << endl;
                }
            }else{
                if(query[0] == "pwd"){
                    currDirPtr->pwd();
                }else{
                    if(query[0] == "ls"){
                        if(query.size()>1 && query[1] == "-l"){
                            currDirPtr->ls_l();
                        }else{
                            currDirPtr->ls();
                        }
                    }else{
                        if(query[0] == "mkdir"){
                            currDirPtr->mkdir(query[1]);
                        }else{
                            if(query[0] == "touch"){
                                currDirPtr->touch(query[1]);
                            }else{
                                if(query[0] == "rmdir"){
                                    found = false;
                                            for (int i = 0; i < currDirPtr->getSize(); i++){
                                                if( currDirPtr->getDirectoryVect()[i]->getDirectoryName() == query[2]){
                                                    currDirPtr->rmdir(query[1]);
                                                    found = true;
                                                }
                                            }
                                            for (int i = 0; i < currDirPtr->getFilesSize(); i++){
                                                if(currDirPtr->getFilesVect()[i].getFileName() == query[2]){
                                                    currDirPtr->rmdir(query[1]);
                                                    found = true;
                                                }
                                            }
                                            if(found == false){
                                                cout << "-mash: rmdir: " 
                                                     << query[1] 
                                                     << ": No such directory" 
                                                     << endl;
                                            }
                                }else{
                                    if(query[0] == "rm"){
                                        found = false;
                                            for (int i = 0; i < currDirPtr->getSize(); i++){
                                                if( currDirPtr->getDirectoryVect()[i]->getDirectoryName() == query[2]){
                                                    currDirPtr->rm(query[1]);
                                                    found = true;
                                                }
                                            }
                                            for (int i = 0; i < currDirPtr->getFilesSize(); i++){
                                                if(currDirPtr->getFilesVect()[i].getFileName() == query[2]){
                                                    currDirPtr->rm(query[1]);
                                                    found = true;
                                                }
                                            }
                                            if(found == false){
                                                cout << "-mash: rm: " 
                                                     << query[1] 
                                                     << ": No such file" 
                                                     << endl;
                                            }
                                    }else{
                                        if(query[0] == "chmod"){
                                            found = false;
                                            for (int i = 0; i < currDirPtr->getSize(); i++){
                                                if(query.size() > 2){
                                                    if( currDirPtr->getDirectoryVect()[i]->getDirectoryName() == query[2]){
                                                        currDirPtr->chmod(query[1], query[2]);
                                                        found = true;
                                                    }
                                                }
                                            }
                                            for (int i = 0; i < currDirPtr->getFilesSize(); i++){
                                                if(query.size() > 2){
                                                    if(currDirPtr->getFilesVect()[i].getFileName() == query[2]){
                                                        currDirPtr->chmod(query[1], query[2]);
                                                        found = true;
                                                    }
                                                }
                                            }
                                            if(found == false && query.size() == 3 ){
                                                cout << "-mash: chmod: " 
                                                     << query[2] 
                                                     << ": No such file or directory" 
                                                     << endl;
                                            }else{
                                                if(query.size() < 3){
                                                    cout << "-mash: chmod "  
                                                        << ": No such definition of chmod" 
                                                        << endl;
                                                }
                                            }
                                        }else{
                                            if(query[0] == "exit" || query[0] == "quit"){
                                                control = false;
                                            }else{
                                                cout << "-mash: " 
                                                     << query[0]
                                                     << ": command not found\n";
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}