#include <kweb.h>

int
home (void *p, onion_request *req, onion_response *res)
{
  struct kpage page = kpage_create ();

  kpage_add_simple_element (&page, ELEMENT_LABEL, "Hello world from C!");
  kpage_add_simple_element (&page, ELEMENT_LABEL,
                            "The next element is now an empty label.");
  kpage_add_simple_element (&page, ELEMENT_LABEL, NULL);

  struct element *el
      = element_create (ELEMENT_LABEL, "This is a label with children ");

  element_add_child_simple (el, ELEMENT_BOLD_LABEL,
                            "i am contained inside a label");
  element_add_child_simple (el, ELEMENT_LABEL, " i am just another child");

  kpage_add_element (&page, el);

  struct element *div_content = element_create (ELEMENT_DIVISION, NULL);
  element_set_class (div_content, "content");

  element_add_child_simple (div_content, ELEMENT_LABEL,
                            "I am the child of a division.");

  struct element *div_div = element_create (ELEMENT_DIVISION, NULL);
  element_set_id (div_div, "nested_division another_id");

  element_add_child_simple (
      div_div, ELEMENT_LABEL,
      "And I am a label inside of a div inside of a div :3");

  element_add_child (div_content, div_div);

  kpage_add_element (&page, div_content);

  kpage_render (&page, res);

  kpage_free (&page);
  return OCS_PROCESSED;
}

int
main (int main, char **argv)
{
  struct kweb k = kweb_init (5000, "0.0.0.0", "15000");

  kweb_add_page (&k, "", home);

  printf ("Check this website at: 0.0.0.0:15000\n");

  kweb_listen (&k);
}
