#include <iostream>
#include <map>
#include <string>
#include <regex>
#include <cstring>

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::strncpy;

map<string, bool>DEFAULT_ATTRS = {
        {"diagnoses_history", true},
        {"family_history", true},
        {"medication_history", true},
        {"drug_history", true},
        {"mh_history", true}
    };


class Sectionizer{
        public:
            string language = "en";
            char name[11] = "Bio-Medcpp";
            string start_line_phrase = "";
            string end_line_phrase = "";
            char match_attr[6] = "lower";
            char new_line_rule[14] = "r[\n\r]+[s]*$";


            Sectionizer(
            string language, 
            string start_line_phrase,
            string end_line_phrase,
            char match_attr[6]
            ) {
            this->language = language;
            this->start_line_phrase = start_line_phrase;
            this->end_line_phrase = end_line_phrase;
            strncpy(this->match_attr, match_attr, 6);
            };

            //lineRule -> return new_line_rule
            string lineRule() {
                return new_line_rule;
            };

            //matchAttr -> returns match_attr
            char matchAttr() {
                return *match_attr;
            };
    };


extern "C" {

    void load(string l, 
        string slp, 
        string elp, 
        char ma[6]){

    Sectionizer newSectionizer(l, slp, elp, ma);
    }

}






