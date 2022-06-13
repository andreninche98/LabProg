#include <iostream>
#include "IniFileManager.h"

int main() {
    IniFileManager file("FirstFile.ini");
    std::cout << " FileName: " << file.getFileName() << std::endl;

    file.setValue("Sezione 1", "Parametro 1", "Valore 1");

    file.addSection("Sezione 2");
    file.addParameter("Sezione 1", "Parametro 2");
    file.nullify("Sezione 2", "Parametro 2");

    file.addComment("Ciao!", "Ciao!", false);

    file.printAll();

    int NumberOfParameters = file.numParameters("Sezione 1");
    std::cout << " Numero parametri prima sezione: " << NumberOfParameters << std::endl;

    file.end();

}
