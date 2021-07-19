#include <kweb.h>

int
home (void *p, onion_request *req, onion_response *res)
{
  struct kpage page = kpage_create ();

  kpage_add_simple_element (&page, ELEMENT_LABEL, "Hello world from C!");
  kpage_add_simple_element (&page, ELEMENT_LABEL,
                            "The next element is now an empty label.");
  kpage_add_simple_element (&page, ELEMENT_LABEL, NULL);

  kpage_render (&page, res);

  kpage_free (&page);
  return OCS_PROCESSED;
}

int
main (int main, char **argv)
{
  struct kweb k = kweb_init (5000, "0.0.0.0");

  kweb_add_page (&k, "", home);

  kweb_listen (&k);
}
