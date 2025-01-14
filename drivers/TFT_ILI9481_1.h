/*
  ILI9481_1 driver, default

  Copyright (c) 2023, rspber (https://github.com/rspber)

*/

#pragma once

#include "TFT_ILI9x81.h"

class TFT_ILI9481_1 : public TFT_ILI9x81 {
public:
  TFT_ILI9481_1() : TFT_ILI9x81() {}

  void init()
  {
    sendCmd(TFT_SLPOUT);
    delay(20);
    sendCmdData(ILI9481_POWERSET, (uint8_t*)"\x07\x42\x18", 3);
    sendCmdData(ILI9481_VCOMCTL, (uint8_t*)"\x00\x07\x10", 3);
    sendCmdData(ILI9481_POWNORMD, (uint8_t*)"\x01\x02", 2);
    sendCmdData(ILI9481_PANELDRV, (uint8_t*)"\x10\x3B\x00\x02\x11", 5);
    sendCmdByte(ILI9481_FRAINCTL, 0x03);
    sendCmdData(ILI9481_GAMMASET, (uint8_t*)"\x00\x32\x36\x45\x06\x16\x37\x75\x77\x54\x0C\x00", 12);
    sendCmdByte(TFT_MADCTL, 0x0A);
    sendCmdByte(TFT_PIXFMT, TFT_PIXFMT_VALUE);
    //sendCmd(TFT_INVON);
    sendCmd(TFT_DISPON);
    delay(25);
  }

};
