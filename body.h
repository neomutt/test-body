#ifndef _BODY_H
#define _BODY_H

#include "queue.h"

TAILQ_HEAD(BodyList, Body);
struct Body
{
  char *name;
  struct BodyList children;
  TAILQ_ENTRY(Body) entries;
};

void         body_free(struct Body *b);
struct Body *body_new(const char *name);

void bodylist_clear(struct BodyList *bl);

void dump_body(struct Body *b, int indent);
void dump_bodies(struct BodyList *bl, int indent);

#endif // _BODY_H
