#include <stdio.h>
#include <string.h>
#include "../include/display.h"

typedef struct node
{
    t_Case key;
    struct node *left;
    struct node *right;
} node;
