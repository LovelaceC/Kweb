#include <kweb.h>

int
home (void *p, onion_request *req, onion_response *res)
{
  struct kpage page = kpage_create ();

  struct element *div = element_create (ELEMENT_DIVISION, NULL);

  element_add_child_simple (div, ELEMENT_LABEL,
                            "First child of element `div'.");
  element_add_child_simple (div, ELEMENT_LABEL,
                            "Second child of element `div'.");

  char *make = file_read ("Makefile");
  element_add_child_simple (div, ELEMENT_LABEL,
                            "Contents of file `Makefile': ");
  element_add_child_simple (div, ELEMENT_LABEL, make);
  free (make);

  kpage_add_element (&page, div);

  kpage_render (&page, res);

  kpage_free (&page);
  return OCS_PROCESSED;
}

int
main (int main, char **argv)
{
  struct kweb k = kweb_init (5000, "0.0.0.0", "15000");

  // This supports regex: "^user/(.*)/$"
  kweb_add_page (&k, "^(.*)$", home);

  printf ("Check this website at: 0.0.0.0:15000\n");

  kweb_listen (&k);
}
