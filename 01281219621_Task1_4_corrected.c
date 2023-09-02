#include <stdio.h>

// Function to calculate the average of two values
float average(float value1, float accuracy1, float value2, float accuracy2)
{
    // Weighted average calculation
    float weightedSum = (value1 / accuracy1) + (value2 / accuracy2);
    float totalAccuracy = (1 / accuracy1) + (1 / accuracy2);
    return weightedSum / totalAccuracy;
}

int main()
{
    // Define the input arrays
    float mpu6050[10] = {0.0, 11.68, 18.95, 23.56, 25.72, 25.38, 22.65, 18.01, 10.14, -0.26};
    float bno55[10] = {0.0, 9.49, 16.36, 21.2, 23.16, 22.8, 19.5, 14.85, 6.79, -2.69};

    // Calculate the output array
    float output[10];
    int i;
    for (i = 0; i < 10; i++)
    {
        output[i] = average(mpu6050[i], 0.79, bno55[i], 0.92);
    }

    // Print the output array
    printf("Output: ");
    for (i = 0; i < 10; i++)
    {
        printf("%.2f ", output[i]);
    }

    return 0;
}
