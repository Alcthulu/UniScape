#include "View.h"


#pragma comment(lib, "winmm.lib")

using namespace std;

Controller * C = new Controller();

void View::RunMenu() {
	char option = '0';
	bool exit = false;
	while (!exit){

		system("CLS");
		SetColor(DARKGRAY);
		cout << endl << endl << endl;
		cout << "    -************************-  ********************************************************************" << endl;
		cout << "    -"; SetColor(LIGHTRED); cout << "           /\\           "; SetColor(DARKGRAY); cout << "-                                                                     *" << endl;
		cout << "    -"; SetColor(LIGHTRED); cout << "          /__\\          "; SetColor(DARKGRAY); cout << "-"; SetColor(WHITE); cout << "      You wake up in a huge bed, you don't know where you are.       "; SetColor(DARKGRAY); cout << "*" << endl;
		cout << "    -"; SetColor(LIGHTGRAY); cout << "          |"; SetColor(LIGHTCYAN); cout << "[]"; SetColor(LIGHTGRAY); cout << "|          "; SetColor(DARKGRAY); cout << "-"; SetColor(WHITE); cout << "                You feel a strange smell, like incense.              "; SetColor(DARKGRAY); cout << "*" << endl;
		cout << "    -"; SetColor(LIGHTGRAY); cout << "      ____]__[____      "; SetColor(DARKGRAY); cout << "-"; SetColor(WHITE); cout << "      You try to open your eyes, a blinding light prevents you.      "; SetColor(DARKGRAY); cout << "*" << endl;
		cout << "    -"; SetColor(LIGHTGRAY); cout << "      |"; SetColor(BROWN); cout << " UniScape"; SetColor(LIGHTGRAY); cout << " |      "; SetColor(DARKGRAY); cout << "-"; SetColor(WHITE); cout << "  You try again, this time slower, where does that light come from?  "; SetColor(DARKGRAY); cout << "*" << endl;
		cout << "    -"; SetColor(LIGHTGRAY); cout << "   |==  "; SetColor(BROWN); cout << "THE GAME  "; SetColor(LIGHTGRAY); cout << "==|   "; SetColor(DARKGRAY); cout << "-"; SetColor(WHITE); cout << "    What are those strange colors? Then you see it, on your right,   "; SetColor(DARKGRAY); cout << "*" << endl;
		cout << "    -"; SetColor(LIGHTGRAY); cout << "   |"; SetColor(YELLOW); cout << "-_-_-_ "; SetColor(LIGHTGRAY); cout << "**"; SetColor(YELLOW); cout << " _-_-_-"; SetColor(LIGHTGRAY); cout << "|   "; SetColor(DARKGRAY); cout << "-"; SetColor(WHITE); cout << "      a huge stained-glass window, with a ... medieval design?       "; SetColor(DARKGRAY); cout << "*" << endl;
		cout << "    -"; SetColor(LIGHTGRAY); cout << "   |______ .. ______|   "; SetColor(DARKGRAY); cout << "-                                                                     *" << endl;
		cout << "    -                        -"; SetColor(WHITE); cout << "               Where are you and how did you get here?               "; SetColor(DARKGRAY); cout << "*" << endl;
		cout << "    -                        -"; SetColor(WHITE); cout << "          Even more importantly, how will you get back home?         "; SetColor(DARKGRAY); cout << "*" << endl;
		cout << "    -"; SetColor(WHITE); cout << "   1.>>> NEW GAME       "; SetColor(DARKGRAY); cout << "-"; SetColor(WHITE); cout << "           Will you have what it takes to get out of this?           "; SetColor(DARKGRAY); cout << "*" << endl;
		cout << "    -"; SetColor(WHITE); cout << "   2.>>> QUIT           "; SetColor(DARKGRAY); cout << "-                                                                     *" << endl;
		cout << "    -........................-  ********************************************************************" << endl;
		cout << endl << endl;
		SetColor(WHITE);
		cout << "    Select an option >>> ";
		sndPlaySound(MENU, SND_LOOP | SND_ASYNC);
		cin >> option;
		string name;
		
		switch (option) {

			case '1':

				sndPlaySound(SELECTION, SND_ASYNC);
				this->NewGame();
				system("CLS");
				this->GameLoop();
				sndPlaySound(SELECTION, SND_ASYNC);
				break;

			case '2':
				sndPlaySound(SELECTION, SND_ASYNC);
				Quit(exit);
				break;

			default:
				break;
		}


	}

}

void View::Quit(bool & quit){

	char option;
	bool again = true;
	while (again) {
		system("CLS");
		cout << " Are you sure you want to quit? (y/n) >>> ";

		cin >> option;

		switch (option) {

			case 'y':
				sndPlaySound(SELECTION, SND_SYNC);
				quit = true;
				again = false;
				break;

			case 'n':
				sndPlaySound(SELECTION, SND_ASYNC);
				again = false;
				break;

			default:
				break;
		}
	}

	
}

void View::NewGame() {
	
	system("CLS");
	string name;
	cin.ignore();
	SetColor(WHITE); cout << endl << "\tWhat is your name? : ";
	SetColor(YELLOW); getline(cin, name);
	sndPlaySound(SELECTION, SND_ASYNC);
	SetColor(WHITE);
	this->c.NewPlayer(name);
	this->c.GenerateMap();


}

