/*
  GC9A01 driver 

  Copyright (c) 2023, rspber (https://github.com/rspber)

*/

#pragma once

#include <TFT_ILI9xxx.h>

class TFT_GC9A01 : public TFT_ILI9xxx {
public:
  TFT_GC9A01() : TFT_ILI9xxx() {}

protected:
  void init()
  {
    sendCmd(0xEF);
    sendCmdByte(0xEB, 0x14);
    sendCmd(0xFE);
    sendCmd(0xEF);
    sendCmdByte(0xEB, 0x14);
    sendCmdByte(0x84, 0x40);
    sendCmdByte(0x85, 0xFF);
    sendCmdByte(0x86, 0xFF);
    sendCmdByte(0x87, 0xFF);
    sendCmdByte(0x88, 0x0A);
    sendCmdByte(0x89, 0x21);
    sendCmdByte(0x8A, 0x00);
    sendCmdByte(0x8B, 0x80);
    sendCmdByte(0x8C, 0x01);
    sendCmdByte(0x8D, 0x01);
    sendCmdByte(0x8E, 0xFF);
    sendCmdByte(0x8F, 0xFF);
    sendCmdData(0xB6, (uint8_t*)"\x00\x20", 2);
    sendCmdByte(0x3A, 0x05);
    sendCmdData(0x90, (uint8_t*)"\x08\x08\x08\x08", 4);
    sendCmdByte(0xBD, 0x06);
    sendCmdByte(0xBC, 0x00);
    sendCmdData(0xFF, (uint8_t*)"\x60\x01\x04", 3);
    sendCmdByte(0xC3, 0x13);
    sendCmdByte(0xC4, 0x13);
    sendCmdByte(0xC9, 0x22);
    sendCmdByte(0xBE, 0x11);
    sendCmdData(0xE1, (uint8_t*)"\x10\x0E", 2);
    sendCmdData(0xDF, (uint8_t*)"\x21\x0c\x02", 3);
    sendCmdData(0xF0, (uint8_t*)"\x45\x09\x08\x08\x26\x2A", 6);
    sendCmdData(0xF1, (uint8_t*)"\x43\x70\x72\x36\x37\x6F", 6);
    sendCmdData(0xF2, (uint8_t*)"\x45\x09\x08\x08\x26\x2A", 6);
    sendCmdData(0xF3, (uint8_t*)"\x43\x70\x72\x36\x37\x6F", 6);
    sendCmdData(0xED, (uint8_t*)"\x1B\x0B", 2);
    sendCmdByte(0xAE, 0x77);
    sendCmdByte(0xCD, 0x63);
    sendCmdData(0x70, (uint8_t*)"\x07\x07\x04\x0E\x0F\x09\x07\x08\x03", 9);
    sendCmdByte(0xE8, 0x34);
    sendCmdData(0x62, (uint8_t*)"\x18\x0D\x71\xED\x70\x70\x18\x0F\x71\xEF\x70\x70", 12);
    sendCmdData(0x63, (uint8_t*)"\x18\x11\x71\xF1\x70\x70\x18\x13\x71\xF3\x70\x70", 12);
    sendCmdData(0x64, (uint8_t*)"\x28\x29\xF1\x01\xF1\x00\x07", 7);
    sendCmdData(0x66, (uint8_t*)"\x3C\x00\xCD\x67\x45\x45\x10\x00\x00\x00", 10);
    sendCmdData(0x67, (uint8_t*)"\x00\x3C\x00\x00\x00\x01\x54\x10\x32\x98", 10);
    sendCmdData(0x74, (uint8_t*)"\x10\x85\x80\x00\x00\x4E\x00", 7);
    sendCmdData(0x98, (uint8_t*)"\x3e\x07", 2);
    sendCmd(0x35);
    sendCmd(0x21);
    sendCmd(0x11);
    delay(120);
    sendCmd(0x29);
    delay(20);
  }

};
