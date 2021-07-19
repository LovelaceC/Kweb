#include <kweb.h>

int
home (void *p, onion_request *req, onion_response *res)
{
  struct label hello_label = label_create ("Hello world from C");
  label_draw (&hello_label, res);

  label_free (&hello_label);
  return OCS_PROCESSED;
}

int
main (int main, char **argv)
{
  struct kweb k = kweb_init (5000, "0.0.0.0");

  kweb_add_page (&k, "", home);

  kweb_listen (&k);
}
