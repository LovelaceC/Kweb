#include <kweb.h>

void
division_draw (struct element *division, onion_response *res)
{
  onion_response_printf (res, "<div class=\"%s\" id=\"%s\">\n",
                         division->class != NULL ? division->class : "",
                         division->id != NULL ? division->id : "");

  if (!vector_is_empty (&division->children))
    {
      element_draw_nested (&division->children, res);
    }

  onion_response_printf (res, "</div>\n");
}
