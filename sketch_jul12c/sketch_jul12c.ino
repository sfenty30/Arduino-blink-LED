int led=13;
int but=8;
int temp=A2;
void setup() {
  // put your setup code here, to run once:
pinMode (led,OUTPUT);
pinMode (but,INPUT);
pinMode (temp,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int b=digitalRead(but);
  Serial.print("button_state: ");
  Serial.println(b);
  float t= analogRead(temp);
  t=((t*0.125)-22.0);
  Serial.println(t);
  if(b==1){
   digitalWrite(led,HIGH);
  }else{
  digitalWrite(led,LOW);
  }


}
