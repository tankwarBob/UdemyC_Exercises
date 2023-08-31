#include <stdint.h>
#include <stdio.h>

#include "AdFunctions.h"
#include "AdTypes.h"

void  print_scene(float speed_mps, uint32_t lane_idx){

    enum LaneAssociationType lane;

    lane = lane_idx;

    switch (lane)
    {
    case LANE_ASSOCIATION_TYPE_RIGHT:
        printf("  L   C   R\n");
        printf("|   |   | V |\n");
        break;
    case LANE_ASSOCIATION_TYPE_LEFT:
        printf("  L   C   R\n");
        printf("| V |   |   |\n");
        break;
    case LANE_ASSOCIATION_TYPE_CENTER:
        printf("  L   C   R\n");
        printf("|   | V |   |\n");
        break;
    default:
        printf("  L   C   R\n");
        printf("| X | X | X |\n");
        break;
    }

    printf("Speed: %f\n",speed_mps);
}
