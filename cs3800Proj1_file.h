#ifndef CS3800PROJ1_FILE_H
#define CS3800PROJ1_FILE_H

#include<iostream>
#include<cstring>
#include<string>
#include<ctime>
#include<chrono>

using namespace std;

class file{
    private:
        string permissions;
        string userName;
        int fileSize;
        string timestamp;
        string path;
        string fileName;

    public:
        file(string name);

        string getPermissions() const{return permissions;}
        string getUserName() const{return userName;}
        int getFileSize() const{return fileSize;}
        string getTimestamp() const{return timestamp;}
        string getFileName() const{return fileName;}

        void setTimestamp();


};

#endif