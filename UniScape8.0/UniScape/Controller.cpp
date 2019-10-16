#include "Controller.h"


void Controller::NewPlayer(string name)
{
	this->m.NewPlayer(name);
}

void Controller::GetPlayerData(string &name) 
{
	this->m.GetPlayerData(name);
}


//
//   MAP GENERATOR
//

int Controller::GenerateMap()
{

	generateStart();
	generateGroundCorridor();
	generateLetrine();
	generateFirstFloorCorridor();
	generateDarkRoom();
	generateKitchen();
	generatePrinceRoom();

	return 0;
}
int Controller::generateStart()
{

	// GENERATE OBJECTS:

	// KEY1 -> OPENS THE DOOR TO THE CORRIDOR
	Object key1 ("old key",                "                   An old rusty iron wrench.", true, "corriDoor1");
	// KEY2
	Object key2 ("gold coin",              "                   A shiny gold coin with your face engraved on one side\n                   and a bunny on the other, seems useless.", true);
	// MISCELLANEOUS:
	Object window ("stained glass window", "                   A beautiful window of stained glass. By looking more\n                   closely you realize something. The drawing on the\n                   window is not just any design. In the artwork you\n                   can see two people, they look at each other with love,\n                   but they seem sad. One of them is in a higher place\n                   than the other, the colors around it are more alive\n                   and bright, but, they go fading and becoming more and\n                   more sad and dark the closer they come to the other\n                   person. When you look closely at it's face... it looks\n                   like you! and the other... the other one looks like...\n                   no way, you are just dizzy.");
	Object carpet ("tapestry",             "                   I know the drawing of that tapestry. It tells the fable\n                   of the stray sheep. The tapestry is composed of several\n                   scenes. Scene 1: the sheep walks with the flock through\n                      a green meadow. Scene 2: the herd goes to cross a\n                    valley through the lower part, but the protagonist of\n                   the story, the sheep with a more grayish wool, realizes\n                   that there are some rocks about to detach from the wall\n                   of the valley. Scene 3: The sheep tries to convince the\n                   rest of them to climb the mountain and avoid the valley,\n                   telling them that if they follow that road they run a\n                   serious danger. Scene 4: our protagonist has been left\n                   behind, thinking whether to follow the others despite the\n                   danger or venture to go alone on the other path despite\n                   how terrorific that is and take responsibility for\n                   deciding for itself, but still has the option of reaching\n                   the flock. Scene 5: finally the intrepid stray decides to\n                   be guided by its conscience and to return home for the\n                   terrifying and lonely path of the mountain. Scene 6: the\n                   gray wool sheep finally arrives home, it is already night\n                   and it arrives tired, but upon arriving he realizes the\n                   wisdom of his decision to see that only half of the herd\n                   has survived the other way.");

	// GENERATE DOORS:

	// ONLY VISIBLE DOOR
	Door gCorridor ("Door to Ground Corridor", "Start Room", "Ground Corridor", true, "corriDoor1");

	// GENERATE CONTAINERS:

	Container drawer1 ("left drawer", "                   Just a common wooden drower, looks like it can be opened.", false, key1);
	Container drawer2 ("right drawer", "                   Just a common wooden drower, looks like it can be opened.", false, key2);

	// CREATE LISTS:

	vector<Object> objects;
	
		objects.push_back(window);
		objects.push_back(carpet);

	vector<Container> containers;

		containers.push_back(drawer1);
		containers.push_back(drawer2);

	vector<Door> doors;

		doors.push_back(gCorridor);
	

	// GENERATE ROOM:

	Room start("Start Room", "\n\n                   You are in a big room with a high roof. From the door to the ground\n                   corridor, on the right, there is a big double sized bed, where you\n                   woke up. On the left, there is a big dressing table.", objects, containers, doors);
                                                                                                                                                                                                                                                                                                                                                                                                                                  
	// ADD ROOM TO MODEL

	m.AddRoom(start);
	
	return 0;
}
int Controller::generateGroundCorridor() {

	// GENERATE OBJECTS:

	// MISCELLANEOUS:
	Object armors("armors",  "                   They look like the armors on the museums, but much\n                   better condition. I think they are handmade, but\n                   that make them cooler...");
	Object banners("banners","                   Some of the flags only have some colors while others\n                   have some kind of blazon, i wonder what's it's meaning...");
	// GENERATE DOORS:

	Door sRoom("Door to Start Room", "Ground Corridor", "Start Room");
	Door toLetrine("Door to Letrine", "Ground Corridor", "Letrine");
	Door firstFloorCorridor("Stairs to First Floor Corridor", "Ground Corridor", "First Floor Corridor");
	// DOOR TO THE VICTORY:
	Door victory("Door to the Outside", "Ground Corridor", "the Outside", true, "WinKey");

	// GENERATE CONTAINERS:


	// CREATE LISTS:

	vector<Object> objects;
	
		objects.push_back(armors);
		objects.push_back(banners);

	vector<Container> containers;

	vector<Door> doors;
		
		doors.push_back(sRoom);
		doors.push_back(toLetrine);
		doors.push_back(victory);
		doors.push_back(firstFloorCorridor);


	// GENERATE ROOM:

	Room gC("Ground Corridor", "\n\n                   It's a huge corridor but it's dark in here. The only light comes from\n                   the torches hanging on the stone walls and from some windows over a\n                   big door at one end of the corridor.", objects, containers, doors);

	// ADD ROOM TO MODEL

	m.AddRoom(gC);

	return 0;
}
int Controller::generateLetrine() {

	// GENERATE OBJECTS:

	// MISCELLANEOUS:
	Object clothes("dry clothes", "                   I guess they use them to dry their hands after whashing them...");
	Object vessels("water vessels", "                   So that's what they use here to wash their hands afer using the letrine...");
	Object hole("hole on the floor", "                   It doesn't look like i fit thru there but anyways i'm not using that...");
	// GENERATE DOORS:

	Door gCorridor("Door to Ground Corridor", "Letrine", "Ground Corridor");

	// GENERATE CONTAINERS:


	// CREATE LISTS:

	vector<Object> objects;

		objects.push_back(vessels);
		objects.push_back(clothes);
		objects.push_back(hole);

	vector<Container> containers;

	vector<Door> doors;

		doors.push_back(gCorridor);



	// GENERATE ROOM:

	Room letrine("Letrine", "\n\n                   You are in a small dark room only iluminated by one torch.", objects, containers, doors);

	// ADD ROOM TO MODEL

	m.AddRoom(letrine);

	return 0;
}
int Controller::generateFirstFloorCorridor() {

	// GENERATE OBJECTS:

	// MISCELLANEOUS:
	
	// GENERATE DOORS:

	Door gCorridor("Stairs to Ground Corridor", "First Floor Corridor", "Ground Corridor");
	Door kitchen("Door to Kitchen", "First Floor Corridor", "Kitchen");
	Door darkRoom("Door to Dark Room", "First Floor Corridor", "Dark Room");
	Door princeRomm("Stairs to Little Prince\'s Room", "First Floor Corridor", "Little Prince's Room", true, "Chef");

	// GENERATE CONTAINERS:


	// CREATE LISTS:

	vector<Object> objects;

	vector<Container> containers;

	vector<Door> doors;

		doors.push_back(gCorridor);
		doors.push_back(kitchen);
		doors.push_back(darkRoom);
		doors.push_back(princeRomm);

	// GENERATE NPC:

	NPC knight("Knight", "                   It's a medieval knight. He has a shiny silver armor with the coolest helmet\n                   i've ever seen. He is holding a great sword with his right and a big shield\n                   with his left. On the middle of the shield i can see a rose drawn.", 0);



	// GENERATE ROOM:

	Room fCorridor("First Floor Corridor", "\n\n                   It's a really simple straight corridor. It's full of windows on the sides\n                   and it has a long red carpet from the stairs to the door in front of them.", objects, containers, doors, knight);

	// ADD ROOM TO MODEL

	m.AddRoom(fCorridor);

	return 0;
}
int Controller::generateDarkRoom() {

	// GENERATE OBJECTS:

	// LITTLE PRINCE'S DRAW:
	
	Object drawing("drawing", "                   In the drawing you can see a man and a woman with\n                   a small boy and a slightly taller girl, maybe she's\n                   a bit older. There is also some kind of animal near\n                   them. They are all smiling. ", true, "");
	
	// MISCELLANEOUS:


	// GENERATE DOORS:

	Door firstFloorCorridor("Door to First Floor Corridor", "Dark Room", "First Floor Corridor");
	
	// GENERATE CONTAINERS:

	Container box("small purple box", "                   Just a small purple box. It can be opened.", false, drawing, "");

	// CREATE LISTS:

	vector<Object> objects;

	vector<Container> containers;

		containers.push_back(box);

	vector<Door> doors;

		doors.push_back(firstFloorCorridor);
	


	// GENERATE ROOM:

	Room darkRoom("Dark Room", "\n\n                   Everything is dark.", objects, containers, doors);

	// ADD ROOM TO MODEL

	m.AddRoom(darkRoom);

	return 0;
}
int Controller::generateKitchen() {

	// GENERATE OBJECTS:


	// KITCHEN UTENSILS:

	Object knife("knife", "                   Big kitchen knife. I can use it to cut food or to \"skip the job\"...", true, "");
	Object fork("fork", "                   Just a normal fork...", true, "");
	Object firewood("firewood", "                   I can use it to light a fire...", true, "");
	Object bowl("bowl", "                   I can throw things inside...", false, "");
	Object pan("pan", "                   I can cook with it...", false, "");

	// INGREDIENTS:

	Object eggs("eggs", "                   Just eggs...", true, "");
	Object onions("onions", "                   Just onions...", true, "");
	Object potatoes("potatoes", "                   Just potatoes... \\_(^.^)_/", true, "");
	Object oil("oil", "                   A bottle of oil. I'd say it's virgin...", true, "");
	Object cod("cod", "                   Fresh cod of the best quality...", true, "");

	// MISCELLANEOUS:


	// GENERATE DOORS:

	Door firstFloorCorridor("Door to First Floor Corridor", "Dark Room", "First Floor Corridor");

	// GENERATE CONTAINERS:

	Container lefBasket("left basket", "                   Straw basket. I can open it...", false, eggs, "");
	Container midBasket("middle basket", "                   Straw basket. I can open it...", false, onions, "");
	Container rightBasket("right basket", "                   Straw basket. I can open it...", false, potatoes, "");

	// CREATE LISTS:

	vector<Object> objects;

		objects.push_back(knife);
		objects.push_back(fork);
		objects.push_back(firewood);
		objects.push_back(bowl);
		objects.push_back(oil);
		objects.push_back(cod);
		objects.push_back(pan);

	vector<Container> containers;

		containers.push_back(lefBasket);
		containers.push_back(midBasket);
		containers.push_back(rightBasket);

	vector<Door> doors;

		doors.push_back(firstFloorCorridor);



	// GENERATE ROOM:

	Room kitchen("Kitchen", "\n\n                   This is the biggest kitchen i've ever seen!...", objects, containers, doors);

	// ADD ROOM TO MODEL

	m.AddRoom(kitchen);

	return 0;
}
int Controller::generatePrinceRoom() {

	// GENERATE OBJECTS:


	// MISCELLANEOUS:


	// GENERATE DOORS:

	Door firstFloorCorridor("Stairs to First Floor Corridor", "Little Prince\'s Room", "First Floor Corridor");

	// GENERATE CONTAINERS:


	// CREATE LISTS:

	vector<Object> objects;

	vector<Container> containers;

	vector<Door> doors;

	doors.push_back(firstFloorCorridor);

	// GENERATE NPC:

	NPC	prince("Little Prince", "                   It's a little boy. He is wearing a blue pijama and a silver crown.\n                   He is playing with some toys on a corner of the room", 0);

	// GENERATE ROOM:

	Room princeRoom("Little Prince\'s Room", "\n\n                   This is a small room, but it's cozy, it almost feels like home. The walls\n                   are blue and orange, there is a small bed with lots of stuffed animals over\n                   the sheets. It's a bit messy but it's a happy mess, a floor full of toys and\n                   drawings... seems like the prince has been having fun lately...", objects, containers, doors, prince);

	// ADD ROOM TO MODEL

	m.AddRoom(princeRoom);

	return 0;
}
int Controller::generateExit() {
	Room exit("the Outside", "", vector<Object>(), vector<Container>(), vector<Door>());
	m.AddRoom(exit);
	return 0;
}

