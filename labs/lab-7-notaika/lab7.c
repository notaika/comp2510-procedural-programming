/*
 * Lab 7 Programming Task: Sensor Data System
 *
 * Compile:
 *   gcc -Wall -Wextra lab7.c -o lab7
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Typedef struct representing a sensor reading
typedef struct {
    int device_id;
    double temperature;
    char *location;
} SensorData_t;

void strcopy(char * location,
            const char * loc);

// Task A: Allocate memory for the struct AND the string, then initialize.
SensorData_t* create_sensor_data(int id, double temp, const char *loc) {
    // TODO: 1. Allocate memory for the SensorData_t struct
    SensorData_t *data = malloc(sizeof(SensorData_t));
    if (data == NULL)
    {
        perror("ERROR: Memory Allocation Failed for SensorData");
        return nullptr; //nullptr_t
    }

    // TODO: 2. Allocate memory for the location string (don't forget the null terminator!)
    data->location = malloc(strlen(loc) + 1);
    if (data->location == NULL)
    {
        perror("ERROR: Memory Allocation Failed for SensorData");
        free(data);
        return nullptr;
    }

    // TODO: 3. Copy the string and assign the other variables
    // up to strlen(loc) + 1) <- prevents overflow
    strncpy(data->location, loc, strlen(loc) + 1);

    data->temperature = temp;
    data->device_id = id;

    // TODO: 4. Return the new struct
    return data;
}

// Task B.1: Safely append the sensor data to a file.
int log_sensor_data(const SensorData_t *data, const char *filename) {
    // TODO: 1. Open file in append mode
    FILE *fp = fopen(filename, "a");

    // TODO: 2. Check if file opened successfully (return 0 if not and print to stderr)
    if (fp == NULL)
    {
        fprintf(stderr, "ERROR: File not found.\n");
        return 0;
    }

    // TODO: 3. Print "[ID] Location: Temperature\n" to the file
    fprintf(fp, "[%d] %s: %.2f\n", data->device_id, data->location, data->temperature);

    // TODO: 4. Close the file
    fclose(fp);

    // TODO: 5. Return 1 for success
    return 1;
}

int main(void) {
    const char *logfile = "sensor_logs.txt";

    // Create dynamic sensor data
    SensorData_t *sensor1 = create_sensor_data(101, 22.5, "Server Room A");
    if (sensor1 == NULL) {
        fprintf(stderr, "Failed to create sensor1 data.\n");
        return 1;
    }

    SensorData_t *sensor2 = create_sensor_data(205, -4.2, "External Roof Array");
    if (sensor2 == NULL) {
        fprintf(stderr, "Failed to create sensor2 data.\n");

        // Must free sensor1 before exiting to prevent memory leaks!
        free(sensor1->location);
        free(sensor1);
        return 1;
    }

    // Log the data to a file
    printf("Logging sensor 1... %s\n", log_sensor_data(sensor1, logfile) ? "Success" : "Failed");
    printf("Logging sensor 2... %s\n", log_sensor_data(sensor2, logfile) ? "Success" : "Failed");

    // Task B.2: Clean up memory (Freeing order matters!)
    free(sensor1->location);
    free(sensor1);

    free(sensor2->location);
    free(sensor2);

    printf("Check '%s' to verify your output!\n", logfile);

    return 0;
}