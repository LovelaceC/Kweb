#ifndef __KWEB_H
#define __KWEB_H

#include <onion/log.h>
#include <onion/onion.h>
#include <onion/version.h>

#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// elements/label.h
struct label
{
  char *content;
};

struct label label_create (char *content);
void label_draw (struct label *label, onion_response *res);
void label_free (struct label *label);

#endif
