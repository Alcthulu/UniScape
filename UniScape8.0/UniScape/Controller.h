#ifndef __CONTROLLER_H
#define __CONTROLLER_H


#include "Model.h"


class Controller {

	private:
		Model m;
		Room Iam;

	public:

		//
		//
		//
		void NewPlayer(string name);
		void GetPlayerData(string & name);
		
		int GenerateMap();
		int generateStart();
		int generateGroundCorridor();
		int generateLetrine();
		int generateFirstFloorCorridor();
		int generateDarkRoom();
		int generateKitchen();
		int generatePrinceRoom();
		int generateExit();

		string generateSlicedOnions();
		string generateSlicedPotatoes();
		string generateCrumbledCod();
		string generateMixedEggsAndChips();
		string generateHotPan();
		string generatePanReadyToCook();
		string generateChips();
		string generatePanCookingOnions();
		string generatePanCookingOnionsAndCod();
		string generateBowlOfEggs();
		string generateMixedEggs();
		string generateGoldenCod();
		string generateDirtyPan();
		string generateSilverKey();
		string generateMainDoorKey();
		string generateRecipe();
		

		void setIam(string roomName);

		string getRoomDescription();
		string getObjectDescription(string objectName);
		string getObjectDescriptionInventory(string objectName);
		string getObjectInteractionCode(string objectName);
		string getContainerDescription(string containerName);
		string getDoorInteractionCode(string objectName);
		string getNpcDescription();
		int checkToRoom(string toRoom);
		int checkDoor(string toRoom);
		bool checkObject(string objectName);
		bool checkObjectOnInventory(string objectName);
		bool checkContainer(string containerName);
		bool checkNPC(string npcName);
		bool containerExamined(string toOpen);
		bool containerIsEmpty(string containerName);
		bool canBePickedUp(string objectName);
		string getContainerContentName(string containerName);
		string getContainerContentDescription(string containerName);
		void deleteFromInventory(string objectName);
		void deleteFromRoom(string objectName);
		void pickUpFromContainer(string containerName);
		void pickUpFromRoom(string objectName);
		void addToInventory(Object toAdd);
		void addObjectToRoom(Object toAdd);
		void unlockDoor(string doorID);
		string inventoryDisplay();
		string roomDisplay();
		int getNpcStage();
		void updateStage(int stage);
};


#endif // !__CONTROLLER_H
