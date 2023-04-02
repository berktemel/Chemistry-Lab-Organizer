//
// Berk Temel 22002675
//

#include <iostream>
#include "LabOrganizer.h"
using namespace std;

LabOrganizer::LabOrganizer() {
    cabinetCount = 0;
    idCount = 0;
    chemicalCount = 0;
    cabinets = new Cabinet[cabinetCount];
    IDs = new int[idCount];
    chemicals = new Chemical[chemicalCount];
}

LabOrganizer::~LabOrganizer() {
    delete[] cabinets;
    delete[] IDs;
    delete[] chemicals;
}

void LabOrganizer::addCabinet(int id, int rows, int columns) {
    if(isIDUnique(id) && rows < 10 && columns < 10) {
        Cabinet* tempCab = new Cabinet[cabinetCount + 1];
        for(int i = 0; i < cabinetCount; i++) {
            tempCab[i] = cabinets[i];
        }
        tempCab[cabinetCount] = Cabinet(id, rows, columns);
        delete[] cabinets;
        cabinets = tempCab;
        cabinetCount++;
        for(int i = 0; i < cabinetCount; i++)
            cabinets[i].initArray();

        int* tempId = new int[idCount + 1];

        for(int i = 0; i < idCount; i++)
            tempId[i] = IDs[i];
        tempId[idCount] = id;
        delete[] IDs;
        IDs = tempId;
        idCount++;
        cout << "Added a cabinet: ID " << id << " and dimensions " << rows << " to " << columns << endl;
    } else if(!isIDUnique(id)) {
        cout << "Cannot add the cabinet: ID " << id << " is already in the system." << endl;
    } else {
        cout << "Cannot add the cabinet: Dimensions are out of bounds." << endl;
    }
}

void LabOrganizer::removeCabinet(int id) {
    if(!validCabinetId(id)) {
        cout << "Cabinet " << id << " does not exist in the system." << endl;
    } else {
        Cabinet* tempCab = new Cabinet[cabinetCount - 1];
        int k = 0;
        for(int i = 0; i < cabinetCount; i++) {
            if(k < cabinetCount - 1) {
                tempCab[k] = cabinets[i];
            }
            if(cabinets[i].getId() != id)
                k++;
        }
        delete[] cabinets;
        cabinets = tempCab;
        cabinetCount--;
        for(int i = 0; i < cabinetCount; i++)
            cabinets[i].initArray();

        int* tempId = new int[idCount - 1];
        int j = 0;
        for(int i = 0; i < idCount; i++) {
            if(j < idCount - 1)
                tempId[j] = IDs[i];
            if(IDs[i] != id)
                j++;
        }
        idCount--;
        delete[] IDs;
        IDs = tempId;
        cout << "Cabinet " << id << " has been removed." << endl;
    }
}

void LabOrganizer::listCabinets() {
    for(int i = 0; i < cabinetCount; i++) {
        cout << "ID: " << cabinets[i].getId() << ", Dim: " << cabinets[i].getRow() << "x" << cabinets[i].getColumn()
             << ", Number of empty slots: " << cabinets[i].getEmptySlots() << endl;
    }
}

void LabOrganizer::cabinetContents(int id) {
    if(validCabinetId(id)) {
        Cabinet &cab = findCabinet(id);
        cout << " ";
        for (int i = 0; i < cab.getColumn(); i++)
            cout << " " << cab.getColumnName(i);
        cout << endl;
        for (int i = 0; i < cab.getRow(); i++) {
            cout << cab.getRowName(i);
            for (int j = 0; j < cab.getColumn(); j++) {
                Chemical currentChem = cab.getChemical(i, j);
                cout << " ";
                if (currentChem.chemicalExists()) {
                    cout << currentChem.getChemicalType().at(0);
                } else {
                    cout << "+";
                }
            }
            cout << endl;
        }
    } else {
        cout << "Cabinet " << id << " is not in the system." << endl;
    }
}

