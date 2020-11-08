double number1;
double number2;
double result;
char operation;

void setup()
{
	Serial.begin(9600);
}

void loop()
{
  while(Serial.available() >0)
  {
    number1 = Serial.parseInt();
    operation = Serial.read();
    number2 = Serial.parseInt();
    
    if(number1>99 || number2>99)
    {
      Serial.println("Liczba powinna być dwucyfrowa!");
      return;
    }
    
    if(operation == '/' && number2==0)
    {
      Serial.println("Nie mozna dzielic przez 0!");
      return;
    }
    Serial.print("Wynik :");
	Serial.print(calculateExpression());
    Serial.println();
  }
}

double calculateExpression() { 
  
  switch (operation) {
    
    case '+' :
		return number1 + number2;    
    case '-' : 
		return number1 - number2; 
    case '*' : 
		return number1 * number2;
    case '/' :
		return number1 / number2; 
    default :
    Serial.println("Niepoprawny symbol!");
    return 0.0;
  }
}