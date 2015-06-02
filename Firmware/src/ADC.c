#include "ADC.h"

/*
 * ADC.c
 *
 * Created on: Apr 15, 2015
 * Author: Caspar Friedrich
 */

void adc_Init(void) {
	// Enable the ADC
	ADCSRA |= (1 << ADEN);
}

uint16_t adc_Read(uint8_t channel) {
	// Setup conversion: Use AVCC as reference.
	ADMUX |= (1 << REFS0) | channel;

	// Start the conversion
	ADCSRA |= (1 << ADSC);

	// Wait for conversion to finish
	while ((ADCSRA & (1 << ADSC)))
		;

	// Return ADC value register
	return ADC;
}
