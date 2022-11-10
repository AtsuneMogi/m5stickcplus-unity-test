#include <BluetoothSerial.h>
#include <M5StickCPlus.h>


BluetoothSerial SerialBT;

float acc[3];           
     
float pitch = 0.0F;
float roll  = 0.0F;             

const float pi = 3.14;

void freq(int f, int t) {
    M5.Beep.tone(f, t);
    delay(t);
    M5.Beep.mute();
    delay(t);
}


void readGyro() {
    M5.IMU.getAccelData(&acc[0], &acc[1], &acc[2]);
    pitch =  atan(acc[1] / sqrt((acc[0] *acc[0]) + (acc[2] * acc[2]))) * 180 / pi;
    roll  =  atan(acc[0] / sqrt((acc[1] *acc[1]) + (acc[2] * acc[2]))) * 180 / pi; 
}


void setup() {
    M5.begin();

    M5.Lcd.setRotation(1);
    M5.Lcd.setTextSize(3);
    
    Serial.begin(115200);
    SerialBT.begin("Unity-M5StickCPlus");

    M5.IMU.Init();

    M5.Beep.setVolume(1);
}


void loop() {
    M5.update();
    
    if (M5.BtnA.isReleased() && M5.BtnB.isReleased()) {
        readGyro();
    } else if (M5.BtnA.wasPressed()) {
        freq(740, 150);
        freq(587, 150);
        freq(440, 150);
        freq(587, 150);
        freq(659, 150);
        freq(880, 300);
        freq(440, 150);
        freq(659, 150);
        freq(740, 150);
        freq(650, 150);
        freq(440, 150);
        freq(587, 450);
    } else if (M5.BtnB.wasPressed()) {
        freq(880, 100); // la
        freq(880, 200); // la
        freq(988, 100);
        freq(880, 100);
        freq(740, 100);
        freq(880, 200);
        
        freq(880, 100); // la
        freq(880, 200); // la
        freq(988, 100);
        freq(880, 100);
        freq(740, 100);
        freq(880, 200);

        freq(587, 100);
        freq(587, 100);
        freq(587, 100);
        freq(659, 100);
        freq(740, 300);
        freq(587, 100);
        freq(740, 300);
        freq(880, 100);
        freq(880, 400);
        
        freq(587, 100);
        freq(587, 100);
        freq(587, 100);
        freq(659, 100);
        freq(740, 400);
        freq(587, 100);
        freq(587, 100);
        freq(587, 100);
        freq(659, 100);
        freq(740, 400);

        freq(659, 100);
        freq(659, 100);
        freq(659, 100);
        freq(587, 100);
        freq(659, 200);
        freq(740, 200);
        freq(880, 200);
        freq(784, 200);
        freq(740, 200);
        freq(659, 200);

        freq(880, 100); // la
        freq(880, 200); // la
        freq(988, 100);
        freq(880, 100);
        freq(740, 100);
        freq(880, 200);
        
        freq(880, 100); // la
        freq(880, 200); // la
        freq(988, 100);
        freq(880, 100);
        freq(740, 100);
        freq(659, 200);
        freq(587, 400);
    }

    M5.Lcd.fillScreen(BLACK);

    M5.Lcd.setCursor(0, 0);
    M5.Lcd.println();
    M5.Lcd.printf(" Pitch = %d\n", (int)pitch);
    M5.Lcd.printf(" Roll  = %d\n", (int)roll);
    M5.Lcd.println();
    if (!SerialBT.connected()) {
        M5.Lcd.println("Not Connected");
    } else {
        M5.Lcd.println(" Connected");
        SerialBT.printf("%d %d\n", (int)pitch, (int)roll);
    }
    
    delay(200);
}