void View::GameLoop() {


	string ActualRoom = "Start Room";
	bool OVER = false;
	bool Win = false;
	int end = 0;
	string command;
	c.setIam(ActualRoom);
	while (!OVER) {

		system("CLS");
		SetColor(BLUE);
		cout << endl << "\t" << ActualRoom << ": ";
		SetColor(WHITE);
		cout << c.getRoomDescription() << endl << endl;
		cout << "\t\tYou can see: " << endl;
		SetColor(GREEN);
		cout << c.roomDisplay() << endl << endl;
		SetColor(WHITE);
		cout << "\tEnter a command >> ";
		SetColor(YELLOW);
		getline(cin, command);
		CommandManager(command, ActualRoom, OVER, Win, end);
	}
	if (Win) { 
		if (end == 0) win(); 
		else if (end == 1) win1();
		else if (end == 2) win2();
	}
	else lose();
}

void View::CommandManager(string command, string &ActualRoom, bool &OVER, bool &win, int &end) {
	if (!command.compare("Give up")) {
		OVER = true;
	}
	else if (!command.compare("Help")) {
		displayHelp();
	}
	else if (!command.find("Examine", 0)) {
		system("CLS");
		string object = command;
		object.erase(0, 8);
		if (c.checkObject(object)) {
			SetColor(BLUE);
			cout << endl << endl << "\t\t\t\t" << object;
			SetColor(WHITE);
			cout << endl << endl << c.getObjectDescription(object);
			cin.ignore();
		}
		else if (c.checkContainer(object)) {

			SetColor(BLUE);
			cout << endl << endl << "\t\t\t\t" << object;
			SetColor(WHITE);
			cout << endl << endl << c.getContainerDescription(object);
			cin.ignore();
		}
		else if (c.checkObjectOnInventory(object)) {
			SetColor(BLUE);
			cout << endl << endl << "\t\t\t\t" << object;
			SetColor(WHITE);
			cout << endl << endl << c.getObjectDescriptionInventory(object);
			cin.ignore();
		}
		else if (c.checkNPC(object)) {
			SetColor(BLUE);
			cout << endl << endl << "\t\t\t\t" << object;
			SetColor(WHITE);
			cout << endl << endl << c.getNpcDescription();
			cin.ignore();
		}
		else {
			nothingHapens();
		}
		
	}
	else if (!command.find("Open", 0)) {
		system("CLS");
		string toOpen = command;
		toOpen.erase(0, 5);
		if (c.checkContainer(toOpen)) {
			if (c.containerExamined(toOpen)) {
				containerCommandManager(toOpen);
			}
			else {
				SetColor(WHITE);
				cout << endl << endl << "\tDon't know if it can be opened... Maybe you should examine it...";
				cin.ignore();
			}
		}
		else {
			nothingHapens();
		}
	}
	else if(!command.find("List inventory",0)){
		system("CLS");
		SetColor(BLUE);
		cout << endl << endl << "\t\tINVENTORY:" << endl;
		SetColor(WHITE);
		cout << c.inventoryDisplay();
		cin.ignore();
	}
	else if (!command.find("Pick up", 0)) {
		string object = command;
		object.erase(0, 8);
		if (c.checkObject(object) && c.canBePickedUp(object)) {
			c.pickUpFromRoom(object);
			system("CLS");
			SetColor(GREEN);
			cout << endl << "\t\t\t" << object;
			SetColor(WHITE);
			cout << " picked up!";
			cin.ignore();
		}
		else {
			nothingHapens();
		}
	}
	else if (!command.find("Go to", 0)) {
		string room = command;
		room.erase(0, 6);
		if (c.checkToRoom(room) == -1) {
			nothingHapens();
		}
		else if (c.checkToRoom(room) == 0){
			system("CLS");
			SetColor(WHITE);
			cout << endl << endl << "\tThe door is locked, try to use a key...";
			cin.ignore();
		}
		else {
			if (!room.compare("the Outside")) {
				win = true; OVER = true; return;
			}
			ActualRoom = room;
			c.setIam(ActualRoom);
			
		}
	}
	else if (!command.find("Use", 0)) {
		int with = command.find("with");
		string item1 = command;
		item1.erase(with-1, command.size() - 1);
		item1.erase(0, 4);
		string item2 = command;
		item2.erase(0, with + 5);
		useItems(item1, item2, OVER, win, end);
		
	}
	else if (!command.find("Talk to", 0)) {
		
		string npc = command;
		npc.erase(0, 8);
		if (c.checkNPC(npc)){
			npcUI(npc);
		}
		else {
			nothingHapens();
		}
	}
	else {
		nothingHapens();
	}
}

