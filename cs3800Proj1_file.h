#ifndef CS3800PROJ1_FILE_H
#define CS3800PROJ1_FILE_H

#include<iostream>
#include<cstring>
#include<string>
#include<ctime>

using namespace std;

class file{
    private:
        //inner properties of file class
        string permissions;
        string userName;
        int fileSize;
        string timestamp;
        string path;
        string fileName;
    public:
        //constructor, only used in touch, no need for destructor since new mem not allocated
        file(string name);
        //getters, since private
        string getPermissions() const{return permissions;}
        string getUserName() const{return userName;}
        int getFileSize() const{return fileSize;}
        string getTimestamp() const{return timestamp;}
        string getFileName() const{return fileName;}
        //setters since private
        void setTimestamp();
        void setPermissions(string PermCode);
        //this obj does not need any functions, since this is only here as a dummy obj
};

#endif