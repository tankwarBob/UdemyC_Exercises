#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "lib.h"

bool all_of(int32_t *array, size_t length, int32_t value)
{
    if (array == NULL)
    {
        return false;
    }

    for (size_t i = 0; i < length; i++)
    {
        if (array[i] != value)
        {
            return false; // if one of the values is different, return false
        }
    }
    return true;
}

bool any_of(int32_t *array, size_t length, int32_t value)
{
    if (array == NULL)
    {
        return false;
    }
    for (size_t i = 0; i < length; i++)
    {
        if (array[i] == value)
        {
            return true; // if one of the values is equal, return true
        }
    }
    return false;
}

bool none_of(int32_t *array, size_t length, int32_t value)
{
    if (array == NULL)
    {
        return false;
    }
    for (size_t i = 0; i < length; i++)
    {
        if (array[i] == value)
        {
            return false; // if one of the values is equal, return false
        }
    }
    return true;
}

size_t count(int32_t *array, size_t length, int32_t value)
{
    if (array == NULL)
    {
        return 0;
    }
    size_t counter = 0;

    for (size_t i = 0; i < length; i++)
    {
        if (array[i] == value)
        {
            counter++;
        }
    }
    return counter;

}
