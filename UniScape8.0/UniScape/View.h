#ifndef __VIEW_H
#define __VIEW_H



#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Controller.h"
#include "TextConf.h"
#include "Sounds.h"

class View {
	private:
		Controller c;

	public:
		void RunMenu();
		void Quit(bool &quit);
		void NewGame();

		void GameLoop();

		void CommandManager(string command, string &ActualRoom, bool &OVER, bool &win, int &end);

		void useItems(string item1, string item2, bool &OVER, bool &win, int &end);
		void useItemsOnOnventory(string item1, string item2);
		void useItemsOnRoom(string item1, string item2);
		void useItemsNPC(string item1, string item2, bool &OVER, int &end);

		void containerCommandManager(string containerName);

		void npcUI(string npcName);

		void nothingHapens();

		void displayHelp();

		void lose();
		void win();

		void win1();

		void win2();

};

#endif // !__VIEW_H