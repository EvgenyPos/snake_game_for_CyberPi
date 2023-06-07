#include "cyberpi.h"

CyberPi cyber;

#define Y_BUTT cyber.get_joystick_y()
#define X_BUTT cyber.get_joystick_x()
#define OK_BUTT cyber.get_button_a()
#define HOME_BUTT cyber.get_button_menu()
#define CENTR_BUTT cyber.get_joystick_pressed()
#define OPEND_BUTT cyber.get_button_b()

int ys[200];
int xs[200];

int8_t mapS[13][13] {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
  { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
  { 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

uint16_t telo[100]{
  0x0000, 0x0000, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0x0000, 0x0000,
  0x0000, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0x0000,
  0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0,
  0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0,
  0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0,
  0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0,
  0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0,
  0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0,
  0x0000, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0x0000,
  0x0000, 0x0000, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0x0000, 0x0000
};

uint16_t eda[100]{
  0x0000, 0x0000, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0x0000, 0x0000,
  0x0000, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0x0000,
  0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777,
  0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777,
  0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777,
  0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777,
  0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777,
  0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777,
  0x0000, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0x0000,
  0x0000, 0x0000, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0xF777, 0x0000, 0x0000
};

int x, y, n, i, dlinatela, sx, sy, xys, xst, yst, spase, ybot1, xbot1, s, per;

bool edapr1;

uint32_t tmr1;

void setup() {
  Serial.begin(921600);
  cyber.begin();
  mapSnake();
  dlinatela = 4;
  x = 70;
  y = 70;
  n = 1;
  s = 0;
  edapr1 = false;
}
void loop() {
  if (Y_BUTT == -1) {
    if (n == 4) {} else {
      n = 3;
    }
  } else if (Y_BUTT == 1) {
    if (n == 3) {} else {
      n = 4;
    }
  } else if (X_BUTT == 1) {
    if (n == 2) {} else {
      n = 1;
    }
  } else if (X_BUTT == -1) {
    if (n == 1) {} else {
      n = 2;
    }
  }
  if (millis() - tmr1 > 200) {
    if (n == 1) {
      x = x + 10;
    } else if (n == 2) {
      x = x - 10;
    } else if (n == 3) {
      y = y - 10;
    } else if (n == 4) {
      y = y + 10;
    }
    if (x == 130 || x == -10 || y == 130 || y == -10) {
      res();
    }
    i = dlinatela;
    while (i > 0) {
      if (x == xs[i] && y == ys[i]) {
        res();
      }
      i = i - 1;
    }
    for (int i = 0; i < 13; i++) {
      sy = i;
      for (int a = 0; a < 13; a++) {
        sx = a;
        xys = mapS[sy][sx];
        if (xys == 1) {
          if (x == sx * 10 && y == sy * 10) {
            res();
          }
        }
      }
    }
    if (xst != x || yst != y) {
      drawMap(x, y, 10, 10, 1);
    }
    i = dlinatela;
    while (i > 0) {
      xs[i] = xs[i - 1];
      ys[i] = ys[i - 1];
      i = i - 1;
    }
    xs[0] = x;
    ys[0] = y;
    if (xst != x || yst != y) {
      fillRect(xs[dlinatela], ys[dlinatela], 10, 10, 0x0000);
      xst = x;
      yst = y;
    }
    if (edapr1 == false) {
      edapr1 = true;
      per = random(0, spase);
      ybot1 = 0;
      while (per > 12) {
        per = per - 12;
        ybot1 = ybot1 + 1;
      }
      xbot1 = 0;
      while (per > 0) {
        per = per - 1;
        xbot1 = xbot1 + 1;
      }
      ybot1 = ybot1 * 10;
      xbot1 = xbot1 * 10;
      i = dlinatela;
      while (i > 0) {
        if (xbot1 == xs[i]) {
          edapr1 = false;
        }
        i = i - 1;
      }
      i = dlinatela;
      while (i > 0) {
        if (ybot1 == ys[i]) {
          edapr1 = false;
        }
        i = i - 1;
      }
      for (int i = 0; i < 13; i++) {
        sy = i;
        for (int a = 0; a < 13; a++) {
          sx = a;
          xys = mapS[sy][sx];
          if (xys == 1) {
            if (xbot1 == sx * 10 && ybot1 == sy * 10) {
              edapr1 = false;
            }
          }
        }
      }
      if (edapr1 == true) {
      drawMap(xbot1, ybot1, 10, 10, 2);
      }
    }
    if (x == xbot1 && y == ybot1) {
      edapr1 = false;
      dlinatela = dlinatela + 1;
      s = s + 1;
    }
    tmr1 = millis();
    cyber.render_lcd();
  }
}

void mapSnake() {
  fillRect(0, 0, 128, 128, 0x0000);
  spase = 0;
  for (int i = 0; i < 13; i++) {
    sy = i;
    for (int a = 0; a < 13; a++) {
      sx = a;
      xys = mapS[sy][sx];
      if (xys == 0) {
        spase = spase + 1;
      } else if (xys == 1) {
        fillRect(sx * 10, sy * 10, 10, 10, 0x049F);
      }
    }
  }
}

void res() {
  mapSnake();
  dlinatela = 4;
  x = 70;
  y = 70;
  n = 1;
  s = 0;
  edapr1 = false;
  for (int i = 0; i < 200; i++) {
    ys[i] = 0;
    xs[i] = 0;
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void fillRect(int x_for_display, int y_for_display, int d_x_for_display, int d_y_for_display, int16_t color) {
  for (int i = 0; i < d_x_for_display; i++) {
    for (int u = 0; u < d_y_for_display; u++) {
      int for_x = x_for_display + i;
      int for_y = y_for_display + u;
      cyber.set_lcd_pixel(for_x, for_y, color);
    }
  }
}

void drawMap(int x_for_display, int y_for_display, int d_x_for_display, int d_y_for_display, int namber_for_display) {
  int namber = 0;
  uint16_t color;
  for (int i = 0; i < d_y_for_display; i++) {
    for (int u = 0; u < d_x_for_display; u++) {
      if(namber_for_display==1){
        color = telo[namber];
      } else if(namber_for_display==2){
        color = eda[namber];
      }
      namber = namber + 1;
      int for_x = x_for_display + u;
      int for_y = y_for_display + i;
      cyber.set_lcd_pixel(for_x, for_y, color);
    }
  }
}
