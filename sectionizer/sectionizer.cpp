#include <iostream>
#include <map>
#include <string>
#include <regex>

using std::cout;
using std::endl;
using std::map;
using std::string;



extern "C" {

    map<string, bool>DEFAULT_ATTRS = {
        {"is_historical", true},
        {"family_history", true}
    };

    class Sectionizer{
        char language[3] = "en";
        char new_line_rule[14] = "r[\n\r]+[s]*$";

        private:
        void match(string){
        };



    };

}




