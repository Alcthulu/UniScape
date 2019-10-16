#include "Object.h"



Object::Object(){
	name = "";
	description = "";
	pick = false;
	interactionCode = "";
}

Object::Object(string name, string description, bool pick, string interactionCode) {
	this->name = name;
	this->description = description;
	this->pick = pick;
	this->interactionCode = interactionCode;
}

string Object::getName() {
	return this->name;
}

string Object::getDescription() {
	return this->description;
}

bool Object::getPick() {
	return this->pick;
}

string Object::getInteractionCode() {
	return this->interactionCode;
}

void Object::setName(string name){
	this->name = name;
}

void Object::setDescription(string description){
	this->description = description;
}

void Object::setPick(bool pick){
	this->pick = pick;
}

void Object::setInteractionCode(string interactionCode){
	this->interactionCode = interactionCode;
}