void View::useItems(string item1, string item2, bool &OVER, bool &win, int &end) {

	//Check if item1 is in the inventory
	if (c.checkObjectOnInventory(item1)) {
		//Get the interaction code for item1
		string code1 = c.getObjectInteractionCode(item1);
		//See if item1 has an interaction code
		if (code1.compare("")) {
			//Check if item2 is a locked door
			if (c.checkDoor(item2) == 0) {
				//Check if the interaction code is the same for both items
				if (!c.getDoorInteractionCode(item2).compare(code1)) {
					c.unlockDoor(item2);
					system("CLS");
					SetColor(WHITE);
					cout << endl << endl << "\tYou use ";SetColor(GREEN);cout << item1;SetColor(WHITE);cout << " on ";SetColor(GREEN);cout << item2;SetColor(WHITE);cout << "...";
					cin.ignore();
					cout << "\tThe door is now open! :D...";
					cin.ignore();
					c.deleteFromInventory(item1);
					return;
				}
				else {
					nothingHapens();
					return;
				}
			}
			else {
				nothingHapens();
			}
			
		}
		else if (c.checkObjectOnInventory(item2)) {
			system("CLS");
			useItemsOnOnventory(item1, item2);
			return;
		}
		else if (c.checkObject(item2)) {
			system("CLS");
			useItemsOnRoom(item1, item2);
			return;
		}
		else if (c.checkNPC(item2)) {
			system("CLS");
			useItemsNPC(item1, item2, OVER, end);
			return;
		}
		else {
			nothingHapens();
			return;
		}

	}
	else {
		nothingHapens();
	}
	/* 1º Check if the first one is an object on inventory and has a interaction Code
			if not nothing happens. return
	   2º Check if the second one is a door(this first) and has the same interaction Code(this later)
			if yes unlock the door and delete the first item from inventary. return
			if is a door with different or no Code nothing happens. return
	   3º Check if the second one is an object on inventory and has the same interaction Code
			if yes depends on the interaction code
			if not nothing happens. return*/
	
}

void View::useItemsOnOnventory(string item1, string item2)
{
	if (!item1.compare("knife")) {
		if(!item2.compare("onions")){
			c.deleteFromInventory(item2);
			system("CLS");
			SetColor(WHITE);
			cout << endl << endl << "\tYou use "; SetColor(GREEN); cout << item1; SetColor(WHITE); cout << " on "; SetColor(GREEN); cout << item2; SetColor(WHITE); cout << "...";
			cin.ignore();
			cout << "\tYou have "; SetColor(GREEN); cout << c.generateSlicedOnions(); SetColor(WHITE); cout << " now!...";
			cin.ignore();
			return;
		}
		else if (!item2.compare("potatoes")) {
			c.deleteFromInventory(item2);
			system("CLS");
			SetColor(WHITE);
			cout << endl << endl << "\tYou use "; SetColor(GREEN); cout << item1; SetColor(WHITE); cout << " on "; SetColor(GREEN); cout << item2; SetColor(WHITE); cout << "...";
			cin.ignore();
			cout << "\tYou have "; SetColor(GREEN); cout << c.generateSlicedPotatoes(); SetColor(WHITE); cout << " now!...";
			cin.ignore();
			return;
		}
		else if (!item2.compare("cod")) {
			c.deleteFromInventory(item2);
			system("CLS");
			SetColor(WHITE);
			cout << endl << endl << "\tYou use "; SetColor(GREEN); cout << item1; SetColor(WHITE); cout << " on "; SetColor(GREEN); cout << item2; SetColor(WHITE); cout << "...";
			cin.ignore();
			cout << "\tYou have "; SetColor(GREEN); cout << c.generateCrumbledCod(); SetColor(WHITE); cout << " now!...";
			cin.ignore();
			return;
		}
		else {
			nothingHapens();
			return;
		}
	}
	else if (!item1.compare("mixed eggs")) {
		if (!item2.compare("chips")) {
			c.deleteFromInventory(item2);
			system("CLS");
			SetColor(WHITE);
			cout << endl << endl << "\tYou use "; SetColor(GREEN); cout << item1; SetColor(WHITE); cout << " with "; SetColor(GREEN); cout << item2; SetColor(WHITE); cout << "...";
			cin.ignore();
			cout << "\tYou have "; SetColor(GREEN); cout << c.generateMixedEggsAndChips(); SetColor(WHITE); cout << " now!...";
			cin.ignore();
			return;
		}
		else {
			nothingHapens();
			return;
		}
	}
	else if (!item1.compare("chips")) {
		if (!item2.compare("mixed eggs")) {
			c.deleteFromInventory(item2);
			system("CLS");
			SetColor(WHITE);
			cout << endl << endl << "\tYou use "; SetColor(GREEN); cout << item1; SetColor(WHITE); cout << " with "; SetColor(GREEN); cout << item2; SetColor(WHITE); cout << "...";
			cin.ignore();
			cout << "\tYou have "; SetColor(GREEN); cout << c.generateMixedEggsAndChips(); SetColor(WHITE); cout << " now!...";
			cin.ignore();
			return;
		}
		else {
			nothingHapens();
			return;
		}
	}
	else {
		nothingHapens();
	}
	

}

