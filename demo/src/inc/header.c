#include "header.h"

void
include_header (struct kpage *page, char *title, char *description)
{
  char final_title[128];
  sprintf (final_title, "%s | Bassara", title);

  kpage_set_meta (page, final_title, description, "Bassara");

  struct element *header_elm = element_create (ELEMENT_DIVISION, NULL);
  {
    // #.header# contents
    element_add_child_simple (header_elm, ELEMENT_LABEL, "Bassara website");

    element_add_child_simple (
        header_elm, ELEMENT_LABEL,
        "This website is just a test of the `kweb' library created by me.");

    element_add_child_simple (header_elm, ELEMENT_LABEL,
                              "Here's a simple menu:");

    struct element *list = element_create (ELEMENT_LIST, NULL);
    element_set_class (list, "menu");
    {
      // TODO: Support for links
      element_add_child_simple (list, ELEMENT_LIST_CHILD, "Home");

      element_add_child_simple (list, ELEMENT_LIST_CHILD,
                                "Blog"); // TODO: Markdown based blog

      element_add_child_simple (list, ELEMENT_LIST_CHILD, "Essays");
      element_add_child_simple (list, ELEMENT_LIST_CHILD, "Contact");
      element_add_child_simple (list, ELEMENT_LIST_CHILD, "Donate");
    }
    element_add_child (header_elm, list);
  }
  kpage_add_element (page, header_elm);

  // TODO: Add separator "hr"

  kpage_add_simple_element (page, ELEMENT_BOLD_LABEL, title);
}
