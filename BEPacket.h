#pragma once
#include <cstdint>

namespace BE {
    enum packetID : std::uint8_t {
        INIT        = 0x00,
        START       = 0x02,
        REQ         = 0x04,
        RES         = 0x05,
        HEARTBEAT   = 0x09,
    };

#pragma pack(push, 1)
    struct beFragment {
        std::uint8_t count;
        std::uint8_t index;
    };

    struct bePacketHeader {
        std::uint8_t ID;
        std::uint8_t sequence;
    };

    struct bePacket : bePacketHeader {
        union {
            beFragment fragment;

            // DATA STARTS AT body[1] IF PACKET IS FRAGMENTED
            struct {
                std::uint8_t noFragmentationFlag;
                std::uint8_t body[0];
            };
        };

        inline bool fragmented() {
            return this->fragment.count != 0x00;
        }
    };

#pragma pack(pop)
}