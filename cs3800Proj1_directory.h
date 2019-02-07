#ifndef CS3800PROJ1_DIRECTORY_H
#define CS3800PROJ1_DIRECTORY_H

#include <vector>
#include <cstring>
#include <string>
#include <iostream>
#include "cs3800Proj1_file.h"

using namespace std;

class directory{
    private:
        vector<directory> innerDirectories;
        vector<file> innerFiles;

        string permissions;
        string userName;
        int fileSize;
        string timestamp;
        string path;
        string directoryName;

    public:
        directory(string name);
        directory& operator=(const directory &newDir);

        string getPermissions() const{return permissions;}
        string getUserName() const{return userName;}
        int getFileSize()const{return fileSize;}
        string getTimestamp() const{return timestamp;}
        string getPath() const{return path;}
        string getDirectoryName() const{return directoryName;}

        void pwd();
        void ls();
        void mkdir(string newDirName);
        void rmdir(string dirToDel);

};

#endif