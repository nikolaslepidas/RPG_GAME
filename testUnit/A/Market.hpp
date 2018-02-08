#ifndef MARKET
#define MARKET

#include <string>
#include "Spell.hpp"
#include "Weapon.hpp"
#include "Armor.hpp"
#include "Potion.hpp"
#include <list>
#include <iostream>

using namespace std;

class Market{
	private:
		list<Spell> Spells;
		list<Weapon> Weapons;
		list<Armor> Armors;
		list<Potion> Potions;

	public:
		/*Accessors*/
		Spell& getSpells(int index);
		list<Weapon>& getWeapon(int index);
		list<Armor>& getArmors(int index);

		/*Prints*/
		void printSpells(void);
		void printWeapons(void);
		void printArmors(void);
		void printPotions(void);

		/*Others*/
		void addWeapon(string Name,int MinLevel);
		void addArmor(string Name,int MinLevel);
		void addPotion(string Name,int MinLevel,string WtIncrease);
		void addSpell(string Name,int MinLevel);
		void checkMarket(void);
		//void menuMarket(Hero**&heroes,int arraySize);
		void printOptions(void);
};

#endif