#include "Room.h"

Room::Room(){
	this->name = "";
	this->description = "";
}

Room::Room(string name, string description, vector<Object> objects, vector<Container> containers, vector<Door> doors, NPC npc){
	this->name = name;
	this->description = description;
	this->objects = objects;
	this->containers = containers;
	this->doors = doors;
	this->npc = npc;
}

string Room::getName(){
	return this->name;
}

string Room::getDescription(){
	return this->description;
}

vector<Object> Room::getObjects(){
	return this->objects;
}

vector<Container> Room::getContainers(){
	return this->containers;
}

vector<Door> Room::getDoors(){
	return this->doors;
}

NPC Room::getNPC()
{
	return npc;
}

void Room::setName(string name){
	this->name = name;
}

void Room::setDescription(string description){
	this->description = description;
}

void Room::setObjects(vector<Object> objects){
	this->objects = objects;
}

void Room::setContainers(vector<Container> containers){
	this->containers = containers;
}

void Room::setDoors(vector<Door> doors){
	this->doors = doors;
}

void Room::setNPC(NPC npc)
{
	this->npc = npc;
}

void Room::updateObject(Object toUpdate) {
	for (unsigned int i = 0; i < this->objects.size(); i++) {
		string name = this->objects[i].getName();
		if (!toUpdate.getName().compare(name)) {
			this->objects[i] = toUpdate;
		}
	}
}

Object Room::substractObject(string objectName) {
	for (unsigned int i = 0; i < objects.size(); i++) {
		if (!objects[i].getName().compare(objectName)) {
			Object substracted = objects[i];
			for (unsigned int j = i; j < objects.size()-1; j++) {
				objects[j] = objects[j + 1];
			}
			objects.pop_back();
			return substracted;
		}
	}
}

Object Room::getObject(string objectName) {
	for (unsigned int i = 0; i < this->objects.size(); i++) {
		string name = this->objects[i].getName();
		if (!objectName.compare(name)) {
			return this->objects[i];
		}
	}
	return Object();
}

void Room::updateContainer(Container toUpdate) {
	for (unsigned int i = 0; i < this->containers.size(); i++) {
		string name = this->containers[i].getName();
		if (!toUpdate.getName().compare(name)) {
			this->containers[i] = toUpdate;
		}
	}
}

Container Room::getContainer(string containerName) {
	for (unsigned int i = 0; i < this->containers.size(); i++) {
		string name = this->containers[i].getName();
		if (!containerName.compare(name)) {
			return this->containers[i];
		}
	}
	return Container();
}

