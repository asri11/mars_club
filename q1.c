#include <stdio.h>
#include <math.h>

// Function to calculate Euclidean distance
double calculate_distance(double x, double y, double z) {
    return sqrt(x * x + y * y + z * z);
}

// Transform marker position from camera frame to rover center frame
void transform_marker_position(double x, double y, double z,
                               double *x_final, double *y_final, double *z_final) {
    // The rover’s center is 55 cm behind the camera along the z-axis
    *x_final = x;
    *y_final = y;
    *z_final = z + 55; // moving backward in camera frame
}

int main() {
    double x, y, z;
    double x_final, y_final, z_final;

    // Example input
    printf("Enter marker coordinates in camera frame (x y z): ");
    scanf("%lf %lf %lf", &x, &y, &z);

    // Original distance from camera to marker
    double original_distance = calculate_distance(x, y, z);

    // Adjust for rover’s center
    transform_marker_position(x, y, z, &x_final, &y_final, &z_final);

    // New distance from rover center to marker
    double adjusted_distance = calculate_distance(x_final, y_final, z_final);

    // Output new position and distances
    printf("\nAdjusted Marker Position (Rover Frame): (%.2f, %.2f, %.2f)\n",
           x_final, y_final, z_final);
    printf("Distance (Camera Frame): %.2f cm\n", original_distance);
    printf("Distance (Rover Center Frame): %.2f cm\n", adjusted_distance);

    return 0;
}
