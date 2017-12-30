#include "Inventory.hpp"
#include <iostream>
using namespace std;

/*printSpells*/
void Inventory::printSpells(void){
	int i=0;
	list<Spell>::iterator it;
	cout<<"Spells are:"
	for(it=Spells.begin();it!=Spells.end();it++){ //for every spell
		cout<<"<------"<<i++<<"------>"<<endl;
		it->printSpell(); //call the print function for the spell
		cout<<endl; //leave one line empty
	}
}

/*printWeapons*/
void Inventory::printWeapons(void){
	int i=0;
	list<Weapon>::iterator it;
	cout<<"Weapons are:"
	for(it=Weapons.begin();it!=Weapons.end();it++){ //for every weapon
		cout<<"<------"<<i++<<"------>"<<endl;
		it->printWeapon(); //call the print function for the weapon
		cout<<endl; //leave one line empty
	}
}

/*printArmors*/
void Inventory::printArmors(void){
	int i=0;
	list<Armor>::iterator it;
	cout<<"Armors are:"
	for(it=Armors.begin();it!=Armors.end();it++){ //for every Armor
		cout<<"<------"<<i++<<"------>"<<endl;
		it->printArmor(); //call the print function for the Armor
		cout<<endl; //leave one line empty
	}
}

/*checkInventory*/
void Inventory::checkInventory(void){
	printWeapons();
	printArmors();
	printSpells();
}

