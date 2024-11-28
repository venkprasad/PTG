#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

// Enum to represent different types of events
enum EventType {
    TAP,
    SWIPE
};

// Event class to store event data
class Event {
public:
    EventType eventType;
    int x, y;  // Coordinates of the event
    int endX, endY;  // For swipe events, we store the end coordinates
    string timestamp;

    // Constructor for Tap event
    Event(EventType type, int x, int y) : eventType(type), x(x), y(y), endX(-1), endY(-1) {
        timestamp = getCurrentTimestamp();
    }

    // Constructor for Swipe event
    Event(EventType type, int x, int y, int endX, int endY) : eventType(type), x(x), y(y), endX(endX), endY(endY) {
        timestamp = getCurrentTimestamp();
    }

    // Helper method to get the current timestamp
    string getCurrentTimestamp() {
        auto now = chrono::system_clock::now();
        time_t now_time = chrono::system_clock::to_time_t(now);
        char buf[100];
        strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&now_time));
        return string(buf);
    }
};

// EventQueue class to store and process events
class EventQueue {
private:
    queue<Event> events;

public:
    // Add event to the queue
    void enqueue(const Event& event) {
        events.push(event);
    }

    // Process the next event in the queue
    void processNextEvent() {
        if (!events.empty()) {
            Event currentEvent = events.front();
            events.pop();
            cout << "\nProcessing event at " << currentEvent.timestamp << ":\n";
            // Handle different event types
            if (currentEvent.eventType == TAP) {
                handleTapEvent(currentEvent);
            } else if (currentEvent.eventType == SWIPE) {
                handleSwipeEvent(currentEvent);
            }
        } else {
            cout << "No events in the queue to process.\n";
        }
    }

    // Get the size of the queue
    size_t size() const {
        return events.size();
    }

private:
    // Handle Tap event: Display the tapped position
    void handleTapEvent(const Event& event) {
        cout << "Tap event at position (" << event.x << ", " << event.y << ")\n";
    }

    // Handle Swipe event: Calculate and display swipe direction
    void handleSwipeEvent(const Event& event) {
        string direction;
        if (event.endX > event.x) {
            direction = "Right";
        } else if (event.endX < event.x) {
            direction = "Left";
        } else if (event.endY > event.y) {
            direction = "Down";
        } else if (event.endY < event.y) {
            direction = "Up";
        } else {
            direction = "Invalid Swipe";
        }

        cout << "Swipe event from (" << event.x << ", " << event.y << ") to (" 
             << event.endX << ", " << event.endY << "). Direction: " << direction << endl;
    }
};

// Function to simulate random event generation
void generateRandomEvents(EventQueue& eventQueue) {
    srand(time(0));  // Seed for random number generation

    for (int i = 0; i < 5; ++i) {
        int eventType = rand() % 2;  // Randomly choose between Tap and Swipe

        int x = rand() % 500;        // Random x coordinate
        int y = rand() % 500;        // Random y coordinate

        if (eventType == TAP) {
            // Create a Tap event
            Event event(TAP, x, y);
            eventQueue.enqueue(event);
        } else if (eventType == SWIPE) {
            // Create a Swipe event with random end coordinates
            int endX = rand() % 500;
            int endY = rand() % 500;
            Event event(SWIPE, x, y, endX, endY);
            eventQueue.enqueue(event);
        }
    }
}

int main() {
    EventQueue eventQueue;

    // Simulate generating random events
    generateRandomEvents(eventQueue);

    // Process events in the queue
    while (eventQueue.size() > 0) {
        eventQueue.processNextEvent();
        this_thread::sleep_for(chrono::seconds(1));  // Wait 1 second between processing events
    }

    return 0;
}
