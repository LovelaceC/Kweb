#ifndef __KWEB_H
#define __KWEB_H

#include <onion/log.h>
#include <onion/onion.h>
#include <onion/types.h>
#include <onion/version.h>

#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definitions go at top
struct element;
struct kweb;
struct kpage;
enum element_types;

// utils/vector.h
struct vector
{
  unsigned int length;
  void **child;
};

struct vector vector_create ();
void vector_add_element (struct vector *vector, void *element);
_Bool vector_is_empty (struct vector *vector);
void vector_free (struct vector *vector);

// core/kweb.h
struct kweb
{
  onion *o;
  onion_url *urls;

  int timeout;
};

struct kweb kweb_init (int timeout, char *hostname);
void kweb_add_page (struct kweb *k, const char *regex, void *fptr);
void kweb_listen (struct kweb *k);

// core/kpage.h
struct kpage
{
  struct vector elements;
};

struct kpage kpage_create ();
void kpage_add_element (struct kpage *page, struct element *element);
void kpage_add_simple_element (struct kpage *page, enum element_types type,
                               void *content);
void kpage_render (struct kpage *page, onion_response *res);
void kpage_free (struct kpage *page);

// elements/element.h
enum element_types
{
  ELEMENT_LABEL,
  ELEMENT_BOLD_LABEL,
  ELEMENT_DIVISION
};

struct element
{
  enum element_types type;

  struct element *parent;
  void *content;

  struct vector children;
};

struct element *element_create (enum element_types type, void *content);
void element_draw (struct element *element, onion_response *res);
void element_draw_nested (struct vector *elements, onion_response *res);
void element_add_child (struct element *parent, struct element *child);
void element_free (struct element *element);

// elements/primitives/label.h
void label_draw (struct element *label, onion_response *res);
void label_draw_bold (struct element *label, onion_response *res);

#endif
