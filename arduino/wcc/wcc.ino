#include "Wire.h" // This seems redundant, but we need to declare this
                  // dependency in the pde file or else it won't be included
                  // in the build.

#include "wiimote.h"

// Classic Controller Buttons
int BDL = 0; // D-PAD LEFT STATE
int BDR = 0; // D-PAD RIGHT STATE
int BDU = 0; // D-PAD UP STATE
int BDD = 0; // D-PAD DOWN STATE
int BA = 0; // A BUTTON STATE
int BB = 0; // B BUTTON STATE
int BX = 0; // X BUTTON STATE
int BY = 0; // Y BUTTON STATE
int BL = 0; // L BUTTON STATE
int BR = 0; // R BUTTON STATE
int BM = 0; // MINUS BUTTON STATE
int BP = 0; // PLUS BUTTON STATE
int BHOME = 0; // HOME BUTTON STATE
int BZL = 0; // ZL BUTTON STATE
int BZR = 0; // ZR BUTTON STATE


const int PIN_BY = 13;				// P1
const int PIN_BL = 9;				// P2
const int PIN_BX = 10;				// P3
const int PIN_BZL = 8;				// P4

const int PIN_BB = 6;				// K1
const int PIN_BR = 12;				// K2
const int PIN_BA = 4;				// K3
const int PIN_BZR = 2;				// K4

const int PIN_BP = 5;				// START
const int PIN_BM = A0;			// SELECT
const int PIN_BHOME = A1;		// HOME

const int PIN_BDR = A2;			// RIGHT
const int PIN_BDD = A5;			// DOWN
const int PIN_BDL = A3;			// LEFT
const int PIN_BDU = A4;			// UP

const int BUTTONS[15] = {BDL,BDR,BDU,BDD,BA,BB,BX,BY,BL,BR,BM,BP,BHOME,BZL,BZR};


/*
 * Analog Buttons.
 * They are initialized with center values from the calibration buffer.
 */
byte LX = calbuf[2]>>2;
byte LY = calbuf[5]>>2;
byte RX = calbuf[8]>>3;
byte RY = calbuf[11]>>3;


// Wiimote button data stream
byte *stream_callback(byte *buffer) {
	wiimote_write_buffer(buffer, BDL, BDR, BDU, BDD, BA, BB, BX, BY, BL, BR, BM, BP, BHOME, LX, LY, RX, RY, BZL, BZR);
	return buffer;
}

void setup() {
	// Set PushButton pins as input, turning pull-up on
	for(int i = 0; i < 15; i++)
	{
		pinMode(BUTTONS[i], INPUT);
		digitalWrite(BUTTONS[i], HIGH);
	}

	// Prepare wiimote communications
	wiimote_stream = stream_callback;
	wiimote_init();
}

void loop() {
	BDL = digitalRead(PIN_BDL);
	BDR = digitalRead(PIN_BDR);
	BDU = digitalRead(PIN_BDU);
	BDD = digitalRead(PIN_BDD);
	BA = digitalRead(PIN_BA);
	BB = digitalRead(PIN_BB);
	BX = digitalRead(PIN_BX);
	BY = digitalRead(PIN_BY);
	BL = digitalRead(PIN_BL);
	BR = digitalRead(PIN_BR);
	BM = digitalRead(PIN_BM);
	BP = digitalRead(PIN_BP);
	BHOME = digitalRead(PIN_BHOME);
	BZL = digitalRead(PIN_BZL);
	BZR = digitalRead(PIN_BZR);

	delay(50);
}
