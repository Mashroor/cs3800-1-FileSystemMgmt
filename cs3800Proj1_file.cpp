#include "cs3800Proj1_file.h"
using namespace std;

file::file(string name){
            fileName = name;
            path = path + name + "/";
            setTimestamp();
            userName = "root";
            fileSize = 1024;
            permissions = "rwxrwxrwx";
}
void file::setTimestamp(){

    std::time_t result = std::time(nullptr);
    char *temp = ctime(&result);
    if (temp[strlen(temp)-1] == '\n'){
        temp[strlen(temp)-1] = '\0';
    }
    //timestamp =asctime(localtime(&result));
    timestamp =temp;

}