#include <kweb.h>

void
division_draw (struct element *division, onion_response *res)
{
  element_draw_opening (division, "div", res);

  if (!vector_is_empty (&division->children))
    {
      element_draw_nested (&division->children, res);
    }

  onion_response_printf (res, "</div>\n");
}
