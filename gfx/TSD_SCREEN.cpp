/*
  TSD_SCREEN for TSDesktop

  Copyright (c) 2023, rspber (https://github.com/rspber)

*/

#include "TSD_SCREEN.h"

/// @TSD_SCREEN

void TSD_SCREEN::fillScreen(const rgb_t color)
{
  fillRect(0, 0, _width, _height, color);
}

void TSD_SCREEN::drawPixel(int16_t x, int16_t y, rgb_t color)
{
  clip_t clip{0, 0, _width, _height};
  drawPixel(clip, x, y, color);
}

void TSD_SCREEN::drawFastVLine(int16_t x, int16_t y, int16_t h, rgb_t color)
{
  clip_t clip{0, 0, _width, _height};
  drawFastVLine(clip, x, y, h, color);
}

void TSD_SCREEN::drawFastHLine(int16_t x, int16_t y, int16_t w, rgb_t color)
{
  clip_t clip{0, 0, _width, _height};
  drawFastHLine(clip, x, y, w, color);
}

void TSD_SCREEN::drawLine(clip_t& clip, int16_t x1, int16_t y1, int16_t x2, int16_t y2, rgb_t color, int16_t ts, uint8_t mode)
{
  if (ts > 1) {
    int16_t u = ts / 2;
    if (x1 == x2) {
      fillRect(clip, x1 - u, y1, ts, y2 - y1, color);
      return;
    }
    if (y1 == y2)  {
      fillRect(clip, x1, y1 - u, x2 - x1, ts, color);
      return;
    }
    switch (mode) {
      case 1:		// cut
      {
        ts = ts * 5 / 4;
        u = ts / 2;
        int16_t d = u - ts;
        while (++d <= 0) {
          drawLine(clip, x1, y1 - d, x2 + d, y2, color);
        }
        --d;
        while (++d <= u) {
          drawLine(clip, x1 + d, y1, x2, y2 - d, color);
        }
        break;
      }
      default:    // flat
      {
        int16_t d = u - ts;
        if (abs(x2 - x1) > abs(y2 - y1)) {
          while (++d <= u) {
            drawLine(clip, x1, y1 + d, x2, y2 + d, color);
          }
        }
        else {
          while (++d <= u) {
            drawLine(clip, x1 + d, y1, x2 + d, y2, color);
          }
        }
      }
    }
  }
  else {
    drawLine(clip, x1, y1, x2, y2, color);
  }
}

void TSD_SCREEN::drawLine(int16_t x1, int16_t y1, int16_t x2, int16_t y2, rgb_t color, int16_t ts, uint8_t mode)
{
  clip_t clip{0, 0, _width, _height};
  drawLine(clip, x1, y1, x2, y2, color, ts, mode);
}

void TSD_SCREEN::drawRect(clip_t& clip, int16_t x, int16_t y, int16_t w, int16_t h, rgb_t color, int16_t ts)
{
  if (ts > 1) {
    int16_t d = ts / 2;
    fillRect(clip, x - d, y - d, w + ts, ts, color);     // Top
    fillRect(clip, x - d, y + h - d, w + ts, ts, color); // Bottom
    fillRect(clip, x - d, y + d, ts, h - ts, color);     // Left
    fillRect(clip, x + w - d, y + d, ts, h - ts, color); // Right
  }
  else {
    drawRect(clip, x, y, w, h, color);
  }
}

void TSD_SCREEN::drawRect(int16_t x, int16_t y, int16_t w, int16_t h, rgb_t color, int16_t ts)
{
  clip_t clip{0, 0, _width, _height};
  drawRect(clip, x, y, w, h, color, ts);
}

void TSD_SCREEN::fillRect(int16_t x, int16_t y, int16_t w, int16_t h, rgb_t color)
{
  clip_t clip{0, 0, _width, _height};
  fillRect(clip, x, y, w, h, color);
}

void TSD_SCREEN::fillRectGradient(int16_t x, int16_t y, int16_t w, int16_t h, gradient_t& z)
{
  clip_t clip{0, 0, _width, _height};
  fillRectGradient(clip, x, y, w, h, z);
}

