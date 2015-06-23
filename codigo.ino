//# Scroll-8x16-con-Arduino-y-matrices-de-8x8
//Scroll 8x16 con Arduino y matrices de 8x8
/*
PUBLIK SCROLL CON DOS MATRICES DE 8X8, PARA HACER UNA DE 8X16,
SIN REGISTROS DE DESPLAZAMIENTO.
ENVÍA MENSAJE A MOSTRAR EN PANTALLA VÍA PUERTO SERIAL, 
ES POSIBLE ENVÍAR VÍA BLUETOOTH U OTRO PERIFERICO DE COMUNICACIÓN SERIAL
MEDIANTE CONEXIÓN POR PUERTOS TX0 RX0 (SERIAL 1)

*** POR: RICARDO J PUPO DIAZ
*** COAUTORÍA: CARLOS GUZMAN NIETO
*** ACESORÍA Y SUPERVISIÓN: ING, MSc CARLOS ARTURO ROBLES ALGARIN
*** UNIVERSIDAD DEL MAGDALENA

****LIBRERÍA FREQUENCYTIMER2: http://playground.arduino.cc/Code/FrequencyTimer2 
*/

// Cargar librería FrequencyTimer2
#include <FrequencyTimer2.h>

// Definimos Caracteres

#define A { \
{0,0,1,1,0,0,0,0}, \
{0,1,1,1,1,0,0,0}, \
{1,1,0,0,1,1,0,0}, \
{1,1,0,0,1,1,0,0}, \
{1,1,1,1,1,1,0,0}, \
{1,1,0,0,1,1,0,0}, \
{1,1,0,0,1,1,0,0}, \
{0,0,0,0,0,0,0,0} \
}
#define B { \
{1,1,1,1,1,1,0,0},\
{0,1,1,0,0,1,1,0},\
{0,1,1,0,0,1,1,0},\
{0,1,1,1,1,1,0,0},\
{0,1,1,0,0,1,1,0},\
{0,1,1,0,0,1,1,0},\
{1,1,1,1,1,1,0,0},\
{0,0,0,0,0,0,0,0}\
}

#define C { \
{0,0,1,1,1,1,0,0},\
{0,1,1,0,0,1,1,0},\
{1,1,0,0,0,0,0,0},\
{1,1,0,0,0,0,0,0},\
{1,1,0,0,0,0,0,0},\
{0,1,1,0,0,1,1,0},\
{0,0,1,1,1,1,0,0},\
{0,0,0,0,0,0,0,0}\
}

#define D { \
{1,1,1,1,1,0,0,0},\
{0,1,1,0,1,1,0,0},\
{0,1,1,0,0,1,1,0},\
{0,1,1,0,0,1,1,0},\
{0,1,1,0,0,1,1,0},\
{0,1,1,0,1,1,0,0},\
{1,1,1,1,1,0,0,0},\
{0,0,0,0,0,0,0,0}\
}


#define E { \
{1,1,1,1,1,1,1,0},\
{0,1,1,0,0,0,1,0},\
{0,1,1,0,1,0,0,0},\
{0,1,1,1,1,0,0,0},\
{0,1,1,0,1,0,0,0},\
{0,1,1,0,0,0,1,0},\
{1,1,1,1,1,1,1,0},\
{0,0,0,0,0,0,0,0}\
}


#define F { \
{1,1,1,1,1,1,1,0},\
{0,1,1,0,0,0,1,0},\
{0,1,1,0,1,0,0,0},\
{0,1,1,1,1,0,0,0},\
{0,1,1,0,1,0,0,0},\
{0,1,1,0,0,0,0,0},\
{1,1,1,1,0,0,0,0},\
{0,0,0,0,0,0,0,0}\
}


#define G { \
{0,0,1,1,1,1,0,0},\
{0,1,1,0,0,1,1,0},\
{1,1,0,0,0,0,0,0},\
{1,1,0,0,0,0,0,0},\
{1,1,0,0,1,1,1,0},\
{0,1,1,0,0,1,1,0},\
{0,0,1,1,1,1,1,0},\
{0,0,0,0,0,0,0,0}\
}

