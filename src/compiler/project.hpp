//This file will contain some data structure for a parsed json object
#include<vector>
#include<string>

const std::string events[] = {"eventWhenFlagClicked"}; //Stores valid strings for events

template<typename T>
class eventStarter { // Used for things like eventWhenFlagClicked probably should be in parser.hpp
	public:
		std::string event;
		T* nxtptr = nullptr;
};

template<typename T>
class stdChnk { // Used to store a block of code from the scratch "standard library" (maybe I should make a standard library for scratch)
	public:
		// Not sure if this is needed because everything is basically a function call or a varible setting
		std::string operator;
		T* nxtptr = nullptr;
};

template<typename T, int S>
class funcCall { // Calls a function
	public:
		std::string funcName;
		express args[S];
		double return1;
		bool return2; // Maybe not needed because scratch doesnt really have bools, they are either represented as 1, 0, or a string
		std::string return3;
		bool hasReturn; // Need to have a way to store return types and values
		T* nxtptr = nullptr;
};

template<typename T>
class express { // Used to store expressions inside of while loops or whatever else
	public:
		// Expressions will most likley be "copy pasted" into code
		char op; // Used for + - / * etc
		char op2; // Optionally used for logical or boolean operators like == && ||
		funcCall func; // Used if a value is a function
		funcCall func2; // Also very recursive stuff going on here
		std::string varid1; // Used if there is a varible in an expression
		std::string varid2;
		express operand1; // Used for nestled expressions
		express operand2; // Maybe make these pointers
		bool isBool; // Not sure if this is needed
};

class varSet { // Stores variables for a sprite or globaly
	public:
		std::vector<std::string> vars;
		std::vector<std::string> varids;
};

class globalObjects { // Used to store global variables and functions and stuff
	public:
		varSet globalVars;
};

class sprite {
	private:
		bool isshown;
		//std::vector<script> scripts;
		std::vector<std::string> costumes; //Contains the paths to the costumes
		varSet vars;
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