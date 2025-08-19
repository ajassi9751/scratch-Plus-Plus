//This file will contain some data structure for a parsed json object
#include<vector>
#include<string>

class script {
    private:
        std::vector<std::string> scripts;
};

class sprite {
    private:
        bool isshown;
        std::vector<script> scripts;
        std::vector<std::string> costumes;
        int costumeshown;
};

class backdrop {
    private:
        std::vector<std::string> backdrops;
        int backdropshown;
};

class project {
    private:
        std::vector<sprite> sprites;
        backdrop background;
};