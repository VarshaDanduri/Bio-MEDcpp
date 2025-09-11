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
            int max_section_length;
            int min_section_length;
            string start_line_phrase = "";
            char start_line_char;
            string end_line_phrase = "";
            char end_line_char;
            char match_attr[6] = "lower";
            char new_line_rule[14] = "r[\n\r]+[s]*$";


            Sectionizer(
            string language, 
            int max_section_length, 
            int min_section_length,
            string start_line_phrase,
            char start_line_char,
            string end_line_phrase,
            char end_line_char,
            char match_attr[6]
            ) {
            this->language = language;
            this->max_section_length = max_section_length;
            this->min_section_length = min_section_length;
            this->start_line_phrase = start_line_phrase;
            this->start_line_char = start_line_char;
            this->end_line_phrase = end_line_phrase;
            this->end_line_char = end_line_char;
            strncpy(this->match_attr, match_attr, 6);
            };

            //lineRule -> return new_line_rule
            string lineRule() {
                return new_line_rule;
            };

            //maxLength -> return max_section_length
            int maxLength() {
                return max_section_length;
            };

            //minLength -> return min_section_length
            int minLength(){
                return min_section_length;
            };

            //matchAttr -> returns match_attr
            char matchAttr() {
                return *match_attr;
            };
    };


extern "C" {

    void load(string l, 
        int max, 
        int min, 
        string slp, 
        char slc, 
        string elp, 
        char elc, 
        char ma[6]){

    Sectionizer newSectionizer(l, max, min, slp, slc, elp, elc, ma);
    }

}






