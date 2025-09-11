#include <iostream>
#include <pybind11/pybind11.h>
#include <map>
#include <string>
#include <regex>
#include <cstring>
#include <list>

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::strncpy;
using std::list;

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

    };

Sectionizer* load() {
    return new Sectionizer("en", "", "", "lower");
}

map<string, bool> get_default_attrs() {
    return DEFAULT_ATTRS;
}

void add_attrs(list<string> attrs) {
    for (string attr: attrs){
        DEFAULT_ATTRS[attrs] = true;
    }
}

PYBIND11_MODULE(sectionizer, m) {
    m.def("load", &load, "Loads a new Sectionizer object.");
    m.def("get_default_attrs", &get_default_attrs, "Returns defaults context rules.");
    m.def("add_attrs", &add_attrs, "Adds new contxt rules. Takes a list of contest rules.");
}






