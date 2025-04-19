//LED anodes
int ROW_1  = 2; 
int ROW_2  = 3;
int ROW_3  = 4;
int ROW_4  = 5;
int ROW_5  = 6;
int ROW_6  = 7;
int ROW_7  = 8;
int ROW_8  = 9;
//Red LED cathodes
int COL_1_R  = 1; 
int COL_2_R  = 10; 
int COL_3_R  = 11; 
int COL_4_R  = 12; 
int COL_5_R  = 13; 
//Green LED cathodes
int COL_1_G  = 14; 
int COL_2_G  = 15; 
int COL_3_G  = 16; 
int COL_4_G  = 17; 
int COL_5_G  = 18; 

//counters for rows and columns of matrix display
int CTR_R  = 1;
int CTR_C  = 1;
int CTR_D  = 1;

void Display_A();
void Display_B();
void Display_C();
void Display_D();
void Display_E();
void Display_F();
void Display_G();
void Display_H();
void Display_I();
void Display_J();
void Display_K();
void Display_L();
void Display_M();
void Display_N();
void Display_N2();
void Display_O();
void Display_P();
void Display_Q();
void Display_R();
void Display_S();
void Display_T();
void Display_U();
void Display_V();
void Display_W();
void Display_X();
void Display_Y();
void Display_Z();


unsigned long previousMillis = 0;
const long interval = 1000;
int currentLetterIndex = 0;

void setup() {
   // initialize pins as output
   pinMode(ROW_1,  OUTPUT);
   pinMode(ROW_2,  OUTPUT);
   pinMode(ROW_3,  OUTPUT);
   pinMode(ROW_4,  OUTPUT);
   pinMode(ROW_5,  OUTPUT);
   pinMode(ROW_6,  OUTPUT);
   pinMode(ROW_7,  OUTPUT);
   pinMode(ROW_8,  OUTPUT);

   pinMode(COL_1_R,  OUTPUT);
   pinMode(COL_2_R,  OUTPUT);
   pinMode(COL_3_R,  OUTPUT);
   pinMode(COL_4_R,  OUTPUT);
   pinMode(COL_5_R,  OUTPUT);

   pinMode(COL_1_G,  OUTPUT);
   pinMode(COL_2_G,  OUTPUT);
   pinMode(COL_3_G,  OUTPUT);
   pinMode(COL_4_G,  OUTPUT);
   pinMode(COL_5_G,  OUTPUT);
}

void (*letters[])()={
  Display_A,
  Display_B,
  Display_C,
  Display_D,
  Display_E,
  Display_F,
  Display_G,
  Display_H,
  Display_I,
  Display_J,
  Display_K,
  Display_L,
  Display_M,
  Display_N,
  Display_N2,
  Display_O,
  Display_P,
  Display_Q,
  Display_R,
  Display_S,
  Display_T,
  Display_U,
  Display_V,
  Display_W,
  Display_X,
  Display_Y,
  Display_Z
};

void loop() {
  unsigned long currentMillis = millis();

  // Mientras no haya pasado el intervalo, sigue mostrando la letra actual
  if (currentMillis - previousMillis < interval) {
    letters[currentLetterIndex](); // Mostrar letra actual una fila a la vez
  } else {
    // Reiniciar el tiempo y pasar a la siguiente letra
    previousMillis = currentMillis;
    currentLetterIndex++;

    if (currentLetterIndex >= sizeof(letters) / sizeof(letters[0])) {
      currentLetterIndex = 0; // Vuelve al inicio del abecedario
    }
  }
}



void Turn_all_green() {
  // Set all row pins to HIGH (anodes)
  digitalWrite(ROW_1, HIGH);
  digitalWrite(ROW_2, HIGH);
  digitalWrite(ROW_3, HIGH);
  digitalWrite(ROW_4, HIGH);
  digitalWrite(ROW_5, HIGH);
  digitalWrite(ROW_6, HIGH);
  digitalWrite(ROW_7, HIGH);
  digitalWrite(ROW_8, HIGH);

  // Set all green column pins to LOW (cathodes)
  digitalWrite(COL_1_G, LOW);
  digitalWrite(COL_2_G, LOW);
  digitalWrite(COL_3_G, LOW);
  digitalWrite(COL_4_G, LOW);
  digitalWrite(COL_5_G, LOW);
}

void Turn_them_all_off(){
   digitalWrite(ROW_1,  LOW);         //Anode side
   digitalWrite(ROW_2,  LOW);
   digitalWrite(ROW_3,  LOW);
   digitalWrite(ROW_4,  LOW);
   digitalWrite(ROW_5,  LOW);
   digitalWrite(ROW_6,  LOW);
   digitalWrite(ROW_7,  LOW);
   digitalWrite(ROW_8,  LOW);
   
   digitalWrite(COL_1_R,  HIGH);      //Cathode side
   digitalWrite(COL_2_R,  HIGH);
   digitalWrite(COL_3_R,  HIGH);
   digitalWrite(COL_4_R,  HIGH);
   digitalWrite(COL_5_R,  HIGH);
   
   digitalWrite(COL_1_G,  HIGH);      //Cathode side
   digitalWrite(COL_2_G,  HIGH);
   digitalWrite(COL_3_G,  HIGH);
   digitalWrite(COL_4_G,  HIGH);
   digitalWrite(COL_5_G,  HIGH);
   
   //delayMicroseconds(500);
}

