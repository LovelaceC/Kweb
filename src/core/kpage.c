#include <kweb.h>

struct kpage
kpage_create ()
{
  struct kpage page;

  page.meta = (struct kpage_meta){ 0 };

  page.elements = vector_create ();

  page.styles = vector_create ();
  page.scripts = vector_create ();

  return page;
}

void
kpage_set_meta (struct kpage *page, char *page_title, char *page_description,
                char *page_author)
{
  page->meta.title = page_title;
  page->meta.description = page_description;
  page->meta.author = page_author;
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
kpage_add_style (struct kpage *page, const char *scr_path)
{
  vector_add_element (&page->styles, (void *)scr_path);
}

void
kpage_render (struct kpage *page, onion_response *res)
{
  onion_response_printf (
      res,
      "<!DOCTYPE html>\n"
      "<html>\n"
      "<head>\n"
      "<title>%s\n</title>\n"
      "<meta name=\"description\" content=\"%s\">\n"
      "<meta name=\"author\" content=\"%s\">\n",
      page->meta.title != NULL ? page->meta.title : "",
      page->meta.description != NULL ? page->meta.description : "",
      page->meta.author != NULL ? page->meta.author : "");

  // Apend styles to the page
  for (int i = 0; i < page->styles.length; i++)
    {
      onion_response_printf (res, "<link rel=\"stylesheet\" href=\"%s\">\n",
                             (char *)page->styles.child[i]);
    }

  onion_response_printf (res, "<body>\n");

  for (int i = 0; i < page->elements.length; i++)
    {
      element_draw ((struct element *)page->elements.child[i], res);
    }

  // Load scripts before `</body>' so the contents are not slowed down.
  for (int i = 0; i < page->scripts.length; i++)
    {
      onion_response_printf (res, "<script src=\"%s\"></script>",
                             (char *)page->scripts.child[i]);
    }

  onion_response_write0 (res, "</body>\n"
                              "</html>\n");
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
  vector_free (&page->styles);
  vector_free (&page->scripts);
}
