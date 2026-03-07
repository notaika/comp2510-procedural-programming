#include <stdio.h>

int main() {
    int access_code = 1234;
    int user_input;

    printf("=== SECURITY SYSTEM ===\n");
    printf("Enter code to disarm: ");
    scanf("%d", &user_input);

    if (user_input == access_code) {
        printf("Access Granted.\n");
        printf("System Disarmed.\n");
    }
    
    // Note: If they type the wrong code, "Access Denied" should print.
    // If they type the right code, "Access Denied" should NOT print.
    if (user_input != access_code) {
        printf("Access Denied. Alarm triggered!\n");
    }

    return 0;
}