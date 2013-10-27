
#include "input.h"

#include <iostream>
#include <sstream>
#include <string>

#include <cstring>

namespace input {

using std::cin;
using std::endl;
using std::string;
using std::stringstream;

const char* Receiver::ReceiveMessage () {
    string value;
    getline(cin, value);
    strcpy(buffer, value.c_str());
    return buffer;
}

double Receiver::ReceiveNumber () {
    double value;
    cin >> value;
    return value;
}

bool Receiver::ReceiveConfirmation () {
    string value;
    cin >> value;
    if (value == "yes")
        return true;
    return false;
}

Info* Receiver::ReceiveInfo () {
    Info*   info = new Info;
    string  line, value;
    getline(cin, line);
    stringstream linestream(line);
    linestream >> value;
    info->set_subject(value.c_str());
    linestream >> value;
    info->set_predicate(value.c_str());
    linestream >> value;
    info->set_object(value.c_str());
    return info;
}

} // namespace input

