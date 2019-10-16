#include "NPC.h"


NPC::NPC(){
	this->name = "";
	this->description = "";
	this->stage = -5;
	
}

NPC::NPC(string name, string description, int stage){
	this->name = name;
	this->description = description;
	this->stage = stage;

}

string NPC::getName(){
	return this->name;
}

string NPC::getDescription(){
	return this->description;
}

int NPC::getStage()
{
	return stage;
}

void NPC::setName(string name){
	this->name = name;
}

void NPC::setDescription(string description){
	this->description = description;
}

void NPC::setStage(int stage)
{
	this->stage = stage;
}
