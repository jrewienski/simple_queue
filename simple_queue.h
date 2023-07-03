#ifndef SIMPLE_QUEUE_H
#define SIMPLE_QUEUE_H
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define CONCAT_2(p1, p2)     p1##p2

typedef enum 
{ 
    QUEUE_OK, 
    QUEUE_EMPTY,
    QUEUE_FULL
} queue_status_t;

typedef struct
{
    void           * p_buffer;          //!< Pointer to the memory that is used as storage.
    size_t           size;              //!< Max size of the queue.
    size_t           element_size;      //!< Size of one element.
    uint32_t         front_idx;         //!< Index of the first element of the queue.
    uint32_t         back_idx;          //!< Index of the last element of the queue.
    bool             is_full;           //!< Indicator that queue is full.
} simple_queue_t;

#define DEF_QUEUE(_qtype, _qname, _qsize)                   \
    static _qtype CONCAT_2(_qname,_buffer[_qsize]);         \
    static simple_queue_t _qname =                          \
    {                                                       \
        .p_buffer = CONCAT_2(_qname,_buffer),               \
        .size  = _qsize,                                    \
        .element_size = sizeof(_qtype),                     \
        .front_idx = 0,                                     \
        .back_idx = 0,                                      \
        .is_full = false                                    \
    }

queue_status_t queue_push(simple_queue_t * p_queue, void * p_element);
queue_status_t queue_pop(simple_queue_t * p_queue, void * p_element);
queue_status_t queue_peek_last(simple_queue_t  * p_queue, void * p_element);
uint32_t queue_current_size(simple_queue_t * p_queue);
bool queue_is_empty(simple_queue_t * p_queue);

#endif /* SIMPLE_QUEUE_h */
