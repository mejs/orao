#include <PS2KeyAdvanced.h>

uint16_t c;

PS2KeyAdvanced keyboard;

#define DATAPIN 3
#define IRQPIN  2

//MT88xx control pins
#define ANALOG_SW_CS        6 // Sets selected cross switch on/off (Old 13)
#define ANALOG_SW_DATA      4 // Sets selected cross switch on/off (Old 13)
#define ANALOG_SW_STROBE    7 // Strobe timing pulse
#define ANALOG_SW_RESET     5 // Reset all MT88XX cross switches to off (Old 2)
#define ANALOG_AX0          8
#define ANALOG_AX1          9
#define ANALOG_AX2          10
#define ANALOG_AX3          11
#define ANALOG_AY0          12
#define ANALOG_AY1          13
#define ANALOG_AY2          14



void setup() {
  delay(1000);
  // Configure the keyboard library
  keyboard.begin( DATAPIN, IRQPIN );
  keyboard.setNoBreak( 0 );
  keyboard.setNoRepeat( 1 ); 
  Serial.begin( 9600 );
  Serial.println( "PS2 Advanced Key Simple Test:" );
  pinMode(ANALOG_SW_DATA, OUTPUT);   
  pinMode(ANALOG_SW_RESET, OUTPUT);   
  pinMode(ANALOG_SW_CS, OUTPUT);  
  pinMode(ANALOG_SW_STROBE, OUTPUT);  
  pinMode(ANALOG_AX0, OUTPUT);          
  pinMode(ANALOG_AX1, OUTPUT);          
  pinMode(ANALOG_AX2, OUTPUT);          
  pinMode(ANALOG_AX3, OUTPUT);          
  pinMode(ANALOG_AY0, OUTPUT);          
  pinMode(ANALOG_AY1, OUTPUT);          
  pinMode(ANALOG_AY2, OUTPUT);          


}