string Controller::generateSlicedOnions() 
{
	Object slicedOnions = Object("sliced onions", "                   Sliced onions...", true, "");
	addToInventory(slicedOnions);
	return slicedOnions.getName();
}
string Controller::generateSlicedPotatoes() 
{
	Object slicedPotatoes = Object("sliced potatoes", "                   Sliced potatoes...", true, "");
	addToInventory(slicedPotatoes);
	return slicedPotatoes.getName();
}
string Controller::generateCrumbledCod() 
{
	Object crumbledCod = Object("crumbled cod", "                   Crumbled cod...", true, "");
	addToInventory(crumbledCod);
	return crumbledCod.getName();
}
string Controller::generateMixedEggsAndChips()
{
	Object mixedEggsAndChips = Object("mixed eggs and chips", "                   Chips mixed with eggs...", true, "");
	addToInventory(mixedEggsAndChips);
	return mixedEggsAndChips.getName();
}
string Controller::generateHotPan()
{
	Object hotPan = Object("hot pan", "                   A hot pan, i should put some oil in it before it burns...", false, "");
	addObjectToRoom(hotPan);
	return hotPan.getName();
}
string Controller::generatePanReadyToCook()
{
	Object panReadyToCook = Object("pan ready to cook", "                   A pan ready to cook, it's time to make something tasty...", false, "");
	addObjectToRoom(panReadyToCook);
	return panReadyToCook.getName();
}
string Controller::generateChips()
{
	Object chips = Object("chips", "                   Some chips. They have to taste good like this but better wait to finish the dish...", true, "");
	addToInventory(chips);
	return chips.getName();
}
string Controller::generatePanCookingOnions()
{
	Object panCookingOnions = Object("pan cooking onions", "                   A pan with some onion slices cooking inside, it makes my eyes cry...", false, "");
	addObjectToRoom(panCookingOnions);
	return panCookingOnions.getName();
}
string Controller::generatePanCookingOnionsAndCod()
{
	Object panCookingOnionsAndCod = Object("pan cooking onions and cod", "                   A pan with some onion slices and cod cooking inside, it smells delicious...", false, "");
	addObjectToRoom(panCookingOnionsAndCod);
	return panCookingOnionsAndCod.getName();
}
string Controller::generateBowlOfEggs()
{
	Object bowlOfEggs = Object("bowl of eggs", "                   A bowl full of eggs. I should mix them...", false, "");
	addObjectToRoom(bowlOfEggs);
	return bowlOfEggs.getName();
}
string Controller::generateMixedEggs()
{
	Object mixedEggs = Object("mixed eggs", "                   Mixed eggs, ready for the chips...", true, "");
	addToInventory(mixedEggs);
	return mixedEggs.getName();
}
string Controller::generateGoldenCod()
{
	Object goldenCod = Object("golden cod", "                   It looks and smells so good i just want to eat it all...", false, "");
	addToInventory(goldenCod);
	return goldenCod.getName();
}
string Controller::generateDirtyPan()
{
	Object dirtyPan("dirty pan", "                   Someone should clean it...", false, "");
	addObjectToRoom(dirtyPan);
	return dirtyPan.getName();
}
string Controller::generateSilverKey()
{
	Object silverKey = Object("silver key", "                   Now i can go to the little prince's room...", true, "Chef");
	addToInventory(silverKey);
	return silverKey.getName();
}
string Controller::generateMainDoorKey()
{
	Object mainKey = Object("main door key", "                   Now i can finally exit this place...", true, "WinKey");
	addToInventory(mainKey);
	return mainKey.getName();
}
string Controller::generateRecipe()
{
	Object recipe = Object("recipe", "                   1.- Take a knife and slice some potatoes.\n                   2.- Fry the potatoes in a pan to make chips.\n                   3.- Take some eggs and mix them in a bowl.\n                   4.- Mix the eggs with the chips and save for later.\n                   5.- With the knife slice some onions and cook them.\n                   6.- Make cod crumbles with the knife.\n                   7.- Add the cod crumbles to the pan with the onions.\n                   8.- Add the mixed eggs with chips to the pan.\n                   9.- Eat it!", true, "");
	addToInventory(recipe);
	return recipe.getName();
}