void Display_A() {
  // Apagar todos los LEDs antes de encender la letra 'A'
  Turn_them_all_off();

  // Mostrar la letra 'A' en la matriz
  switch (CTR_R) {
    case 1: // Primera fila (parte superior de la "A")
      digitalWrite(ROW_1, HIGH);
      digitalWrite(COL_3_G, LOW); // Centro de la parte superior
      CTR_R++;
      break;

    case 2: // Segunda fila (laterales de la "A")
      digitalWrite(ROW_2, HIGH);
      digitalWrite(COL_2_G, LOW); // Lateral izquierdo
      digitalWrite(COL_4_G, LOW); // Lateral derecho
      CTR_R++;
      break;

    case 3: // Tercera fila (laterales de la "A")
      digitalWrite(ROW_3, HIGH);
      digitalWrite(COL_1_G, LOW); // Lateral izquierdo
      digitalWrite(COL_5_G, LOW); // Lateral derecho
      CTR_R++;
      break;

    case 4: // Cuarta fila (línea horizontal del medio de la "A")
      digitalWrite(ROW_4, HIGH);
      digitalWrite(COL_1_G, LOW); // Lateral izquierdo
      digitalWrite(COL_2_G, LOW);
      digitalWrite(COL_3_G, LOW); // Centro
      digitalWrite(COL_4_G, LOW);
      digitalWrite(COL_5_G, LOW); // Lateral derecho
      CTR_R++;
      break;

    case 5: // Quinta fila (laterales de la "A")
      digitalWrite(ROW_5, HIGH);
      digitalWrite(COL_1_G, LOW); // Lateral izquierdo
      digitalWrite(COL_5_G, LOW); // Lateral derecho
      CTR_R++;
      break;

    case 6: // Sexta fila (laterales de la "A")
      digitalWrite(ROW_6, HIGH);
      digitalWrite(COL_1_G, LOW); // Lateral izquierdo
      digitalWrite(COL_5_G, LOW); // Lateral derecho
      CTR_R++;
      break;

    case 7: // Séptima fila (laterales de la "A")
      digitalWrite(ROW_7, HIGH);
      digitalWrite(COL_1_G, LOW); // Lateral izquierdo
      digitalWrite(COL_5_G, LOW); // Lateral derecho
      CTR_R++;
      break;

    case 8: // Octava fila (laterales de la "A")
      digitalWrite(ROW_8, HIGH);
      digitalWrite(COL_1_G, LOW); // Lateral izquierdo
      digitalWrite(COL_5_G, LOW); // Lateral derecho
      CTR_R = 1; // Reinicia el contador de filas
      break;
  }

  delay(2); // Breve retraso para evitar parpadeos
}

