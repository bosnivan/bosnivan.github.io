#include <Adafruit_NeoPixel.h>

#define MODE 1

#define PIN 5
#define PIXNUM 50

Adafruit_NeoPixel pixels(PIXNUM, PIN, NEO_RGB + NEO_KHZ800);

#define RED pixels.Color(50, 0, 0)
#define GREEN pixels.Color(0, 50, 0)
#define BLUE pixels.Color(0, 0, 50)
#define BLACK pixels.Color(0, 0, 0)
#define WHITE pixels.Color(50, 50, 50)

#define NO_LOOP_DELAY 60000
#define BLINK_DELAY 1000
#define SWAP_DELAY 1000
#define SHIFT_DELAY 1000
#define FILL_DELAY 100

#define COLNUM 3
uint32_t colors[] = { RED, GREEN, BLUE };

int shift = 0;
unsigned long long counter = 0;

void setup() {
  pixels.begin();
}

void loop() {
  switch (MODE) {
    case 1:
      v01();
      break;
    case 2:
      v02();
      break;
    case 3:
      v03();
      break;
    case 4:
      v04();
      break;
    case 5:
      v05();
      break;
    case 6:
      v06();
      break;
    case 7:
      v07();
      break;
    case 8:
      v08();
      break;
    case 9:
      v09();
      break;
    case 10:
      v10();
      break;
    case 11:
      v11();
      break;
    case 12:
      v12();
      break;
    case 13:
      v13();
      break;
    case 14:
      v14();
      break;
    case 15:
      v15();
      break;
    case 16:
      v16();
      break;
    case 17:
      v17();
      break;
    case 18:
      v18();
      break;
    case 19:
      v19();
      break;
    case 20:
      v20();
      break;
    case 21:
      v21();
      break;
    case 22:
      v22();
      break;
    case 23:
      v23();
      break;
    case 24:
      v24();
      break;
    default:
      v00();
      break;
  }
}

// off
void v00() {
  pixels.clear();
  pixels.show();
  delay(NO_LOOP_DELAY);
}

// static 1 color
void v01() {
  pixels.fill(WHITE);
  pixels.show();
  delay(NO_LOOP_DELAY);
}

// static N colors
void v02() {
  for (int i = 0; i < PIXNUM; i++) {
    pixels.setPixelColor(i, colors[i % COLNUM]);
  }
  pixels.show();
  delay(NO_LOOP_DELAY);
}

// static random
void v03() {
  for (int i = 0; i < PIXNUM; i++) {
    pixels.setPixelColor(i, colors[random(COLNUM)]);
  }
  pixels.show();
  delay(NO_LOOP_DELAY);
}

// blink 1 color
void v04() {
  pixels.fill(WHITE);
  pixels.show();
  delay(BLINK_DELAY);
  pixels.clear();
  pixels.show();
  delay(BLINK_DELAY);
}

// blink N colors
void v05() {
  for (int i = 0; i < COLNUM; i++) {
    pixels.fill(colors[i]);
    pixels.show();
    delay(BLINK_DELAY);
    pixels.clear();
    pixels.show();
    delay(BLINK_DELAY);
  }
}

// blink random
void v06() {
  for (int i = 0; i < PIXNUM; i++) {
    pixels.setPixelColor(i, colors[random(COLNUM)]);
  }
  pixels.show();
  delay(BLINK_DELAY);
  pixels.clear();
  pixels.show();
  delay(BLINK_DELAY);
}

// swap N colors
void v07() {
  for (int i = 0; i < COLNUM; i++) {
    pixels.fill(colors[i]);
    pixels.show();
    delay(SWAP_DELAY);
  }
}

// swap random
void v08() {
  for (int i = 0; i < PIXNUM; i++) {
    pixels.setPixelColor(i, colors[random(COLNUM)]);
  }
  pixels.show();
  delay(SWAP_DELAY);
}

// shift 2 colors
void v09() {
  for (int i = 0; i < PIXNUM; i++) {
    pixels.setPixelColor(i, colors[(i + shift) % 2]);
  }
  pixels.show();
  delay(SHIFT_DELAY);
  shift = (shift + 1) % 2;
}

// shift N colors
void v10() {
  for (int i = 0; i < PIXNUM; i++) {
    pixels.setPixelColor(i, colors[(i + shift) % COLNUM]);
  }
  pixels.show();
  delay(SHIFT_DELAY);
  shift = (shift + 1) % COLNUM;
}

// fill 1 color
void v11() {
  pixels.clear();
  for (int i = 0; i < PIXNUM; i++) {
    pixels.setPixelColor(i, WHITE);
    pixels.show();
    delay(FILL_DELAY);
  }
}

// fill unfill 1 color
void v12() {
  pixels.clear();
  for (int i = 0; i < PIXNUM; i++) {
    pixels.setPixelColor(i, WHITE);
    pixels.show();
    delay(FILL_DELAY);
  }
  for (int i = PIXNUM - 1; i >= 0; i--) {
    pixels.setPixelColor(i, BLACK);
    pixels.show();
    delay(FILL_DELAY);
  }
}