void Controller::setIam(string roomName) 
{
	this->Iam = m.getRoom(roomName);
}

string Controller::getRoomDescription()
{
	return this->Iam.getDescription();
}

string Controller::getObjectDescription(string objectName) 
{
	Object o = Iam.getObject(objectName);
	return o.getDescription();
}

string Controller::getObjectDescriptionInventory(string objectName)
{

	vector<Object> invent = m.getInventory();
	
	for (unsigned int i = 0; i < invent.size(); i++) {
		if (!invent[i].getName().compare(objectName)) return invent[i].getDescription();
	}

}

string Controller::getObjectInteractionCode(string objectName)
{
	vector<Object> invent = m.getInventory();
	if (!invent.empty()) {
		for (unsigned int i = 0; i < invent.size(); i++) {
			if (!(invent[i].getName().compare(objectName))) {
				return invent[i].getInteractionCode();
			}
		}
	}
	else {
		return "";
	}
}

string Controller::getContainerDescription(string containerName) 
{
	Container c = Iam.getContainer(containerName);
	c.setExamined(true);
	Iam.updateContainer(c);
	m.updateRoom(Iam);
	return c.getDescription();
}

string Controller::getDoorInteractionCode(string objectName)
{
	vector<Door> doors = Iam.getDoors();
	for (unsigned int i = 0; i < doors.size(); i++) {
		if (!doors[i].getId().compare(objectName)) { 
			string code = doors[i].getInteractionCode(); 
			return code;

		}
	}

}
string Controller::getNpcDescription()
{
	return this->Iam.getNPC().getDescription();
}

