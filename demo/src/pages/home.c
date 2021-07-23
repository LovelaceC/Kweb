#include "../pages.h"
#include "kweb.h"

int
homep (void *p, onion_request *req, onion_response *res)
{
  struct kpage page = kpage_create ();

  include_header (&page, "Home",
                  "Home page of the amazing website created with C only!");

  struct element *content = element_create (ELEMENT_DIVISION, NULL);
  {
    element_add_child_simple (content, ELEMENT_LABEL,
                              "Heyy, welcome to my website!");

    element_add_child_simple (
        content, ELEMENT_LABEL,
        "This is nothing but a demo to demonstrate the capabilities - and get "
        "ideas for more things to add - to the library I am currently "
        "creating `kweb'");

    element_add_child_simple (
        content, ELEMENT_LABEL,
        "I know this is something very silly and it will never be something "
        "more than an experiment, but anyway, I think it'd be pretty cool to "
        "create entire dynamic websites (such as social networks) entirely in "
        "C.");

    element_add_child_simple (
        content, ELEMENT_LABEL,
        "Also, you can already use libraries such as Bootstrap or jQuery, so "
        "this might not be that stupid after all?");
  }
  kpage_add_element (&page, content);

  kpage_render (&page, res);
  kpage_free (&page);

  return OCS_PROCESSED;
}
