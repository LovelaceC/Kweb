#include <kweb.h>

struct element *
element_create (enum element_types type, void *content)
{
  struct element *element = NULL;
  element = malloc (sizeof (struct element));

  element->type = type;
  element->parent = NULL;
  element->content = content;
  element->children = vector_create ();

  element->class = NULL;
  element->id = NULL;

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
      division_draw (element, res);
      break;
    case ELEMENT_LIST:
      list_draw (element, res);
      break;
    case ELEMENT_LIST_CHILD:
      list_draw_child (element, res);
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
element_add_child_simple (struct element *parent, enum element_types type,
                          void *content)
{
  struct element *el = element_create (type, content);
  element_add_child (parent, el);
}

void
element_set_class (struct element *element, const char *class)
{
  // Should kweb just not allocate memory?
  size_t class_len = strlen (class);
  element->class = malloc (sizeof (char) * class_len);
  strncpy (element->class, class, class_len);
}

void
element_set_id (struct element *element, const char *id)
{
  // Should kweb just not allocate memory?
  size_t id_len = strlen (id);
  element->id = malloc (sizeof (char) * id_len);
  strncpy (element->id, id, id_len);
}

void
element_draw_opening (struct element *element, const char *tag,
                      onion_response *res)
{
  onion_response_printf (res, "<%s class=\"%s\" id=\"%s\">\n",
                         tag != NULL ? tag : "",
                         element->class != NULL ? element->class : "",
                         element->id != NULL ? element->id : "");
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

  if (element->class != NULL)
    {
      free (element->class);
      element->class = NULL;
    }

  element->parent = NULL;
  element->content = NULL;
}
