#ifndef __OBJECT_H
#define __OBJECT_H



#include <string>

using namespace std;

class Object {

	private:

		string name;
		string description;
		bool pick;
		string interactionCode ;

	public:

	// CONSTRUCTORS:

		Object();
		Object(string name, string description, bool pick = false, string interactionCode = "");

	// GETTERS:

		string getName();
		string getDescription();
		bool getPick();
		string getInteractionCode();

	// SETTERS:

		void setName(string name);
		void setDescription(string description);
		void setPick(bool pick);
		void setInteractionCode(string interactionCode);

};

#endif // !OBJECT__H