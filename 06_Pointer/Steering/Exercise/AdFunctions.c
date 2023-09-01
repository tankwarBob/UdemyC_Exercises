#include <stdint.h>
#include <stdio.h>

#include "AdFunctions.h"
#include "AdTypes.h"
#include "AdConstants.h"

void get_user_input(float *speed_mps, uint32_t *lane_idx){

    printf("\n");

    char longitudinal_action;
    printf("LongitudinalAction (w=Increase, s=Decrease): ");
    scanf(" %c", &longitudinal_action);
    printf("\n");

    char lateral_action;
    printf("LateralAction (a=Left, d=Right): ");
    scanf(" %c", &lateral_action);

    handle_lateral_user_input(lane_idx, lateral_action);
    handle_longitudinal_user_input(speed_mps, longitudinal_action);

}

void handle_lateral_user_input(uint32_t *lane_idx,char lateral_action){
    switch (lateral_action)
    {
    case LATERAL_ACTION_LEFT:
        switch (*lane_idx)
        {
        case LANE_ASSOCIATION_TYPE_LEFT:
            // Steer left on left lane -> not on a lane anymore
            *lane_idx = LANE_ASSOCIATION_TYPE_NONE;
            break;
        case LANE_ASSOCIATION_TYPE_CENTER:
            // Steer left on center lane -> result on left lane
            *lane_idx = LANE_ASSOCIATION_TYPE_LEFT;
            break;
        case LANE_ASSOCIATION_TYPE_RIGHT:
            // Steer left on right lane -> result on center lane
            *lane_idx = LANE_ASSOCIATION_TYPE_CENTER;
            break;
        case LANE_ASSOCIATION_TYPE_NONE:
        default:
            return;
            break;
        }
        break;
    case LATERAL_ACTION_RIGHT:
        switch (*lane_idx)
        {
        case LANE_ASSOCIATION_TYPE_LEFT:
            // Steer right on left lane -> result on center lane
            *lane_idx = LANE_ASSOCIATION_TYPE_CENTER;
            break;
        case LANE_ASSOCIATION_TYPE_CENTER:
            // Steer right on center lane -> result on right lane
            *lane_idx = LANE_ASSOCIATION_TYPE_RIGHT;
            break;
        case LANE_ASSOCIATION_TYPE_RIGHT:
            // Steer right on right lane -> not on a lane anymore
            *lane_idx = LANE_ASSOCIATION_TYPE_NONE;
            break;
        case LANE_ASSOCIATION_TYPE_NONE:
        default:
            return;
            break;
        }
        break;
    case LATERAL_ACTION_NONE:
    default:
        break;
    }

}

void handle_longitudinal_user_input(float *speed_mps,char longitudinal_action){
    switch (longitudinal_action)
    {
    case LOGITUDINAL_ACTION_ACCELERATE:
        if (*speed_mps > 0)
        {
            *speed_mps =
            *speed_mps + *speed_mps * LONGITUDINAL_DIFFERENCE_PERCENTAGE;
        }
        else
            *speed_mps = 0.1f;

        break;
    case LOGITUDINAL_ACTION_DECELERATE:
        *speed_mps =
        *speed_mps - *speed_mps * LONGITUDINAL_DIFFERENCE_PERCENTAGE;

        break;
    case LOGITUDINAL_ACTION_NONE:
    default:
        break;
    }
}

void print_scene(float speed_mps, uint32_t lane_idx)
{
    printf("\n\n");
    printf("\t  L   C   R\n");

    switch (lane_idx)
    {
    case LANE_ASSOCIATION_TYPE_LEFT:
    {
        printf("\t| V |   |   |\n");
        break;
    }
    case LANE_ASSOCIATION_TYPE_CENTER:
    {
        printf("\t|   | V |   |\n");
        break;
    }
    case LANE_ASSOCIATION_TYPE_RIGHT:
    {
        printf("\t|   |   | V |\n");
        break;
    }
    case LANE_ASSOCIATION_TYPE_NONE:
    default:
    {
        printf("\t|   |   |   |\n");
        break;
    }
    }

    printf("\n");
    printf("Speed: %f\n", speed_mps);
    printf("\n");
}
