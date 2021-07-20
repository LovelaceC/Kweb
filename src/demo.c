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
      = element_create (ELEMENT_LABEL, "This is a label with children");

  element_add_child_simple (el, ELEMENT_BOLD_LABEL,
                            " i am contained inside a label");
  element_add_child_simple (el, ELEMENT_LABEL, " i am just another child");

  kpage_add_element (&page, el);

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