#define H { \
{1,1,0,0,1,1,0,0},\
{1,1,0,0,1,1,0,0},\
{1,1,0,0,1,1,0,0},\
{1,1,1,1,1,1,0,0},\
{1,1,0,0,1,1,0,0},\
{1,1,0,0,1,1,0,0},\
{1,1,0,0,1,1,0,0},\
{0,0,0,0,0,0,0,0}\
}


#define I { \
{0,1,1,1,1,0,0,0},\
{0,0,1,1,0,0,0,0},\
{0,0,1,1,0,0,0,0},\
{0,0,1,1,0,0,0,0},\
{0,0,1,1,0,0,0,0},\
{0,0,1,1,0,0,0,0},\
{0,1,1,1,1,0,0,0},\
{0,0,0,0,0,0,0,0}\
}


#define J { \
{0,0,0,1,1,1,1,0},\
{0,0,0,0,1,1,0,0},\
{0,0,0,0,1,1,0,0},\
{0,0,0,0,1,1,0,0},\
{1,1,0,0,1,1,0,0},\
{1,1,0,0,1,1,0,0},\
{0,1,1,1,1,0,0,0},\
{0,0,0,0,0,0,0,0}\
}


#define K { \
{1,1,1,0,0,1,1,0},\
{0,1,1,0,0,1,1,0},\
{0,1,1,0,1,1,0,0},\
{0,1,1,1,1,0,0,0},\
{0,1,1,0,1,1,0,0},\
{0,1,1,0,0,1,1,0},\
{1,1,1,0,0,1,1,0},\
{0,0,0,0,0,0,0,0}\
}



#define L { \
{1,1,1,1,0,0,0,0},\
{0,1,1,0,0,0,0,0},\
{0,1,1,0,0,0,0,0},\
{0,1,1,0,0,0,0,0},\
{0,1,1,0,0,0,1,0},\
{0,1,1,0,0,1,1,0},\
{1,1,1,1,1,1,1,0},\
{0,0,0,0,0,0,0,0}\
}

#define M { \
{1,1,0,0,0,1,1,0},\
{1,1,1,0,1,1,1,0},\
{1,1,1,1,1,1,1,0},\
{1,1,1,1,1,1,1,0},\
{1,1,0,1,0,1,1,0},\
{1,1,0,0,0,1,1,0},\
{1,1,0,0,0,1,1,0},\
{0,0,0,0,0,0,0,0}\
}


#define N { \
{1,1,0,0,0,1,1,0},\
{1,1,1,0,0,1,1,0},\
{1,1,1,1,0,1,1,0},\
{1,1,0,1,1,1,1,0},\
{1,1,0,0,1,1,1,0},\
{1,1,0,0,0,1,1,0},\
{1,1,0,0,0,1,1,0},\
{0,0,0,0,0,0,0,0}\
}

#define NI { \
{0,1,1,1,1,1,0,0},\
{0,0,0,0,0,0,0,0},\
{1,1,0,0,0,1,1,0},\
{1,1,1,0,0,1,1,0},\
{1,1,1,1,0,1,1,0},\
{1,1,0,1,1,1,1,0},\
{1,1,0,0,1,1,1,0},\
{1,1,0,0,0,1,1,0}\
}

#define O { \
{0,0,1,1,1,0,0,0},\
{0,1,1,0,1,1,0,0},\
{1,1,0,0,0,1,1,0},\
{1,1,0,0,0,1,1,0},\
{1,1,0,0,0,1,1,0},\
{0,1,1,0,1,1,0,0},\
{0,0,1,1,1,0,0,0},\
{0,0,0,0,0,0,0,0}\
}


#define P { \
{1,1,1,1,1,1,0,0},\
{0,1,1,0,0,1,1,0},\
{0,1,1,0,0,1,1,0},\
{0,1,1,1,1,1,0,0},\
{0,1,1,0,0,0,0,0},\
{0,1,1,0,0,0,0,0},\
{1,1,1,1,0,0,0,0},\
{0,0,0,0,0,0,0,0}\
}



