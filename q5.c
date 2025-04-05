#include <stdio.h>
#include <math.h>

// Convert degrees to radians
double deg_to_rad(double degrees) {
    return degrees * M_PI / 180.0;
}

// Convert Euler angles to Quaternion
void euler_to_quaternion(double roll, double pitch, double yaw,
                         double *w, double *x, double *y, double *z) {
    // Convert angles to radians
    roll = deg_to_rad(roll);
    pitch = deg_to_rad(pitch);
    yaw = deg_to_rad(yaw);

    // Calculate trigonometric values
    double cy = cos(yaw * 0.5);
    double sy = sin(yaw * 0.5);
    double cp = cos(pitch * 0.5);
    double sp = sin(pitch * 0.5);
    double cr = cos(roll * 0.5);
    double sr = sin(roll * 0.5);

    // Quaternion formula
    *w = cr * cp * cy + sr * sp * sy;
    *x = sr * cp * cy - cr * sp * sy;
    *y = cr * sp * cy + sr * cp * sy;
    *z = cr * cp * sy - sr * sp * cy;
}

int main() {
    double roll, pitch, yaw;
    double w, x, y, z;

    printf("Enter Roll (degrees): ");
    scanf("%lf", &roll);
    printf("Enter Pitch (degrees): ");
    scanf("%lf", &pitch);
    printf("Enter Yaw (degrees): ");
    scanf("%lf", &yaw);

    euler_to_quaternion(roll, pitch, yaw, &w, &x, &y, &z);

    printf("\n👽 Martian Quaternion Representation:\n");
    printf("W: %.6f\n", w);
    printf("X: %.6f\n", x);
    printf("Y: %.6f\n", y);
    printf("Z: %.6f\n", z);

    return 0;
}
