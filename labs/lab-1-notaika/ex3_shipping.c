#include <stdio.h>
// Note: In C23, 'bool', 'true', and 'false' are built-in keywords.
// No extra headers are needed!

int main() {
    float weight, distance;
    bool is_overnight = false;
    float shipping_cost = 0.0;

    // Temporary variable to hold the user's 1 or 0 input
    char overnight_input;

    printf("=== Jungle Shipping Calculator (C23 Edition) ===\n");

    // 1. Get Weight
    printf("Enter package weight (kg): ");
    scanf("%f", &weight);

    // 2. Get Distance
    printf("Enter distance (km): ");
    scanf("%f", &distance);

    // 3. Get Shipping Method
    // Note the space before %c
    // This consumes the '\n' left over from the previous scanf
    printf("Overnight shipping? (y for Yes, n for No): ");
    scanf(" %c", &overnight_input);

    // Convert char input to boolean
    if (overnight_input == 'y' || overnight_input == 'Y') {
        is_overnight = true;
    } else {
        is_overnight = false;
    }

    // --- YOUR CODE STARTS HERE ---

    // LOGIC STEP 1: Validate Input
    // If weight is <= 0 OR distance <= 0:
    // Print "Invalid input" and return 1 (error code).
    // TODO: Write the if statement here...
    if (weight <= 0 || distance <= 0) {
        printf("Invalid input.");

        return 1;
    }

    // LOGIC STEP 2: Calculate Base Cost
    // Rules:
    // - Base cost is always $5.00
    // - If weight is more than 5kg, add $2.00 for every kg OVER 5.
    //   (Example: 7kg package = $5 base + (2 * $2 extra) = $9)
    // TODO: Write the math/logic here...
    shipping_cost = 5.00;

    const int WEIGHT_LIMIT = 5;

    if (weight > WEIGHT_LIMIT) {
        const float WEIGHT_FEE = 2.00;
        int extra_weight = (int) (weight - WEIGHT_LIMIT);

        shipping_cost += (extra_weight * WEIGHT_FEE);
    }

    // LOGIC STEP 3: Distance Surcharge
    // Rules:
    // - If distance is greater than 100km, add $0.10 per km OVER 100.
    // TODO: Write the math/logic here...
    const int DISTANCE_LIMIT = 100;

    if (distance > DISTANCE_LIMIT) {
        const float DISTANCE_FEE = 0.10;
        int extra_distance = (int) (distance - DISTANCE_LIMIT);

        shipping_cost += extra_distance * DISTANCE_FEE;
    }

    // LOGIC STEP 4: Overnight Delivery Modifier
    // Rules:
    // - Use the 'is_overnight' boolean variable.
    // - If it is true, double the current shipping_cost.
    // TODO: Write the if statement here...
    if (is_overnight) {
        shipping_cost *= 2;
    }

    // --- YOUR CODE ENDS HERE ---

    printf("\nTotal Shipping Cost: $%.2f\n", shipping_cost);

    return 0;
}