#include <kweb.h>

#include "pages.h"

int
main ()
{
  struct kweb kweb = kweb_init (5000, "0.0.0.0", "8080");

  kweb_add_page (&kweb, "", homep);

  printf ("Listening in: 0.0.0.0:8080\n");

  kweb_listen (&kweb);
}
