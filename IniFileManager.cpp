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
