#include <cassert>
#include <iostream>
#include "FloatingQueue.h"

int main()
{
    const int MAX_QUEUE_SIZE = 10;
    FloatingQueue<int> queue(MAX_QUEUE_SIZE);

    // Testing an empty queue
    assert(queue.length() == 0);
    std::cout << "1.\tAn empty queue should have no items in it: PASSED\n";

    assert(queue.isEmpty());
    std::cout << "2.\tAn empty queue should be empty: PASSED\n";

    assert(!queue.isFull());
    std::cout << "3.\tAn empty queue should not be full: PASSED\n";

    assert(!queue.dequeue());
    std::cout << "4.\tA client should not be able to dequeue from an empty queue: PASSED\n";

    // Pushing to the empty queue
    int item = 137;
    assert(queue.enqueue(item));
    std::cout << "5.\tPushing an item onto the empty queue should succeed: PASSED\n";

    assert(queue.length() == 1);
    std::cout << "6.\tPushing an item should increase queue's length by 1: PASSED\n";

    assert(queue.peek() == item);
    std::cout << "7.\tThe front item should be the most recently added item: PASSED\n";

    assert(!queue.isEmpty());
    std::cout << "8.\tA non-empty queue should not be empty: PASSED\n";

    assert(!queue.isFull());
    std::cout << "9.\tA non-full queue should not be full: PASSED\n";

    // Dequeueing from the queue
    assert(queue.dequeue());
    std::cout << "10.\tDequeueing the front item should return true: PASSED\n";

    assert(queue.length() == 0);
    std::cout << "11.\tDequeueing an item should decrease queue's length by 1: PASSED\n";

    // Filling the queue
    for (int i = 0; i < MAX_QUEUE_SIZE; i++)
    {
        assert(queue.enqueue(i * i - i));
    }

    assert(queue.isFull());
    std::cout << "12.\tA full queue should be full: PASSED\n";

    assert(!queue.isEmpty());
    std::cout << "13.\tA full queue should not be empty: PASSED\n";

    for (int i = 0; i < MAX_QUEUE_SIZE; i++)
    {
        item = queue.peek();
        assert(i * i - i == item);
        queue.dequeue();
    }
    std::cout << "14.\tPeeking and popping items happens in FIFO order: PASSED\n";

    // Clearing the queue
    // Fill it up again
    for (int i = 0; i < MAX_QUEUE_SIZE; i++)
    {
        assert(queue.enqueue(i * i - i));
    }

    queue.clear();
    assert(queue.isEmpty());
    std::cout << "15.\tClearing the queue should make the queue empty: PASSED\n";

    return 0;
}
