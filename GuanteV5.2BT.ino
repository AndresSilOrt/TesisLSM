#include <MPU9250_WE.h>
#include <SoftwareSerial.h>

  SoftwareSerial miBluetooth(0, 1); // RX, TX
  String receivedChar;
  bool imprimirNumeros = false; // Variable para controlar si se deben imprimir los números
  MPU9250_WE myMPU9250A = MPU9250_WE(&SPI, 10, true);
  MPU9250_WE myMPU9250B = MPU9250_WE(&SPI, 9, true);
  MPU9250_WE myMPU9250C = MPU9250_WE(&SPI, 8, true); 
  MPU9250_WE myMPU9250D = MPU9250_WE(&SPI, 7, true);
  MPU9250_WE myMPU9250E = MPU9250_WE(&SPI, 6, true); 



//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void setup() 
{
  // put your setup code here, to run once:
  miBluetooth.begin(115200);
  //########################################################################
  //Inicializa Sensor A 
  if(!myMPU9250A.init())
  {  
    miBluetooth.println("MPU9250 A does not respond");
  }
  else
  {
    miBluetooth.println("MPU9250 A is connected");
    //miBluetooth.write("A Done!");
  }
    myMPU9250A.autoOffsets(); 

  delay(200);
  //Inicializa Sensor B 
  if(!myMPU9250B.init())
  {  
    miBluetooth.println("MPU9250 B does not respond");
  }
  else
  {
    miBluetooth.println("MPU9250 B is connected");
    //miBluetooth.write("A Done!");
  }
    myMPU9250B.autoOffsets(); 

  delay(200);
  //Inicializa Sensor C 
  if(!myMPU9250C.init())
  {  
    miBluetooth.println("MPU9250 C does not respond");
  }
  else
  {
    miBluetooth.println("MPU9250 C is connected");
    //miBluetooth.write("A Done!");
  }
    myMPU9250C.autoOffsets(); 

  delay(200);
  //Inicializa Sensor D 
  if(!myMPU9250D.init())
  {  
    miBluetooth.println("MPU9250 D does not respond");
  }
  else
  {
    miBluetooth.println("MPU9250 D is connected");
    //miBluetooth.write("A Done!");
  }
    myMPU9250D.autoOffsets(); 

  delay(200);
  //Inicializa Sensor E 
  if(!myMPU9250E.init())
  {  
    miBluetooth.println("MPU9250 E does not respond");
  }
  else
  {
    miBluetooth.println("MPU9250 E is connected");
    //miBluetooth.write("A Done!");
  }
    myMPU9250E.autoOffsets(); 


}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void loop() 
{
  // put your main code here, to run repeatedly:
  while (miBluetooth.available() > 0) 
  {
  receivedChar = miBluetooth.readString(); // Leer el caracter recibido
    
    if (receivedChar == "a")
    {
    // Si el caracter recibido es 'a', cambiar el estado para imprimir los números
    imprimirNumeros = true;
    }
    else if (receivedChar == "z") 
    {
    // Si el caracter recibido es 'z', detener la impresión de números
    imprimirNumeros = false;
   }  
  }

    if (imprimirNumeros) 
    {
      delay(200);
      //Sensor A
      xyzFloat gValueA = myMPU9250A.getGValues();
      miBluetooth.print(gValueA.x);
      miBluetooth.print(" ");
      miBluetooth.print(gValueA.y);
      miBluetooth.print(" ");
      miBluetooth.println(gValueA.z);

      //Sensor B
      xyzFloat gValueB = myMPU9250B.getGValues();
      miBluetooth.print(gValueB.x);
      miBluetooth.print(" ");
      miBluetooth.print(gValueB.y);
      miBluetooth.print(" ");
      miBluetooth.println(gValueB.z);

      //Sensor C
      xyzFloat gValueC = myMPU9250C.getGValues();
      miBluetooth.print(gValueC.x);
      miBluetooth.print(" ");
      miBluetooth.print(gValueC.y);
      miBluetooth.print(" ");
      miBluetooth.println(gValueC.z);

      //Sensor D
      xyzFloat gValueD = myMPU9250D.getGValues();
      miBluetooth.print(gValueD.x);
      miBluetooth.print(" ");
      miBluetooth.print(gValueD.y);
      miBluetooth.print(" ");
      miBluetooth.println(gValueD.z);

      //Sensor E
      xyzFloat gValueE = myMPU9250E.getGValues();
      miBluetooth.print(gValueE.x);
      miBluetooth.print(" ");
      miBluetooth.print(gValueE.y);
      miBluetooth.print(" ");
      miBluetooth.println(gValueE.z);

    }
}