#define Q { \
{0,1,1,1,1,0,0,0},\
{1,1,0,0,1,1,0,0},\
{1,1,0,0,1,1,0,0},\
{1,1,0,0,1,1,0,0},\
{1,1,0,1,1,1,0,0},\
{0,1,1,1,1,0,0,0},\
{0,0,0,1,1,1,0,0},\
{0,0,0,0,0,0,0,0}\
}



#define R { \
{1,1,1,1,1,1,0,0},\
{0,1,1,0,0,1,1,0},\
{0,1,1,0,0,1,1,0},\
{0,1,1,1,1,1,0,0},\
{0,1,1,0,1,1,0,0},\
{0,1,1,0,0,1,1,0},\
{1,1,1,0,0,1,1,0},\
{0,0,0,0,0,0,0,0}\
}


#define S { \
{0,1,1,1,1,0,0,0},\
{1,1,0,0,1,1,0,0},\
{1,1,1,0,0,0,0,0},\
{0,1,1,1,0,0,0,0},\
{0,0,0,1,1,1,0,0},\
{1,1,0,0,1,1,0,0},\
{0,1,1,1,1,0,0,0},\
{0,0,0,0,0,0,0,0}\
}


#define T { \
{1,1,1,1,1,1,0,0},\
{1,0,1,1,0,1,0,0},\
{0,0,1,1,0,0,0,0},\
{0,0,1,1,0,0,0,0},\
{0,0,1,1,0,0,0,0},\
{0,0,1,1,0,0,0,0},\
{0,1,1,1,1,0,0,0},\
{0,0,0,0,0,0,0,0}\
}


#define U { \
{1,1,0,0,1,1,0,0},\
{1,1,0,0,1,1,0,0},\
{1,1,0,0,1,1,0,0},\
{1,1,0,0,1,1,0,0},\
{1,1,0,0,1,1,0,0},\
{1,1,0,0,1,1,0,0},\
{0,1,1,1,1,1,0,0},\
{0,0,0,0,0,0,0,0}\
}



#define V { \
{1,1,0,0,1,1,0,0},\
{1,1,0,0,1,1,0,0},\
{1,1,0,0,1,1,0,0},\
{1,1,0,0,1,1,0,0},\
{1,1,0,0,1,1,0,0},\
{0,1,1,1,1,0,0,0},\
{0,0,1,1,0,0,0,0},\
{0,0,0,0,0,0,0,0}\
}



#define W { \
{1,1,0,0,0,1,1,0},\
{1,1,0,0,0,1,1,0},\
{1,1,0,0,0,1,1,0},\
{1,1,0,1,0,1,1,0},\
{1,1,1,1,1,1,1,0},\
{1,1,1,0,1,1,1,0},\
{1,1,0,0,0,1,1,0},\
{0,0,0,0,0,0,0,0}\
}

#define X { \
{1,1,0,0,0,1,1,0},\
{1,1,0,0,0,1,1,0},\
{0,1,1,0,1,1,0,0},\
{0,0,1,1,1,0,0,0},\
{0,0,1,1,1,0,0,0},\
{0,1,1,0,1,1,0,0},\
{1,1,0,0,0,1,1,0},\
{0,0,0,0,0,0,0,0}\
}


#define Y { \
{1,1,0,0,1,1,0,0},\
{1,1,0,0,1,1,0,0},\
{1,1,0,0,1,1,0,0},\
{0,1,1,1,1,0,0,0},\
{0,0,1,1,0,0,0,0},\
{0,0,1,1,0,0,0,0},\
{0,1,1,1,1,0,0,0},\
{0,0,0,0,0,0,0,0}\
}


