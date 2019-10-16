#ifndef __NPC_H
#define __NPC_H


#include <string>
#include <vector>
#include "Object.h"

using namespace std;

class NPC {

	private:

		string name;
		string description;
		int stage;

	public:

	// CONSTRUCTORS:

		NPC();
		NPC(string name, string description, int stage);

	// GETTERS:

		string getName();
		string getDescription();
		int getStage();

	// SETTERS:

		void setName(string name);
		void setDescription(string description);
		void setStage(int stage);

};


#endif // !__NPC_H