#include <kweb.h>

struct kpage
kpage_create ()
{
  struct kpage page;

  page.elements = vector_create ();

  return page;
}

void
kpage_add_simple_element (struct kpage *page, enum element_types type,
                          void *content)
{
  struct element *el;
  el = malloc (sizeof (struct element));
  *el = element_create (type, content);

  vector_add_element (&page->elements, el);
}

void
kpage_render (struct kpage *page, onion_response *res)
{
  for (int i = 0; i < page->elements.length; i++)
    {
      element_draw ((struct element *)page->elements.child[i], res);
    }
}

void
kpage_free (struct kpage *page)
{
  for (int i = 0; i < page->elements.length; i++)
    {
      // As the elements are malloc'd, they must be free'd too
      // TODO: element_free ((struct element *)page->elements.child[i]);
      free (page->elements.child[i]);
    }

  // Finally, free the space allocated to store their addresses.
  vector_free (&page->elements);
}
