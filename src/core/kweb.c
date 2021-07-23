#include <kweb.h>

static int
kweb_handle_css (void *ptr, onion_request *req, onion_response *res)
{
  onion_response_set_header (res, "Content-Type", "text/css; charset=utf-8");

  const char *path = onion_request_get_fullpath (req);
  path += 1;

  if (!file_exists (path))
    {
      return OCS_INTERNAL_ERROR;
    }

  char *fcnt = file_read (path);
  onion_response_printf (res, "%s", fcnt);

  free (fcnt);

  return OCS_PROCESSED;
}

static int
kweb_handle_js (void *ptr, onion_request *req, onion_response *res)
{
  onion_response_set_header (res, "Content-Type", "application/javascript");

  const char *path = onion_request_get_fullpath (req);
  path += 1;

  if (!file_exists (path))
    {
      return OCS_INTERNAL_ERROR;
    }

  char *fcnt = file_read (path);
  onion_response_printf (res, "%s", fcnt);

  free (fcnt);

  return OCS_PROCESSED;
}

struct kweb
kweb_init (int timeout, const char *hostname, const char *port)
{
  struct kweb k = { 0 };

  k.timeout = timeout;

  // TODO: Could this be a memory leak?
  k.o = onion_new (O_POLL);
  onion_set_timeout (k.o, timeout);
  onion_set_hostname (k.o, hostname);

  k.urls = onion_root_url (k.o);

  onion_url_add (k.urls, "^(.*).css$", kweb_handle_css);
  onion_url_add (k.urls, "^(.*).js$", kweb_handle_js);

  onion_set_port (k.o, port);

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
