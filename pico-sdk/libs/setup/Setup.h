/*
  Setup for TSDesktop

  Copyright (c) 2023, rspber (https://github.com/rspber)

*/

#pragma once

// ---------------- Constans to use in REV and ROTATION ----------------------

#define MAD_MY  0x80  // 00 top to botom, 80 bottom to top
#define MAD_MX  0x40  // 00 left to right, 40 right to left
#define MAD_YX  0x20  // it means that X and Y are exchanged, wrongly called MV
//#define MAD_MV  0x10  // vertical refresh direction, wrongly called ML
//#define MAD_RGB 0x00
//#define MAD_BGR 0x08
//#define MAD_MH  0x04 // horizontal refresh direction,
#define MAD_SS  0x02 // horizontal flip
#define MAD_GS  0x01 // vertical flip

// ------------------- Constans to use in examples ---------------------------

#define ROTATION_VTB 2    // vertical top to bottom
#define ROTATION_VBT 0    // vertical bottom to top
#define ROTATION_HLR 1    // horizontal left to right
#define ROTATION_HRL 3    // horizontal right to left

// --------------------------- User Setups -----------------------------------

//  #include <Setup_RP2040_GPIO_8BITP_ILI9488.h>
//  #include <Setup_RP2040_GPIO_8BITP_ILI9488_1.h>
//  #include <Setup_RP2040_GPIO_8BITP_RM68140.h>

//  #include <Setup_RP2040_PIO_8BITP_ILI9488.h>

//  #include <Setup_RP2040_PIO_SPI_ILI9341.h>
//  #include <Setup_RP2040_PIO_SPI_ST7789.h>

  #include <Setup_RP2040_SPI_ILI9341.h>
//  #include <Setup_RP2040_SPI_ST7789.h>

