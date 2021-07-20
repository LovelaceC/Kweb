#include <kweb.h>

void
list_draw (struct element *list, onion_response *res)
{
  element_draw_opening (list, "ul", res);

  if (!vector_is_empty (&list->children))
    {
      element_draw_nested (&list->children, res);
    }

  onion_response_printf (res, "</ul>\n");
}

void
list_draw_child (struct element *child, onion_response *res)
{
  element_draw_opening (child, "li", res);
  onion_response_printf (res, "%s\n", (char *)child->content);

  if (!vector_is_empty (&child->children))
    {
      element_draw_nested (&child->children, res);
    }

  onion_response_printf (res, "</li>\n");
}
