#include "Information.h"

SMSBL sm;

void Connect::info(){
  M5.Lcd.clear(BLACK);
  M5.Lcd.setTextColor(BLACK);
  M5.Lcd.setTextColor(RED);
  M5.Lcd.setTextSize(3);
  M5.Lcd.setCursor(0, 10);
  M5.Lcd.printf("myCobot");
  M5.Lcd.setCursor(0, 40);
  M5.Lcd.drawFastHLine(0,70,320,GREY);
  M5.Lcd.setTextSize(3);
  M5.Lcd.println("Status Inspection");
  M5.Lcd.setCursor(0, 100);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(2);
  M5.Lcd.println("Press A - Servos motor");
  M5.Lcd.println();
  M5.Lcd.println("Press B - Firmware");
  M5.Lcd.println();
  M5.Lcd.println("Press C - Exit(1S)");
} 

void Connect::test(MycobotBasic &myCobot){
    info();
    sm.pSerial = &Serial2;
    while (1)
    {
        // put your main code here, to run repeatedly:
    M5.update(); // need to call update()  
    M5.Lcd.setCursor(0,0);
   // M5.Lcd.clear(BLACK);
  
     if (M5.BtnA.wasReleased()) {
      Connect::testServo(myCobot);
      } 
    if (M5.BtnB.wasReleased()) {
      Connect::ReadConfig();
      }
    if (M5.BtnC.wasReleasefor(1000)) {
      break;
    }
}
}

void Connect::testServo(MycobotBasic &myCobot){
    M5.Lcd.clear(BLACK);
    delay(50);
    M5.Lcd.setTextSize(3);
    M5.Lcd.setCursor(0, 10);
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.println("connect test");
    M5.Lcd.setTextSize(2);
    M5.Lcd.setCursor(0, 40);
    int state = myCobot.isPoweredOn();
    M5.Lcd.print("atom - ");
    if(state == 1){
    M5.Lcd.setTextColor(GREEN);
    M5.Lcd.println("ok");
    }else{
    M5.Lcd.setTextColor(RED);
    M5.Lcd.println("no");
    }
    M5.Lcd.setTextSize(2);
    M5.Lcd.setCursor(0, 60);
    M5.Lcd.setTextColor(WHITE);
    for(int i = 1; i<7;i++){
      M5.Lcd.setTextColor(WHITE);
      M5.Lcd.print("servo ");
      M5.Lcd.print(i);
      M5.Lcd.print(" - ");
      if(sm.FeedBack(i) != -1){
        M5.Lcd.setTextColor(GREEN);
      M5.Lcd.println("ok");
      }else{
      M5.Lcd.setTextColor(RED);
      M5.Lcd.println("no");
      }
      delay(50);
    }
    M5.update();
    delay(3000);
    info();
}


void Connect::ReadConfig(){
  M5.Lcd.clear(BLACK);
  delay(50);
  M5.Lcd.setTextSize(3);
  M5.Lcd.setCursor(0, 10);
  M5.Lcd.println("connect test");
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(0, 40);
  M5.Lcd.println("Waiting for development");
  M5.update();
  delay(3000);
  info();
}
