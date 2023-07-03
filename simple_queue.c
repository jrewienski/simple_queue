#include <stdbool.h>
#include <string.h>
#include "simple_queue.h"

uint32_t queue_get_next_idx(simple_queue_t * p_queue, uint32_t idx) {
    uint32_t nxt_idx = idx+1;
    if (nxt_idx >= p_queue->size) {
        nxt_idx %= p_queue->size;
    }
    return nxt_idx;
}

queue_status_t queue_push(simple_queue_t * p_queue, void * p_element) {
    memcpy((void*)((size_t)p_queue->p_buffer + (p_queue->back_idx)*(p_queue->element_size)), p_element, p_queue->element_size);
    p_queue->back_idx = queue_get_next_idx(p_queue, p_queue->back_idx);
    
    if (p_queue->back_idx == p_queue->front_idx) {
        p_queue->front_idx = queue_get_next_idx(p_queue, p_queue->front_idx);
        p_queue->is_full = true;
        return QUEUE_FULL;
    }

    return QUEUE_OK;
}

queue_status_t queue_pop(simple_queue_t * p_queue, void * p_element) {
    if (!queue_is_empty(p_queue)) {
        memcpy(p_element, (void*)((size_t)p_queue->p_buffer + (p_queue->front_idx)*(p_queue->element_size)), p_queue->element_size);
        p_queue->front_idx = queue_get_next_idx(p_queue, p_queue->front_idx);
        p_queue->is_full = false;
        return QUEUE_OK;
    }
    return QUEUE_EMPTY;
}

bool queue_is_empty(simple_queue_t * p_queue) {
    if (p_queue->is_full == true) return false;
    if (p_queue->front_idx == p_queue->back_idx) return true;
    return false;
}

uint32_t queue_current_size(simple_queue_t * p_queue) {
    if (p_queue->is_full) return p_queue->size;
    if (p_queue->back_idx >= p_queue->front_idx) {
        return ((p_queue->back_idx) - (p_queue->front_idx));
    }
    return (p_queue->size - p_queue->front_idx + p_queue->back_idx);
    
}

queue_status_t queue_peek_last(simple_queue_t  * p_queue, void * p_element) {
     if (!queue_is_empty(p_queue)) {
        memcpy(p_element, (void*)((size_t)p_queue->p_buffer + (p_queue->front_idx)*(p_queue->element_size)), p_queue->element_size);
        return QUEUE_OK;
    }
    return QUEUE_EMPTY;
}
