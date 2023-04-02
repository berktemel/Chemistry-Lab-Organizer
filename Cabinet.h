//
// Berk Temel 22002675
//

#ifndef UNTITLED_CABINET_H
#define UNTITLED_CABINET_H
#include <string>
#include <sstream>
#include <iostream>
#include "Chemical.h"
using namespace std;

class Cabinet {
public:
    Cabinet(int id, int row, int column);
    Cabinet();
    ~Cabinet();

    int getId() const;
    int getRow() const;
    int getColumn() const;
    int getEmptySlots();
    string getLocation(int r, int col) const;
    char getRowName(int r) const;
    int getColumnName(int k) const;
    bool spaceEmpty(string location);
    Chemical& getChemical(int row, int column);
    void setChemical(Chemical& chem, string location);
    bool cNear(string location);
    Chemical& getChemical(string location);
    string availableNear(string location, string chemicalType);
    void initArray();

private:
    int id;
    int row;
    int column;
    char rowNames[9];
    int columnNumbers[9];
    Chemical** chemicals;
    int chemicalCount;
    bool arrayInitialized;
};


#endif //UNTITLED_CABINET_H
