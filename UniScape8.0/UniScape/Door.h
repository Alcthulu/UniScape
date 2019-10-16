#ifndef __DOOR_H
#define __DOOR_H

#include <string>

using namespace std;

class Door {

	private:

		string id;
		string from;
		string to;
		bool locked;
		string interactionCode;

	public:

	// CONSTRUCTORS:

		Door();
		Door(string id, string from, string to, bool locked = false, string interactionCode = "");
		
	// GETTERS:

		string getId();
		string getFrom();
		string getTo();
		bool getLocked();
		string getInteractionCode();

	// SETTERS:

		void setId(const string &id);//////////WHY WAS IT BETTER????//////////
		void setFrom(string from);
		void setTo(string to);
		void setLocked(bool locked);
		void setInteractionCode(string interactionCode);



};

#endif