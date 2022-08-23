#pragma once
#include "Logger.h"
#include "BEClient.h"

namespace BE {
    class Emulator {
    public:
        Emulator() : m_logger() {}

        void setupBE(BE::beclGameData* gameData, BE::beclBEData* clientData);

        inline loggr& console() {
            return this->m_logger;
        }

    private:
        loggr m_logger;
    };
}