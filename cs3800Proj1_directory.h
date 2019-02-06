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
        directory(string name){
            directoryName = name;
            path = path + name + "/";

        }
        string getPath(){
            return path;
        }

};