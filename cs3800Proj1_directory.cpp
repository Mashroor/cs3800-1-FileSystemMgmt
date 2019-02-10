#include "cs3800Proj1_directory.h"
using namespace std;

directory::directory(string name, directory &newParent){
            directoryName = name;
            parent = &newParent;
            if (parent != nullptr){
                path = parent->getPath() + '/' + directoryName;
            }
            else{
                path = directoryName;
            }
            setTimestamp();
            userName = "user";
            fileSize = 1024;
            permissions = "rwxrwxrwx";
}
directory::~directory(){
    for(int i = 0; i < innerDirectories.size(); i++){
        delete innerDirectories[i];
    }
}
directory& directory::operator=(const directory &newDir){
    permissions = newDir.getPermissions();
    userName = newDir.getUserName();
    fileSize = newDir.getFileSize();
    timestamp = newDir.getTimestamp();
    path = newDir.getPath();
    directoryName = newDir.getDirectoryName();
    return *this;
}
void directory::setTimestamp(){

    std::time_t result = std::time(nullptr);
    char *temp = ctime(&result);
    if (temp[strlen(temp)-1] == '\n'){
        temp[strlen(temp)-1] = '\0';
    }
    timestamp = temp;
}
void directory::setPermissions(string permCode){
    string tempPermissions;
    for(int i = 0; i < permCode.length(); i++){
            if(permCode[i] == '0'){
                tempPermissions += "---";
            }
            if(permCode[i] == '1'){
                tempPermissions += "--x";
            }
            if(permCode[i] == '2'){
                tempPermissions += "-w-";
            }
            if(permCode[i] == '3'){
                tempPermissions += "-wx";
            }
            if(permCode[i] == '4'){
                tempPermissions += "r--";
            }
            if(permCode[i] == '5'){
                tempPermissions += "r-x";
            }
            if(permCode[i] == '6'){
                tempPermissions += "rw-";
            }
            if(permCode[i] == '7'){
                tempPermissions += "rwx";
            }
    }
    permissions = tempPermissions;
}
void directory::setParent(directory* newParent){
    parent = newParent;
}
directory* directory::cd(string objName, directory* newParent){
    for(int i = 0; i < innerDirectories.size(); i++){
        if(innerDirectories[i]->getDirectoryName() == objName){
            return innerDirectories[i];
        }
    }
}
void directory::pwd(){
    cout << getPath() + '/' << endl;
}
void directory::ls(){
    for (int i = 0; i < innerDirectories.size(); i++){
        cout << innerDirectories[i]->getDirectoryName()+ '/' << "\t";
        }
    for (int i = 0; i < innerFiles.size(); i++){
        cout << innerFiles[i].getFileName() << "\t";
        }
    cout << endl;
}
void directory::ls_l(){
    for (int i = 0; i < innerDirectories.size(); i++){
        cout << innerDirectories[i]->getPermissions() << "\t"
              << innerDirectories[i]->getUserName() << "\t"
              << innerDirectories[i]->getFileSize() << "\t"
              << innerDirectories[i]->getTimestamp() << "\t"
              << innerDirectories[i]->getDirectoryName()+ '/' << "\n";
        }
    for (int i = 0; i < innerFiles.size(); i++){
        cout << innerFiles[i].getPermissions() << "\t"
             << innerFiles[i].getUserName() << "\t"
             << innerFiles[i].getFileSize() << "\t"
             << innerFiles[i].getTimestamp() << "\t"
             << innerFiles[i].getFileName() << "\n";
        }
    cout << endl;
}
void directory::chmod(string permCode, string dirName){
    for(int i = 0; i < innerDirectories.size(); i++){
        if(innerDirectories[i]->getDirectoryName() == dirName){
            innerDirectories[i]->setPermissions(permCode);
            innerDirectories[i]->setTimestamp();
        }
    }
    for(int i = 0; i < innerFiles.size(); i++){
        if(innerFiles[i].getFileName() == dirName){
            innerFiles[i].setPermissions(permCode);
            innerFiles[i].setTimestamp();
        }
    }    
}
void directory::mkdir(string newDirName){
    for(int i = 0; i < innerDirectories.size(); i++){
        if(innerDirectories[i]->getDirectoryName() == newDirName){
            cout << "mkdir: " << newDirName << ": File exists\n"; 
            return;
        }
    }    
    directory* newDir = new directory(newDirName, *this);
    innerDirectories.push_back(newDir);
}
void directory::touch(string newFileName){
    for(int i = 0; i < innerFiles.size(); i++){
        if(innerFiles[i].getFileName() == newFileName){
            innerFiles[i].setTimestamp();
            return;
        }
    }
    file newFile(newFileName);
    innerFiles.push_back(newFile);
    return;
}
void directory::rmdir(string dirToDel){
    for(int i = 0; i < innerDirectories.size(); i++){
        if(innerDirectories[i]->getDirectoryName() == dirToDel){
            innerDirectories.erase(innerDirectories.begin()+ i);
        }
    }
}
void directory::rm(string fileToDel){
    for(int i = 0; i < innerDirectories.size(); i++){
        if(innerFiles[i].getFileName() == fileToDel){
            innerFiles.erase(innerFiles.begin()+ i);
        }
    }
}

