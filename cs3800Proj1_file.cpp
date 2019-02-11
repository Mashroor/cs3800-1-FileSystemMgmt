#include "cs3800Proj1_file.h"
using namespace std;

file::file(string name){
            fileName = name;
            path = path + name + "/";
            setTimestamp();
            userName = "user";
            fileSize = 1024;
            permissions = "rwxrwxrwx";
}
void file::setTimestamp(){
    std::time_t result = std::time(nullptr);
    char *temp = ctime(&result);
    if (temp[strlen(temp)-1] == '\n'){
        temp[strlen(temp)-1] = '\0';
    }
    timestamp =temp;
}
void file::setPermissions(string permCode){
    string tempPermissions;
    string backupPermissions = permissions;


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
            if(permCode[i] > '7'){
                permissions = backupPermissions;
                cout << "chmod: Invalid file mode: " << permCode <<endl;
                return;
            }
    }
    permissions = tempPermissions;
}