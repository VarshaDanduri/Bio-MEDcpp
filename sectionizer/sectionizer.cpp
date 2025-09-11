#include <iostream>
#include <pybind11/pybind11.h>
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

            void details(){
                cout << "Language: " << language << endl;
                cout << "Start Line Phrase: " << start_line_phrase << endl;
                cout << "End Line Phrase: " << end_line_phrase << endl;
                cout << "Match Attribute: " << match_attr << endl;
                cout << "New Line Rule: " << new_line_rule << endl;
            };

    };

Sectionizer* load() {
    return new Sectionizer("en", "", "", "lower");
}


PYBIND11_MODULE(sectionizer, m) {
    m.def("load", &load, "A function that loads a Sectionizer object.");
}






