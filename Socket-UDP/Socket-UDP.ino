/*
  仅为at演示，功能后续实现
  Socket UDP
*/

#include "ATOM_DTU_NB.h"
#include "M5Atom.h"

ATOM_DTU_NB DTU;
String readstr;
String socketId = "0";
String port = "37168";
String url = "112.125.89.8";

void setup()
{
  M5.begin(true, true, true);
  //SIM7020
  DTU.Init(&Serial2, 19, 22);
  // DTU.Init();
  //Reset Module
  DTU.sendMsg("AT+CRESET\r\n");
}

void loop()
{
  DTU.sendMsg("AT+CSMINS=?\r\n");
  readstr = DTU.waitMsg(1000);
  Serial.print(readstr);

  while (1) {
    DTU.sendMsg("AT+CSQ\r\n\r\n");
    readstr = DTU.waitMsg(1000);
    Serial.print(readstr);
    if (readstr.indexOf("0,0") == -1 || readstr.indexOf("99") == -1 ) {
      break;
    }
  }

  DTU.sendMsg("AT+CREG?\r\n");
  readstr = "";
  readstr = DTU.waitMsg(1000);
  Serial.print(readstr);

  DTU.sendMsg("AT+COPS?\r\n");
  readstr = "";
  readstr = DTU.waitMsg(1000);
  Serial.print(readstr);

  //创建udp，id=0
  DTU.sendMsg("AT+CSOC=1,2,1\r\n");
  readstr = "";
  readstr = DTU.waitMsg(1000);
  Serial.print(readstr);

  //连接平台，id=0测试平台'netlab.luatos.com'
  DTU.sendMsg("AT+CSOCON="+socketId+","+port+","+url+"\r\n");
  readstr = "";
  readstr = DTU.waitMsg(1000);
  Serial.print(readstr);

  //发送数据，id=0,要求hex码
  DTU.sendMsg("AT+CSOSEND="+socketId+",6,7E117E\r\n");
  readstr = "";
  readstr = DTU.waitMsg(5000);
  Serial.print(readstr);

  Serial.println("start delay 5s");
  delay(5000);
  Serial.println("end delay 5s");

  //销毁连接，id=0
  DTU.sendMsg("AT+CSOCL="+socketId+",\r\n");
  readstr = "";
  readstr = DTU.waitMsg(1000);
  Serial.print(readstr);

  delay(1000);
}
