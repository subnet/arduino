//simple Tx on pin D12
//Written By : Mohannad Rawashdeh
// 3:00pm , 13/6/2013
//http://www.genotronex.com/
// Tutorial at: http://www.instructables.com/id/RF-315433-MHz-Transmitter-receiver-Module-and-Ardu/?ALLSTEPS
//..................................
#include <VirtualWire.h>
char *controller;
void setup() {
  pinMode(13,OUTPUT);
  vw_set_ptt_inverted(true); //
  vw_set_tx_pin(12);
  vw_setup(4000);// speed of data transfer Kbps
}

void loop(){
  controller="1";
  vw_send((uint8_t *)controller, strlen(controller));
  vw_wait_tx(); // Wait until the whole message is gone
  digitalWrite(13,1);
  delay(2000);
  
  controller="0";
  vw_send((uint8_t *)controller, strlen(controller));
  vw_wait_tx(); // Wait until the whole message is gone
  digitalWrite(13,0);
  delay(2000);
  
  const char *msg = "hello";
  digitalWrite(13, 1); // Flash a light to show transmitting
  vw_send((uint8_t *)msg, strlen(msg));
  vw_wait_tx(); // Wait until the whole message is gone
  digitalWrite(13, 0);
  delay(2000);
}