void View::useItemsOnRoom(string item1, string item2)
{
	if (!item1.compare("firewood")) {
		if (!item2.compare("pan")) {
			c.deleteFromInventory(item1);
			c.deleteFromRoom(item2);
			system("CLS");
			SetColor(WHITE);
			cout << endl << endl << "\tYou use "; SetColor(GREEN); cout << item1; SetColor(WHITE); cout << " on "; SetColor(GREEN); cout << item2; SetColor(WHITE); cout << "...";
			cin.ignore();
			cout << "\tThere is a "; SetColor(GREEN); cout << c.generateHotPan(); SetColor(WHITE); cout << " now!...";
			cin.ignore();
			return;
		}
		else {
			nothingHapens();
			return;
		}
	}
	else if (!item1.compare("oil")) {

		if (!item2.compare("hot pan")) {
			c.deleteFromRoom(item2);
			system("CLS");
			SetColor(WHITE);
			cout << endl << endl << "\tYou use "; SetColor(GREEN); cout << item1; SetColor(WHITE); cout << " on "; SetColor(GREEN); cout << item2; SetColor(WHITE); cout << "...";
			cin.ignore();
			cout << "\tThere is a "; SetColor(GREEN); cout << c.generatePanReadyToCook(); SetColor(WHITE); cout << " now!...";
			cin.ignore();
			return;
		}

	}
	else if (!item1.compare("sliced potatoes")) {
		if (!item2.compare("pan ready to cook")) {
			c.deleteFromInventory(item1);
			c.deleteFromRoom(item2);
			system("CLS");
			SetColor(WHITE);
			cout << endl << endl << "\tYou use "; SetColor(GREEN); cout << item1; SetColor(WHITE); cout << " on "; SetColor(GREEN); cout << item2; SetColor(WHITE); cout << "...";
			cin.ignore();
			cout << "\tYou have "; SetColor(GREEN); cout << c.generateChips(); SetColor(WHITE); cout << " and there is a "; SetColor(GREEN); cout << c.generateHotPan(); SetColor(WHITE); cout << " now!...";
			cin.ignore();
			return;
		}
		else {
			nothingHapens();
			return;
		}
	}
	else if (!item1.compare("sliced onions")) {
		if (!item2.compare("pan ready to cook") && (c.checkObjectOnInventory("chips") || c.checkObjectOnInventory("mixed eggs and chips"))) {
			c.deleteFromInventory(item1);
			c.deleteFromRoom(item2);
			system("CLS");
			SetColor(WHITE);
			cout << endl << endl << "\tYou use "; SetColor(GREEN); cout << item1; SetColor(WHITE); cout << " on "; SetColor(GREEN); cout << item2; SetColor(WHITE); cout << "...";
			cin.ignore();
			cout << "\tThere is a "; SetColor(GREEN); cout << c.generatePanCookingOnions(); SetColor(WHITE); cout << " now!...";
			cin.ignore();
			return;
		}
		else {
			nothingHapens();
			return;
		}
	}
	else if (!item1.compare("crumbled cod")) {
		if (!item2.compare("pan cooking onions")) {
			c.deleteFromInventory(item1);
			c.deleteFromRoom(item2);
			system("CLS");
			SetColor(WHITE);
			cout << endl << endl << "\tYou use "; SetColor(GREEN); cout << item1; SetColor(WHITE); cout << " on "; SetColor(GREEN); cout << item2; SetColor(WHITE); cout << "...";
			cin.ignore();
			cout << "\tThere is a "; SetColor(GREEN); cout << c.generatePanCookingOnionsAndCod(); SetColor(WHITE); cout << " now!...";
			cin.ignore();
			return;
		}
		else {
			nothingHapens();
			return;
		}
	}
	else if (!item1.compare("eggs")) {
		if (!item2.compare("bowl")) {
			c.deleteFromInventory(item1);
			c.deleteFromRoom(item2);
			system("CLS");
			SetColor(WHITE);
			cout << endl << endl << "\tYou use "; SetColor(GREEN); cout << item1; SetColor(WHITE); cout << " on "; SetColor(GREEN); cout << item2; SetColor(WHITE); cout << "...";
			cin.ignore();
			cout << "\tThere is a "; SetColor(GREEN); cout << c.generateBowlOfEggs(); SetColor(WHITE); cout << " now!...";
			cin.ignore();
			return;
		}
		else {
			nothingHapens();
			return;
		}
	}
	else if (!item1.compare("fork")) {
		if (!item2.compare("bowl of eggs")) {
			c.deleteFromInventory(item1);
			c.deleteFromRoom(item2);
			system("CLS");
			SetColor(WHITE);
			cout << endl << endl << "\tYou use "; SetColor(GREEN); cout << item1; SetColor(WHITE); cout << " on "; SetColor(GREEN); cout << item2; SetColor(WHITE); cout << "...";
			cin.ignore();
			cout << "\tYou have "; SetColor(GREEN); cout << c.generateMixedEggs(); SetColor(WHITE); cout << " now!...";
			cin.ignore();
			return;
		}
		else {
			nothingHapens();
			return;
		}
	}
	else if (!item1.compare("mixed eggs and chips")) {
		if (!item2.compare("pan cooking onions and cod")) {
			c.deleteFromInventory(item1);
			c.deleteFromRoom(item2);
			system("CLS");
			SetColor(WHITE);
			cout << endl << endl << "\tYou use "; SetColor(GREEN); cout << item1; SetColor(WHITE); cout << " on "; SetColor(GREEN); cout << item2; SetColor(WHITE); cout << "...";
			cin.ignore();
			cout << "\tYou have "; SetColor(GREEN); cout << c.generateGoldenCod(); SetColor(WHITE); cout << " and there is a "; SetColor(GREEN); cout << c.generateDirtyPan(); SetColor(WHITE); cout << " now!...";
			cin.ignore();
			return;
		}
		else {
			nothingHapens();
			return;
		}
	}


}

