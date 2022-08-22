#pragma once
#include <WinSock2.h>
#include <cstdint>
#include <math.h>

namespace Driver {
    void Initialize();
    void DeInitialize();

    SOCKET Connect();
    void   Disconnect(SOCKET connection);

    uint32_t read_mem(SOCKET connection, uint32_t process_id, uintptr_t address, uintptr_t buffer, size_t size);
    uint32_t write_mem(SOCKET connection, uint32_t process_id, uintptr_t address, uintptr_t buffer, size_t size);
    uint64_t get_process_base_address(SOCKET connection, uint32_t process_id);

    template<typename T>
    T read(const SOCKET connection, const uint32_t process_id, const uintptr_t address) {
        T buffer{ };
        read_mem(connection, process_id, address, uint64_t(&buffer), sizeof(T));

        return buffer;
    }

    // HyperionCSharp: TODO: Will Add More Tmr Because Im Sleep And Need To Rest My C++ Brain
}