void loop() {
      digitalWrite(ANALOG_SW_DATA, LOW);    // Data   
      digitalWrite(ANALOG_SW_RESET, LOW);    // Reset   
      digitalWrite(ANALOG_SW_CS, HIGH);    // CS   
      digitalWrite(ANALOG_SW_STROBE, LOW);    // Strobe     
      digitalWrite(ANALOG_AX0, LOW);       
      digitalWrite(ANALOG_AX1, LOW);       
      digitalWrite(ANALOG_AX2, LOW);       
      digitalWrite(ANALOG_AX3, LOW);       
      digitalWrite(ANALOG_AY0, LOW);       
      digitalWrite(ANALOG_AY1, LOW);       
      digitalWrite(ANALOG_AY2, LOW);       

  if (keyboard.available()) {
    
    c = keyboard.read( );
     if( c > 0 )
    {
    Serial.print( "Value " );
    Serial.print( c, HEX );
    Serial.print( " - Status Bits " );
    Serial.print( c >> 8, HEX );
    Serial.print( "  Code " );
    Serial.println( c & 0xFF, HEX );
    }
    // check for some of the special keys
    if (c == 94) {
      Serial.println("dj test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);  
    } else if (c == 32862) {
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);  
      } else if (c == 89) {
      Serial.println("Z test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, HIGH);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);    
      } else if (c == 73 ) {
      Serial.println("I test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, HIGH);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);    
      } else if (c == 81) {
      Serial.println("Q test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, HIGH); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, HIGH);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
    } else if (c == 32849) {
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);
     } else if (c == 74) {
      Serial.println("J test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, HIGH); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, HIGH);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);    
      } else if (c == 65) {
      Serial.println("A test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, HIGH);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);     
      } else if (c == 72) {
      Serial.println("H test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, HIGH);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);      

 
 
 
 
 
 
 
 
 
    } else if (c == 33121) {
      Serial.println("PF1 test"); 
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, LOW);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);       
    } else if (c == 33122) {
      Serial.println("PF2 test"); 
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, HIGH);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);    
    } else if (c == 33123) {
      Serial.println("PF3 test"); 
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, HIGH);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);    
    } else if (c == 33124) {
      Serial.println("PF4 test"); 
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, LOW);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);   
    } else if (c == 33125) {
      Serial.println("PF2 + CR test"); 
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, HIGH);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, LOW);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);                                                            
    } else if (c == 287) {
      Serial.println("space test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, LOW);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);       






        
    } else if (c == 52) {
      Serial.println("4 test"); 
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);       
    } else if (c == 57) {
      Serial.println("9 test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);    
    } else if (c == 51) {
      Serial.println("3 test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, HIGH); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);    
    } else if (c == 61) {
      Serial.println(". test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, HIGH); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);    
    } else if (c == 67) {
      Serial.println("C test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);    
    } else if (c == 86) {
      Serial.println("V test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);     
               
    } else if (c == 32863) {
      Serial.println("; test");
      digitalWrite(ANALOG_SW_DATA, HIGH);   digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, LOW); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);    
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);  
    } else if (c == 54) {
      Serial.println("6 test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, LOW);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);    
    } else if (c == 55) {
      Serial.println("7 test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, LOW);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);         
    } else if (c == 49) {
      Serial.println("1 test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, HIGH); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, LOW);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);    
    } else if (c == 77) {
      Serial.println("M test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, HIGH); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, LOW);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);    
    } else if (c == 90) {
      Serial.println("Y test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, LOW);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);    
    } else if (c == 78) {
      Serial.println("N test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, LOW);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);      

            
    } else if (c == 80) {
      Serial.println("P test");
      digitalWrite(ANALOG_SW_DATA, HIGH);   digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, LOW); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);    
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);  
    } else if (c == 82) {
      Serial.println("R test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, LOW);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);    
    } else if (c == 79) {
      Serial.println("O test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, LOW);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);    
    } else if (c == 69) {
      Serial.println("E test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, HIGH); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, LOW);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);    
    } else if (c == 76) {
      Serial.println("L test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, HIGH); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, LOW);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);    
    } else if (c == 68) {
      Serial.println("D test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, LOW);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);     
    } else if (c == 70) {
      Serial.println("F test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, LOW);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);      

      
    } else if (c == 32828) {
      Serial.println("- test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, LOW); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);    
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);    
    } else if (c == 53) {
      Serial.println("5 test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, LOW);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);    
    } else if (c == 56) {
      Serial.println("8 test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, LOW);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);    
    } else if (c == 50) {
      Serial.println("2 test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, HIGH); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, LOW);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);    
    } else if (c == 59) {
      Serial.println(", test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, HIGH); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, LOW);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);    
    } else if (c == 88) {
      Serial.println("X test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, LOW);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);    
    } else if (c == 66) {
      Serial.println("B test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, LOW);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);      

    
    
    
    
  
    } else if (c == 279) {
      Serial.println("up arrow test"); 
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, HIGH);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);      
    } else if (c == 277) {
      Serial.println("left arrow test"); 
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, LOW);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);  
    } else if (c == 284) {
      Serial.println("left arrow/backspace test"); 
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, LOW);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);   
               
     } else if (c == 280) {
      Serial.println("down arrow test"); 
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, HIGH);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);       
     } else if (c == 278) {
      Serial.println("right arrow test"); 
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, LOW);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);     
    } else if (c == 286) {
      Serial.println("Enter test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, LOW);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);     


    } else if (c == 16434) {
      Serial.println("apostrophe test");
      digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, HIGH); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, LOW); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);      
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH); 

    } else if (c == 16646) {
      Serial.println("shift test");
      digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH); 
            
    } else if (c == 49201) {
      Serial.println("! test");
      digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, HIGH); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, LOW); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);      
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH); 
       
    } else if (c == 16435) {
      Serial.println("# test");
      digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, HIGH); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);    
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH); 
 
    } else if (c == 16436) {
      Serial.println("$ test");
      digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH); 

    } else if (c == 16437) {
      Serial.println("% test");
      digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, LOW); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH); 

    } else if (c == 16438) {
      Serial.println("& test");
      digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, LOW); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH); 

    } else if (c == 16439) {
      Serial.println("` test");
      digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, LOW); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH); 

                  
    } else if (c == 16440) {
      Serial.println("( test");
      digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, LOW); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH); 

                  
    } else if (c == 16441) {
      Serial.println(") test");
      digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH); 
                  
    } else if (c == 49212) {
      Serial.println("= test");
      digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, LOW); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH); 

                   
    } else if (c == 16479) {
      Serial.println("+ test");
      digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, LOW); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH); 
                   
    } else if (c == 16665) {
      Serial.println("* test");
      digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, LOW); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH); 
      
    } else if (c == 16657) {
      Serial.println("? test");
      digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, LOW); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH); 
      
    } else if (c == 16443) {
      Serial.println("< test");
      digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, HIGH); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, LOW); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);  
      
    } else if (c == 16476) {
      Serial.println("@ test");
      digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH); 
       
    } else if (c == 16445) {
      Serial.println("> test");
      digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, HIGH); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);  

    } else if (c == 8456) {
      Serial.println("ctr test");
      digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH); 

                                       
    } else if (c == 8259) {
      Serial.println("ctrl c test");
      digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);      
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH); 

          } else if (c == 41036) {
      Serial.println("ctrl L test");
      digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, HIGH); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, LOW); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);      
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH); 

 
          } else if (c == 8263) {
      Serial.println("ctrl G test");
      digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);      
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);   
        
          } else if (c == 8262) {
      Serial.println("ctrl F test");
      digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, LOW); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);      
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);  

          } else if (c == 8264) {
      Serial.println("ctrl H test");
      digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);      
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);          
            
          } else if (c == 8267) {
      Serial.println("ctrl K test");
      digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, HIGH); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);      
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);          
            
          } else if (c == 8265) {
      Serial.println("ctrl I test");
      digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);      
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);          
            
          } else if (c == 8266) {
      Serial.println("ctrl J test");
      digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, HIGH); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);      
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);          
            
          } else if (c == 8261) {
      Serial.println("ctrl E test");
      digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, HIGH); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, LOW); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);      
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);     
           
           } else if (c == 8258) {
      Serial.println("ctrl B test");
      digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, LOW); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);      
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);          
          
           } else if (c == 8277) {
      Serial.println("ctrl U test");
      digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);      
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);          
          
           } else if (c == 8260) {
      Serial.println("ctrl D test");
      digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, LOW); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);      
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);          
          
           } else if (c == 8269) {
      Serial.println("ctrl M test");
      digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, HIGH); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, LOW); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);      
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);

           } else if (c == 8278) {                
      Serial.println("ctrl V test");
      digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);
      digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_SW_STROBE, LOW);    
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);    
        
           } else if (c == 8108) {
      Serial.println("ctrl test");
      digitalWrite(ANALOG_SW_DATA, HIGH); digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);  

    } else if (c == 93) {
      Serial.println("Sh test");
      digitalWrite(ANALOG_SW_DATA, HIGH);   digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, HIGH); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);    
    } else if (c == 32861) {
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);  
    } else if (c == 84) {
      Serial.println("T test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, HIGH);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);    
    } else if (c == 85) {
      Serial.println("U test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, HIGH); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, HIGH);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);    
    } else if (c == 87) {
      Serial.println("W test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, HIGH); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, HIGH);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);    
    } else if (c == 75) {
      Serial.println("K test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, HIGH); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, HIGH);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);    
    } else if (c == 83) {
      Serial.println("S test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, HIGH);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);     
    } else if (c == 71) {
      Serial.println("G test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, HIGH); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, HIGH);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);      


    } else if (c == 33049) {
      Serial.println(": test");
      digitalWrite(ANALOG_SW_DATA, HIGH);   digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, LOW); digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);    
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);  
    } else if (c == 91) {
      Serial.println("Č test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, LOW);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);        
    } else if (c == 58) {
      Serial.println("Ć test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, HIGH);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);        
   } else if (c == 32830) {
      Serial.println("Ž test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, LOW);  digitalWrite(ANALOG_AY2, HIGH);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);        
   } else if (c == 33041) {
      Serial.println("/ test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, HIGH); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, LOW);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);      
   } else if (c == 32860) {
      Serial.println("^ test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, HIGH); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);      
      

    } else if (c == 48) {
      Serial.println("0 test");
      digitalWrite(ANALOG_SW_DATA, HIGH);  digitalWrite(ANALOG_AX0, LOW); digitalWrite(ANALOG_AX1, LOW); digitalWrite(ANALOG_AX2, LOW); digitalWrite(ANALOG_AX3, LOW); digitalWrite(ANALOG_AY0, LOW); digitalWrite(ANALOG_AY1, HIGH);  digitalWrite(ANALOG_AY2, HIGH);  digitalWrite(ANALOG_SW_STROBE, HIGH); digitalWrite(ANALOG_SW_STROBE, LOW);   
      delay(100);
      digitalWrite(ANALOG_SW_DATA, LOW); digitalWrite(ANALOG_SW_RESET, HIGH);         



    } else {
      
      // otherwise, just print all normal characters
      Serial.print(c);
     
    }
  }
}
