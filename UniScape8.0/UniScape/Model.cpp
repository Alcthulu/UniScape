#include "Model.h"

void Model::NewPlayer(string name){
	p = Player(name);
}

void Model::GetPlayerData(string &name) {
	name = p.getName();
}

void Model::AddRoom(Room room){
	this->rooms.push_back(room);
}

void Model::updateRoom(Room toUpdate){
	for (unsigned int i = 0; i < this->rooms.size(); i++) {
		string name = this->rooms[i].getName();
		if (!toUpdate.getName().compare(name)) {
			this->rooms[i] = toUpdate;
		}
	}
}

Room Model::getRoom(string roomName){
	for (unsigned int i = 0; i < this->rooms.size(); i++) {
		string name = this->rooms[i].getName();
		if (!roomName.compare(name)) {
			return this->rooms[i];
		}
	}
}

vector<Object> Model::getInventory()
{
	return p.getInvetory();
}

void Model::updateInventory(vector<Object> updated)
{
	p.setInventory(updated);
}

