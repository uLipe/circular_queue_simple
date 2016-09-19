#include <stdio.h>
#include <string.h>
#include "../queue_circ.h"


CIRCULAR_QUEUE_DECLARE(test_q, 32 , 32);

char slot_1[] = {"first inserted text \n\r"};
char slot_2[] = {"second inserted text \n\r"};
char slot_3[] = {"third inserted text \n\r"};
char slot_4[] = {"fourth inserted text \n\r"};


int main (int argc, char **argv)
{
  char txt[64] = {0};
  unsigned int size = 0;

  /* insert four texts in queue */
  queue_insert(&test_q,&slot_1, sizeof(slot_1));
  queue_insert(&test_q,&slot_2, sizeof(slot_2));
  queue_insert(&test_q,&slot_3, sizeof(slot_3));
  queue_insert(&test_q,&slot_4, sizeof(slot_4));

  /* retrieve and print the text from queue */
  queue_retrieve(&test_q,&txt, &size);
  printf("%s - size is: %d",txt, size);

  memset(txt, 0, sizeof(txt));
  queue_retrieve(&test_q,&txt, &size);
  printf("%s - size is: %d",txt, size);

  memset(txt, 0, sizeof(txt));
  queue_retrieve(&test_q,&txt, &size);
  printf("%s - size is: %d",txt, size);

  memset(txt, 0, sizeof(txt));
  queue_retrieve(&test_q,&txt, &size);
  printf("%s - size is: %d",txt, size);

  return 0;
}