void TSD_SCREEN::drawRoundRect(clip_t& clip, int16_t x, int16_t y, int16_t w, int16_t h, int16_t radius, rgb_t color, int16_t ts)
{
  if (ts > 1) {
    int16_t max_radius = ((w < h) ? w : h) / 2; // 1/2 minor axis
    int16_t r = radius;
    if (r > max_radius) {
      r = max_radius;
    }
    r += ts;
    // smarter version
    int16_t u = ts / 2;
    fillRect(clip, x + r, y - u, w - 2 * r, ts, color);     // Top
    fillRect(clip, x + r, y + h - u, w - 2 * r, ts, color); // Bottom
    fillRect(clip, x - u, y + r, ts, h - 2 * r, color);     // Left
    fillRect(clip, x + w - u, y + r, ts, h - 2 * r, color); // Right
    // dodraw four corners
    int16_t d = u - ts;
    while (++d <= u ) {
      drawCircleFragment(clip, x + r, y + r, r + d, 1, color);
    }
    d = u - ts;
    while (++d <= u ) {
      drawCircleFragment(clip, x + w - r - 1, y + r, r + d, 2, color);
    }
    d = u - ts;
    while (++d <= u ) {
      drawCircleFragment(clip, x + w - r - 1, y + h - r - 1, r + d, 4, color);
    }
    d = u - ts;
    while (++d <= u ) {
      drawCircleFragment(clip, x + r, y + h - r - 1, r + d, 8, color);
    }
  }
  else {
    drawRoundRect(clip, x, y, w, h, radius, color);
  }
}

void TSD_SCREEN::drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, rgb_t color, int16_t ts)
{
  clip_t clip{0, 0, _width, _height};
  drawRoundRect(clip, x0, y0, w, h, radius, color, ts);
}

void TSD_SCREEN::fillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, rgb_t color)
{
  clip_t clip{0, 0, _width, _height};
  fillRoundRect(clip, x0, y0, w, h, radius, color);
}

void TSD_SCREEN::drawCircle(clip_t& clip, int16_t x0, int16_t y0, int16_t r, rgb_t color, int16_t ts)
{
  int16_t u = ts / 2;
  int16_t d = u - ts;
  while (++d <= u) {
    drawCircle(clip, x0, y0, r + d, color);
  }
}

void TSD_SCREEN::drawCircle(int16_t x0, int16_t y0, int16_t r, rgb_t color, int16_t ts)
{
  clip_t clip{0, 0, _width, _height};
  drawCircle(clip, x0, y0, r, color, ts);
}

void TSD_SCREEN::drawCircleFragment(clip_t& clip, int16_t x0, int16_t y0, int16_t r, uint8_t corners, rgb_t color, int16_t ts)
{
  int16_t u = ts / 2;
  int16_t d = u - ts;
  while (++d <= u) {
    drawCircleFragment(clip, x0, y0, r + d, corners, color);
  }
}

void TSD_SCREEN::drawCircleFragment(int16_t x, int16_t y, int16_t r, uint8_t corners, rgb_t color, int16_t ts)
{
  clip_t clip{0, 0, _width, _height};
  drawCircleFragment(clip, x, y, r, corners, color, ts);
}

void TSD_SCREEN::fillCircle(int16_t x0, int16_t y0, int16_t r, rgb_t color)
{
  clip_t clip{0, 0, _width, _height};
  fillCircle(clip, x0, y0, r, color);
}

void TSD_SCREEN::fillCircleFragment(int16_t x0, int16_t y0, int16_t r, uint8_t corners, int16_t delta, rgb_t color)
{
  clip_t clip{0, 0, _width, _height};
  fillCircleFragment(clip, x0, y0, r, corners, delta, color);
}

void TSD_SCREEN::drawEllipse(int16_t x0, int16_t y0, int16_t rx, int16_t ry, rgb_t color)
{
  clip_t clip{0, 0, _width, _height};
  drawEllipse(clip, x0, y0, rx, ry, color);
}

void TSD_SCREEN::fillEllipse(int16_t x0, int16_t y0, int16_t rx, int16_t ry, rgb_t color)
{
  clip_t clip{0, 0, _width, _height};
  fillEllipse(clip, x0, y0, rx, ry, color);
}

void TSD_SCREEN::drawTriangle(clip_t& clip, int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, rgb_t color, int16_t ts, uint8_t mode)
{
  drawLine(clip, x0, y0, x1, y1, color, ts, mode);
  drawLine(clip, x1, y1, x2, y2, color, ts, mode);
  drawLine(clip, x2, y2, x0, y0, color, ts, mode);
}

void TSD_SCREEN::drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, rgb_t color, int16_t ts, uint8_t mode)
{
  clip_t clip{0, 0, _width, _height};
  drawTriangle(clip, x0, y0, x1, y1, x2, y2, color, ts, mode);
}

void TSD_SCREEN::fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, rgb_t color)
{
  clip_t clip{0, 0, _width, _height};
  fillTriangle(clip, x0, y0, x1, y1, x2, y2, color);
}

void TSD_SCREEN::drawBitmap(int16_t x, int16_t y, const uint8_t* bitmap, int16_t w, int16_t h, rgb_t color)
{
  clip_t clip{0, 0, _width, _height};
  drawBitmap(clip, x, y, bitmap, w, h, color);
}

void TSD_SCREEN::drawBitmap(int16_t x, int16_t y, const uint8_t* bitmap, int16_t w, int16_t h, rgb_t color, rgb_t bg)
{
  clip_t clip{0, 0, _width, _height};
  drawBitmap(clip, x, y, bitmap, w, h, color, bg);
}

