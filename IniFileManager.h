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

    string getFileName();

    void setFileName(string FileName);

    string getValue(string section, string parameter);

    void setValue(string section, string parameter, string newValue);

    void modify(string section, string parameter, string newValue);

    void removeParameter(string section, string parameter);

    void removeSection(string section);

    void addParameter(string section, string newParameter);

    void addSection(string newSection);

    void nullify(string section, string parameter);


private:
    string FileName;
    map<string, map<string, string>> file;
    int CurrentComment;
    int MaxComments;
    fstream NewProject;
};


#endif //LABPROG_INIFILEMANAGER_H
