#include <stdint.h>
#include <stdio.h>

enum LaneAssociationType
{
    LANE_ASSOCIATION_TYPE_UNKNOWN,
    LANE_ASSOCIATION_TYPE_RIGHT,
    LANE_ASSOCIATION_TYPE_CENTER,
    LANE_ASSOCIATION_TYPE_LEFT
};

int main()
{
    float current_speed;
    enum LaneAssociationType lane;
    printf("Create the properties of a vehicle.\n");
    printf("Speed in m/s: ");
    scanf("%f",&current_speed);
    printf("Lane (1=Right, 2=Center, 3=Left): ");
    scanf("%u",&lane);

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

    printf("Speed: %f\n",current_speed);

    return 0;
}