void TSD_SCREEN::drawGrayscaleBitmap(int16_t x, int16_t y, const uint8_t* bitmap, int16_t w, int16_t h)
{
  clip_t clip{0, 0, _width, _height};
  drawGrayscaleBitmap(clip, x, y, bitmap, w, h);
}

void TSD_SCREEN::drawGrayscaleBitmap(int16_t x, int16_t y, const uint8_t* bitmap, const uint8_t* mask, int16_t w, int16_t h)
{
  clip_t clip{0, 0, _width, _height};
  drawGrayscaleBitmap(clip, x, y, bitmap, mask, w, h);
}

void TSD_SCREEN::drawRGBBitmap(int16_t x, int16_t y, const rgb_t* bitmap, int16_t w, int16_t h)
{
  clip_t clip{0, 0, _width, _height};
  drawRGBBitmap(clip, x, y, bitmap, w, h);
}

void TSD_SCREEN::drawRGBBitmap(int16_t x, int16_t y, const rgb_t* bitmap, const uint8_t *mask, int16_t w, int16_t h)
{
  clip_t clip{0, 0, _width, _height};
  drawRGBBitmap(clip, x, y, bitmap, mask, w, h);
}

// utf-8

void TSD_SCREEN::drawChar(cursor_t& cursor, font_t& font, const char* c, rgb_t colorh, rgb_t bg, rgb_t colorl, const int8_t spacing)
{
  clip_t clip{0, 0, _width, _height};
  drawChar(clip, cursor, font, (char **)&c, colorh, bg, colorl, spacing);
}

void TSD_SCREEN::drawTextLine(cursor_t& cursor, font_t& font, const char* text, rgb_t colorh, rgb_t bg, rgb_t colorl, const int8_t spacing)
{
  clip_t clip{0, 0, _width, _height};
  drawTextLine(clip, cursor, font, text, colorh, bg, colorl, spacing);
}

void TSD_SCREEN::drawText(const int16_t x, const int16_t y, const char* text, const GFXfont** gfxFont, const int8_t fontSize, rgb_t colorh, rgb_t bg, rgb_t colorl, const int8_t spacing)
{
  if (text) {
    cursor_t cursor{ x, y };
    clip_t clip{0, 0, _width, _height};
    font_t font{gfxFont, fontSize, fontSize};
    const char* p = text;
    while (*p) {
      p = drawTextLine(clip, cursor, font, p, colorh, bg, colorl, spacing);
      while (*p == '\r') ++p;
      if (*p == '\n') ++p;
      cursor.x = x;
      cursor.y += font.textLineHeight();
    }
  }
}

void TSD_SCREEN::drawText(const int16_t x, const int16_t y, const char* text, const int8_t fontSize, rgb_t colorh, rgb_t bg, rgb_t colorl, const int8_t spacing)
{
  drawText(x, y, text, (const GFXfont**)NULL, fontSize, colorh, bg, colorl, spacing);
}

// unicode

void TSD_SCREEN::drawChar(cursor_t& cursor, font_t& font, const uint16_t uchar, rgb_t colorh, rgb_t bg, rgb_t colorl, const int8_t spacing)
{
  clip_t clip{0, 0, _width, _height};
  drawChar(clip, cursor, font, uchar, colorh, bg, colorl, spacing);
}

const uint16_t* TSD_SCREEN::drawTextLine(cursor_t& cursor, font_t& font, const uint16_t* utext, rgb_t colorh, rgb_t bg, rgb_t colorl, const int8_t spacing)
{
  clip_t clip{0, 0, _width, _height};
  return drawTextLine(clip, cursor, font, utext, colorh, bg, colorl, spacing);
}

void TSD_SCREEN::drawText(const int16_t x, const int16_t y, const uint16_t* utext, const GFXfont** gfxFont, const int8_t fontSize, rgb_t colorh, rgb_t bg, rgb_t colorl, const int8_t spacing)
{
  if (utext) {
    cursor_t cursor{ x, y };
    clip_t clip{0, 0, _width, _height};
    font_t font{gfxFont, fontSize, fontSize};
    const uint16_t* p = utext;
    while (*p) {
      p = drawTextLine(clip, cursor, font, p, colorh, bg, colorl, spacing);
      while (*p == '\r') ++p;
      if (*p == '\n') ++p;
      cursor.x = x;
      cursor.y += font.textLineHeight();
    }
  }
}

void TSD_SCREEN::drawText(const int16_t x, const int16_t y, const uint16_t* utext, const int8_t fontSize, rgb_t colorh, rgb_t bg, rgb_t colorl, const int8_t spacing)
{
  drawText(x, y, utext, (const GFXfont**)NULL, fontSize, colorh, bg, colorl, spacing);
}
