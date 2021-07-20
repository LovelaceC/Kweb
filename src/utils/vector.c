#include <kweb.h>

struct vector
vector_create ()
{
  struct vector vector;

  vector.length = 0;
  vector.child = NULL;

  return vector;
}

void
vector_add_element (struct vector *vector, void *element)
{
  vector->child
      = realloc (vector->child, sizeof (void *) * vector->length + 1);

  if (!vector->child)
    {
      printf ("vector_add_element: Failed allocating memory for `child'.");
      return;
    }

  vector->child[vector->length] = element;
  vector->length += 1;
}

_Bool
vector_is_empty (struct vector *vector)
{
  return vector->length == 0;
}

void
vector_free (struct vector *vector)
{
  free (vector->child);
  vector->child = NULL;
}
