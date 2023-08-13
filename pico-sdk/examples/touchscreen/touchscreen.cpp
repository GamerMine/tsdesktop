/*
  Calculator on TSDesktop

  Copyright (c) 2023, rspber (https://github.com/rspber)

*/

#include <eval.h>
#include <Media.h>
#include <TSDesktop.h>
#include <Editable.h>

#define BG_COLOR  WHITE

Display display;
bool screenEnabled = false;

Touch touch;

#define ROTATION ROTATION_HRL

// ----------------------------------------------------------------

void setup() {

  media_begin(ROTATION);

  screenEnabled = true;
}

void loop() {

  point_t p;
  if (touch.getTouch(&p)) {
    display.drawPixel(p.x, p.y, RED);
  }

  delay(50);
}

int main() {

  stdio_init_all();
  
  setup();

  while (true) {
    loop();
  }
}

// ----------------------------------------------------------------
