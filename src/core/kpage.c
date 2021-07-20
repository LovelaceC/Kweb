#include <kweb.h>

struct kpage
kpage_create ()
{
  struct kpage page;

  page.elements = vector_create ();

  return page;
}

void
kpage_add_element (struct kpage *page, struct element *element)
{
  vector_add_element (&page->elements, element);
}

void
kpage_add_simple_element (struct kpage *page, enum element_types type,
                          void *content)
{
  struct element *el = element_create (type, content);

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

const char *
kpage_get_path (onion_request *req)
{
  const char *path = onion_request_get_fullpath (req);
  path += 1;
  return path;
}

void
kpage_free (struct kpage *page)
{
  for (int i = 0; i < page->elements.length; i++)
    {
      // Free children
      element_free (page->elements.child[i]);

      // As the elements are malloc'd, they must be free'd too
      free (page->elements.child[i]);
      page->elements.child[i] = NULL;
    }

  // Finally, free the space allocated to store their addresses.
  vector_free (&page->elements);
}
