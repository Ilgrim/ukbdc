#pragma once

#include "rawhid.h"

/* Packet types */
#define PING                    0x00
#define PONG                    0x01
#define MSG_START               0x02
#define MSG_CONT                0x03
#define RESET_PROTO             0x04

/* Message types */
#define MESSAGE_DFU			0x00
#define MESSAGE_WRITE_PAGE		0x01
#define MESSAGE_ACTIVATE_LAYOUT		0x02
#define MESSAGE_DEACTIVATE_LAYOUT	0x03

#define MSG_HDR_SIZE		3

/* Statuses */
#define IDLE			0
#define UNEXPECTED_CONT_ERROR	1
#define CRC_ERROR		2
#define RECEIVING_MESSAGE	3
#define EXECUTING		4
#define MESSAGE_ERROR		6
#define BUSY_ERROR		7
#define WRONG_MESSAGE_ERROR	8

struct RAWHID_packet {
	uint8_t header;
	uint8_t payload[RAWHID_SIZE - 1];
};

struct RAWHID_state {
	uint8_t status;
	int recvd;
	int len;
	uint16_t crc;
	uint8_t msg[256];
};

void RAWHID_PROTOCOL_task();
void RAWHID_PROTOCOL_handle_packet(uint8_t __attribute__((unused)) flags);