int Controller::checkToRoom(string toRoom)
{
	vector<Door> doors = Iam.getDoors();
	for (unsigned int i = 0; i < doors.size(); i++) {
		if (!doors[i].getTo().compare(toRoom)) {
			if (doors[i].getLocked()) {
				return 0;
			}
			else {
				return 1;
			}
		}
	}
	return -1;
}

int Controller::checkDoor(string doorName)
{
	vector<Door> doors = Iam.getDoors();
	for (unsigned int i = 0; i < doors.size(); i++) {
		if (!doors[i].getId().compare(doorName)) {
			if (doors[i].getLocked()) {
				return 0;
			}
			else {
				return 1;
			}
		}
	}
	return -1;
}

bool Controller::checkObject(string objectName)
{
	vector<Object> invent = Iam.getObjects();
	if (invent.empty()) return false;
	else {
		for (unsigned int i = 0; i < invent.size(); i++) {
			if (!invent[i].getName().compare(objectName)) return true;
		}
	}
	return false;
}

bool Controller::checkObjectOnInventory(string objectName)
{
	vector<Object> invent = m.getInventory();
	if (!invent.empty()){
		for (unsigned int i = 0; i < invent.size(); i++) {
			if (!(invent[i].getName().compare(objectName))) {
				return true;
			}
		}
		return false;
	}
	else {
		return false;
	}
}

