//This file will contain some data structure for a parsed json object
#include<vector>
#include<string>

class script {
	public:
		std::vector<std::string> scripts;
};

class sprite {
	private:
		bool isshown;
		std::vector<script> scripts;
		std::vector<std::string> costumes; //Contains the paths to the costumes
		std::vector<std::string> vars;
		int costumeshown;
		void reload_appearance () {
			//Switches the costume to the current costume
		}
	public:
		std::string get_costume (int index) {
			return costume[index];
		}
		std::string get_var (int index) {
			return vars[index];
		}
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
		void add_var (std::string tstring) {
			vars.push_back(tstring);
		}
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
		void switch_backdrop (backdrop) {
			backdropshown = backdrop;
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
};
