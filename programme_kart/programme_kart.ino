
#include <math.h>

unsigned int cpt; 
float Omega;
float V;
float Dpneu=0.254;                   //diamètre du pneu arrière en cm
float Rpneu=Dpneu/2;                 //rayon du pneu arrière en cm
long temps;

void Prog_comptage()
  {
   cpt++;      //cpt=nombre d'impultion sur 1sec
  }


void setup() 
{
 Serial.begin(115200);                                             //vitesse de la liaison série (USM) 115200 bauds
 pinMode(2,INPUT_PULLUP);
 attachInterrupt(digitalPinToInterrupt(2), Prog_comptage, RISING);
 temps = millis();
}

void loop() {
 
  if ((millis()-temps)>1000)                             //toutes les secondes
    {
     temps = millis();
     //combien d'impulsion 
     cpt=cpt/2;                                 //nombre de tour par sec (2 impultions par tour)
     Serial.print(cpt);                        //Afficher la vitesse en tr/s
     Serial.print("\t");                             
     Omega=2*PI*cpt;
     V=Omega*Rpneu*3.6;                        //vitesse linéaire en km/h
     Serial.println(V);                        //Afficher la vitesse en km/h
     cpt = 0;
    }
}


