#ifndef AD_TYPES_H
#define AD_TYPES_H

enum LaneAssociationType
{
    LANE_ASSOCIATION_TYPE_NONE,
    LANE_ASSOCIATION_TYPE_LEFT,
    LANE_ASSOCIATION_TYPE_CENTER,
    LANE_ASSOCIATION_TYPE_RIGHT,
};

enum LogitudinalAction
{
    LOGITUDINAL_ACTION_NONE,
    LOGITUDINAL_ACTION_ACCELERATE = 'w',
    LOGITUDINAL_ACTION_DECELERATE = 's',
};

enum LateralAction
{
    LATERAL_ACTION_NONE,
    LATERAL_ACTION_LEFT = 'a',
    LATERAL_ACTION_RIGHT = 'd',
};

#endif