// fill 2 colors
void v13() {
  pixels.clear();
  for (int i = 0; i < PIXNUM / 2; i++) {
    pixels.setPixelColor(i, RED);
    pixels.setPixelColor(PIXNUM - 1 - i, GREEN);
    pixels.show();
    delay(FILL_DELAY);
  }
}

// fill unfill 2 colors
void v14() {
  pixels.clear();
  for (int i = 0; i < PIXNUM / 2; i++) {
    pixels.setPixelColor(i, RED);
    pixels.setPixelColor(PIXNUM - 1 - i, GREEN);
    pixels.show();
    delay(FILL_DELAY);
  }
  for (int i = 0; i < PIXNUM / 2; i++) {
    pixels.setPixelColor(PIXNUM / 2 - 1 - i, BLACK);
    pixels.setPixelColor(PIXNUM / 2 + i, BLACK);
    pixels.show();
    delay(FILL_DELAY);
  }
}

// fill 2 colors with replace
void v15() {
  pixels.clear();
  for (int i = 0; i < PIXNUM / 2; i++) {
    pixels.setPixelColor(i, RED);
    pixels.setPixelColor(PIXNUM - 1 - i, GREEN);
    pixels.show();
    delay(FILL_DELAY);
  }
  for (int i = 0; i < PIXNUM / 2; i++) {
    pixels.setPixelColor(PIXNUM / 2 - 1 - i, GREEN);
    pixels.setPixelColor(PIXNUM / 2 + i, RED);
    pixels.show();
    delay(FILL_DELAY);
  }
}

// fill 2 colors with 3rd color replace
void v16() {
  pixels.clear();
  for (int i = 0; i < PIXNUM / 2; i++) {
    pixels.setPixelColor(i, RED);
    pixels.setPixelColor(PIXNUM - 1 - i, GREEN);
    pixels.show();
    delay(FILL_DELAY);
  }
  for (int i = 0; i < PIXNUM / 2; i++) {
    pixels.setPixelColor(PIXNUM / 2 - 1 - i, BLUE);
    pixels.setPixelColor(PIXNUM / 2 + i, BLUE);
    pixels.show();
    delay(FILL_DELAY);
  }
}

// fireflies
void v17() {
  pixels.clear();
  for (int i = 0; i < PIXNUM; i++) {
    if (random(PIXNUM) < 0.05 * PIXNUM) {
      pixels.setPixelColor(i, WHITE);
    }
  }
  pixels.show();
  delay(500);
}

// emergency
void v18() {
  for (int i = 0; i < PIXNUM / 2; i++) {
    pixels.setPixelColor(i, RED);
    pixels.setPixelColor(i + PIXNUM / 2, BLUE);
  }
  pixels.show();
  delay(1000);
  for (int i = 0; i < PIXNUM / 2; i++) {
    pixels.setPixelColor(i, BLUE);
    pixels.setPixelColor(i + PIXNUM / 2, RED);
  }
  pixels.show();
  delay(1000);
}

// coin toss
void v19() {
  pixels.clear();
  for (int i = 0; i < PIXNUM; i++) {
    if (random(2)) {
      pixels.setPixelColor(i, WHITE);
    }
  }
  pixels.show();
  delay(1000);
}

// fireworks
void v20() {
  for (int i = 0; i < PIXNUM; i++) {
    pixels.clear();
    pixels.setPixelColor(i, WHITE);
    pixels.show();
    delay(50);
  }
  int index = random(3);
  for (int i = PIXNUM - 1; i > PIXNUM / 2; i--) {
    pixels.setPixelColor(i, colors[index]);
    pixels.show();
    delay(20);
  }
  delay(2000);
}

// particle accelerator
void v21() {
  for (int i = 0; i < PIXNUM / 2; i++) {
    pixels.clear();
    pixels.setPixelColor(i, WHITE);
    pixels.setPixelColor(PIXNUM - i, WHITE);
    pixels.show();
    delay(50);
  }
  for (int i = 0; i < PIXNUM / 2; i++) {
    pixels.setPixelColor(PIXNUM / 2 - 1 - i, WHITE);
    pixels.setPixelColor(PIXNUM / 2 + i, WHITE);
    pixels.show();
    delay(50);
  }
}

// campfire
void v22() {
  for (int i = 0; i < PIXNUM; i++) {
    pixels.setPixelColor(i, pixels.Color(50, 4 * random(5) + 5, 0));
  }
  pixels.show();
  delay(100);
}

// binary counter
void v23() {
  pixels.clear();
  for (int i = 0; i < PIXNUM; i++) {
    if (bitRead(counter, i)) {
      pixels.setPixelColor(i, WHITE);
    }
  }
  pixels.show();
  counter++;
}

// chaos theory
void v24() {
  for (int i = 0; i < PIXNUM; i++) {
    pixels.setPixelColor(i, pixels.Color(random(51), random(51), random(51)));
  }
  pixels.show();
  delay(1000);
}
