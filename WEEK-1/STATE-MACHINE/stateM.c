#include <stdio.h>
#include <unistd.h> // for sleep()

// 1️⃣ Define all possible states using an enum
typedef enum {
    STATE_RED,
    STATE_GREEN,
    STATE_YELLOW
} TrafficLightState;

// 2️⃣ Function to print the current state
void print_state(TrafficLightState state) {
    switch (state) {
        case STATE_RED:
            printf("State: RED - Stop\n");
            break;
        case STATE_GREEN:
            printf("State: GREEN - Go\n");
            break;
        case STATE_YELLOW:
            printf("State: YELLOW - Slow Down\n");
            break;
    }
}

// 3️⃣ Function to move to the next state
TrafficLightState get_next_state(TrafficLightState current) {
    switch (current) {
        case STATE_RED:
            return STATE_GREEN;
        case STATE_GREEN:
            return STATE_YELLOW;
        case STATE_YELLOW:
            return STATE_RED;
        default:
            return STATE_RED; // Default fallback
    }
}

int main() {
    TrafficLightState current_state = STATE_RED;

    while (1) {
        print_state(current_state);        // Display the current state
        sleep(3);                          // Wait for 1 second (simulate delay)
        current_state = get_next_state(current_state); // Transition to next state
    }

    return 0;
}

