#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "lib.h"

void unique_elements(int32_t *array, size_t length)
{
    if (array == NULL)
    {
        return;
    }

    for (size_t i = 0; i < length; i++)
    {
        bool unique = true;
        int32_t current_value = array[i];

        for (size_t j = 0; j < length; j++)
        {
            //don't compare with same value (index i)
            if (i == j)
            {
                continue;
            }
            //if current value found again, it is not unique
            if (current_value == array[j])
            {
                unique = false;
            }
        }
        //after all values have been checked, print out if unique
        if (unique == true)
        {
            printf("%d\n", current_value);
        }

    }


}

void remove_duplicates(int32_t *array, size_t *length)
{
     if (array == NULL)
    {
        return;
    }

    for (size_t i = 0; i < *length; i++)
    {
        size_t duplicate_index = -1;
        int32_t current_value = array[i];

        for (size_t j = i + 1; j < *length; j++)
        {
            if (array[j] == current_value)
            {
                duplicate_index = j;
                (*length)--;
                break;
            }

        }

        if (duplicate_index == -1)
        {
            continue;
        }

        for (size_t j = duplicate_index; j < *length; j++)
        {
            array[j] = array[j+1];
        }

    }


}

void rotate_left(int32_t *array, size_t length)
{
     if (array == NULL)
    {
        return;
    }

    int32_t first_element = array[0];

    for (size_t i = 1; i < length; i++)
    {
        array[i-1] = array[i];
    }
    array[length-1] = first_element;

}

void rotate_right(int32_t *array, size_t length)
{
     if (array == NULL)
    {
        return;
    }
    int32_t last_element = array[length-1];

    for (size_t i = length-1; i > 0; i--)
    {
        array[i] = array[i-1];
    }
    array[0] = last_element;
}
