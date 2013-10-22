
#include "out.h"
#include "info.h"

#include <string>
#include <iostream>

namespace out {

using std::cout;
using std::endl;
using data::Info;

Sender::Sender ()
    : break_line(true), TALKER_NAME("Bob Singer") {}

void Sender::SendMessage (const char* str) {
    if (break_line)
        cout << TALKER_NAME << ": " << str << endl;
    else {
        cout << TALKER_NAME << ": " << str;
        cout.flush();
    }
}

void Sender::SendMultimessage (const char* str, int n) {
    for (int i=0; i < n; i++)
        cout << TALKER_NAME << ": " << str << endl;
}

void Sender::SendInfo (const Info& the_info) {
    cout << the_info.subject() << " " << the_info.predicate() << " " << the_info.object() << endl;
}

} // namespace out

