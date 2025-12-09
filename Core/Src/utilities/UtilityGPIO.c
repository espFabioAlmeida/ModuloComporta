///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    UtilityGPIO
//AUTOR:      Fábio Almeida
//CRIADO:     04/08/2023
//OBSERVAÇÕES:
////////////////////////////////////////////////////////////////////////////////
#include "main.h"
#include "global.h"
/*==============================================================================
DEBOUNCE PULSOS
==============================================================================*/
uint8_t debouncePulsos(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) {
	#ifndef DEBOUNCE_PULSOS
		#define DEBOUNCE_PULSOS 15
	#endif

	if(!HAL_GPIO_ReadPin(GPIOx, GPIO_Pin)) {
		HAL_Delay(DEBOUNCE_PULSOS);
		if(!HAL_GPIO_ReadPin(GPIOx, GPIO_Pin)) {
			return true;
		}
	}

	return false;
}
/*==============================================================================
DEBOUNCE PULSOS INVERSO
==============================================================================*/
uint8_t debouncePulsosInverso(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) {
	#ifndef DEBOUNCE_PULSOS
		#define DEBOUNCE_PULSOS 15
	#endif

	if(HAL_GPIO_ReadPin(GPIOx, GPIO_Pin)) {
		HAL_Delay(DEBOUNCE_PULSOS);
		if(HAL_GPIO_ReadPin(GPIOx, GPIO_Pin)) {
			return true;
		}
	}

	return false;
}
/*==============================================================================
DEBOUNCE
==============================================================================*/
uint8_t debounce(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) {
	#ifndef DEBOUNCE
		#define DEBOUNCE 120
	#endif

	if(!HAL_GPIO_ReadPin(GPIOx, GPIO_Pin)) {
		HAL_Delay(DEBOUNCE);
		if(!HAL_GPIO_ReadPin(GPIOx, GPIO_Pin)) {
			return true;
		}
	}

	return false;
}
/*==============================================================================
DEBOUNCE INVERSO
==============================================================================*/
uint8_t debounceInverso(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) {
	#ifndef DEBOUNCE
		#define DEBOUNCE 120
	#endif

	if(HAL_GPIO_ReadPin(GPIOx, GPIO_Pin)) {
		HAL_Delay(DEBOUNCE);
		if(HAL_GPIO_ReadPin(GPIOx, GPIO_Pin)) {
			return true;
		}
	}

	return false;
}
/*==============================================================================
LEITURA ENTRADA
==============================================================================*/
uint8_t input(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) {
	if(HAL_GPIO_ReadPin(GPIOx, GPIO_Pin)) {
		return true;
	}
	return false;
}
/*==============================================================================
ACIONA SAIDA
==============================================================================*/
void on(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) {
	HAL_GPIO_WritePin(GPIOx, GPIO_Pin, 1);
}
/*==============================================================================
DESACIONA SAIDA
==============================================================================*/
void off(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) {
	HAL_GPIO_WritePin(GPIOx, GPIO_Pin, 0);
}
/*==============================================================================
INVERTE SAIDA
==============================================================================*/
void toggle(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) {
	HAL_GPIO_TogglePin(GPIOx, GPIO_Pin);
}
/*==============================================================================
SETA SAIDA
==============================================================================*/
void setPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState) {
	HAL_GPIO_WritePin(GPIOx, GPIO_Pin, PinState);
}
/*==============================================================================
FIM DO ARQUIVO
==============================================================================*/
