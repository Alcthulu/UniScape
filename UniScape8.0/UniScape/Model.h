#ifndef __MODEL_H
#define __MODEL_H


#include "Room.h"
#include "Player.h"

class Model {

	private:

		vector<Room> rooms;
		Player p;

	public:

		void NewPlayer(string name);
		void GetPlayerData(string & name);
		void AddRoom(Room room);
		void updateRoom(Room toUpdate);
		Room getRoom(string roomName);
		vector<Object> getInventory();
		void updateInventory(vector<Object> updated);
};

#endif