#ifndef __CONTAINER_H
#define __CONTAINER_H

#include <string>
#include "Object.h"
#include "Door.h"

using namespace std;

class Container {

	private:

		string name;
		string description;
		bool examined;
		string interactionCode;
		Object content;

	public:

	// CONSTRUCTOR:

		Container();
		Container(string name, string description, bool examined, Object content = Object(), string interactionCode = "");
		
	// GETTERS:

		string getName();
		string getDescription();
		bool getExamined();
		string getInteractionCode();
		Object getContent();

	// SETTERS:

		void setName(string name);
		void setDescription(string description);
		void setExamined(bool examined);
		void setInteractionCode(string interactionCode);
		void setContent(Object content);


};

#endif