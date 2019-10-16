#include "Player.h"

Player::Player(){
	name = "PLAYER";
}

Player::Player(string name){
	this->name = name;
}

string Player::getName(){
	return this->name;
}

vector<Object> Player::getInvetory(){
	return this->inventory;
}

void Player::setName(string name) {
	this->name = name;
}

void Player::setInventory(vector<Object> inventory){
	this->inventory = inventory;
}
