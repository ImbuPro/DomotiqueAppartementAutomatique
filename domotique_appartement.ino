int boutonPresence;
int capJour;
int tempAppart;
int DO;
int presence;
int lum;
int i;
void setup()
{
    pinMode(A0, INPUT); // Capteur température dans l'appartement
    pinMode(A1, INPUT); // Capteur lumière
    pinMode(1, INPUT);  // Intérupteur Lumière
    pinMode(2, INPUT);  // DO
    pinMode(3, INPUT);  // Bouton de présence
    pinMode(4, INPUT);  // infra-rouge
    pinMode(5, OUTPUT); // Chauffage
    pinMode(6, OUTPUT); // Ouvrir volet
    pinMode(7, OUTPUT); // Fermer volet
    pinMode(8, OUTPUT); // Lumière
    pinMode(9, OUTPUT); // Alarme
}
void loop()
{
    //Personne Présente
    boutonPresence = digitalRead(3);
    if (boutonPresence == 1)
    {
        capJour = analogRead(A1);
        if (capJour > 600)
        {
            tempAppart = analogRead(A0);
            if (tempAppart < 143) //19°C
            {
                digitalWrite(5, HIGH);
            }
            else
            {
                digitalWrite(5, LOW);
            }
        }
        else
        {
            tempAppart = analogRead(A0);
            if (tempAppart < 141) //18°C
            {
                digitalWrite(5, HIGH);
            }
            else
            {
                digitalWrite(5, LOW);
            }
        }
    }
    // Personne non-présente
    else
    {
        digitalWrite(7, HIGH);
        delay(5000);
        digitalWrite(7, LOW);
        tempAppart = analogRead(A0);
        if (tempAppart < 139) //17°C
        {
            digitalWrite(5, HIGH);
        }
        else
        {
            digitalWrite(5, LOW);
        }
        DO = digitalRead(2);
        if (DO == 1)
        {
            delay(10000);
            boutonPresence = digitalRead(3);
            if (boutonPresence == 0)
            {
                digitalWrite(9, HIGH);
                boutonPresence = digitalRead(3);
            }
            else
            {
                digitalWrite(9, LOW);
                boutonPresence = digitalRead(3);
            }
        }

        presence = digitalRead(4);
        if (presence == 1)
        {
            boutonPresence = digitalRead(3);
            if (boutonPresence == 0)
            {
                digitalWrite(9, HIGH);
            }
            else
            {
                digitalWrite(9, LOW);
            }
        }
    }
    if (i == 0)
    {
        digitalWrite(8, HIGH);
    }
}
