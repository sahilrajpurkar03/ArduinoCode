#define en_in=A0;

//Variable for Encoder
int curA=0,preA=0,disp1=0;

void encoder_start();

void setup() 
{
  pinMode(A0,INPUT);
  Serial.begin(9600);
}

void loop() 
{
  encoder_start();
  Serial.println(disp1); 
}

void encoder_start()
{
  curA=analogRead(A0);

  disp1+= curA - preA;
  if(curA - preA <=-150)
  {
    disp1 -= (curA-preA);
    disp1++;
  }
  if(curA - preA >=150)
  {
    
    disp1 -= (curA-preA);
    disp1--;
  }
  preA = curA;

}