void View::useItemsNPC(string item1, string item2,bool &OVER, int &end) 
{
	if (!item1.compare("knife")) {
		if (!item2.compare("Knight")) {
			system("CLS");
			SetColor(WHITE);
			cout << endl << endl << "\tYou try to stab the Knight with your knife but it does nothing to the armor...";
			cin.ignore();
			cout << endl << "\t\t Knight: "; SetColor(DARKGRAY); string dial = "Hahaha... you really thought you could hurt me with that?\n\t\t         That was funny... but now... PREPARE TO DIE!!!"; slowPrint(dial, CHARACTERS);
			cin.ignore();
			OVER = true;
			
		} 
		else if (!item2.compare("Little Prince")) {
			system("CLS");
			string name;
			SetColor(WHITE);
			cout << endl << endl << "\tThe little prince look at your eyes worried, you can almost hear his heartbeat accelerating...";
			cin.ignore();
			c.GetPlayerData(name);
			cout << endl << "\t\t Little Prince: "; SetColor(LIGHTCYAN); string dial = "What is that knife for, " + name + "? You would never hurt me, right?"; slowPrint(dial, CHARACTERS);
			cin.ignore();
			SetColor(WHITE);
			cout << endl << endl << "\tYou kill the little prince... You steal the main door key from his still warm hands...";
			cin.ignore();
			cin.ignore();
			cout << "\tYou have "; SetColor(RED); cout << c.generateMainDoorKey(); SetColor(WHITE); cout << " now...";
			cin.ignore();
			end = 2;

		}
		else {
			nothingHapens();
			return;
		}
	} 
	else if (!item1.compare("cod")){
		if (!item2.compare("Knight")) {
			system("CLS");
			SetColor(WHITE);
			cout << endl << endl << "\tYou slap the Knight in the face with the fresh cod...";
			cin.ignore();
			cout << endl << "\t\t Knight: "; SetColor(DARKGRAY); string dial = "Hahaha... you really thought you could hurt me with that?\n\t\t         That was funny... but now... PREPARE TO DIE!!!"; slowPrint(dial, CHARACTERS);
			cin.ignore();
			OVER = true;

		}
		else {
			nothingHapens();
		}
	}
	else if (!item1.compare("eggs")) {
		if (!item2.compare("Knight")) {
			system("CLS");
			SetColor(WHITE);
			cout << endl << endl << "\tYou throw the eggs to the Knight with all your stregths...";
			cin.ignore();
			cout << endl << "\t\t Knight: "; SetColor(DARKGRAY); string dial = "Hahaha... you really thought you could hurt me with that?\n\t\t         That was funny... but now... PREPARE TO DIE!!!"; slowPrint(dial, CHARACTERS);
			cin.ignore();
			OVER = true;

		}
		else {
			nothingHapens();
		}
	}
	else if (!item1.compare("oil")) {
		if (!item2.compare("Knight")) {
			system("CLS");
			SetColor(WHITE);
			cout << endl << endl << "\tYou spil oil all over the Knight...";
			cin.ignore();
			cout << endl << "\t\t Knight: "; SetColor(DARKGRAY); string dial = "Hahaha... you really thought you could hurt me with that?\n\t\t         That was funny... but now... PREPARE TO DIE!!!"; slowPrint(dial, CHARACTERS);
			cin.ignore();
			SetColor(WHITE);
			cout << endl << endl << "\tYou though you were dead... but the knight slips cause of the oil and falls over his own sword dying.";
			cin.ignore();
			cout << endl << "\tYou take advantage of the event to steal the keys from the knight...";
			cin.ignore();
			cout << "\tYou have "; SetColor(GREEN); cout << c.generateSilverKey(); SetColor(WHITE); cout << " now!...";
			cin.ignore();
			end = 1;

		}
		else {
			nothingHapens();
		}
	}
}

void View::containerCommandManager(string containerName) {
	
	string command;
	bool closed = false;

	while (!closed) {
		system("CLS");
		SetColor(BLUE);
		cout << endl << endl << "\t\t" << containerName;
		SetColor(WHITE);
		
		if (c.containerIsEmpty(containerName)) {
			cout << endl << endl << "\t\tIt is empty... " << endl << endl << endl;
			cout << "\tEnter a command >> ";
			SetColor(YELLOW);
			getline(cin, command);

			if (!command.find("Close")) {
				closed = true;
			}
			else {
				nothingHapens();
			}
		}
		else {

			string content = c.getContainerContentName(containerName);
			cout << endl << endl << "\t\t\tIt contains: ";
			SetColor(GREEN);
			cout << content << endl << endl << endl;
			SetColor(WHITE);
			cout << "\tEnter a command >> ";
			SetColor(YELLOW);
			getline(cin, command);

			if (!command.find("Close", 0)) {
				closed = true;
			}
			else if (!command.find("Pick up",0)) {
				string object = command;
				object.erase(0, 8);
				if(!object.compare(content)){
					c.pickUpFromContainer(containerName);
					system("CLS");
					SetColor(GREEN);
					cout << endl << "\t\t\t" << object;
					SetColor(WHITE);
					cout << " picked up!";
					cin.ignore();
				}
				else {
					nothingHapens();
				}
				
			}
			else if (!command.find("Examine", 0)) {
				system("CLS");
				string object = command;
				object.erase(0, 8);
				if (!object.compare(content)) {
					SetColor(BLUE);
					cout << endl << endl << "\t\t\t\t" << object;
					SetColor(WHITE);
					cout << endl << endl << c.getContainerContentDescription(containerName);
					cin.ignore();
				}
			}
			else {
				nothingHapens();
			}

		}
	
	}
}

