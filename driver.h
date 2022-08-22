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

    template<typename T>
    void write(const SOCKET connection, const uint32_t process_id, const uintptr_t address, size_t buffer) {
        write_mem(connection, process_id, address, uint64_t(&buffer), sizeof(T));
    }
}

class Vector3 {
public:
    Vector3() : x(0.f), y(0.f), z(0.f) {
        // None
    }

    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {
        // None
    }

    ~Vector3() {
        // None
    }

    float x;
    float y;
    float z;

    inline float Dot(Vector3 v) {
        return x * v.x, y * v.y, z * v.z;
    }

    inline float Distance(Vector3 v) {
        return float(sqrtf(powf(v.x - x, 2.0) + powf(v.y - y, 2.0) + powf(v.z - z, 2.0)));
    }

    Vector3 operator+(Vector3 v) {
        return Vector3(x + v.x, y + v.y, z + v.z);
    }

    Vector3 operator-(Vector3 v) {
        return Vector3(x - v.x, y - v.y, z - v.z);
    }

    Vector3 operator*(float number) const {
        return Vector3(x * number, y * number, z * number);
    }
};
