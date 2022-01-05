#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "email.h"
#include "body.h"
#include "queue.h"

void email_free(struct Email *e)
{
  bodylist_clear(&e->body_parts);
  free(e->subject);
  free(e);
}

struct Email *email_new(const char *subject)
{
  struct Email *e = calloc(1, sizeof(struct Email));

  e->subject = strdup(subject);
  TAILQ_INIT(&e->body_parts);

  return e;
}

void dump_email(struct Email *e)
{
  printf("Email: %s\n", e->subject);
  dump_bodies(&e->body_parts, 0);
}

void populate_email(struct Email *e)
{
  struct Body *b_top1 = body_new("apple");
  struct Body *b_top2 = body_new("banana");
  struct Body *b_top3 = body_new("cherry");

  TAILQ_INSERT_TAIL(&e->body_parts, b_top1, entries);
  TAILQ_INSERT_TAIL(&e->body_parts, b_top2, entries);
  TAILQ_INSERT_TAIL(&e->body_parts, b_top3, entries);

  struct Body *b_top11 = body_new("aardvark");
  struct Body *b_top12 = body_new("antelope");

  TAILQ_INSERT_TAIL(&b_top1->children, b_top11, entries);
  TAILQ_INSERT_TAIL(&b_top1->children, b_top12, entries);

  struct Body *b_top21 = body_new("baboon");
  struct Body *b_top22 = body_new("buffalo");
  struct Body *b_top23 = body_new("bat");

  TAILQ_INSERT_TAIL(&b_top2->children, b_top21, entries);
  TAILQ_INSERT_TAIL(&b_top2->children, b_top22, entries);
  TAILQ_INSERT_TAIL(&b_top2->children, b_top23, entries);

  struct Body *b_top31 = body_new("chameleon");

  TAILQ_INSERT_TAIL(&b_top3->children, b_top31, entries);
}
