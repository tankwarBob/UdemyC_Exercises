#include <stdbool.h>

#include "lib.h"

bool is_numeric(const char character)
{
    if ((character >= '0') && (character <= '9'))
    {
        return true;
    }
    else{
        return false;
    }
}

bool is_alpha(const char character)
{
    if (is_upper_case(character) || is_lower_case(character))
    {
        return true;
    }
    else{
        return false;
    }
}

bool is_alpha_numeric(const char character)
{
    if (is_alpha(character) || is_numeric(character))
    {
        return true;
    }
    else{
        return false;
    }
}

bool is_upper_case(const char character)
{
    if ((character >= 'A') && (character <= 'Z'))
    {
        return true;
    }
    else{
        return false;
    }
}

bool is_lower_case(const char character)
{
    if ((character >= 'a') && (character <= 'z'))
    {
        return true;
    }
    else{
        return false;
    }
}

char to_upper_case(const char character)
{
    if (is_lower_case(character))
    {
        return character - 32;
    }
    else{
        return character;
    }
}

char to_lower_case(const char character)
{
    if (is_upper_case(character))
    {
        return character + 32;
    }
    else{
        return character;
    }
}
