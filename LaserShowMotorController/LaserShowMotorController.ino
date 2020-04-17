#define LASER_PWM_DUTY_CYCLE_INPUT_PIN A0
#define LASER_PWM_FREQ_INPUT_PIN A1
#define MOTOR1_SPEED_INPUT_PIN A2
#define MOTOR2_SPEED_INPUT_PIN A3
#define MOTOR1_SPEED_OUTPUT_PIN 9
#define MOTOR2_SPEED_OUTPUT_PIN 10
#define LASER_ENABLE_PIN 11
#define LASER_POWER_PIN 12 // or connect directly to 5V

void setup() {
    pinMode(MOTOR1_SPEED_INPUT_PIN, INPUT);
    pinMode(MOTOR1_SPEED_INPUT_PIN, INPUT);
    pinMode(LASER_PWM_DUTY_CYCLE_INPUT_PIN, INPUT);
    pinMode(LASER_PWM_FREQ_INPUT_PIN, INPUT);
    pinMode(MOTOR1_SPEED_OUTPUT_PIN, OUTPUT);
    pinMode(MOTOR2_SPEED_OUTPUT_PIN, OUTPUT);
    digitalWrite(MOTOR1_SPEED_OUTPUT_PIN, LOW);
    digitalWrite(MOTOR2_SPEED_OUTPUT_PIN, LOW);
    pinMode(LASER_ENABLE_PIN, OUTPUT);
    pinMode(LASER_POWER_PIN, OUTPUT);
    digitalWrite(LASER_POWER_PIN, HIGH);
}

void loop() {
  int input, speed, dutyCycle;
  uint8_t pwmSetting;

  input = analogRead(MOTOR1_SPEED_INPUT_PIN);
  speed = map(input, 0, 1023, 0, 255);
  analogWrite(MOTOR1_SPEED_OUTPUT_PIN, speed);

  input = analogRead(MOTOR2_SPEED_INPUT_PIN);
  speed = map(input, 0, 1023, 0, 255);
  analogWrite(MOTOR2_SPEED_OUTPUT_PIN, speed);

  input = analogRead(LASER_PWM_DUTY_CYCLE_INPUT_PIN);
  dutyCycle = map(input, 0, 1023, 0, 255);
  analogWrite(LASER_ENABLE_PIN, dutyCycle);

  input = analogRead(LASER_PWM_FREQ_INPUT_PIN);
  pwmSetting = map(input, 0, 1024, 0x04, 0x08); // map [0,1023] to [0x04,0x07]
  TCCR2B = (TCCR2B & 0b11111000) | pwmSetting;
}
