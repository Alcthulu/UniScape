#ifndef __ROOM_H
#define __ROOM_H


#include <string>
#include <vector>
#include "Object.h"
#include "Container.h"
#include "Door.h"
#include "NPC.h"


class Room {

	private:

		string name;
		string description;
		vector<Object> objects;
		vector<Container> containers;
		vector<Door> doors;
		NPC npc = NPC();

	public:

	// CONSTRUCTORS:

		Room();
		Room(string name, string description, vector<Object> objects, vector<Container> containers, vector<Door> doors, NPC npc = NPC());

	// GETTERS:

		string getName();
		string getDescription();
		vector<Object> getObjects();
		vector<Container> getContainers();
		vector<Door> getDoors();
		NPC getNPC();

	// SETTERS:

		void setName(string name);
		void setDescription(string description);
		void setObjects(vector<Object> objects);
		void setContainers(vector<Container> containers);
		void setDoors(vector<Door> doors);
		void setNPC(NPC npc);

	// OTHERS:

		void updateObject(Object toUpdate);
		Object substractObject(string objectName);
		Object getObject(string objectName);

		void updateContainer(Container toUpdate);

		Container getContainer(string containerName);


};


#endif