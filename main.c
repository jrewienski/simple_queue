#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include "simple_queue.h"

#define QUEUE_SIZE  10

DEF_QUEUE(uint8_t, myq, QUEUE_SIZE);

int main() {
    uint8_t test_val = 0;

    /* Check empty queue. */
    assert(queue_peek_last(&myq, &test_val) == QUEUE_EMPTY);

    /* Add 3 elements and check size. */
    for (int i = 1; i < 4; i++) {
        assert(queue_push(&myq, &i) == QUEUE_OK);
    }
    assert(queue_current_size(&myq) == 3);

    /* Pop 3 elements, check if valid and check size. */
    for (int i = 1; i < 4; i++) {
        assert(queue_pop(&myq, &test_val) == QUEUE_OK);
        assert(test_val == i);
    }
    assert(queue_current_size(&myq) == 0);

    /* Make the queue almost full, check size. */
    for (int i = 1; i < QUEUE_SIZE; i++) {
        assert(queue_push(&myq, &i) == QUEUE_OK);
        assert(queue_current_size(&myq) == i);
    }

    /* Add LAST element to make queue full*/
    test_val = QUEUE_SIZE;
    assert(queue_push(&myq, &test_val) == QUEUE_FULL);
    assert(queue_current_size(&myq) == QUEUE_SIZE);

    /* Continue adding elements, queue size to remain max */
    for (int i = QUEUE_SIZE + 1; i < 2*QUEUE_SIZE; i++) {
        assert(queue_push(&myq, &i) == QUEUE_FULL);
        assert(queue_current_size(&myq) == QUEUE_SIZE);
    }

    /* Peek last element and check if it's correct. */
    uint32_t current_size;
    uint8_t current_val = 0; 
    current_size = queue_current_size(&myq);
    assert(queue_peek_last(&myq, &current_val) == QUEUE_OK);
    assert(queue_current_size(&myq) == current_size);

    /* Try again, checking if the size has not changed and element is the same. */
    assert(queue_peek_last(&myq, &test_val) == QUEUE_OK);
    assert(test_val == current_val);
    assert(queue_current_size(&myq) == current_size);

    /* Empty the queue */
    for (int i = QUEUE_SIZE + 1; i < 2*QUEUE_SIZE; i++) {
        assert(queue_pop(&myq, &test_val) == QUEUE_OK);
        assert(test_val == i);
    }


    /* Pop further, check if value is being changed */
    test_val = 200;
    current_val = test_val;
    for (int i = 0; i < QUEUE_SIZE*100; i++) {
        assert(queue_pop(&myq, &current_val) == QUEUE_EMPTY);
        assert(test_val == current_val);
    }

}
