#include <kweb.h>

struct label
label_create (char *content)
{
  struct label label = { 0 };
  label.content = content;
  return label;
}

void
label_draw (struct label *label, onion_response *res)
{
  onion_response_printf (res, "<p>%s</p>",
                         label->content != NULL ? label->content : "");
}

void
label_free (struct label *label)
{
}
