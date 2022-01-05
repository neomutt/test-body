#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "body.h"
#include "queue.h"

void body_free(struct Body *b)
{
  bodylist_clear(&b->children);

  free(b->name);
  free(b);
}

struct Body *body_new(const char *name)
{
  struct Body *b = calloc(1, sizeof(struct Body));

  b->name = strdup(name);
  TAILQ_INIT(&b->children);

  return b;
}

void bodylist_clear(struct BodyList *bl)
{
  struct Body *b_child = NULL;
  struct Body *tmp = NULL;
  TAILQ_FOREACH_SAFE(b_child, bl, entries, tmp)
  {
    TAILQ_REMOVE(bl, b_child, entries);
    body_free(b_child);
  }
}

void dump_body(struct Body *b, int indent)
{
  printf("%*sBody: %s\n", indent * 4, "", b->name);
  dump_bodies(&b->children, indent + 1);
}

void dump_bodies(struct BodyList *bl, int indent)
{
  struct Body *b = NULL;
  TAILQ_FOREACH(b, bl, entries)
  {
    dump_body(b, indent);
  }
}
