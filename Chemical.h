//
// Berk Temel 22002675
//

#ifndef UNTITLED_CHEMICAL_H
#define UNTITLED_CHEMICAL_H
#include <string>
using namespace std;

class Chemical {
public:
    Chemical(int id, string type, int cabId);
    Chemical();
    int getId() const;
    int getCabinetId() const;
    void setId(int id);
    void setType(string type);
    string getChemicalType() const;
    bool chemicalExists() const;

private:
    int id;
    string type;
    int cabId;
};


#endif //UNTITLED_CHEMICAL_H
