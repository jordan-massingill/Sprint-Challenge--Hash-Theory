#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);

  // YOUR CODE HERE
  Answer *answer = malloc(sizeof(Answer));
  for (int i=0; i<length; i++) {
    hash_table_insert(ht, weights[i], i);
    printf("%d\n", weights[i]);
  }
  for (int i=0; i<length; i++) {
    if (hash_table_retrieve(ht, limit - weights[i]) != -1) {
      int secondval = hash_table_retrieve(ht, limit - weights[i]);
      int firstval = hash_table_retrieve(ht, weights[i]);
      printf("%d %d\n", firstval, secondval);
      if (firstval != -1 && weights[firstval] > weights[secondval]) {
        answer->index_1 = firstval;
        answer->index_2 = secondval;
        printf("ANSWER1: %d, %d\n", answer->index_1, answer->index_2);
        return answer;
      } else if (firstval != -1 && weights[firstval] < weights[secondval]) {
        answer->index_1 = secondval;
        answer->index_2 = firstval;
        printf("ANSWER2: %d, %d\n", answer->index_1, answer->index_2);
        return answer;
      } else if (firstval != -1 && (&firstval != &secondval)) {
        answer->index_1 = firstval;
        answer->index_2 = secondval;
        printf("ANSWER3: %d, %d\n", answer->index_1, answer->index_2);
        return answer;
      }
    }
  }
  free(answer);
  destroy_hash_table(ht);
  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}

#ifndef TESTING
int main(void)
{
  int weights_4[] = {12, 6, 7, 14, 19, 3, 0, 25, 40};

  Answer* answer_4 = get_indices_of_item_weights(weights_4, 9, 7);

  if (answer_4->index_1 != 6)
    printf("Your function did not return the expected answer for input {12, 6, 7, 14, 19, 3, 0, 25, 40}");
  if (answer_4->index_2 != 2)
    printf("Your function did not return the expected answer for input {12, 6, 7, 14, 19, 3, 0, 25, 40}");

  return 0;
}
#endif
