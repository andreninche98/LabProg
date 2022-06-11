//
// Created by andrea on 10/06/22.
//

#include "IniFileManager.h"
#include "iostream"

using namespace std;

IniFileManager::IniFileManager(const string &FileName, int MaxComments) {
    this->FileName = FileName;
    this->NewProject.open(FileName);
    this->MaxComments = MaxComments;
    this->CurrentComment = 0;
}

IniFileManager::~IniFileManager() {
    this->NewProject.close();
}

string IniFileManager::getFileName() {
    return this->FileName;
}

void IniFileManager::setFileName(const string FileName) {
    this->FileName = FileName;
}

string IniFileManager::getValue(string section, string parameter) {
    return file[section][parameter];
}

void IniFileManager::setValue(string section, string parameter, const string newValue) {
    auto it = file[section].find(parameter);
    if (it == file[section].end())
        file[section][parameter] = newValue;
    else
        modify(section, parameter, newValue);
}

void IniFileManager::modify(string section, string parameter, const string newValue) {
    std::cout << "ATTENZIONE: troppi valori inseriti per il parametro " << parameter
              << " premere l per continuare ed aggiungere l'ultimo valore immesso " << std::endl;
    string last;
    std::cin >> last;
    if (last == "l")
        file[section][parameter] = newValue;
}

void IniFileManager::removeParameter(string section, string parameter) {
    auto it = file[section].find(parameter);
    if (it != file[section].end())
        file[section].erase(parameter);
}

void IniFileManager::removeSection(string section) {
    auto it = file.find(section);
    if (it != file.end())
        file.erase(section);
}

void IniFileManager::addParameter(string section, string newParameter) {
    file[section][newParameter] = "null";
}

void IniFileManager::addSection(string newSection) {
    file[newSection];
}

void IniFileManager::nullify(string section, string parameter) {
    file[section][parameter] = "null";
}
