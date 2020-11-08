
		const int INPUT1 = 3;
		const int INPUT2 = 4;
		const int INPUT3 = 5;
		const int ENG1 = 8;
		const int ENG2 = 9;
		int numberOfCycles = 0;
		bool isOn = false;
		bool states[6] ={
            0, 0, 0, 0, 0, 0
		} ;

        void readStates ()
        {
            states[0] = states[1];
            states[2] = states[3];
            states[4] = states[5];
            states[1] = digitalRead(INPUT1);
            states[3] = digitalRead(INPUT2);
            states[5] = digitalRead(INPUT3);
        }
        bool isStateChanged (bool state1, bool state2)
        {
            return state1 == LOW && state2 == HIGH;
        }

        void setup ()
        {
            Serial.begin(9600);
            pinMode(INPUT1, INPUT);
            pinMode(INPUT2, INPUT);
            pinMode(INPUT3, INPUT);
            pinMode(ENG1, OUTPUT);
            pinMode(ENG2, OUTPUT);
            digitalWrite(ENG1, LOW);
            digitalWrite(ENG2, LOW);
        }


        void loop ()
        {

            readStates();

            if (isStateChanged(states[0], states[1])) {
                isOn = !isOn;
                numberOfCycles++;
                digitalWrite(ENG1, LOW);
                digitalWrite(ENG2, LOW);
            }
            if (isOn) {

                if (isStateChanged(states[2], states[3])) {
                    digitalWrite(ENG1, HIGH);
                    digitalWrite(ENG2, LOW);
                }

                if (isStateChanged(states[4], states[5])) {
                    digitalWrite(ENG1, LOW);
                    digitalWrite(ENG2, HIGH);
                }
            }
            Serial.println(numberOfCycles);
        }