bool Controller::checkContainer(string containerName)
{
	if (Iam.getContainer(containerName).getName().compare("")) {
		return true;
	}else {
		return false;
	}
}

bool Controller::checkNPC(string npcName)
{
	if (Iam.getNPC().getName().compare(npcName)) return false;
	else return true;
}

bool Controller::containerExamined(string toOpen)
{
	return Iam.getContainer(toOpen).getExamined();
}

bool Controller::containerIsEmpty(string containerName)
{
	if (Iam.getContainer(containerName).getContent().getName().compare("")) return false;
	else return true;
}

bool Controller::canBePickedUp(string objectName)
{
	return Iam.getObject(objectName).getPick();
}

string Controller::getContainerContentName(string containerName)
{
	Object o = Iam.getContainer(containerName).getContent();
	return o.getName();
}

string Controller::getContainerContentDescription(string containerName)
{
	Object o = Iam.getContainer(containerName).getContent();
	return o.getDescription();
}

void Controller::deleteFromInventory(string objectName) {
	vector<Object> invent = m.getInventory();

	for (unsigned int i = 0; i < invent.size(); i++) {
		if (!invent[i].getName().compare(objectName)) {
			for (unsigned int j = i; j < invent.size() - 1; j++) {
				invent[j] = invent[j + 1];
			}
			invent.pop_back();
		}
	}
	m.updateInventory(invent);
}

