
#ifndef OUROBOROS_MILESTONE_PROMPT_IN_H_
#define OUROBOROS_MILESTONE_PROMPT_IN_H_

namespace input {

class Receiver {

  public:

    /// Receives a message from the input.
    const char* ReceiveMessage ();
    
    /// Receives a number from the input.
    double ReceiveNumber ();
    
    /// Receives a confirmation from the input.
    bool ReceiveConfirmation ();

  private:

    char buffer[256];

};

} // namespace in

#endif

