#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "lib.h"

bool array_equal(int32_t *array1,
                 size_t length1,
                 int32_t *array2,
                 size_t length2)
{
    if (array1 == NULL || array2 == NULL || length1 != length2)
    {
        return false;
    }

    for (size_t i = 0; i < length1; i++)
    {
        if (array1[i] != array2[i])
        {
            //if one element is different, return false
            return false;
        }
    }
    return true;


}

void array_clamp(int32_t *array,
                 size_t length,
                 int32_t min_value,
                 int32_t max_value)
{
    if (array == NULL)
    {
        return;
    }
    for (size_t i = 0; i < length; i++)
    {
        if (array[i] < min_value)
        {
            array[i] = min_value;
        }
        if (array[i] > max_value)
        {
            array[i] = max_value;
        }

    }

}

void array_reverse(int32_t *array, size_t length)
{
    if (array == NULL)
    {
        return;
    }

    int32_t temp_value = 0;
    size_t j = length-1;
    for (size_t i = 0; i < length/2; i++)
    {
        temp_value = array[i];
        array[i] = array[j];
        array[j] = temp_value;
        j--;
    }

}

void array_fill_n(int32_t *array, size_t length, size_t n, int32_t value)
{
    if (array == NULL)
    {
        return;
    }
    if (n > length)
    {
        n = length;
    }

    for (size_t i = 0; i < n; i++)
    {
        array[i] = value;
    }

}
