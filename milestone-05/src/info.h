
#ifndef OUROBOROS_MILESTONE_PROMPT_INFO_H_
#define OUROBOROS_MILESTONE_PROMPT_INFO_H_

class Info {

  public:

    Info ();

    const char* subject ();
    const char* predicate ();
    const char* object ();

    void set_subject (const char* the_subject);
    void set_predicate (const char* the_predicate);
    void set_object (const char* the_object);

  private:

    char subject_[256], predicate_[256], object_[256];

};

#endif // OUROBOROS_MILESTONE_PROMPT_INFO_H_

