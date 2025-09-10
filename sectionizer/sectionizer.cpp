#include <iostream>
#include <map>
#include <string>
#include <regex>
#include <Python.h>

using std::cout;
using std::endl;
using std::map;
using std::string;



extern "C" {

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
            string start_line_phrase;
            char start_line_char;
            string end_line_phrase;
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
            language = language;
            max_section_length = max_section_length;
            min_section_length = min_section_length;
            start_line_phrase = start_line_phrase;
            start_line_char = start_line_char;
            end_line_phrase = end_line_phrase;
            end_line_char = end_line_char;
            match_attr = match_attr;

            //lineRule -> return new_line_rule
            //maxLength -> return max_section_length
            //minLength -> return min_section_length
            //startPhrase -> return start_line_phrase
            //startChar -> return start_line_char
            //endPhrase -> return end_line_phrase
            //endChar -> retur end_line_char
            //matchAttr -> returns match_attr
        };


    };
}






