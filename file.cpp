//IDEA: Create a class that stores information into a filesystem and accesses said information in a way that is password protected.
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <thread>
#include <chrono>
#include <bits/stdc++.h>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <array>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <forward_list>
#include <iterator>
#include <utility>

#define stringify( name ) # name

using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

enum class file_type {
    string_,
    int_,
    double_,
    bool_,
    char_,
    array_,
    list_,
    map_,
    set_,
    unordered_map_,
    unordered_set_,
    queue_,
    deque_,
    stack_,
    forward_list_,
    null_
};

enum class folder_type {
    open,
    encrypted,
    hidden,
    null
};

class filesystem {
private:
//folders
    string folderName;
    int folderNumber;
    string folderPath;
    string folderDateCreated;
    string folderDateModified;
    string folderDateAccessed;
//files
    string fileName;
    int fileNumber;
    string filePath;
    string fileDateCreated;
    string fileDateModified;
    string fileDateAccessed;
    string fileContent;
    file_type fileType;
    int fileSize;
    double fileSizeDouble;
    bool fileWritable;
    bool fileReadable;
    bool fileExecutable;
    bool fileHidden;
};

class folder : public filesystem {
public:
    folder(string folderName, int folderNumber, string folderPath, string folderDateCreated, string folderDateModified, string folderDateAccessed, folder_type folderType, string currentWorkingDirectory) {
        this->folderName = folderName;
        this->folderNumber = folderNumber;
        this->folderPath = folderPath;
        this->folderDateCreated = folderDateCreated;
        this->folderDateModified = folderDateModified;
        this->folderDateAccessed = folderDateAccessed;
        this->folderType = folderType;
        this->currentWorkingDirectory = currentWorkingDirectory;
    }
    ~folder() {
        cout << "Folder " << folderName << " has been deleted." << endl;
    }
    void printFolder() {
        cout << "Folder Name - " << folderName << endl;
        cout << "Path: " << folderPath << endl;
        cout << "Date Created: " << folderDateCreated << endl;
        cout << "Date Modified: " << folderDateModified << endl;
        cout << "Date Accessed: " << folderDateAccessed << endl;
        cout << "Folder Type: " << stringify(folderType) << endl;
    }
    void CWD_Root() {
        folder root("root", 0, "~/", stringify(getdate(0)), stringify(getdate(0)), stringify(getdate(0)), folder_type::hidden, "~/");
        root.printFolder();
        folder home("home", 1, "~/home/", stringify(getdate(0)), stringify(getdate(0)), stringify(getdate(0)), folder_type::open, "~/home/");
        folder documents("documents", 2, "~/home/documents/", stringify(getdate(0)), stringify(getdate(0)), stringify(getdate(0)), folder_type::open, "~/home/documents/");
        folder pictures("pictures", 3, "~/home/pictures/", stringify(getdate(0)), stringify(getdate(0)), stringify(getdate(0)), folder_type::open, "~/home/pictures/");
        folder downloads("downloads", 4, "~/home/downloads/", stringify(getdate(0)), stringify(getdate(0)), stringify(getdate(0)), folder_type::open, "~/home/downloads/");
        folder system("system", -1, "~/system/", stringify(getdate(0)), stringify(getdate(0)), stringify(getdate(0)), folder_type::encrypted, "~/system/");
    }
    string getCWD() {
        return currentWorkingDirectory;
    }
    string getFolderName() {
        return folderName;
    }
    string getFolderPath() {
        return folderPath;
    }
    string getFolderDateCreated() {
        return folderDateCreated;
    }
    string getFolderDateModified() {
        return folderDateModified;
    }
    string getFolderDateAccessed() {
        return folderDateAccessed;
    }
    string getFolderType() {
        return stringify(folderType);
    }
    folder_type getFolderTypeEnum() {
        return folderType;
    }
    void renameFolder(string newName) {
        folderName = newName;
    }
    void moveFolder(string newPath) {
        if (any_of<file::getFilePath(), getFolderPath()->(newPath)) {
            cout << "Cannot move folder with files in it." << endl;
        }
    }

private:
    string currentWorkingDirectory;
    string folderName;
    int folderNumber;
    string folderPath;
    string folderDateCreated;
    string folderDateModified;
    string folderDateAccessed;
    folder_type folderType;
};

class file : public folder {
private:
    string fileName;
    int fileNumber;
    string filePath;
    string fileDateCreated;
    string fileDateModified;
    string fileDateAccessed;
    string fileContent;
    file_type fileType;
    bool fileWritable;
    bool fileReadable;
    bool fileExecutable;
    bool fileHidden;
public:
    file(string fileName, int fileNumber, string filePath, string fileDateCreated, string fileDateModified, string fileDateAccessed, string fileContent, file_type fileType, bool fileWritable = true, bool fileReadable = true, bool fileExecutable = true, bool fileHidden = false) {
        this->fileName = fileName;
        this->fileNumber = fileNumber;
        this->filePath = filePath;
        this->fileDateCreated = fileDateCreated;
        this->fileDateModified = fileDateModified;
        this->fileDateAccessed = fileDateAccessed;
        this->fileContent = fileContent;
        this->fileType = fileType;
        this->fileWritable = fileWritable;
        this->fileReadable = fileReadable;
        this->fileExecutable = fileExecutable;
        this->fileHidden = fileHidden;
    }
    ~file() {
        cout << "File " << fileName << " has been deleted." << endl;
    }
    string getFileName() {
        return fileName;
    }
    string getFilePath() {
        return filePath;
    }
    string getFileDateCreated() {
        return fileDateCreated;
    }
    string getFileDateModified() {
        return fileDateModified;
    }
    string getFileDateAccessed() {
        return fileDateAccessed;
    }
    string getFileContent() {
        return fileContent;
    }
    file_type getFileType() {
        return fileType;
    }
    void printFile() {
        cout << "File Name - " << getFileName() << endl;
        cout << "Path: " << getFilePath() << endl;
        cout << "Date Created: " << getFileDateCreated() << endl;
        cout << "Date Modified: " << getFileDateModified() << endl;
        cout << "Date Accessed: " << getFileDateAccessed() << endl;
        cout << "File Type: " << stringify(getFileType()) << endl;
    }
    void renameFile(string newName) {
        fileName = newName;
    }
    void moveFile(string newPath) {
        filePath = newPath;
    }
    string getCurrentWorkingDirectory() {
        return getCWD();
    }

};