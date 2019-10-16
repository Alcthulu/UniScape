#include "Container.h"


Container::Container(){
	name = "";
	description = "";
	examined = false;
	interactionCode = "NONE";
	content = Object();
}

Container::Container(string name, string description, bool examined, Object content, string interactionCode) {
	this->name = name;
	this->description = description;
	this->examined = examined;
	this->interactionCode = interactionCode;
	this->content = content;
}

string Container::getName() {
	return this->name;
}

string Container::getDescription() {
	return this->description;
}

bool Container::getExamined()
{
	return this->examined;
}

string Container::getInteractionCode(){
	return this->interactionCode;
}

Object Container::getContent(){
	return this->content;
}

void Container::setName(string name){
	this->name = name;
}

void Container::setDescription(string description){
	this->description = description;
}

void Container::setExamined(bool examined){
	this->examined = examined;
}

void Container::setInteractionCode(string interactionCode){
	this->interactionCode = interactionCode;
}

void Container::setContent(Object content){
	this->content = content;
}