#define Z { \
{1,1,1,1,1,1,1,0},\
{1,1,0,0,0,1,1,0},\
{1,0,0,0,1,1,0,0},\
{0,0,0,1,1,0,0,0},\
{0,0,1,1,0,0,1,0},\
{0,1,1,0,0,1,1,0},\
{1,1,1,1,1,1,1,0},\
{0,0,0,0,0,0,0,0}\
}

#define ES { \
{0,0,0,0,0,0,0,0},\
{0,0,0,0,0,0,0,0},\
{0,0,0,0,0,0,0,0},\
{0,0,0,0,0,0,0,0},\
{0,0,0,0,0,0,0,0},\
{0,0,0,0,0,0,0,0},\
{0,0,0,0,0,0,0,0},\
{0,0,0,0,0,0,0,0}\
}

#define COR { \
{0,1,1,0,1,1,0,0},\
{1,1,1,1,1,1,1,0},\
{1,1,1,1,1,1,1,0},\
{1,1,1,1,1,1,1,0},\
{0,1,1,1,1,1,0,0},\
{0,0,1,1,1,0,0,0},\
{0,0,0,1,0,0,0,0},\
{0,0,0,0,0,0,0,0}\
}

byte col = 0;
byte leds[8][16];

//conexiones
int pines[25]= {-1, 5, 4, 3, 2, 14, 15, 16, 17, 13, 12, 11, 10, 9, 8, 7, 6,22,23,24,25,26,27,28,29};

//pines filas
int filas[16] = {pines[16], pines[15], pines[11], pines[06], pines[10], pines[4], pines[3], pines[13],pines[24],pines[23],pines[22],pines[21],pines[20],pines[19],pines[18],pines[17]};

//pines columnas
int cols[8] = {pines[9], pines[14], pines[8], pines[12], pines[1], pines[7], pines[2], pines[5]};

byte letras[29][8][8]={A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,NI,ES,COR};

//Cargamos numletras con un máximo de 70, luego de este valor parece volverse lenta la comunicación
// este valor será reajustado más adelante.
const int numletras=70;
byte mensaje[numletras][8][8] = {}; //inicializamos el arreglo mensaje, donde posteriormente cargaremos lo envíado desde el puerto serial

int letra = 0;

void setup() {
  
  // Configuración de pines
  for (int i = 1; i <= 24; i++) {
    pinMode(pines[i], OUTPUT);
  }

  // apagamaos matriz
  for (int i = 1; i <= 8; i++) {
    digitalWrite(cols[i - 1], LOW);
  }

  for (int i = 1; i <= 16; i++) {
    digitalWrite(filas[i - 1], LOW);

  }
    Serial.begin(9600);
  limpiarLeds();

/* Librería que genera una interrupción en el codigo periodicamente, 
y llama a la función display, para que vaya escribiendo en las matrices 8x8 el mensaje enviado*/

// Desactivar conmutación de pin 11  
  FrequencyTimer2::disable();
  // Tiempo para proxima interrupción
  FrequencyTimer2::setPeriod(5000);
  // llamar rutina de interrupción
  FrequencyTimer2::setOnOverflow(display);

/* llamamos la función obtpalabra, con letra=0, para inicializar la variable leds con un valor previo
antes de comenzar a llenar con la palabra recibida */
  obtpalabra(letra);

}
int tam=0
;
char dato_rec[numletras+1];
void loop() {
  if (Serial.available()>0){
    
    Serial.readBytes(dato_rec,numletras); //vamos cargando el ascii de cada letra enviada por puerto serial a la variable dato_rec, con un tamaño igual a numletras
    Serial.println(dato_rec); 
    
    for(int z=0;z<numletras;z++)
    {
      if(dato_rec[z]==35) //preguntamos por el ascii de "#" (que es 35), para modificar el tamaño de la palabra, en nuestra app android, se concatena un "#" al final del mensaje antes de enviarse via bluetooth al pto serial del arduino
      {
       tam=z; //si se lee "#" (35) entonces "tam" será igual a la posición donde se encontró, así la matriz palabra quedará reducida al tamaño real. En adelante "numletras" dejará de usarse como tamaño del mensaje para que tome su lugar "tam".
        break; //interrumpimos si se cumple para no analizar las 70 posiciones dadas por defecto
      }
    }
    
    for(int z=0;z<tam;z++)
    {
      if(dato_rec[z]==110) //el sistema no detectó bien el ascii de "Ñ" así que usamos n (minuscula) en su lugar,
      {dato_rec[z]=dato_rec[z]-19;} // si se lee n (minuscula), restamos 110-19=91, donde 91 es la posición de la matriz "letras", donde se llama a la variable definida "NI", que muestra "Ñ" en pantalla 
      if(dato_rec[z]==32) //"Espacio", misma lógica de "Ñ"
      {dato_rec[z]=dato_rec[z]+60;}
      if(dato_rec[z]==99) // Corazón declarado en "c" (minuscula), (esto fue para enamorar mas a mi novia (R.puppo))
      {dato_rec[z]=dato_rec[z]-6;}
      dato_rec[z]=dato_rec[z]-65; //leido el ascii de cada letra enviada al puerto serial, restamos 65, de manera que coincida con la posición de la matriz "LETRAS", ej: A= 65 (ascii) -> A-65=0, el valor en la posición 0 de la matriz "LETRAS" es A.
    }

    
    //a continuación cargamos el mensaje recibido y condificado a la matriz "mensaje"
        for(int z=0;z<tam;z++)
    {
  for (int i = 0; i < 8; i++) 
  {
    for (int j = 0; j < 8; j++) 
    {
    mensaje[z][i][j]=letras[dato_rec[z]][i][j]; //letra en la posición "dato_rec[z]"
    }
  }
     }
  }
     letra = ++letra % tam; //letra es un valor de uno en uno hasta tamaño
    corrimiento(letra, 60); //60 es la velocidad del desplazamiento (delay "del")

}