void View::npcUI(string npcName)
{
	if (!npcName.compare("Knight")) {

		int stage = c.getNpcStage();

		switch (stage)
		{
			case 0: 
			{
				system("CLS");
				SetColor(WHITE);
				cout << endl << "\t\t Knight: "; SetColor(DARKGRAY); string dial = "Hahaha... so you want me to give you the key?\n\t\t         That was funny... but no... i can't trust you yet...\n\t\t         but maybe if you make me a favour i will.\n\t\t         You only need to cook my favourite meal ever for me.\n\t\t         I'll give you the recipe, just follow the steps."; slowPrint(dial, CHARACTERS);
				cin.ignore();
				SetColor(WHITE);
				cout << endl << "\tYou have "; SetColor(GREEN); cout << c.generateRecipe(); SetColor(WHITE); cout << " now!...";
				c.updateStage(1);
				cin.ignore();
				break;
			}
			case 1:
			{
				if (c.checkObjectOnInventory("golden cod")) {
					system("CLS");
					SetColor(WHITE);
					cout << endl << "\t\t Knight: "; SetColor(DARKGRAY); string dial = "Great job, that looks amazing! I can't wait to eat it...\n\t\t         As i promised i'll give you the key."; slowPrint(dial, CHARACTERS);
					cin.ignore();
					SetColor(WHITE);
					cout << endl <<"\tYou have "; SetColor(GREEN); cout << c.generateSilverKey(); SetColor(WHITE); cout << " now!...";
					c.updateStage(2);
					cin.ignore();
					break;
				}
				else {
					system("CLS");
					SetColor(WHITE);
					cout << endl << "\t\t Knight: "; SetColor(DARKGRAY); string dial = "Come back when you finish cooking..."; slowPrint(dial, CHARACTERS);
					cin.ignore();
					break;
				}
			}
			default:
				system("CLS");
				SetColor(WHITE);
				cout << endl << "\t\t Knight: "; SetColor(DARKGRAY); string dial = "Now go, i have nothing else to say..."; slowPrint(dial, CHARACTERS);
				cin.ignore();
				break;
		}
	}
	else if (!npcName.compare("Little Prince")) {

		int stage = c.getNpcStage();

		switch (stage)
		{
			case 0:
			{
				system("CLS");
				string name;
				c.GetPlayerData(name);
				SetColor(WHITE);
				cout << endl << "\t\t Little Prince: "; SetColor(LIGHTCYAN); string dial = "Oh, hey " + name + "... I was waiting for you...\n\t\t                I guess you want the key to get out of my castle... but...\n\t\t                first i need you to do me a favour...\n\t\t                I'd like you to go to the dark room downstairs and bring me what\n\t\t                is inside the box on the center of the room... \n\t\t                i'll give you the key when you bring it :D"; slowPrint(dial, CHARACTERS);
				c.updateStage(1);
				cin.ignore();
				break;
			}
			case 1:
			{
				if (c.checkObjectOnInventory("drawing")) {
					system("CLS");
					SetColor(WHITE);
					cout << endl << "\t\t Little Prince: "; SetColor(LIGHTCYAN); string dial = "That's what i wanted! Thanks thanks thanks thanks!.\n\t\t                This is the only memory i have from them since i moved from home...\n\t\t                Yes... they are my family... This bearded man here is my dad...\n\t\t                this lady here is my mom... this girl here is my sister...\n\t\t                and this little thing here is our dog, he's allways running around and maiking noise...\n\t\t                now that they are not here the house feels empty...\n\t\t                Thanks to you now i won't forget them.\n\n\t\t                Princes always keep their word so take this... "; slowPrint(dial, CHARACTERS);
					cin.ignore();
					SetColor(WHITE);
					cout << endl << "\tYou have "; SetColor(GREEN); cout << c.generateMainDoorKey(); SetColor(WHITE); cout << " now!...";
					c.updateStage(2);
					cin.ignore();
					cout << endl << endl << "\t\t Little Prince: "; SetColor(LIGHTCYAN); string dial2 = "Good luck out there! ...you'll need it."; slowPrint(dial2, CHARACTERS);
					cin.ignore();
					break;
				}
				else {
					system("CLS");
					SetColor(WHITE);
					cout << endl << "\t\t Little Prince: "; SetColor(DARKGRAY); string dial = "I'll give you the key when you bring me the content of the box..."; slowPrint(dial, CHARACTERS);
					cin.ignore();
					break;
				}
			}
			default:
				system("CLS");
				SetColor(WHITE);
				cout << endl << endl << "\t\t Little Prince: "; SetColor(LIGHTCYAN); string dial = "Good luck out there! ...you'll need it."; slowPrint(dial, CHARACTERS);
				cin.ignore();
				break;
		}
	}
}

