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
    explicit IniFileManager(const string &FileName, int MaxComments = 50);

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

    bool findSection(string section);

    bool findParameter(string section, string parameter);

    void printSections();

    void printParameters(string section);

    void printValue(string section, string parameter);

    void printAll();

    void end();

    int numParameters(string section);

    void addComment(string section, string textComment, bool inSection = false);

    void reset();


private:
    string FileName;
    map<string, map<string, string>> file;
    int CurrentComment;
    int MaxComments;
    fstream NewProject;
};


#endif //LABPROG_INIFILEMANAGER_H
