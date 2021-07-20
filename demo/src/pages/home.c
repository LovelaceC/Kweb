#include "home.h"
#include "kweb.h"

int
homep (void *p, onion_request *req, onion_response *res)
{
  struct kpage page = kpage_create ();

  kpage_add_simple_element (&page, ELEMENT_LABEL, "Welcome to kweb.");
  kpage_add_simple_element (
      &page, ELEMENT_LABEL,
      "The following is a list of the available entries in this website:");

  struct element *entries_list = element_create (ELEMENT_LIST, NULL);

  element_add_child_simple (entries_list, ELEMENT_LIST_CHILD, "Home");
  element_add_child_simple (entries_list, ELEMENT_LIST_CHILD, "Blog");
  element_add_child_simple (entries_list, ELEMENT_LIST_CHILD, "Contact");

  kpage_add_element (&page, entries_list);

  struct element *did_you_know = element_create (ELEMENT_LABEL, NULL);

  element_add_child_simple (did_you_know, ELEMENT_BOLD_LABEL,
                            "Did you know...");
  element_add_child_simple (
      did_you_know, ELEMENT_LABEL,
      "This website is entirely made in the C programming language?");

  kpage_add_element (&page, did_you_know);

  if (file_exists ("Makefile"))
    {
      kpage_add_simple_element (&page, ELEMENT_LABEL,
                                "There's a `Makefile' file.");
    }

  kpage_render (&page, res);
  kpage_free (&page);

  return OCS_PROCESSED;
}