void Controller::deleteFromRoom(string objectName) {
	Iam.substractObject(objectName);
	m.updateRoom(Iam);
}

void Controller::pickUpFromContainer(string containerName)
{
	Container c = Iam.getContainer(containerName);
	Object toAdd = c.getContent();
	c.setContent(Object());
	Iam.updateContainer(c);
	m.updateRoom(Iam);
	addToInventory(toAdd);

}

void Controller::pickUpFromRoom(string objectName)
{
	Object toAdd = Iam.substractObject(objectName);
	m.updateRoom(Iam);
	addToInventory(toAdd);
}

void Controller::addToInventory(Object toAdd)
{
	vector<Object> invent = m.getInventory();
	invent.push_back(toAdd);
	m.updateInventory(invent);
}

void Controller::addObjectToRoom(Object toAdd)
{
	vector<Object> ob = Iam.getObjects();
	ob.push_back(toAdd);
	Iam.setObjects(ob);
	m.updateRoom(Iam);
}

void Controller::unlockDoor(string doorID) {
	vector<Door> doors = Iam.getDoors();
	for (unsigned int i = 0; i < doors.size(); i++) {
		if (!doors[i].getId().compare(doorID)) {
			doors[i].setLocked(false);
		}
	}
	Iam.setDoors(doors);
	m.updateRoom(Iam);
}

string Controller::inventoryDisplay()
{
	vector<Object> invent = m.getInventory();
	string Display = "";
	if (invent.size() > 0) {
		for (unsigned int i = 0; i < invent.size(); i++) {
			Display += "\n\t\t\t" + invent[i].getName();
		}
	}
	else {
		Display = "\t\t\tIt's empty! :(";
	}

	return Display;
}

string Controller::roomDisplay()
{
	string Display = "";
	vector<Object> objects = Iam.getObjects();
	vector<Container> containers = Iam.getContainers();
	vector<Door> doors = Iam.getDoors();
	NPC npc = Iam.getNPC();
	if (objects.size() + containers.size() + doors.size() < 1) {
		return "nothing relevant...";
	}
	else {
		for (unsigned int i = 0; i < objects.size(); i++) {
			Display += "\n\t\t\t" + objects[i].getName();
		}
		for (unsigned int i = 0; i < containers.size(); i++) {
			Display += "\n\t\t\t" + containers[i].getName();
		}
		for (unsigned int i = 0; i < doors.size(); i++) {
			Display += "\n\t\t\t" + doors[i].getId();
		}
	}
	if (npc.getName().compare("")) Display += "\n\t\t\t" + npc.getName();

	return Display;
}

int Controller::getNpcStage()
{
	return Iam.getNPC().getStage();
}

void Controller::updateStage(int stage)
{
	NPC  npc = Iam.getNPC();
	npc.setStage(stage);
	Iam.setNPC(npc);
	m.updateRoom(Iam);

}
