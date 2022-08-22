#pragma once
#include <windows.h>
#include <iostream>
#include <chrono>
#include <fmt\core.h>

// HyperionCSharp: TODO: Will finish in a later repo update

class logger {
public:
    logger() {
        // SETUP CONSOLE IF NOT PRESENT
        auto consoleWindow = GetConsoleWindow();
        if (consoleWindow == 0x00) {
            if (!AllocConsole()) {
                // NEVER HAPPEN????
                return;
            }

            std::freopen("CONOUT$", "w", stdout);

            mDidAllocateConsole = true;
        }
    }
    ~logger() {
        // FREE CONSOLE IF DYNAMICALLY ALLOCATED
        if (mDidAllocateConsole) {
            const auto freed = FreeConsole();

            if (!freed) {
                // ??
            }
        }
    }

    // CONSOLE LOGGING FUNCTIONS
    template <class...T>
            inline void logRaw(T... args) const {
        fmt::print(args...);
    }
};