void Display_B() {
  // Apagar todos los LEDs antes de encender la letra 'B'
  Turn_them_all_off();

  // Mostrar la letra 'B' en la matriz
  switch (CTR_R) {
    case 1: // Primera fila (OOOOI)
      digitalWrite(ROW_1, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_2_G, LOW);
      digitalWrite(COL_3_G, LOW);
      digitalWrite(COL_4_G, LOW);
      // COL_5_G permanece apagado
      CTR_R++;
      break;

    case 2: // Segunda fila (OIIIO)
      digitalWrite(ROW_2, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW); // O
      CTR_R++;
      break;

    case 3: // Tercera fila (OIIOI)
      digitalWrite(ROW_3, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW); // O
      CTR_R++;
      break;

    case 4: // Cuarta fila (OOOII)
      digitalWrite(ROW_4, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_2_G, LOW); // O
      digitalWrite(COL_3_G, LOW); // O
      digitalWrite(COL_4_G, LOW); // O
      // COL_4_G y COL_5_G permanecen apagados (I)
      CTR_R++;
      break;

    case 5: // Quinta fila (OIIOI)
      digitalWrite(ROW_5, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      // COL_2_G permanece apagado (I)
      // COL_4_G permanece apagado (I)
      digitalWrite(COL_5_G, LOW); // O
      CTR_R++;
      break;

    case 6: // Sexta fila (OIIIO)
      digitalWrite(ROW_6, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      // COL_2_G y COL_3_G permanecen apagados (I)
      digitalWrite(COL_5_G, LOW); // O
      CTR_R++;
      break;

    case 7: // Séptima fila (OIIIO)
      digitalWrite(ROW_7, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      // COL_2_G y COL_3_G permanecen apagados (I)
      digitalWrite(COL_5_G, LOW); // O
      CTR_R++;
      break;

    case 8: // Octava fila (OOOOI)
      digitalWrite(ROW_8, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_2_G, LOW);
      digitalWrite(COL_3_G, LOW);
      digitalWrite(COL_4_G, LOW);
      // COL_5_G permanece apagado
      CTR_R = 1; // Reinicia el contador de filas
      break;
  }

  delay(2); // Breve retraso para evitar parpadeos
}

void Display_C(){
    Turn_them_all_off();

  
  switch (CTR_R) {
    case 1: // Primera fila (OOOOI)
      digitalWrite(ROW_1, HIGH);
      digitalWrite(COL_3_G, LOW);
      digitalWrite(COL_4_G, LOW);
      digitalWrite(COL_5_G, LOW);
      // COL_5_G permanece apagado
      CTR_R++;
      break;

    case 2: // Segunda fila (OIIIO)
      digitalWrite(ROW_2, HIGH);
      digitalWrite(COL_2_G, LOW); // O
      CTR_R++;
      break;

    case 3: // Tercera fila (OIIOI)
      digitalWrite(ROW_3, HIGH);
      digitalWrite(COL_1_G, LOW); // O
    
      CTR_R++;
      break;

    case 4: // Cuarta fila (OOOII)
      digitalWrite(ROW_4, HIGH);
      digitalWrite(COL_1_G, LOW); // O
    
      // COL_4_G y COL_5_G permanecen apagados (I)
      CTR_R++;
      break;

    case 5: // Quinta fila (OIIOI)
      digitalWrite(ROW_5, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      
      CTR_R++;
      break;

    case 6: // Sexta fila (OIIIO)
      digitalWrite(ROW_6, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      CTR_R++;
      break;

    case 7: // Séptima fila (OIIIO)
      digitalWrite(ROW_7, HIGH);
      digitalWrite(COL_2_G, LOW); // O
      
      CTR_R++;
      break;

    case 8: // Octava fila (OOOOI)
      digitalWrite(ROW_8, HIGH);
      digitalWrite(COL_3_G, LOW);
      digitalWrite(COL_4_G, LOW);
      digitalWrite(COL_5_G, LOW);
      
      // COL_5_G permanece apagado
      CTR_R = 1; // Reinicia el contador de filas
      break;
  }

  delay(2); // Breve retraso para evitar parpadeos
}

void Display_D(){
    Turn_them_all_off();

  
  switch (CTR_R) {
    case 1: // Primera fila (OOOOI)
      digitalWrite(ROW_1, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_2_G, LOW);
      digitalWrite(COL_3_G, LOW);
      

      // COL_5_G permanece apagado
      CTR_R++;
      break;

    case 2: // Segunda fila (OIIIO)
      digitalWrite(ROW_2, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_4_G, LOW);
      CTR_R++;
      break;

    case 3: // Tercera fila (OIIOI)
      digitalWrite(ROW_3, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW);
    
      CTR_R++;
      break;

    case 4: // Cuarta fila (OOOII)
      digitalWrite(ROW_4, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW);
    
      // COL_4_G y COL_5_G permanecen apagados (I)
      CTR_R++;
      break;

    case 5: // Quinta fila (OIIOI)
      digitalWrite(ROW_5, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW);
      
      CTR_R++;
      break;

    case 6: // Sexta fila (OIIIO)
      digitalWrite(ROW_6, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 7: // Séptima fila (OIIIO)
      digitalWrite(ROW_7, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_4_G, LOW);
      CTR_R++;
      break;

    case 8: // Octava fila (OOOOI)
      digitalWrite(ROW_8, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_2_G, LOW);
      digitalWrite(COL_3_G, LOW);
      
      
      // COL_5_G permanece apagado
      CTR_R = 1; // Reinicia el contador de filas
      break;
  }

  delay(2); // Breve retraso para evitar parpadeos
}

void Display_E(){
    Turn_them_all_off();

  
  switch (CTR_R) {
    case 1: // Primera fila (OOOOI)
      digitalWrite(ROW_1, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_2_G, LOW);
      digitalWrite(COL_3_G, LOW);
      digitalWrite(COL_4_G, LOW);
      digitalWrite(COL_5_G, LOW);

      // COL_5_G permanece apagado
      CTR_R++;
      break;

    case 2: // Segunda fila (OIIIO)
      digitalWrite(ROW_2, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      
      CTR_R++;
      break;

    case 3: // Tercera fila (OIIOI)
      digitalWrite(ROW_3, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      
    
      CTR_R++;
      break;

    case 4: // Cuarta fila (OOOII)
      digitalWrite(ROW_4, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_2_G, LOW);
      digitalWrite(COL_3_G, LOW);
      digitalWrite(COL_4_G, LOW);
      // COL_4_G y COL_5_G permanecen apagados (I)
      CTR_R++;
      break;

    case 5: // Quinta fila (OIIOI)
      digitalWrite(ROW_5, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      
      
      CTR_R++;
      break;

    case 6: // Sexta fila (OIIIO)
      digitalWrite(ROW_6, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      
      CTR_R++;
      break;

    case 7: // Séptima fila (OIIIO)
      digitalWrite(ROW_7, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      
      CTR_R++;
      break;

    case 8: // Octava fila (OOOOI)
      digitalWrite(ROW_8, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_2_G, LOW);
      digitalWrite(COL_3_G, LOW);
      digitalWrite(COL_4_G, LOW);
      digitalWrite(COL_5_G, LOW);
      
      
      // COL_5_G permanece apagado
      CTR_R = 1; // Reinicia el contador de filas
      break;
  }

  delay(2); // Breve retraso para evitar parpadeos
}

void Display_F(){
    Turn_them_all_off();

  
  switch (CTR_R) {
    case 1: // Primera fila (OOOOI)
      digitalWrite(ROW_1, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_2_G, LOW);
      digitalWrite(COL_3_G, LOW);
      digitalWrite(COL_4_G, LOW);
      digitalWrite(COL_5_G, LOW);

      // COL_5_G permanece apagado
      CTR_R++;
      break;

    case 2: // Segunda fila (OIIIO)
      digitalWrite(ROW_2, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      
      CTR_R++;
      break;

    case 3: // Tercera fila (OIIOI)
      digitalWrite(ROW_3, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      
    
      CTR_R++;
      break;

    case 4: // Cuarta fila (OOOII)
      digitalWrite(ROW_4, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_2_G, LOW);
      digitalWrite(COL_3_G, LOW);
      digitalWrite(COL_4_G, LOW);
      // COL_4_G y COL_5_G permanecen apagados (I)
      CTR_R++;
      break;

    case 5: // Quinta fila (OIIOI)
      digitalWrite(ROW_5, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      
      
      CTR_R++;
      break;

    case 6: // Sexta fila (OIIIO)
      digitalWrite(ROW_6, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      
      CTR_R++;
      break;

    case 7: // Séptima fila (OIIIO)
      digitalWrite(ROW_7, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      
      CTR_R++;
      break;

    case 8: // Octava fila (OOOOI)
      digitalWrite(ROW_8, HIGH);
      digitalWrite(COL_1_G, LOW);
      
      
      
      // COL_5_G permanece apagado
      CTR_R = 1; // Reinicia el contador de filas
      break;
  }

  delay(2); // Breve retraso para evitar parpadeos
}

void Display_G(){
    Turn_them_all_off();

  
  switch (CTR_R) {
    case 1: // Primera fila (OOOOI)
      digitalWrite(ROW_1, HIGH);
      
      digitalWrite(COL_2_G, LOW);
      digitalWrite(COL_3_G, LOW);
      digitalWrite(COL_4_G, LOW);
      digitalWrite(COL_5_G, LOW);

      // COL_5_G permanece apagado
      CTR_R++;
      break;

    case 2: // Segunda fila (OIIIO)
      digitalWrite(ROW_2, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      
      CTR_R++;
      break;

    case 3: // Tercera fila (OIIOI)
      digitalWrite(ROW_3, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      
    
      CTR_R++;
      break;

    case 4: // Cuarta fila (OOOII)
      digitalWrite(ROW_4, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_3_G, LOW);
      digitalWrite(COL_4_G, LOW);
      digitalWrite(COL_5_G, LOW);
      
      // COL_4_G y COL_5_G permanecen apagados (I)
      CTR_R++;
      break;

    case 5: // Quinta fila (OIIOI)
      digitalWrite(ROW_5, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 6: // Sexta fila (OIIIO)
      digitalWrite(ROW_6, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 7: // Séptima fila (OIIIO)
      digitalWrite(ROW_7, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 8: // Octava fila (OOOOI)
      digitalWrite(ROW_8, HIGH);
      digitalWrite(COL_2_G, LOW);
      digitalWrite(COL_3_G, LOW);
      digitalWrite(COL_4_G, LOW);
      CTR_R = 1; // Reinicia el contador de filas
      break;
  }

  delay(2); // Breve retraso para evitar parpadeos
}

void Display_H(){
    Turn_them_all_off();

  
  switch (CTR_R) {
    case 1: // Primera fila (OOOOI)
      digitalWrite(ROW_1, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_5_G, LOW);

      // COL_5_G permanece apagado
      CTR_R++;
      break;

    case 2: // Segunda fila (OIIIO)
      digitalWrite(ROW_2, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW);
      
      CTR_R++;
      break;

    case 3: // Tercera fila (OIIOI)
      digitalWrite(ROW_3, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW);
    
      CTR_R++;
      break;

    case 4: // Cuarta fila (OOOII)
      digitalWrite(ROW_4, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_2_G, LOW);
      digitalWrite(COL_3_G, LOW);
      digitalWrite(COL_4_G, LOW);
      digitalWrite(COL_5_G, LOW);
      
      // COL_4_G y COL_5_G permanecen apagados (I)
      CTR_R++;
      break;

    case 5: // Quinta fila (OIIOI)
      digitalWrite(ROW_5, HIGH);
      digitalWrite(COL_1_G, LOW); // O}
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 6: // Sexta fila (OIIIO)
      digitalWrite(ROW_6, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 7: // Séptima fila (OIIIO)
      digitalWrite(ROW_7, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 8: // Octava fila (OOOOI)
      digitalWrite(ROW_8, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_5_G, LOW);
      CTR_R = 1; // Reinicia el contador de filas
      break;
  }

  delay(2); // Breve retraso para evitar parpadeos
}

void Display_I(){
    Turn_them_all_off();

  
  switch (CTR_R) {
    case 1: // Primera fila (OOOOI)
      digitalWrite(ROW_1, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_2_G, LOW);
      digitalWrite(COL_3_G, LOW);
      digitalWrite(COL_4_G, LOW);
      digitalWrite(COL_5_G, LOW);

      // COL_5_G permanece apagado
      CTR_R++;
      break;

    case 2: // Segunda fila (OIIIO)
      digitalWrite(ROW_2, HIGH);
      digitalWrite(COL_3_G, LOW); // O
  
      
      CTR_R++;
      break;

    case 3: // Tercera fila (OIIOI)
      digitalWrite(ROW_3, HIGH);
      digitalWrite(COL_3_G, LOW); // O
      
    
      CTR_R++;
      break;

    case 4: // Cuarta fila (OOOII)
      digitalWrite(ROW_4, HIGH);
      
      digitalWrite(COL_3_G, LOW);
     
      
      // COL_4_G y COL_5_G permanecen apagados (I)
      CTR_R++;
      break;

    case 5: // Quinta fila (OIIOI)
      digitalWrite(ROW_5, HIGH);
      digitalWrite(COL_3_G, LOW);
      CTR_R++;
      break;

    case 6: // Sexta fila (OIIIO)
      digitalWrite(ROW_6, HIGH);
      digitalWrite(COL_3_G, LOW); // O
      CTR_R++;
      break;

    case 7: // Séptima fila (OIIIO)
      digitalWrite(ROW_7, HIGH);
      digitalWrite(COL_3_G, LOW); // O
      CTR_R++;
      break;

    case 8: // Octava fila (OOOOI)
      digitalWrite(ROW_8, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_2_G, LOW);
      digitalWrite(COL_3_G, LOW);
      digitalWrite(COL_4_G, LOW);
      digitalWrite(COL_5_G, LOW);
      CTR_R = 1; // Reinicia el contador de filas
      break;
  }

  delay(2); // Breve retraso para evitar parpadeos
}

void Display_J(){
    Turn_them_all_off();

  
  switch (CTR_R) {
    case 1: // Primera fila (OOOOI)
      digitalWrite(ROW_1, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_2_G, LOW);
      digitalWrite(COL_3_G, LOW);
      digitalWrite(COL_4_G, LOW);
      digitalWrite(COL_5_G, LOW);

      // COL_5_G permanece apagado
      CTR_R++;
      break;

    case 2: // Segunda fila (OIIIO)
      digitalWrite(ROW_2, HIGH);
      digitalWrite(COL_3_G, LOW); // O
  
      
      CTR_R++;
      break;

    case 3: // Tercera fila (OIIOI)
      digitalWrite(ROW_3, HIGH);
      digitalWrite(COL_3_G, LOW); // O
      
    
      CTR_R++;
      break;

    case 4: // Cuarta fila (OOOII)
      digitalWrite(ROW_4, HIGH);
      
      digitalWrite(COL_3_G, LOW);
     
      
      // COL_4_G y COL_5_G permanecen apagados (I)
      CTR_R++;
      break;

    case 5: // Quinta fila (OIIOI)
      digitalWrite(ROW_5, HIGH);
      digitalWrite(COL_3_G, LOW);
      CTR_R++;
      break;

    case 6: // Sexta fila (OIIIO)
      digitalWrite(ROW_6, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_3_G, LOW); // O
      CTR_R++;
      break;

    case 7: // Séptima fila (OIIIO)
      digitalWrite(ROW_7, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_3_G, LOW); // O
      CTR_R++;
      break;

    case 8: // Octava fila (OOOOI)
      digitalWrite(ROW_8, HIGH);
      digitalWrite(COL_2_G, LOW);
      CTR_R = 1; // Reinicia el contador de filas
      break;
  }

  delay(2); // Breve retraso para evitar parpadeos
}

void Display_K(){
    Turn_them_all_off();

  
  switch (CTR_R) {
    case 1: // Primera fila (OOOOI)
      digitalWrite(ROW_1, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_5_G, LOW);

      // COL_5_G permanece apagado
      CTR_R++;
      break;

    case 2: // Segunda fila (OIIIO)
      digitalWrite(ROW_2, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_4_G, LOW); // O
      
      CTR_R++;
      break;

    case 3: // Tercera fila (OIIOI)
      digitalWrite(ROW_3, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_3_G, LOW); // O
      
    
      CTR_R++;
      break;

    case 4: // Cuarta fila (OOOII)
      digitalWrite(ROW_4, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_2_G, LOW);
     
      CTR_R++;
      break;

    case 5: // Quinta fila (OIIOI)
      digitalWrite(ROW_5, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_2_G, LOW);
      CTR_R++;
      break;

    case 6: // Sexta fila (OIIIO)
      digitalWrite(ROW_6, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_3_G, LOW); // O
      CTR_R++;
      break;

    case 7: // Séptima fila (OIIIO)
      digitalWrite(ROW_7, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_4_G, LOW); // O
      CTR_R++;
      break;

    case 8: // Octava fila (OOOOI)
      digitalWrite(ROW_8, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_5_G, LOW); // O
      CTR_R = 1; // Reinicia el contador de filas
      break;
  }

  delay(2); // Breve retraso para evitar parpadeos
}

void Display_L(){
    Turn_them_all_off();

  
  switch (CTR_R) {
    case 1: // Primera fila (OOOOI)
      digitalWrite(ROW_1, HIGH);
      digitalWrite(COL_1_G, LOW);
      CTR_R++;
      break;

    case 2: // Segunda fila (OIIIO)
      digitalWrite(ROW_2, HIGH);
      digitalWrite(COL_1_G, LOW); 
      CTR_R++;
      break;

    case 3: // Tercera fila (OIIOI)
      digitalWrite(ROW_3, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      CTR_R++;
      break;

    case 4: // Cuarta fila (OOOII)
      digitalWrite(ROW_4, HIGH);
      digitalWrite(COL_1_G, LOW); 
      CTR_R++;
      break;

    case 5: // Quinta fila (OIIOI)
      digitalWrite(ROW_5, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      
      CTR_R++;
      break;

    case 6: // Sexta fila (OIIIO)
      digitalWrite(ROW_6, HIGH);
      digitalWrite(COL_1_G, LOW);
      
      CTR_R++;
      break;

    case 7: // Séptima fila (OIIIO)
      digitalWrite(ROW_7, HIGH);
      digitalWrite(COL_1_G, LOW);
      
      CTR_R++;
      break;

    case 8: // Octava fila (OOOOI)
      digitalWrite(ROW_8, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_2_G, LOW);
      digitalWrite(COL_3_G, LOW);
      digitalWrite(COL_4_G, LOW);
      digitalWrite(COL_5_G, LOW); // O
      CTR_R = 1; // Reinicia el contador de filas
      break;
  }

  delay(2); // Breve retraso para evitar parpadeos
}
void Display_M(){
    Turn_them_all_off();

  
  switch (CTR_R) {
    case 1: // Primera fila (OOOOI)
      digitalWrite(ROW_1, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_5_G, LOW);

      // COL_5_G permanece apagado
      CTR_R++;
      break;

    case 2: // Segunda fila (OIIIO)
      digitalWrite(ROW_2, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_2_G, LOW);
      digitalWrite(COL_4_G, LOW);
      digitalWrite(COL_5_G, LOW);
      
      CTR_R++;
      break;

    case 3: // Tercera fila (OIIOI)
      digitalWrite(ROW_3, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_3_G, LOW);
      digitalWrite(COL_5_G, LOW);
    
      CTR_R++;
      break;

    case 4: // Cuarta fila (OOOII)
      digitalWrite(ROW_4, HIGH);
      digitalWrite(COL_1_G, LOW); 
      digitalWrite(COL_5_G, LOW);
      
      // COL_4_G y COL_5_G permanecen apagados (I)
      CTR_R++;
      break;

    case 5: // Quinta fila (OIIOI)
      digitalWrite(ROW_5, HIGH);
      digitalWrite(COL_1_G, LOW); // O}
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 6: // Sexta fila (OIIIO)
      digitalWrite(ROW_6, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 7: // Séptima fila (OIIIO)
      digitalWrite(ROW_7, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 8: // Octava fila (OOOOI)
      digitalWrite(ROW_8, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_5_G, LOW);
      CTR_R = 1; // Reinicia el contador de filas
      break;
  }

  delay(2); // Breve retraso para evitar parpadeos
}

void Display_N(){
    Turn_them_all_off();

  
  switch (CTR_R) {
    case 1: // Primera fila (OOOOI)
      digitalWrite(ROW_1, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_5_G, LOW);

      // COL_5_G permanece apagado
      CTR_R++;
      break;

    case 2: // Segunda fila (OIIIO)
      digitalWrite(ROW_2, HIGH);
      digitalWrite(COL_1_G, LOW); 
      digitalWrite(COL_5_G, LOW);
      
      CTR_R++;
      break;

    case 3: // Tercera fila (OIIOI)
      digitalWrite(ROW_3, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_2_G, LOW);
      digitalWrite(COL_5_G, LOW);
    
      CTR_R++;
      break;

    case 4: // Cuarta fila (OOOII)
      digitalWrite(ROW_4, HIGH);
      digitalWrite(COL_1_G, LOW); 
      digitalWrite(COL_3_G, LOW); 
      digitalWrite(COL_5_G, LOW);
      
      // COL_4_G y COL_5_G permanecen apagados (I)
      CTR_R++;
      break;

    case 5: // Quinta fila (OIIOI)
      digitalWrite(ROW_5, HIGH);
      digitalWrite(COL_1_G, LOW); // O}
      digitalWrite(COL_4_G, LOW); 
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 6: // Sexta fila (OIIIO)
      digitalWrite(ROW_6, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 7: // Séptima fila (OIIIO)
      digitalWrite(ROW_7, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 8: // Octava fila (OOOOI)
      digitalWrite(ROW_8, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_5_G, LOW);
      CTR_R = 1; // Reinicia el contador de filas
      break;
  }

  delay(2); // Breve retraso para evitar parpadeos
}

void Display_N2(){
    Turn_them_all_off();

  
  switch (CTR_R) {
    case 1: // Primera fila (OOOOI)
      digitalWrite(ROW_1, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_2_G, LOW);
      digitalWrite(COL_3_G, LOW);
      digitalWrite(COL_4_G, LOW);
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 2: // Segunda fila (OIIIO)
      digitalWrite(ROW_2, HIGH);
      
      CTR_R++;
      break;

    case 3: // Tercera fila (OIIOI)
      digitalWrite(ROW_3, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW); // O
    
      CTR_R++;
      break;

    case 4: // Cuarta fila (OOOII)
      digitalWrite(ROW_4, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_2_G, LOW);
      digitalWrite(COL_5_G, LOW);
      // COL_4_G y COL_5_G permanecen apagados (I)
      CTR_R++;
      break;

    case 5: // Quinta fila (OIIOI)
      digitalWrite(ROW_5, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_3_G, LOW); // O
      digitalWrite(COL_5_G, LOW); // O
      CTR_R++;
      break;

    case 6: // Sexta fila (OIIIO)
      digitalWrite(ROW_6, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_4_G, LOW); // O
      digitalWrite(COL_5_G, LOW); // O
      CTR_R++;
      break;

    case 7: // Séptima fila (OIIIO)
      digitalWrite(ROW_7, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW); // O
      
      CTR_R++;
      break;

    case 8: // Octava fila (OOOOI)
      digitalWrite(ROW_8, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_5_G, LOW);
      CTR_R = 1; // Reinicia el contador de filas
      break;
  }

  delay(2); // Breve retraso para evitar parpadeos
}

void Display_O(){
    Turn_them_all_off();

  
  switch (CTR_R) {
    case 1: // Primera fila (OOOOI)
      digitalWrite(ROW_1, HIGH);
      digitalWrite(COL_2_G, LOW);
      digitalWrite(COL_3_G, LOW);
      digitalWrite(COL_4_G, LOW);
      CTR_R++;
      break;

    case 2: // Segunda fila (OIIIO)
      digitalWrite(ROW_2, HIGH);

      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 3: // Tercera fila (OIIOI)
      digitalWrite(ROW_3, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 4: // Cuarta fila (OOOII)
      digitalWrite(ROW_4, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW);
      // COL_4_G y COL_5_G permanecen apagados (I)
      CTR_R++;
      break;

    case 5: // Quinta fila (OIIOI)
      digitalWrite(ROW_5, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 6: // Sexta fila (OIIIO)
      digitalWrite(ROW_6, HIGH);
      digitalWrite(COL_1_G, LOW); 
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 7: // Séptima fila (OIIIO)
      digitalWrite(ROW_7, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 8: // Octava fila (OOOOI)
      digitalWrite(ROW_8, HIGH);
      digitalWrite(COL_2_G, LOW);
      digitalWrite(COL_3_G, LOW);
      digitalWrite(COL_4_G, LOW);
      
      // COL_5_G permanece apagado
      CTR_R = 1; // Reinicia el contador de filas
      break;
  }

  delay(2); // Breve retraso para evitar parpadeos
}

void Display_P() {
  // Apagar todos los LEDs antes de encender la letra 'B'
  Turn_them_all_off();

  // Mostrar la letra 'B' en la matriz
  switch (CTR_R) {
    case 1: // Primera fila (OOOOI)
      digitalWrite(ROW_1, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_2_G, LOW);
      digitalWrite(COL_3_G, LOW);
      digitalWrite(COL_4_G, LOW);
      CTR_R++;
      break;

    case 2: // Segunda fila (OIIIO)
      digitalWrite(ROW_2, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW); // O
      CTR_R++;
      break;

    case 3: // Tercera fila (OIIOI)
      digitalWrite(ROW_3, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW); // O
      CTR_R++;
      break;

    case 4: // Cuarta fila (OOOII)
      digitalWrite(ROW_4, HIGH);
      digitalWrite(COL_1_G, LOW); 
      digitalWrite(COL_5_G, LOW); // O
      // COL_4_G y COL_5_G permanecen apagados (I)
      CTR_R++;
      break;

    case 5: // Quinta fila (OIIOI)
      digitalWrite(ROW_5, HIGH);
      digitalWrite(COL_1_G, LOW); 
      digitalWrite(COL_2_G, LOW); // O
      digitalWrite(COL_3_G, LOW); // O
      digitalWrite(COL_4_G, LOW); 
      CTR_R++;
      break;

    case 6: // Sexta fila (OIIIO)
      digitalWrite(ROW_6, HIGH);
      digitalWrite(COL_1_G, LOW); 
      CTR_R++;
      break;

    case 7: // Séptima fila (OIIIO)
      digitalWrite(ROW_7, HIGH);
      digitalWrite(COL_1_G, LOW); 
      CTR_R++;
      break;

    case 8: // Octava fila (OOOOI)
      digitalWrite(ROW_8, HIGH);
      digitalWrite(COL_1_G, LOW);
      CTR_R = 1; // Reinicia el contador de filas
      break;
  }

  delay(2); // Breve retraso para evitar parpadeos
}
void Display_Q(){
    Turn_them_all_off();

  
  switch (CTR_R) {
    case 1: // Primera fila (OOOOI)
      digitalWrite(ROW_1, HIGH);
      digitalWrite(COL_2_G, LOW);
      digitalWrite(COL_3_G, LOW);
      digitalWrite(COL_4_G, LOW);
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 2: // Segunda fila (OIIIO)
      digitalWrite(ROW_2, HIGH);

      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 3: // Tercera fila (OIIOI)
      digitalWrite(ROW_3, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 4: // Cuarta fila (OOOII)
      digitalWrite(ROW_4, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW);
      // COL_4_G y COL_5_G permanecen apagados (I)
      CTR_R++;
      break;

    case 5: // Quinta fila (OIIOI)
      digitalWrite(ROW_5, HIGH);
      digitalWrite(COL_2_G, LOW); 
      digitalWrite(COL_3_G, LOW);
      digitalWrite(COL_4_G, LOW); // O
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 6: // Sexta fila (OIIIO)
      digitalWrite(ROW_6, HIGH);
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 7: // Séptima fila (OIIIO)
      digitalWrite(ROW_7, HIGH);
      digitalWrite(COL_4_G, LOW);
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 8: // Octava fila (OOOOI)
      digitalWrite(ROW_8, HIGH);
      digitalWrite(COL_5_G, LOW);
      
      // COL_5_G permanece apagado
      CTR_R = 1; // Reinicia el contador de filas
      break;
  }

  delay(2); // Breve retraso para evitar parpadeos
}

void Display_R() {
  // Apagar todos los LEDs antes de encender la letra 'B'
  Turn_them_all_off();

  // Mostrar la letra 'B' en la matriz
  switch (CTR_R) {
    case 1: // Primera fila (OOOOI)
      digitalWrite(ROW_1, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_2_G, LOW);
      digitalWrite(COL_3_G, LOW);
      digitalWrite(COL_4_G, LOW);
      CTR_R++;
      break;

    case 2: // Segunda fila (OIIIO)
      digitalWrite(ROW_2, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW); // O
      CTR_R++;
      break;

    case 3: // Tercera fila (OIIOI)
      digitalWrite(ROW_3, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW); // O
      CTR_R++;
      break;

    case 4: // Cuarta fila (OOOII)
      digitalWrite(ROW_4, HIGH);
      digitalWrite(COL_1_G, LOW); 
      digitalWrite(COL_5_G, LOW); // O
      // COL_4_G y COL_5_G permanecen apagados (I)
      CTR_R++;
      break;

    case 5: // Quinta fila (OIIOI)
      digitalWrite(ROW_5, HIGH);
      digitalWrite(COL_1_G, LOW); 
      digitalWrite(COL_2_G, LOW); // O
      digitalWrite(COL_3_G, LOW); // O
      digitalWrite(COL_4_G, LOW); 
      CTR_R++;
      break;

    case 6: // Sexta fila (OIIIO)
      digitalWrite(ROW_6, HIGH);
      digitalWrite(COL_1_G, LOW); 
      digitalWrite(COL_3_G, LOW); 
      CTR_R++;
      break;

    case 7: // Séptima fila (OIIIO)
      digitalWrite(ROW_7, HIGH);
      digitalWrite(COL_1_G, LOW); 
      digitalWrite(COL_4_G, LOW); 
      CTR_R++;
      break;

    case 8: // Octava fila (OOOOI)
      digitalWrite(ROW_8, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_5_G, LOW); 
      CTR_R = 1; // Reinicia el contador de filas
      break;
  }

  delay(2); // Breve retraso para evitar parpadeos
}
void Display_S(){
    Turn_them_all_off();

  
  switch (CTR_R) {
    case 1: // Primera fila (OOOOI)
      digitalWrite(ROW_1, HIGH);
      digitalWrite(COL_2_G, LOW);
      digitalWrite(COL_3_G, LOW);
      digitalWrite(COL_4_G, LOW);
      digitalWrite(COL_5_G, LOW);

      // COL_5_G permanece apagado
      CTR_R++;
      break;

    case 2: // Segunda fila (OIIIO)
      digitalWrite(ROW_2, HIGH);
      digitalWrite(COL_1_G, LOW); 
      CTR_R++;
      break;

    case 3: // Tercera fila (OIIOI)
      digitalWrite(ROW_3, HIGH);
      digitalWrite(COL_1_G, LOW); 
      CTR_R++;
      break;

    case 4: // Cuarta fila (OOOII)
      digitalWrite(ROW_4, HIGH);
      digitalWrite(COL_2_G, LOW);
      digitalWrite(COL_3_G, LOW);
      digitalWrite(COL_4_G, LOW);
      CTR_R++;
      break;

    case 5: // Quinta fila (OIIOI)
      digitalWrite(ROW_5, HIGH);
      digitalWrite(COL_5_G, LOW); 
      CTR_R++;
      break;

    case 6: // Sexta fila (OIIIO)
      digitalWrite(ROW_6, HIGH);
      digitalWrite(COL_5_G, LOW); 
      CTR_R++;
      break;

    case 7: // Séptima fila (OIIIO)
      digitalWrite(ROW_7, HIGH);
      digitalWrite(COL_5_G, LOW); 
      CTR_R++;
      break;

    case 8: // Octava fila (OOOOI)
      digitalWrite(ROW_8, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_2_G, LOW);
      digitalWrite(COL_3_G, LOW);
      digitalWrite(COL_4_G, LOW);
      CTR_R = 1; // Reinicia el contador de filas
      break;
  }

  delay(2); // Breve retraso para evitar parpadeos
}
void Display_T(){
    Turn_them_all_off();

  
  switch (CTR_R) {
    case 1: // Primera fila (OOOOI)
      digitalWrite(ROW_1, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_2_G, LOW);
      digitalWrite(COL_3_G, LOW);
      digitalWrite(COL_4_G, LOW);
      digitalWrite(COL_5_G, LOW);

      // COL_5_G permanece apagado
      CTR_R++;
      break;

    case 2: // Segunda fila (OIIIO)
      digitalWrite(ROW_2, HIGH);
      digitalWrite(COL_3_G, LOW); // O
  
      
      CTR_R++;
      break;

    case 3: // Tercera fila (OIIOI)
      digitalWrite(ROW_3, HIGH);
      digitalWrite(COL_3_G, LOW); // O
      
    
      CTR_R++;
      break;

    case 4: // Cuarta fila (OOOII)
      digitalWrite(ROW_4, HIGH);
      
      digitalWrite(COL_3_G, LOW);
     
      
      // COL_4_G y COL_5_G permanecen apagados (I)
      CTR_R++;
      break;

    case 5: // Quinta fila (OIIOI)
      digitalWrite(ROW_5, HIGH);
      digitalWrite(COL_3_G, LOW);
      CTR_R++;
      break;

    case 6: // Sexta fila (OIIIO)
      digitalWrite(ROW_6, HIGH);
      digitalWrite(COL_3_G, LOW); // O
      CTR_R++;
      break;

    case 7: // Séptima fila (OIIIO)
      digitalWrite(ROW_7, HIGH);
      digitalWrite(COL_3_G, LOW); // O
      CTR_R++;
      break;

    case 8: // Octava fila (OOOOI)
      digitalWrite(ROW_8, HIGH);
      digitalWrite(COL_3_G, LOW);
      CTR_R = 1; // Reinicia el contador de filas
      break;
  }

  delay(2); // Breve retraso para evitar parpadeos
}

void Display_U(){
    Turn_them_all_off();

  
  switch (CTR_R) {
    case 1: // Primera fila (OOOOI)
      digitalWrite(ROW_1, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 2: // Segunda fila (OIIIO)
      digitalWrite(ROW_2, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW);
      
      CTR_R++;
      break;

    case 3: // Tercera fila (OIIOI)
      digitalWrite(ROW_3, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW);
    
      CTR_R++;
      break;

    case 4: // Cuarta fila (OOOII)
      digitalWrite(ROW_4, HIGH);
      digitalWrite(COL_1_G, LOW); 
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 5: // Quinta fila (OIIOI)
      digitalWrite(ROW_5, HIGH);
      digitalWrite(COL_1_G, LOW); // O}
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 6: // Sexta fila (OIIIO)
      digitalWrite(ROW_6, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 7: // Séptima fila (OIIIO)
      digitalWrite(ROW_7, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 8: // Octava fila (OOOOI)
      digitalWrite(ROW_8, HIGH);
      digitalWrite(COL_2_G, LOW);
      digitalWrite(COL_3_G, LOW);
      digitalWrite(COL_4_G, LOW);
      CTR_R = 1; // Reinicia el contador de filas
      break;
  }

  delay(2); // Breve retraso para evitar parpadeos
}

void Display_V(){
    Turn_them_all_off();

  
  switch (CTR_R) {
    case 1: // Primera fila (OOOOI)
      digitalWrite(ROW_1, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 2: // Segunda fila (OIIIO)
      digitalWrite(ROW_2, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW);
      
      CTR_R++;
      break;

    case 3: // Tercera fila (OIIOI)
      digitalWrite(ROW_3, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW);
    
      CTR_R++;
      break;

    case 4: // Cuarta fila (OOOII)
      digitalWrite(ROW_4, HIGH);
      digitalWrite(COL_1_G, LOW); 
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 5: // Quinta fila (OIIOI)
      digitalWrite(ROW_5, HIGH);
      digitalWrite(COL_1_G, LOW); // O}
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 6: // Sexta fila (OIIIO)
      digitalWrite(ROW_6, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 7: // Séptima fila (OIIIO)
      digitalWrite(ROW_7, HIGH);
      digitalWrite(COL_2_G, LOW); // O
      digitalWrite(COL_4_G, LOW);
      CTR_R++;
      break;

    case 8: // Octava fila (OOOOI)
      digitalWrite(ROW_8, HIGH);
      digitalWrite(COL_3_G, LOW);
      CTR_R = 1; // Reinicia el contador de filas
      break;
  }

  delay(2); // Breve retraso para evitar parpadeos
}

void Display_W(){
    Turn_them_all_off();

  
  switch (CTR_R) {
    case 1: // Primera fila (OOOOI)
      digitalWrite(ROW_1, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_5_G, LOW);

      // COL_5_G permanece apagado
      CTR_R++;
      break;

    case 2: // Segunda fila (OIIIO)
      digitalWrite(ROW_2, HIGH);
      digitalWrite(COL_1_G, LOW); 
      digitalWrite(COL_5_G, LOW);
      
      CTR_R++;
      break;

    case 3: // Tercera fila (OIIOI)
      digitalWrite(ROW_3, HIGH);
      digitalWrite(COL_1_G, LOW); 
      digitalWrite(COL_5_G, LOW);
    
      CTR_R++;
      break;

    case 4: // Cuarta fila (OOOII)
      digitalWrite(ROW_4, HIGH);
      digitalWrite(COL_1_G, LOW); 
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 5: // Quinta fila (OIIOI)
      digitalWrite(ROW_5, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 6: // Sexta fila (OIIIO)
      digitalWrite(ROW_6, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_3_G, LOW); // O
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 7: // Séptima fila (OIIIO)
      digitalWrite(ROW_7, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_2_G, LOW);
      digitalWrite(COL_4_G, LOW); // O
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 8: // Octava fila (OOOOI)
      digitalWrite(ROW_8, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_5_G, LOW);
      CTR_R = 1; // Reinicia el contador de filas
      break;
  }

  delay(2); // Breve retraso para evitar parpadeos
}

void Display_X(){
    Turn_them_all_off();

  
  switch (CTR_R) {
    case 1: // Primera fila (OOOOI)
      digitalWrite(ROW_1, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_5_G, LOW);

      // COL_5_G permanece apagado
      CTR_R++;
      break;

    case 2: // Segunda fila (OIIIO)
      digitalWrite(ROW_2, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW);
      
      CTR_R++;
      break;

    case 3: // Tercera fila (OIIOI)
      digitalWrite(ROW_3, HIGH);
      digitalWrite(COL_2_G, LOW); // O
      digitalWrite(COL_4_G, LOW);
    
      CTR_R++;
      break;

    case 4: // Cuarta fila (OOOII)
      digitalWrite(ROW_4, HIGH);
      digitalWrite(COL_3_G, LOW);
      CTR_R++;
      break;

    case 5: // Quinta fila (OIIOI)
      digitalWrite(ROW_5, HIGH);
      digitalWrite(COL_2_G, LOW); // O}
      digitalWrite(COL_4_G, LOW);
      CTR_R++;
      break;

    case 6: // Sexta fila (OIIIO)
      digitalWrite(ROW_6, HIGH);
      digitalWrite(COL_2_G, LOW); // O
      digitalWrite(COL_4_G, LOW);
      CTR_R++;
      break;

    case 7: // Séptima fila (OIIIO)
      digitalWrite(ROW_7, HIGH);
      digitalWrite(COL_1_G, LOW); // O
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 8: // Octava fila (OOOOI)
      digitalWrite(ROW_8, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_5_G, LOW);
      CTR_R = 1; // Reinicia el contador de filas
      break;
  }

  delay(2); // Breve retraso para evitar parpadeos
}

void Display_Y(){
    Turn_them_all_off();

  
  switch (CTR_R) {
    case 1: // Primera fila (OOOOI)
      digitalWrite(ROW_1, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 2: // Segunda fila (OIIIO)
      digitalWrite(ROW_2, HIGH);
      digitalWrite(COL_1_G, LOW); 
      digitalWrite(COL_5_G, LOW); 
      CTR_R++;
      break;

    case 3: // Tercera fila (OIIOI)
      digitalWrite(ROW_3, HIGH);
      digitalWrite(COL_2_G, LOW);
      digitalWrite(COL_4_G, LOW);  
      CTR_R++;
      break;

    case 4: // Cuarta fila (OOOII)
      digitalWrite(ROW_4, HIGH);
      digitalWrite(COL_3_G, LOW);
      CTR_R++;
      break;

    case 5: // Quinta fila (OIIOI)
      digitalWrite(ROW_5, HIGH);
      digitalWrite(COL_3_G, LOW);
      CTR_R++;
      break;

    case 6: // Sexta fila (OIIIO)
      digitalWrite(ROW_6, HIGH);
      digitalWrite(COL_3_G, LOW); // O
      CTR_R++;
      break;

    case 7: // Séptima fila (OIIIO)
      digitalWrite(ROW_7, HIGH);
      digitalWrite(COL_3_G, LOW); // O
      CTR_R++;
      break;

    case 8: // Octava fila (OOOOI)
      digitalWrite(ROW_8, HIGH);
      digitalWrite(COL_3_G, LOW);
      CTR_R = 1; // Reinicia el contador de filas
      break;
  }

  delay(2); // Breve retraso para evitar parpadeos
}

void Display_Z(){
    Turn_them_all_off();

  
  switch (CTR_R) {
    case 1: // Primera fila (OOOOI)
      digitalWrite(ROW_1, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_2_G, LOW);
      digitalWrite(COL_3_G, LOW);
      digitalWrite(COL_4_G, LOW);
      digitalWrite(COL_5_G, LOW);
      CTR_R++;
      break;

    case 2: // Segunda fila (OIIIO)
      digitalWrite(ROW_2, HIGH);
      digitalWrite(COL_5_G, LOW); 
      CTR_R++;
      break;

    case 3: // Tercera fila (OIIOI)
      digitalWrite(ROW_3, HIGH);
      digitalWrite(COL_4_G, LOW); 
      CTR_R++;
      break;

    case 4: // Cuarta fila (OOOII)
      digitalWrite(ROW_4, HIGH);
      digitalWrite(COL_3_G, LOW);
      CTR_R++;
      break;

    case 5: // Quinta fila (OIIOI)
      digitalWrite(ROW_5, HIGH);
      digitalWrite(COL_2_G, LOW); 
      CTR_R++;
      break;

    case 6: // Sexta fila (OIIIO)
      digitalWrite(ROW_6, HIGH);
      digitalWrite(COL_1_G, LOW); 
      CTR_R++;
      break;

    case 7: // Séptima fila (OIIIO)
      digitalWrite(ROW_7, HIGH);
      digitalWrite(COL_1_G, LOW); 
      CTR_R++;
      break;

    case 8: // Octava fila (OOOOI)
      digitalWrite(ROW_8, HIGH);
      digitalWrite(COL_1_G, LOW);
      digitalWrite(COL_2_G, LOW);
      digitalWrite(COL_3_G, LOW);
      digitalWrite(COL_4_G, LOW);
      digitalWrite(COL_5_G, LOW);
      CTR_R = 1; // Reinicia el contador de filas
      break;
  }

  delay(2); // Breve retraso para evitar parpadeos
}
