#ifndef VARIABLES_H
#define VARIABLES_H

typedef struct {

	double x, y, z;

} Position;
typedef enum {
	Left_corner,
	Right_corner,
	Center,
	Left_side,
	Right_side
} Position_of_shooting;
#define PI 3.14159265358979323
#define TIMER_ID 0
#define TIMER_INTERVAL 20
#define G 9.81
#endif
