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
        directory& operator=(directory &newDir);

        string getPermissions(){return permissions;}
        string getUserName(){return userName;}
        int getFileSize(){return fileSize;}
        string getTimestamp(){return timestamp;}
        string getPath(){return path;}
        string getDirectoryName(){return directoryName;}

        void pwd();
        void ls();
        void mkdir(std::string newDirName);

};

#endif