void View::nothingHapens() {
	system("CLS");
	SetColor(WHITE);
	cout << endl << endl << "\tNothing happens...";
	cin.ignore();
}

void View::displayHelp() 
{
	system("CLS");
	SetColor(BLUE);
	cout << endl << "\tHELP:";
	SetColor(MAGENTA); cout << endl << endl << "\t\tGo to <ROOM NAME>"; SetColor(WHITE); cout << " -> "; SetColor(LIGHTGREEN); cout << "Go to another room.\n\t\t                      - If the door to that room is locked you have to unlock it first.";
	SetColor(MAGENTA); cout << endl << endl << "\t\tExamine <OBJECT NAME>"; SetColor(WHITE); cout << " -> "; SetColor(LIGHTGREEN); cout << "Display the description of an object or character.";
	SetColor(MAGENTA); cout << endl << endl << "\t\tPick up <OBJECT NAME>"; SetColor(WHITE); cout << " -> "; SetColor(LIGHTGREEN); cout << "Add an object from the room or the container to your inventory.";
	SetColor(MAGENTA); cout << endl << endl << "\t\tOpen <OBJECT NAME>"; SetColor(WHITE); cout << " -> "; SetColor(LIGHTGREEN); cout << "Open a container and see what is inside.\n\t\t                       -You have to examine an object before opening it.";
	SetColor(MAGENTA); cout << endl << endl << "\t\tClose <Object NAME>"; SetColor(WHITE); cout << " -> "; SetColor(LIGHTGREEN); cout << "Close the container and return to the room.";
	SetColor(MAGENTA); cout << endl << endl << "\t\tUse <OBJECT NAME> with <OBJECT/DOOR NAME"; SetColor(WHITE); cout << " -> "; SetColor(LIGHTGREEN); cout << "Trigger the interaction between an object\n\t\t                                            from your inventory and other object or door.";
	SetColor(MAGENTA); cout << endl << endl << "\t\tTalk to <CHARACTER NAME>"; SetColor(WHITE); cout << " -> "; SetColor(LIGHTGREEN); cout << "Starts a dialogue with a character.";
	SetColor(MAGENTA); cout << endl << endl << "\t\tList inventory"; SetColor(WHITE); cout << " -> "; SetColor(LIGHTGREEN); cout << "Display what you have in your inventory.";
	SetColor(MAGENTA); cout << endl << endl << "\t\tGive up"; SetColor(WHITE); cout << " -> "; SetColor(LIGHTGREEN); cout << "Ends the game by loosing.";

	cin.ignore();
}

void View::lose() {
	system("CLS");
	sndPlaySound(GAMEOVERL, SND_LOOP | SND_ASYNC);
	cout << endl << endl << endl;
	SetColor(BLUE);
	cout << "       __    __    ________    ___    ___          ___         ________    ________    ________    _______" << endl;
	cout << "       \\ \\  / /   |  ____  |  | _ |  | _ |        |   |       |  ____  |  |  ____  |  |   _____|  |  _____|" << endl;
	cout << "        \\\\\\///    | |    | |  | | |  | | |        |   |       | |    | |  | |    | |  |  |_____   |  |" << endl;
	cout << "         \\\\//     | |    | |  | | |  | | |        |   |       | |    | |  | |    | |  L_____   ]  |  |____" << endl;
	cout << "          \\/      | |    | |  | | |  | | |        |   |       | |    | |  | |    | |        ]  |  |   ____|" << endl;
	cout << "          \\/      | |    | |  | | |__| | |        |   |       | |    | |  | |    | |        |  |  |  |" << endl;
	cout << "          \\/      | |____| |  | |______| |        |   |____   | |____| |  | |____| |   _____|  |  |  |____" << endl;
	cout << "          \\/      |________|  |__________|        |________|  |________|  |________|  |________|  |_______|" << endl;
	SetColor(WHITE);
	cout << endl << endl << endl << endl << "\t\t\t\t\tCREATED BY: ALVARO ROSA GONZALEZ...";
	
	cin.ignore();
}

