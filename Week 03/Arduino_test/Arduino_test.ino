// Task 1 writing program for blinking LED using pin number 2

void setup() 
{
  //  pinMode(13,OUTPUT); // a
  //  pinMode(12,OUTPUT); // b
  //  pinMode(11,OUTPUT); // c
  //  pinMode(10,OUTPUT); // d
  //  pinMode(9,OUTPUT);  // e
  //  pinMode(8,OUTPUT);  // f
  //  pinMode(7,OUTPUT);  // g

  for (int i = 7; i <= 13; i++)
    pinMode(i,OUTPUT);
}

String Number[] = {"0111111", "0000110", "1011011", "1001111", "1100110", "1101101", "1111101", "0000111", "1111111", "1101111"};
int a = 0;

void loop() 
{
  if (a == 10)
    a = 0;

  for (int i = 7; i <= 13; i++)
    digitalWrite(i, String(Number[a][i - 7]).toInt());
    delay(400);
    a++;
  
  /*
  // 0
  digitalWrite(13,1);
  digitalWrite(12,1);
  digitalWrite(11,1);
  digitalWrite(10,1);
  digitalWrite(9,1);
  digitalWrite(8,1);
  digitalWrite(7,0);
  delay(400);

  // 1
  digitalWrite(13,0);
  digitalWrite(12,1);
  digitalWrite(11,1);
  digitalWrite(10,0);
  digitalWrite(9,0);
  digitalWrite(8,0);
  digitalWrite(7,0);
  delay(400);

  // 2
  digitalWrite(13,1);
  digitalWrite(12,1);
  digitalWrite(11,0);
  digitalWrite(10,1);
  digitalWrite(9,1);
  digitalWrite(8,0);
  digitalWrite(7,1);
  delay(400);

  // 3
  digitalWrite(13,1);
  digitalWrite(12,1);
  digitalWrite(11,1);
  digitalWrite(10,1);
  digitalWrite(9,0);
  digitalWrite(8,0);
  digitalWrite(7,1);
  delay(400);

  // 4
  digitalWrite(13,0);
  digitalWrite(12,1);
  digitalWrite(11,1);
  digitalWrite(10,0);
  digitalWrite(9,0);
  digitalWrite(8,1);
  digitalWrite(7,1);
  delay(400);

  // 5
  digitalWrite(13,1);
  digitalWrite(12,0);
  digitalWrite(11,1);
  digitalWrite(10,1);
  digitalWrite(9,0);
  digitalWrite(8,1);
  digitalWrite(7,1);
  delay(400);

  // 6
  digitalWrite(13,1);
  digitalWrite(12,0);
  digitalWrite(11,1);
  digitalWrite(10,1);
  digitalWrite(9,1);
  digitalWrite(8,1);
  digitalWrite(7,1);
  delay(400);

  // 7
  digitalWrite(13,1);
  digitalWrite(12,1);
  digitalWrite(11,1);
  digitalWrite(10,0);
  digitalWrite(9,0);
  digitalWrite(8,0);
  digitalWrite(7,0);
  delay(400);

  // 8
  digitalWrite(13,1);
  digitalWrite(12,1);
  digitalWrite(11,1);
  digitalWrite(10,1);
  digitalWrite(9,1);
  digitalWrite(8,1);
  digitalWrite(7,1);
  delay(400);

  // 9
  digitalWrite(13,1);
  digitalWrite(12,1);
  digitalWrite(11,1);
  digitalWrite(10,1);
  digitalWrite(9,0);
  digitalWrite(8,1);
  digitalWrite(7,1);
  delay(400);
  */
}
