#include "Door.h"

Door::Door(){
	this->id = -1;
	this->from = "";
	this->to = "";
	this->locked = false;
	this->interactionCode = "";
}

Door::Door(string id, string from, string to, bool locked, string interactionCode){
	this->id = id;
	this->from = from;
	this->to = to;
	this->locked = locked;
	this->interactionCode = interactionCode;
}

string Door::getId(){
	return this->id;
}

string Door::getFrom(){
	return this->from;
}

string Door::getTo(){
	return this->to;
}

bool Door::getLocked(){
	return this->locked;
}

string Door::getInteractionCode(){
	return this->interactionCode;
}

void Door::setId(const string & id){
	this->id = id;
}

void Door::setFrom(string from){
	this->from = from;
}

void Door::setTo(string to){
	this->to = to;
}

void Door::setLocked(bool locked){
	this->locked = locked;
}

void Door::setInteractionCode(string interactionCode){
	this->interactionCode = interactionCode;
}
