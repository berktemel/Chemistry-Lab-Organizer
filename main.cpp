#include <iostream>
using namespace std;
#include "LabOrganizer.h"
int main(){
	LabOrganizer L;
	L.listCabinets();
	// Testing add cabinet
	cout << "Testing add cabinet" << endl;
	cout << endl;
	L.addCabinet(908, 6, 6);
	L.addCabinet(707, 7, 4);
	L.addCabinet(404, 9, 9);
	cout << endl;
	L.addCabinet(908, 7, 2 );
	L.addCabinet(100, 10, 2);
	L.addCabinet(404, 11, 12);

	cout << endl;
	L.addCabinet(222, 7, 7);
	L.addCabinet(340, 6, 5);

	cout << endl;
	L.listCabinets();
	cout << endl;
	// Testing remove cabinet
	cout << endl;
	cout << "Testing remove cabinet" << endl;
	cout << endl;
	L.removeCabinet(999);
	L.removeCabinet(404);
	L.removeCabinet(404);
	L.removeCabinet(222);
	cout << endl;
	L.removeCabinet(660);
	L.removeCabinet(456);
	L.removeCabinet(707);
	cout << endl;
	L.addCabinet(111, 8, 8);
	cout << endl;
	L.listCabinets();
	cout << endl;
	// Testing place Chemical
	cout << endl;
	cout << "Testing place chemical" << endl;
	cout << endl;
	L.placeChemical( 908, "B2", "combustive", 768);
	L.placeChemical( 908, "C2", "retardant", 923);
	L.placeChemical( 908, "C3", "combustive", 200);
	cout << endl;
	L.placeChemical( 908, "E5", "combustive", 222);
	L.placeChemical( 908, "D3", "combustive", 300);
	L.placeChemical( 999, "D3", "retardant", 100);
	L.placeChemical( 908, "A6", "retardant", 923);

	cout << endl;
	L.placeChemical( 340, "E4", "combustive", 645);
	L.placeChemical( 340, "A1", "retardant", 112);
	L.placeChemical( 340, "E3", "combustive", 555);
	L.placeChemical( 340, "E3", "retardant", 555);
	L.placeChemical( 340, "C3", "combustive", 672);

	cout << endl;
	L.placeChemical( 111, "A2", "combustive", 435);
	L.placeChemical( 111, "C3", "retardant", 435);
	L.placeChemical( 111, "B3", "retardant", 908);
	L.placeChemical( 111, "C4", "combustive", 134);
	cout << endl;
	L.placeChemical( 111, "D3", "combustive", 687);
	L.placeChemical( 111, "F4", "retardant", 666);
	cout << endl;
	L.listCabinets();
	cout << endl;
	// Testing find chemical
	cout << endl;
	cout << "Testing find chemical" << endl;
	cout << endl;

	L.findChemical(898);
	L.findChemical(923);
	L.findChemical(666);
	cout << endl;

	L.findChemical(435);
	L.findChemical(333);
	L.findChemical(555);
	cout << endl;
	L.findChemical(300);
	cout << endl;
	// Testing show cabinet contents
	cout << endl;
	cout << "Testing show cabinet contents" << endl;
	cout << endl;
	L.cabinetContents(908);
	cout << endl;
	L.cabinetContents(340);
	cout << endl;
	L.cabinetContents(111);
	cout << endl;
	L.cabinetContents(200);
	cout << endl;
	// Testing remove chemical
	cout << endl;
	cout << "Testing remove chemical" << endl;
	cout << endl;
	L.removeChemical(923);
	L.removeChemical(300);
	L.removeChemical(222);
	cout << endl;
	L.removeChemical(189);
	L.removeChemical(777);
	L.removeChemical(672);
	// cout << endl;
	L.removeCabinet(240);
	cout << endl;
	L.removeCabinet(111);
	cout << endl;
	return 0;
}