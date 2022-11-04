const int PINLED[] = {13, 12, 14, 27, 26, 25, 33};
const int BUTTON_PIN[] = {32, 35};


enum ledMode {
  mode1, mode2
};

uint8_t state = mode1;

void ledOff() {
  for (int i = 0; i < 7; i++) {
    digitalWrite(PINLED[i], LOW);
  }
}

void ledMode1() {
  Serial.printf("Begin mode1\n");
  int duration = 500; // 500ms
  for (int i = 0; i < 7; i ++) {
    digitalWrite(PINLED[i], HIGH);
    for (int dur = 0; dur < duration / 10; dur += 10) {
      if (digitalRead(BUTTON_PIN[0]) == 1) {
        state = mode2;
        Serial.printf("switched to mode2\n");
        goto out;
      }
      delay(10);
    }
  }
  ledOff();
  for (int dur = 0; dur < duration / 10; dur += 10) {
    if (digitalRead(BUTTON_PIN[0]) == 1) {
      state = mode2;
      Serial.printf("switched to mode2\n");
      goto out;
    }
    delay(10);
  }
out:;
}

void ledMode2() {
  int duration = 500;
  Serial.printf("Begin mode2\n");
  for (int l = 0; l < 4; l++) {
    for (int i = 0; i < 7; i++) {
      digitalWrite(PINLED[i], HIGH);
      for (int dur = 0; dur < duration / 10; dur += 10) {
        if (digitalRead(BUTTON_PIN[1]) == 1) {
          state = mode1;
          Serial.printf("switched to mode1\n");
          goto out;
        }
        delay(10);
      }
      ledOff();
    }
  }
out:;
}

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < 2; i++) {
    pinMode(BUTTON_PIN[i], INPUT);
  }
  for (int i = 0; i < 7; i++) {
    pinMode(PINLED[i], OUTPUT);
  }
  ledOff();
}

void loop() {
  switch (state) {
    case mode1:
      ledMode1();
      break;
    case mode2:
      ledMode2();
      break;
    default:
      Serial.printf("Mode default\n");
	  break;
  }
}