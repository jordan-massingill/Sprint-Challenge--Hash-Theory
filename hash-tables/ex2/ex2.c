#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "ex2.h"

char **reconstruct_trip(Ticket **tickets, int length)
{
  HashTable *hash = create_hash_table(16);
  char **route = malloc(length * sizeof(char *));

  // YOUR CODE HERE
  for (int i=0; i<length; i++) {
    hash_table_insert(hash, tickets[i]->source, tickets[i]->destination);
  }
  route[0] = hash_table_retrieve(hash, "NONE");
  for (int i=0; i<length-1; i++) {
    route[i+1] = hash_table_retrieve(hash, route[i]);
  }
  return route;
}

void print_route(char **route, int length)
{
  for (int i = 0; i < length; i++) {
    printf("%s\n", route[i]);
  }
}

#ifndef TESTING
int main(void)
{
  Ticket **tickets = malloc(3 * sizeof(Ticket *));

  Ticket *ticket_1 = malloc(sizeof(Ticket));
  ticket_1->source = "NONE";
  ticket_1->destination = "PDX";
  tickets[0] = ticket_1;

  Ticket *ticket_2 = malloc(sizeof(Ticket));
  ticket_2->source = "PDX";
  ticket_2->destination = "DCA";
  tickets[1] = ticket_2;

  Ticket *ticket_3 = malloc(sizeof(Ticket));
  ticket_3->source = "DCA";
  ticket_3->destination = "NONE";
  tickets[2] = ticket_3;

  char **answer = reconstruct_trip(tickets, 3);

  printf("%s\n", *answer);

  return 0;
}
#endif