void limpiarLeds() {
  // Limpiamos las matrices
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 15; j++) {
      leds[i][j] = 0;
    }
  }
}

void obtpalabra(int letra) { //ESTO ES PARA INICIALIZAR LEDS UNICAMENTE, SE LLAMA EN VOID SETUP Y SE CARGA CON LETRA=0
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 15; j++) {
      leds[i][j] = mensaje[letra][i][j];
    }
  }
}

/* Al inicializar leds, en obtpalabra, ya viene cargado con un valor previo en este punto,
dicho valor en la posición 0 no es visible, por lo que no importa */
void corrimiento(int letra, int del) {
  for (int l = 0; l < 8; l++) {
    for (int i = 0; i < 15; i++) { 
      for (int j = 0; j < 8; j++) {
        leds[j][i] = leds[j][i+1]; //lo que está en 15 lo pone en 14, 14 en 13, 13 en 12... lo que estaba en 0 queda en -1 (sale).
      }
    }
    /* se recorre la matriz de cada letra en "Mensaje" columna a columna, y se van hubicando cada una en 15
   como se explica en el comentario anterior, luego lo que esté en 15 estará en 14... */
    for (int j = 0; j < 8; j++) {
      leds[j][15] = mensaje[letra][j][l];
    }
    delay(del);
  }
}

// rutina de interrupción, es llamada cada periodicamente por la librería FrequencyTimer2, permite ir escribiendo las matrices casi en tiempo real conforme van codificandose los datos
void display() {
  delay(50);
  digitalWrite(cols[col], LOW);  // APAGAMOS COLUMNA
  col++;
  if (col == 8) {
    col = 0;
  }
  for (int fila = 0; fila < 16; fila++) {
    if (leds[col][15 - fila] == 1) {
      digitalWrite(filas[fila], LOW);  // PRENDEMOS LED EN ESTA POSICIÓN (DONDE EXISTA 1 EN "leds")
    }
    else {
      digitalWrite(filas[fila], HIGH); // APAGAMOS LED EN ESTA POSICIÓN (DONDE NO EXISTAN 1 EN "leds")
    }
  }
  digitalWrite(cols[col], HIGH); // PRENDEMOS LA COLUMNA
}
