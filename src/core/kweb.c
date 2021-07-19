#include <kweb.h>

struct kweb
kweb_init (int timeout, char *hostname)
{
  struct kweb k = { 0 };

  k.timeout = timeout;

  k.o = onion_new (O_POLL);
  onion_set_timeout (k.o, timeout);
  onion_set_hostname (k.o, hostname);

  k.urls = onion_root_url (k.o);

  return k;
}

void
kweb_add_page (struct kweb *k, const char *regex, void *fptr)
{
  onion_url_add (k->urls, regex, fptr);
}

void
kweb_listen (struct kweb *k)
{
  onion_listen (k->o);
}
