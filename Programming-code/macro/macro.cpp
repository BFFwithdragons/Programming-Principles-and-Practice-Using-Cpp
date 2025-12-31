#include <atomic>
#include <iostream>
#include <thread>
#include <unistd.h>
#include <cstdlib> // for system()

std::atomic<bool> toggle(false);
std::atomic<bool> running(true);

// Press a key using wtype
void pressKey(const std::string &key) {
    std::string command = "wtype -M 200 " + key; // -M 200 = hold 200ms
    system(command.c_str());
}

// Macro loop
void macroLoop() {
    while (running) {
        if (toggle) {
            pressKey("w");       // Press W
            usleep(2000 * 1000); // wait 2s
            pressKey("space");   // Press Space
            usleep(500 * 1000);  // wait 0.5s
            pressKey("e");       // Press E
            usleep(3000 * 1000); // wait 3s
        } else {
            usleep(100 * 1000);
        }
    }
}

int main() {
    std::thread macroThread(macroLoop);

    std::cout << "Macro ready. Press 1 to toggle ON/OFF, 0 to quit.\n";
    int input;
    while (true) {
        std::cin >> input;
        if (input == 1) {
            toggle = !toggle;
            std::cout << "Macro " << (toggle ? "ON" : "OFF") << "\n";
        } else if (input == 0) {
            running = false;
            break;
        }
    }

    macroThread.join();
    return 0;
}