// gcc -Wall -Wextra -Wpedantic -I. -fsanitize=address -o email *.c

#include "email.h"

int main()
{
  struct Email *e = email_new("refactoring");
  populate_email(e);
  dump_email(e);
  email_free(e);

  return 0;
}
