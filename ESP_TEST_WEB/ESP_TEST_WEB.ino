#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer sv(80);
int count = 0;
void setup() {
  // put your setup code here, to run once:
  WiFi.mode(WIFI_AP_STA);
  WiFi.softAP("dong tran", "dongtam09");
  WiFi.begin("ANHHA4_plus", "12356789DEF");
  while (WiFi.waitForConnectResult() != WL_CONNECTED)
    delay(100);
  Serial.begin(115200);
  //lệnh xem dia chi ip cua esp truy cập vào wifi 
  Serial.println(WiFi.localIP());
  //dap ung loi goi: sv.on("/",HTTP_POST/HTTP/GET,[]{....
  sv.on("/",[]{
      Serial.println(String("Co nguoi truy cap:") + count++);
      //connected
      sv.send(200,"text/plain","xin chao Dong");
  });

  sv.on("/online",[]{
      Serial.println(String("Co nguoi truy cap:") + count++);
      //connected
      sv.send(200,"text/plain",String("so nguoi truy cap:") + count);
  });

  
  //begin server
  sv.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //ham duy tri su song server
  sv.handleClient();
}