void View::win() {
	system("CLS");
	cout << endl << endl;
	SetColor(WHITE);
	string toPrint = "\t\tYou cross the main door... get blinded by a bright light... \n\t\tIt's the same light from before  when you woke up...\n\t\tNow you see it... it all makes sense.\n\t\tYou just woke up again, but this time you are not it a castle,\n\t\tyou are in your classroom in the MI Building!\n\t\tThe things around you gave you signals all the time,\n\t\tThe light from the computer... the carpet... the ground floor disposal...\n\n\t\t.- I think it's time to go home...";
	slowPrint(toPrint, DESCRIPTIONS);
	cin.ignore();
	system("CLS");
	sndPlaySound(WIN, SND_ASYNC | SND_LOOP);
	cout << endl << endl << endl;
	SetColor(GREEN);
	cout << "       __    __    ________    ___    ___          __          __    __    ___       _" << endl;
	cout << "       \\ \\  / /   |  ____  |  | _ |  | _ |        |  |        |  |  |  |  |   \\     | |" << endl;
	cout << "        \\\\\\///    | |    | |  | | |  | | |        |  |        |  |  |  |  | |\\ \\    | |" << endl;
	cout << "         \\\\//     | |    | |  | | |  | | |        |  |   __   |  |  |  |  | | \\ \\   | |" << endl;
	cout << "          \\/      | |    | |  | | |  | | |        |  |  |  |  |  |  |  |  | |  \\ \\  | |" << endl;
	cout << "          \\/      | |    | |  | | |__| | |        |  |  |  |  |  |  |  |  | |   \\ \\ | |" << endl;
	cout << "          \\/      | |____| |  | |______| |        |  |__|  |__|  |  |  |  | |    \\ \\| |" << endl;
	cout << "          \\/      |________|  |__________|        |______/\\______|  |__|  |_|     \\___|" << endl;
	SetColor(WHITE);
	cout << endl << endl << endl << endl << "\t\t\t\tCREATED BY: ALVARO ROSA GONZALEZ...";

	cin.ignore();
	cin.ignore();
}
void View::win1() {
	system("CLS");
	cout << endl << endl;
	SetColor(WHITE);
	string toPrint = "\t\tYou cross the main door... get blinded by a bright light... \n\t\tIt's the same light from before  when you woke up...\n\t\tNow you see it... it all makes sense.\n\t\tYou just woke up again, but this time you are not it a castle,\n\t\tyou are in your classroom in the MI Building!\n\t\tThe things around you gave you signals all the time,\n\t\tThe light from the computer... the carpet... the ground floor disposal...\n\n\t\t.- I think it's time to go home...";
	slowPrint(toPrint, DESCRIPTIONS);
	cin.ignore();
	system("CLS");
	sndPlaySound(WIN, SND_ASYNC | SND_LOOP);
	cout << endl << endl << endl;
	SetColor(YELLOW);
	cout << "       __    __    ________    ___    ___          __          __    __    ___       _" << endl;
	cout << "       \\ \\  / /   |  ____  |  | _ |  | _ |        |  |        |  |  |  |  |   \\     | |" << endl;
	cout << "        \\\\\\///    | |    | |  | | |  | | |        |  |        |  |  |  |  | |\\ \\    | |" << endl;
	cout << "         \\\\//     | |    | |  | | |  | | |        |  |   __   |  |  |  |  | | \\ \\   | |" << endl;
	cout << "          \\/      | |    | |  | | |  | | |        |  |  |  |  |  |  |  |  | |  \\ \\  | |" << endl;
	cout << "          \\/      | |    | |  | | |__| | |        |  |  |  |  |  |  |  |  | |   \\ \\ | |" << endl;
	cout << "          \\/      | |____| |  | |______| |        |  |__|  |__|  |  |  |  | |    \\ \\| |" << endl;
	cout << "          \\/      |________|  |__________|        |______/\\______|  |__|  |_|     \\___|" << endl;
	SetColor(WHITE);
	cout << endl << endl << endl << endl << "\t\t\t\tCREATED BY: ALVARO ROSA GONZALEZ...";

	cin.ignore();
	cin.ignore();
}
void View::win2() {
	system("CLS");
	cout << endl << endl;
	SetColor(WHITE);
	string toPrint = "\t\tYou cross the main door... get blinded by a bright light... \n\t\tIt's the same light from before  when you woke up...\n\t\tNow you see it... it all makes sense.\n\t\tYou just woke up again, but this time you are not it a castle,\n\t\tyou are in your classroom in the MI Building!\n\t\tThe things around you gave you signals all the time,\n\t\tThe light from the computer... the carpet... the ground floor disposal...\n\n\t\t.- I think it's time to go home...";
	slowPrint(toPrint, DESCRIPTIONS);
	cin.ignore();
	system("CLS");
	sndPlaySound(WIN, SND_ASYNC | SND_LOOP);
	cout << endl << endl << endl;
	SetColor(RED);
	cout << "       __    __    ________    ___    ___          __          __    __    ___       _" << endl;
	cout << "       \\ \\  / /   |  ____  |  | _ |  | _ |        |  |        |  |  |  |  |   \\     | |" << endl;
	cout << "        \\\\\\///    | |    | |  | | |  | | |        |  |        |  |  |  |  | |\\ \\    | |" << endl;
	cout << "         \\\\//     | |    | |  | | |  | | |        |  |   __   |  |  |  |  | | \\ \\   | |" << endl;
	cout << "          \\/      | |    | |  | | |  | | |        |  |  |  |  |  |  |  |  | |  \\ \\  | |" << endl;
	cout << "          \\/      | |    | |  | | |__| | |        |  |  |  |  |  |  |  |  | |   \\ \\ | |" << endl;
	cout << "          \\/      | |____| |  | |______| |        |  |__|  |__|  |  |  |  | |    \\ \\| |" << endl;
	cout << "          \\/      |________|  |__________|        |______/\\______|  |__|  |_|     \\___|" << endl;
	SetColor(WHITE);
	cout << endl << endl << endl << endl << "\t\t\t\tCREATED BY: ALVARO ROSA GONZALEZ...";

	cin.ignore();
	cin.ignore();
}


