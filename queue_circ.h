/**
 * @brief Simple circular queue implementation with basic management functions
 */

#ifndef __QUEUE_CIRC_H
#define __QUEUE_CIRC_H


/** circular queue management structure */
typedef struct {
  unsigned char *data;
  unsigned int  items;
  unsigned int  slots_number;
  unsigned int  wr_ptr;
  unsigned int  rd_ptr;
  int  slot_len;
} queue_circ_t;



/**
 * @brief insert a stream data with size lenght to the queue
 */
int queue_insert(queue_circ_t *q,void *data, unsigned int size);

/**
 *  @brief retrieves a stream of dat with specified size
 */
int queue_retrieve(queue_circ_t *q, void *data, unsigned int *size);

/**
 *  @brief check if queue is already full
 */
int queue_full(queue_circ_t *q);

/**
 * @brief makes the queue empty
 */
int queue_flush(queue_circ_t *q);

/**
 * @brief  check if queue is empty
 */
int queue_empty(queue_circ_t *q);

/** declare a initialized circular queue
 * name - name of the allocated queue structure
 * slot_size -size in bytes of each slot
 * noof_slots - number of slots (elements) in this queue
 */
#define CIRCULAR_QUEUE_DECLARE(name,slot_size, noof_slots)    \
        unsigned char queue_memory_##name[(slot_size + sizeof(unsigned int)) * noof_slots];\
        queue_circ_t name = {                                 \
          .data = &queue_memory_##name[0],                    \
          .items = 0,                                         \
          .slots_number = noof_slots,                         \
          .wr_ptr = 0,                                        \
          .rd_ptr = 0,                                        \
          .slot_len = slot_size                               \
        }

#endif
