#ifndef _EMAIL_H
#define _EMAIL_H

#include "body.h"

struct Email
{
  char *subject;
  struct BodyList body_parts;
};

void          email_free(struct Email *e);
struct Email *email_new(const char *subject);

void dump_email(struct Email *e);
void populate_email(struct Email *e);

#endif // _EMAIL_H
