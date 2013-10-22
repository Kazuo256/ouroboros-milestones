
#include "info.h"

#include <cstring>

Info::Info () {}

const char* Info::subject () {
    return subject_;
}

const char* Info::predicate () {
    return predicate_;
}

const char* Info::object () {
    return object_;
}

void Info::set_subject (const char* the_subject) {
    std::strcpy(subject_, the_subject);
}

void Info::set_predicate (const char* the_predicate) {
    std::strcpy(predicate_, the_predicate);
}

void Info::set_object (const char* the_object) {
    std::strcpy(object_, the_object);
}

