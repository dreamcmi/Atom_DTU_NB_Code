#include "ATOM_DTU_NB.h"
#include "M5Atom.h"

ATOM_DTU_NB DTU;
String readstr;
String comdata;

void setup() {
  M5.begin(true, true, true);
  //SIM7020
  DTU.Init(&Serial2, 19, 22);
  // DTU.Init();
}

void loop() {
  comdata = "";//缓存清零
  while (Serial.available() > 0)//循环串口是否有数据
  {
    comdata += char(Serial.read());//叠加数据到comdata
    delay(2);//延时等待响应
  }
  DTU.sendMsg(comdata);
  readstr = DTU.waitMsg(1000);
  Serial.print(readstr);
}
