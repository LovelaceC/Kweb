#include <kweb.h>

void
label_draw (struct element *label, onion_response *res)
{
  _Bool should_create = 0; // Determines if we should create a `p' tag or just
                           // append text to an existing label (parent)

  if ((label->parent == NULL)
      || (label->parent != NULL && label->parent->type != ELEMENT_LABEL))
    {
      should_create = 1;
      onion_response_printf (res, "<p class=\"%s\" id=\"%s\">",
                             label->class != NULL ? label->class : "",
                             label->id != NULL ? label->id : "");
    }

  // Print the content
  onion_response_printf (res, "%s",
                         label->content != NULL ? (char *)label->content : "");

  // Children
  if (!vector_is_empty (&label->children))
    {
      element_draw_nested (&label->children, res);
    }

  // Print `/p' if necessary
  if (should_create)
    {
      onion_response_write0 (res, "</p>\n");
    }
}

void
label_draw_bold (struct element *label, onion_response *res)
{
  onion_response_printf (res, "<b class=\"%s\" id=\"%s\">%s",
                         label->class != NULL ? label->class : "",
                         label->id != NULL ? label->id : "",
                         label->content != NULL ? (char *)label->content : "");

  if (!vector_is_empty (&label->children))
    {
      element_draw_nested (&label->children, res);
    }

  onion_response_write0 (res, "</b>");
}
