//This file will contain some data structure for a parsed json object
#include <vector>
#include <string>

const std::string events[] = {"eventWhenFlagClicked"}; //Stores valid strings for events should be in parser.hpp

class eventStarter { // Used for things like eventWhenFlagClicked probably should be in parser.hpp
	public:
		std::string event;
		stdChnk* nxtptr = nullptr;
};

class rstdChnk {
	public:
	stdChnk* nxtptr = nullptr;
};

class stdChnk { // Used to store a block of code from the scratch "standard library" (maybe I should make a standard library for scratch)
	public:
		// Not sure if this is needed because everything is basically a function call or a varible setting
		// Could be used to store inside of a loop to provide a type wrapper around func calls and varible expressions
		bool inACondition;
		bool inARepeatUntil;
		bool inARepeatNum;
		bool inAnElse;
		funcCall func; // Can call functions like: somefunc(); withour using its retrun value (if it has one). Very good for messages.
		express ex; // Can be like x = 2 or x = y or x = somefunc();
		rstdChnk* nxtptr = nullptr;
};

class funcdef { // Used for message brodcasts and "my blocks"
	private:
		std::string returntype;
		std::string funcname;
		stdChnk* nxtptr = nullptr;
};

class ifThen {
	bexpress condition; //Used to paste into the statement but must be boolean so maybe make a bool express class
	stdChnk* nxtptr = nullptr;
}; // Also can use an else

class repeatWNum {
	bexpress condition;
	stdChnk* nxtptr = nullptr;
}; // Can be a while true also

class repeatUntil { // Used for loops
	bexpress condition;
	stdChnk* nxtptr = nullptr;
}; 

//template<typename T, int S> // Using a template for S may not be good becuase we dont know the value at compile time
class funcCall { // Calls a function
	public:
		std::string funcName;
		std::vector<express> args; // It would be better I could instead make a stack allocated array at runtime
		double return1;
		bool return2; // Maybe not needed because scratch doesnt really have bools, they are either represented as 1, 0, or a string
		std::string return3;
		bool hasReturn; // Need to have a way to store return types and values or have it be used in an expression
		// Maybe make a different class for void boolean and other functions
};

class bexpress { // Used for if statements and while loops and the sort that need boolean expressions. like if ("x==2") {}, the part in quotes is a boolean expression
	char op1;
	char op2;
	funcCall func1;
	funcCall func2;
	express exp1;
	express exp2;
	var var1;
	var var2;
};

class list {
	// Used for which will just be a singly linked list from the stl
};

class express { // Used as number values. like x = sqrt(4); is an expression
	public:
		// Expressions will most likley be "copy pasted" into code
		char op; // Used for + - / * etc
		char op2; // Optionally used for logical or boolean operators like == && ||
		funcCall func; // Used if a value is a function
		funcCall func2; // Also very recursive stuff going on here
		var var1; // Used if there is a varible in an expression
		var var2;
		//express operand1; // Used for nestled expressions
		//express operand2; // Maybe make these pointers
};

class var {
	public:
		std::string name;
		std::string id;
};

typedef struct { // Used to store global variables and functions and stuff
	public:
		std::vector<var> globalVars;
		//std::vector<funcCall> funcs; // I need to stop using this many templates tha I cant evaluate at compile time
} globalObjects;

class sprite {
	private:
		bool isshown;
		//std::vector<script> scripts;
		std::vector<std::string> costumes; //Contains the paths to the costumes
		std::vector<var> vars;
		int costumeshown;
		void reload_appearance () {
			//Switches the costume to the current costume and calls some kind of renderer function
		}
	public:
		std::string get_costume (int index) {
			return costumes[index];
		}
		//std::string get_var (int index) {
			//return vars[index];
		//}
		std::string get_current_costume () {
			return costumes[costumeshown];
		}
		void switch_costume (int costume) {
			costumeshown = costume;
			reload_appearance();
		}
		void add_costume (std::string tstring) {
			costumes.push_back(tstring);
		}
		//void add_var (std::string tstring) {
			//vars.push_back(tstring);
		//}
		void change_shown (bool shown) {
			isshown = shown;
			reload_appearance();
		}
};

class backdrop {
	private:
		std::vector<std::string> backdrops;
		int backdropshown;
		void reload_backdrop () {
			
		}
	public:
		void switch_backdrop (int bckdrp) {
			backdropshown = bckdrp;
			reload_backdrop();
		}
		void add_backdrop (std::string tstring) {
			backdrops.push_back(tstring);
		}
		std::string get_current_backdrop () {
			return backdrops[backdropshown];
		}
		std::string get_backdrop (int index) {
			return backdrops[index];
		}
};

class project {
    public:
		std::vector<std::string> globalVars;
    	std::vector<sprite> sprites;
    	backdrop background;
		globalObjects globals;
};