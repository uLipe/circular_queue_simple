
#include <string.h>
#include "queue_circ.h"


int queue_insert(queue_circ_t *q,void *data, unsigned int size)
{
  int ret = -1;

  if(q == NULL) {
    /* check your queue parameter */
    return(ret);
  } else {

    /* points the insertion index in correct queue
     * memory region
     */
    unsigned char *ptr = (unsigned char *)q->data;
    int pos = q->wr_ptr * q->slot_len;

    if(size > q->slot_len) {
      /* data will not fit in this slot */
      ret = -1;
    } else {
      /* the first 4 bytes are the size of slot in bytes */
      memcpy(&ptr[pos], &size, sizeof(size));
      /* insert the data */
      memcpy(&ptr[pos + sizeof(size)], data, size);
      /* update the indexes */
      q->wr_ptr = (q->wr_ptr + 1) % q->slots_number;
      ++q->items;
      ret = 0;
    }
  }
  return(ret);
}


int queue_retrieve(queue_circ_t *q,  void *data, unsigned int *size)
{
  int ret = -1;

  if(q == NULL || size == NULL) {
    /* check your queue parameter */
    return(ret);
  } else {

    /* points the insertion index in correct queue
     * memory region
     */
    unsigned char *ptr = (unsigned char *)q->data;
    int pos = q->rd_ptr * q->slot_len;

      /* the first 4 bytes are the size of slot in bytes */
      memcpy(&size,&ptr[pos], sizeof(size));
      /* retrieve the data */
      memcpy(data,&ptr[pos + sizeof(size)], size);
      /* update the indexes */
      q->rd_ptr = (q->rd_ptr + 1) % q->slots_number;
      --q->items;
      ret = 0;
  }
  return(ret);
}


int queue_full(queue_circ_t *q)
{
  int ret = 0;
  if(q->items >= q->slots_number) {
    ret = 1;
  }
  return(ret);
}


int queue_flush(queue_circ_t *q)
{
  int ret = 0;

  if(q != NULL) {
    q->wr_ptr = q->rd_ptr;
    q->items = 0;
  } else {
    ret = -1;
  }
  return(ret);
}


int queue_empty(queue_circ_t *q)
{
  return((q->items == 0? 1: 0));
}
