#pragma once
#include <cstdint>

namespace BE {
    enum instanceStatus {
        NONE,
        NOT_INITIALIZED,
        SUCCESSFULLY_INITIALIZED,
        DESTROYING,
        DESTROYED
    };

    struct beclGameData {
        char* game_version;
        std::uint32_t addy;
        std::uint16_t port;

        // FUNCTIONS
        using print_message_t = void(*)(char* msg);
        print_message_t printMessage;

        using request_restart_t = void(*)(std::uint32_t reason);
        request_restart_t requestRestart;

        using send_packet_t = void(*)(void* packet, std::uint32_t length);
        send_packet_t sendPacket;

        using disconnect_peer_t = void(*)(std::uint8_t guid, std::uint32_t guid_length, char* reason);
        disconnect_peer_t disconnectPeer;
    };

    struct beclBEData {
        using exit_t = bool(*)();
        exit_t exit;

        using run_t = void(*)();
        run_t run;

        using command_t = void(*)(char* command);
        command_t command;

        using received_packet_t = void(*)(std::uint8_t* receivedPacket, std::uint32_t length);
        received_packet_t receivedPacket;

        using on_receive_auth_ticket_t = void(*)(std::uint8_t* ticket, std::uint32_t length);
        on_receive_auth_ticket_t onReceiveAuthTicket;

        using add_peer_t = void(*)(std::uint8_t guid, std::uint32_t guidLength);
        add_peer_t addPeer;

        using remove_peer_t = void(*)(std::uint8_t guid, std::uint32_t guidLength);
        remove_peer_t removePeer;
    };
}