#include <kweb.h>

struct label
label_create (char *content)
{
  size_t len = strlen (content);

  struct label label = { 0 };
  label.content = malloc (sizeof (char) * len);
  strncpy (label.content, content, len);

  return label;
}

void
label_draw (struct label *label, onion_response *res)
{
  onion_response_printf (res, "<p>%s</p>", label->content);
}

void
label_free (struct label *label)
{
  free (label->content);
  label->content = NULL;
}
