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

bool IniFileManager::findSection(string section) {
    bool found = false;
    auto it = file.find(section);
    if (it != file.end())
        found = true;
    return found;
}

bool IniFileManager::findParameter(string section, string parameter) {
    bool found = false;
    auto it = file[section].find(parameter);
    if (it != file[section].end())
        found = true;
    return found;
}

void IniFileManager::printSections() {
    std::cout << " Sezioni: " << std::endl;
    for (auto &it: file)
        std::cout << it.first << std::endl;
}

void IniFileManager::printParameters(string section) {
    std::cout << " Parametri della sezione " << section << " : " << std::endl;
    for (auto &it: file[section])
        std::cout << it.first << std::endl;
}

void IniFileManager::printValue(string section, string parameter) {
    std::cout << parameter << " = " << file[section][parameter] << std::endl;

}

void IniFileManager::printAll() {
    for (auto &it: file) {
        if (it.first == " commenti ")
            for (auto &secondIterator: file[" commenti "])
                std::cout << secondIterator.second << std::endl;
        else {
            std::cout << " [ " << it.first << " ] " << std::endl;
            for (auto &secondIterator: file[it.first]) {
                int temp = 0;
                bool commentFound = false;
                while (temp < MaxComments && !commentFound) {
                    if (secondIterator.first == to_string(temp)) {
                        commentFound = true;
                        std::cout << secondIterator.second << std::endl;
                    } else
                        temp++;
                }
                if (!commentFound)
                    std::cout << secondIterator.first << " = " << secondIterator.second << std::endl;
            }
        }
    }
}

void IniFileManager::end() {
    this->NewProject.close();
}

int IniFileManager::numParameters(string section) {
    int count = 0;
    for (auto &it: file[section])
        count++;
    std::cout << "" << std::endl;
    return count;
}

void IniFileManager::addComment(string section, string textComment, bool inSection) {
    string parameter;
    CurrentComment += 1;
    parameter = to_string(CurrentComment);
    if (inSection)
        file[section][parameter] = " > " + textComment;
    else
        file[" commenti "][parameter] = " > " + textComment;
}

void IniFileManager::reset() {
    std::cout << " Voui resettare? [S/N] " << std::endl;
    string clear;
    cin >> clear;
    if (clear == "S")
        file.clear();
}
