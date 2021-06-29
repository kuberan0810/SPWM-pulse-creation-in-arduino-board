double arrayy[72];
double alpha=0, sineval=0.0;
int St=0;
unsigned long prev=0;

void setup() 
{
  DDRB |= (1<<1)|(1<<2);
  TCCR1A |= (1<<5)|(1<<7)|(1<<4);
  TCCR1A &= ~((1<<1)|1|(1<<6));
  TCCR1B |= 1|(1<<4);
  TCCR1B &= ~((1<<3)|(1<<2)|(1<<1));
  TCNT1 = 0;
  ICR1 = 1600;  
  OCR1A=800;
  OCR1B=800;
  for(int i=0;i<72;i++)
  {
    arrayy[i]= sin(alpha*PI/180);
    alpha +=5;
  }
Serial.begin(115200);
}

void loop() 
{
  SandH(278);
  if (St==72)
   St =0;
   
   sineval = (int)((arrayy[St]*800)+800);
  //OCR1A =sineval;
  //OCR1B = sineval;
 }

void SandH (int t)
{
  if (micros()-prev >= t)
  {
    St +=1;
    prev = micros();
  }
}
