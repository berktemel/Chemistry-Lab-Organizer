//
// Berk Temel 22002675
//

#ifndef UNTITLED_LABORGANIZER_H
#define UNTITLED_LABORGANIZER_H
#include <string>
#include "Cabinet.h"

using namespace std;
class LabOrganizer {
public:
    LabOrganizer();
    ~LabOrganizer();

    void addCabinet(int id, int rows, int columns);
    void removeCabinet(int id);
    void listCabinets();
    void cabinetContents(int id);
    void placeChemical(int cabinetId, string location, string chemType, int chemID);
    void findChemical(int id);
    void removeChemical(int id);
    bool isIDUnique(int id);
    bool validCabinetId(int id);
    bool validChemicalId(int id);
    Cabinet& findCabinet(int id);

private:
    Cabinet* cabinets;
    int cabinetCount;
    int* IDs;
    int idCount;
    Chemical* chemicals;
    int chemicalCount;
};


#endif //UNTITLED_LABORGANIZER_H
