#ifndef __PLAYER_H
#define __PLAYER_H


#include "Object.h"
#include <vector>


class Player {
	
	private:

		string name;
		vector<Object> inventory;

	public:

	// CONSTRUCTORS:

		Player();
		Player(string name);

	// GETTERS:

		string getName();
		vector<Object> getInvetory();

	// SETTERS:

		void setName(string name);
		void setInventory(vector<Object> inventory);
};


#endif
