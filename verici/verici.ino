#include <VirtualWire.h>
char *mesaj;
int butonPin =3;
int butonDurum;

void setup(){
  Serial.begin(9600);
  
  pinMode(butonPin,INPUT);

  vw_set_ptt_inverted(true);
  
  vw_set_tx_pin(2);         //modulun bağlı olduğu pin
  
  vw_setup(4000);
}

void loop(){

  butonDurum =digitalRead(butonPin);

  if(butonDurum = HIGH){
    mesaj ="1";
  }else {
    mesaj ="0";
  }
  Serial.println(mesaj);
  vw_send((uint8_t *)mesaj,strlen(mesaj));       //mesaj işaretinin gönderimi
  vw_wait_tx();
  delay(100);
}
