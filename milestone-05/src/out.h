
#ifndef OUROBOROS_MILESTONE_00_PROMPT_H_
#define OUROBOROS_MILESTONE_00_PROMPT_H_

#include "info.h"

namespace out {

class Sender {

  public:

    /// Avtivates line breaking.
    bool break_line;

    /// Constructor.
    Sender();
    
    /// Prints prompt output.
    void SendMessage (const char* str);
    
    /// Prints n prompt outputs.
    void SendMultimessage (const char* str, int n);

    /// Prints an information.
    void SendInfo (Info* the_info);

  private:

    const char *const TALKER_NAME;

};

} // namespace out

#endif

