int Moteur_sens1=4; // Pin 4 Arduino vers broche A+ du L293D
int Moteur_sens2=5; // Pin 5 Arduino vers broche A- du L293D
int Potentiometre = A3; // Pin A0 Arduino vers broche variable du potentiomètre
int ValeurPot=0; // Variable potentiomètre
int PWM; // Variable PWM image de la vitesse
int moteur1_PWM = 10; // Pin 10 Arduino PWM vers EN1 du L293D
// Code de configuration exécuté une seule fois

void setup() {
Serial.begin(9600); // Ouverture du port série et debit de communication fixé à 9600 bauds
pinMode(moteur1_PWM, OUTPUT); // Pin 10 Arduino en sortie PWM
pinMode(Moteur_sens1, OUTPUT); // Pin 4 Arduino en sortie digitale
pinMode(Moteur_sens2, OUTPUT); // Pin 5 Arduino en sortie digitale
}
// Boucle du programme
void loop() {
ValeurPot=analogRead(Potentiometre); // Lecture de la valeur analogique en sortie du potentiomètre
PWM=map(ValeurPot,0,1020,0,255); // Associer la valeur du potentiomètre au signal PWM
analogWrite(moteur1_PWM,PWM); // Envoi du signal PWM sur la sortie analogique 10
// Condition Si la vitesse est supérieure à zéro alors on fait tourner le moteur
if(PWM>0){
digitalWrite(Moteur_sens1,HIGH); // Activation de la broche A+ du L293D
digitalWrite(Moteur_sens2,LOW); // Désactivation de la broche A- du L293D
}
else{// Sinon on arrête le moteur
digitalWrite(Moteur_sens1,LOW); // Désactivation de la broche A+ du L293D
digitalWrite(Moteur_sens2,LOW); // Désactivation de la broche A- du L293D
}
Serial.print("Valeur PWM : "); // Affichage sur le moninteur série du texte
Serial.println(PWM); // Affichage sur le moninteur série de la valeur PWM

}
