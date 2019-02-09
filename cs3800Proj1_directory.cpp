#include "cs3800Proj1_directory.h"
using namespace std;

directory::directory(string name){
            directoryName = name;
            path = path + name + "/";
            userName = "root";
            fileSize = 1024;
            permissions = "rwxrwxrwx";
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

void directory::pwd(){
    cout << getPath() << endl;
}
void directory::ls(){
    for (int i = 0; i < innerDirectories.size(); i++){
        cout << innerDirectories[i].getDirectoryName() << "\t";
        }

    for (int i = 0; i < innerFiles.size(); i++){
        cout << innerFiles[i].getFileName() << "\t";
        }
    cout << endl;
}
void directory::ls_l(){
    for (int i = 0; i < innerDirectories.size(); i++){
        cout << innerDirectories[i].getDirectoryName() << "\t";
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
void directory::mkdir(string newDirName){
    directory newDir(newDirName);
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
void directory::rmdir(string DirToDel){
    for(int i = 0; i < innerDirectories.size(); i++){
        if(innerDirectories[i].getDirectoryName() == DirToDel){
            innerDirectories.erase(innerDirectories.begin()+ i);
        }
    }
}

