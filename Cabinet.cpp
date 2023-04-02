//
// Created by Berk on 3.11.2021.
//
#include "Cabinet.h"

Cabinet::Cabinet(const int id, const int row, const int column) {
    this->id = id;
    this->row = row;
    this->column = column;

    rowNames[0] = 'A';
    rowNames[1] = 'B';
    rowNames[2] = 'C';
    rowNames[3] = 'D';
    rowNames[4] = 'E';
    rowNames[5] = 'F';
    rowNames[6] = 'G';
    rowNames[7] = 'H';
    rowNames[8] = 'I';

    columnNumbers[0] = 1;
    columnNumbers[1] = 2;
    columnNumbers[2] = 3;
    columnNumbers[3] = 4;
    columnNumbers[4] = 5;
    columnNumbers[5] = 6;
    columnNumbers[6] = 7;
    columnNumbers[7] = 8;
    columnNumbers[8] = 9;

    chemicalCount = 0;
    arrayInitialized = false;
}

Cabinet::Cabinet() {
    chemicalCount = 0;
    arrayInitialized = false;
}

Cabinet::~Cabinet() {
    if(arrayInitialized) {
        for (int i = 0; i < row; i++)
            delete[] chemicals[i];
        delete[] chemicals;
    }
}

void Cabinet::initArray() {
    chemicals = new Chemical*[row];
    for(int i = 0; i < row; i++)
        chemicals[i] = new Chemical[column];
    arrayInitialized = true;
}

int Cabinet::getId() const {
    return id;
}

int Cabinet::getRow() const {
    return row;
}

int Cabinet::getColumn() const {
    return column;
}

int Cabinet::getEmptySlots() {
    return row * column - chemicalCount;
}

string Cabinet::getLocation(int r, int col) const {
    string colNumber;
    stringstream ss;
    ss << columnNumbers[col];
    ss >> colNumber;
    return rowNames[r] + colNumber;
}

char Cabinet::getRowName(int r) const {
    return rowNames[r];
}

int Cabinet::getColumnName(int c) const {
    return columnNumbers[c];
}

bool Cabinet::spaceEmpty(string location) {
    return !getChemical(location).chemicalExists();
}

Chemical& Cabinet::getChemical(int row, int column) {
    return chemicals[row][column];
}

void Cabinet::setChemical(Chemical& chem, string location) {
    getChemical(location).setId(chem.getId());
    getChemical(location).setType(chem.getChemicalType());
    chemicalCount++;
}

Chemical& Cabinet::getChemical(string location) {
    int rowValue, columnValue;
    for (int i = 0; i < row; i++) {
        if (getRowName(i) == location.at(0))
            rowValue = i;
    }
    for (int j = 0; j < column; j++) {
        int locationColumn = location.at(1) - 48;
        if (getColumnName(j) == locationColumn)
            columnValue = j;
    }
    return chemicals[rowValue][columnValue];
}

bool Cabinet::cNear(string location) {
    int locRow, locColumn;
    for (int i = 0; i < row; i++) {
        if (getRowName(i) == location.at(0)) {
            locRow = i;
            for (int j = 0; j < column; j++) {
                int locationColumn = location.at(1) - 48;
                if (getColumnName(j) == locationColumn) {
                    locColumn = j;
                }
            }
        }
    }

    bool combustiveNear = false;
    for(int i = locRow - 1; i <= locRow + 1; i++) {
        if(i >= 0 && i < row) {
            for (int j = locColumn - 1; j <= locColumn + 1; j++) {
                if(j >= 0 && j < column) {
                    if(getChemical(i, j).getChemicalType() == "combustive")
                        combustiveNear = true;
                }
            }
        }
    }
    return combustiveNear;
}

string Cabinet::availableNear(string location, string chemicalType) {
    string available;
    int locRow, locColumn;
    for (int i = 0; i < row; i++) {
        if (getRowName(i) == location.at(0)) {
            locRow = i;
            for (int j = 0; j < column; j++) {
                int locationColumn = location.at(1) - 48;
                if (getColumnName(j) == locationColumn) {
                    locColumn = j;
                }
            }
        }
    }
    string tempLocation;
    bool notFound = true;
    int k = 1;
    while(notFound) {
        for (int i = locRow - k; i <= locRow + k; i++) {
            if (i >= 0 && i < row) {
                for (int j = locColumn - k; j <= locColumn + k; j++) {
                    if (j >= 0 && j < column) {
                        string colNumber;
                        stringstream ss;
                        ss << getColumnName(j);
                        ss >> colNumber;
                        tempLocation = getRowName(i) + colNumber;
                        if (((chemicalType == "combustive" && !cNear(tempLocation)) || chemicalType == "retardant") &&
                            spaceEmpty(tempLocation))
                            available += tempLocation + " ";
                    }
                }
            }
        }
        if(available.empty())
            k++;
        else
            notFound = false;
    }
    return available;
}
