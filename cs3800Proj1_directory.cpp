#include "cs3800Proj1_directory.h"
using namespace std;

directory::directory(string name){
            directoryName = name;
            path = path + name + "/";
}

directory& directory::operator=(directory &newDir){
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
    cout << endl;
}
void directory::mkdir(std::string newDirName){
    directory newDir(newDirName);
    innerDirectories.push_back(newDir);


}

