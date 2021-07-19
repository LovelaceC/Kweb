#include <kweb.h>

struct element
element_create (enum element_types type, void *content)
{
  struct element element;

  element.type = type;
  element.content = content;

  return element;
}

void
element_draw (struct element *element, onion_response *res)
{
  switch (element->type)
    {
    case ELEMENT_LABEL:
      struct label l = label_create ((char *)element->content);
      label_draw (&l, res);
      label_free (&l);
      break;
    case ELEMENT_DIVISION:
      break;
    default:
      break;
    }
}
