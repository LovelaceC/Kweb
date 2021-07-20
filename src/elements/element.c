#include <kweb.h>
#include <stdlib.h>

struct element *
element_create (enum element_types type, void *content)
{
  struct element *element = NULL;
  element = malloc (sizeof (struct element));

  element->type = type;
  element->parent = NULL;
  element->content = content;
  element->children = vector_create ();

  return element;
}

void
element_draw (struct element *element, onion_response *res)
{
  switch (element->type)
    {
    case ELEMENT_LABEL:
      label_draw (element, res);
      break;
    case ELEMENT_BOLD_LABEL:
      label_draw_bold (element, res);
      break;
    case ELEMENT_DIVISION:
      break;
    default:
      break;
    }
}

void
element_draw_nested (struct vector *elements, onion_response *res)
{
  for (int i = 0; i < elements->length; i++)
    {
      element_draw (elements->child[i], res);
    }
}

void
element_add_child (struct element *parent, struct element *child)
{
  vector_add_element (&parent->children, child);
  child->parent = parent;
}

void
element_add_child_easy (struct element *parent, enum element_types type,
                        void *content)
{
  struct element *el = element_create (type, content);
  element_add_child (parent, el);
}

void
element_free (struct element *element)
{
  for (int i = 0; i < element->children.length; i++)
    {
      element_free (element->children.child[i]);

      free (element->children.child[i]);
      element->children.child[i] = NULL;
    }

  vector_free (&element->children);
  element->parent = NULL;
  element->content = NULL;
}
