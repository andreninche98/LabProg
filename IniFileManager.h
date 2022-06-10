//
// Created by andrea on 10/06/22.
//

#ifndef LABPROG_INIFILEMANAGER_H
#define LABPROG_INIFILEMANAGER_H

#include "string"
#include "map"
#include "fstream"

using namespace std;

class IniFileManager {
public:
    explicit IniFileManager(const string &FileName, int MaxComments = 100);

    virtual ~IniFileManager();

private:
    string FileName;
    map<string, map<string, string>> file;
    int CurrentComment;
    int MaxComments;
    fstream NewProject;
};


#endif //LABPROG_INIFILEMANAGER_H