void LabOrganizer::placeChemical(int cabinetId, string location, string chemType, int chemID) {
    Cabinet& cab = findCabinet(cabinetId);
    if(validCabinetId(cabinetId) && isIDUnique(chemID) && cab.spaceEmpty(location)) {
        Chemical chemical(chemID, chemType, cabinetId);
        if(chemType == "retardant") {
            cab.setChemical(chemical, location);

            Chemical* tempChemicals = new Chemical[chemicalCount + 1];
            for(int i = 0; i < chemicalCount; i++)
                tempChemicals[i] = chemicals[i];
            tempChemicals[chemicalCount] = chemical;
            delete[] chemicals;
            chemicals = tempChemicals;
            chemicalCount++;

            int* tempId = new int[idCount + 1];
            for(int i = 0; i < idCount; i++)
                tempId[i] = IDs[i];
            tempId[idCount] = chemID;
            delete[] IDs;
            IDs = tempId;
            idCount++;
            cout << chemType << " chemical with ID " << chemID << " has been placed at location "
                 << location << " in cabinet " << cabinetId << endl;
        } else {
            if(cab.cNear(location))
                cout << "Location " << location << " is not suitable for combustive chemical." <<
                     " Nearest possible locations for this chemical: " << cab.availableNear(location, chemType) << endl;
            else {
                cab.setChemical(chemical, location);

                Chemical* tempChemicals = new Chemical[chemicalCount + 1];
                for(int i = 0; i < chemicalCount; i++)
                    tempChemicals[i] = chemicals[i];
                tempChemicals[chemicalCount] = chemical;
                delete[] chemicals;
                chemicals = tempChemicals;
                chemicalCount++;

                int* tempId = new int[idCount + 1];
                for(int i = 0; i < idCount; i++)
                    tempId[i] = IDs[i];
                tempId[idCount] = chemID;
                delete[] IDs;
                IDs = tempId;
                idCount++;
                cout << chemType << " chemical with ID " << chemID << " has been placed at location "
                     << location << " in cabinet " << cabinetId << endl;
            }
        }
    } else if(!isIDUnique(chemID)) {
        cout << "Cannot add the chemical: ID " << chemID << " is already in the system." << endl;
    } else if(!validCabinetId(cabinetId)) {
        cout << "Cabinet " << cabinetId << " does not exist in the system." << endl;
    } else if(!cab.spaceEmpty(location)) {
        cout << "Location " << location << " in cabinet " << cabinetId << " is already occupied." <<
             " Nearest possible locations for this chemical: " << cab.availableNear(location, chemType) << endl;
    }
}

void LabOrganizer::findChemical(int id) {
    if(isIDUnique(id))
        cout << "Chemical " << id << " is not in the system." << endl;
    else {
        int row;
        int column;
        int index;
        for(int i = 0; i < chemicalCount; i++) {
            if(chemicals[i].getId() == id)
                index = i;
        }
        Chemical& chem = chemicals[index];
        Cabinet& cab = findCabinet(chem.getCabinetId());
        for(int i = 0; i < cab.getRow(); i++) {
            for(int j = 0; j < cab.getColumn(); j++) {
                if(cab.getChemical(i, j).getId() == id) {
                    row = i;
                    column = j;
                }
            }
        }
        cout << "Chemical " << id << " is at location " << cab.getLocation(row, column) << " in Cabinet " << cab.getId() << endl;
    }
}

void LabOrganizer::removeChemical(int id) {
    if(!validChemicalId(id))
        cout << "Chemical " << id << " is not in the system." << endl;
    else {
        Chemical* tempChem = new Chemical[chemicalCount - 1];
        Chemical removedChem;
        int j = 0;
        for(int i = 0; i < chemicalCount; i++) {
            if(j < chemicalCount - 1)
                tempChem[j] = chemicals[i];
            if(chemicals[i].getId() != id)
                j++;
            else
                removedChem = chemicals[i];
        }
        chemicalCount--;
        delete[] chemicals;
        chemicals = tempChem;

        int* tempId = new int[idCount - 1];
        j = 0;
        for(int i = 0; i < idCount; i++) {
            if(j < idCount - 1)
                tempId[j] = IDs[i];
            if(IDs[i] != id)
                j++;
        }
        idCount--;
        delete[] IDs;
        IDs = tempId;

        cout << "Chemical " << id << " has been removed from Cabinet " << removedChem.getCabinetId() << endl;
    }
}

bool LabOrganizer::isIDUnique(int id) {
    for( int i = 0; i < idCount; i++) {
        if( IDs[i] == id)
            return false;
    }
    return true;
}

bool LabOrganizer::validCabinetId(int id) {
    for(int i = 0; i < cabinetCount; i++) {
        if( cabinets[i].getId() == id)
            return true;
    }
    return false;
}

bool LabOrganizer::validChemicalId(int id) {
    for(int i = 0; i < chemicalCount; i++) {
        if(chemicals[i].getId() == id)
            return true;
    }
    return false;
}

Cabinet& LabOrganizer::findCabinet(int id) {
    int index;
    for(int i = 0; i < cabinetCount; i++) {
        if(cabinets[i].getId() == id)
            index = i;
    }
    return cabinets[index];
}
