#ifndef CS3800PROJ1_DIRECTORY_H
#define CS3800PROJ1_DIRECTORY_H

#include <vector>
#include <cstring>
#include <string>
#include <ctime>
#include <iostream>
#include "cs3800Proj1_file.h"

using namespace std;

class directory{
    private:
        //tracking of inner objects
        vector<directory*> innerDirectories;
        vector<file> innerFiles;

        directory* parent;
        //inner properties of directory class
        string permissions;
        string userName;
        int fileSize;
        string timestamp;
        string path;
        string directoryName;

    public:
        directory(): parent(nullptr) {}; //used in mkdir(), to allocate a new directory obj
        directory(string name, directory &newParent); //used for any time a diretory is made
        ~directory(); //since making a new directory, need a way to deref, avoid mem leaking
        directory& operator=(const directory &newDir);
        //getters, since private
        string getPermissions() const{return permissions;}
        string getUserName() const{return userName;}
        int getFileSize()const{return fileSize;}
        string getTimestamp() const{return timestamp;}
        string getPath() const{return path;}
        string getDirectoryName() const{return directoryName;}
        int getSize() const{return innerDirectories.size();}
        int getFilesSize() const{return innerFiles.size();}
        directory* getParent() const{return parent;}
        vector<directory*> getDirectoryVect() const{return innerDirectories;}
        vector<file> getFilesVect() const{return innerFiles;}
        //setters, since private 
        void setTimestamp();
        void setName(string name){directoryName = name;}
        void setPermissions(string permCode);
        void setParent(directory* newParent);
        //start directory commands
        directory* cd(string objName, directory* newParent);
        void pwd();
        void ls();
        void ls_l();
        void chmod(string permCode, string dirName);
        void mkdir(string newDirName);
        void touch(string newFileName);
        void rmdir(string dirToDel);
        void rm(string fileToDel);

};

#endif