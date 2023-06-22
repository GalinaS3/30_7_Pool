#pragma once
#include"RequestHandler.h"

RequestHandler pool1;
std::future<void> fut;

void quicksort(std::shared_ptr<int[]> array, long left, long right)
{
    if (left >= right) return;
    long left_bound = left;
    long right_bound = right;

    long middle = array[(left_bound + right_bound) / 2];

    do {
        while (array[left_bound] < middle) {
            left_bound++;
        }
        while (array[right_bound] > middle) {
            right_bound--;
        }

        if (left_bound <= right_bound) {
            std::swap(array[left_bound], array[right_bound]);
            left_bound++;
            right_bound--;
        }
    } while (left_bound <= right_bound);

    if ((right_bound - left > 100'000))
    {
        std::packaged_task<void()> task([=]() { pool1.pushRequest(quicksort, array, left, right_bound); });

        quicksort(array, left_bound, right);

        fut = task.get_future();
        task();
    }
    else
    {
        quicksort(array, left, right_bound);
        quicksort(array, left_bound, right);
    }
}


void quicksort1(std::shared_ptr<int[]> array, long left, long right) {
    if (left >= right) return;
    long left_bound = left;
    long right_bound = right;

    long middle = array[(left_bound + right_bound) / 2];

    do {
        while (array[left_bound] < middle)
        {
            left_bound++;
        }
        while (array[right_bound] > middle)
        {
            right_bound--;
        }

        if (left_bound <= right_bound)
        {
            std::swap(array[left_bound], array[right_bound]);
            left_bound++;
            right_bound--;
        }
    } while (left_bound <= right_bound);
    quicksort1(array, left, right_bound);
    quicksort1(array, left_bound, right);
}



