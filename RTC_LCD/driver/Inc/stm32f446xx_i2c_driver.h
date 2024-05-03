/*
 * stm32f446xx_i2c_driver.h
 *
 *  Created on: Apr 25, 2024
 *      Author: Sunil
 */

#ifndef INC_STM32F446XX_I2C_DRIVER_H_
#define INC_STM32F446XX_I2C_DRIVER_H_

#include "stm32f446xx.h"

/*
 * Configuration Structure for I2Cx Peripheral
 */
typedef struct
{
	uint32_t I2C_SCLSpeed;
	uint8_t  I2C_DeviceAddress;
	uint8_t  I2C_ACKControl;
	uint16_t I2C_FMDutyCycle;

}I2C_Config_t;

/*
 * Handle Structure for I2Cx Perpheral
 */
typedef struct
{
	I2C_RegDef_t *pI2Cx;
	I2C_Config_t I2C_Config;

	//Flags added for I2C Interrupt
	uint8_t *pTxBuffer;		/*!< To store app TxBuffer address >*/
	uint8_t *pRxBuffer;		/*!< To store app RxBuffer address >*/
	uint32_t TxLen;			/*!< To store Tx Len >*/
	uint32_t RxLen;			/*!< To store Rx Len >*/
	uint8_t  TxRxState;		/*!< To store Tx and Rx State : Half Duplex>*/
	uint8_t  DevAddr;		/*!< To store Device Address >*/
	uint32_t RxSize;		/*!< To store RxSize >*/
	uint8_t  Sr;			/*!< To store Reapeted Start Value >*/

}I2C_Handle_t;

/*
 * @I2C_SCLSpeed
 */
#define I2C_SCL_SPEED_SM		100000
#define I2C_SCL_SPEED_FM4K		400000
#define I2C_SCL_SPEED_FM2K		200000

/*
 * @I2C_ACKControl
 */
#define I2C_ACK_ENABLE			1
#define I2C_ACK_DISABLE			0

/*
 * @I2C_FMDutyCycle
 */
#define I2C_FM_DUTY_2			0
#define I2C_FM_DUTY_16_9		1

/*
 * I2C Flags
 */
#define I2C_FLAG_TXE		   (1 << I2C_SR1_TXE)
#define I2C_FLAG_RXNE		   (1 << I2C_SR1_RXNE)
#define I2C_FLAG_SB		   	   (1 << I2C_SR1_SB)
#define I2C_FLAG_ADDR		   (1 << I2C_SR1_ADDR)
#define I2C_FLAG_BTF		   (1 << I2C_SR1_BTF)
#define I2C_FLAG_STOPF		   (1 << I2C_SR1_STOPF)
#define I2C_FLAG_OVR		   (1 << I2C_SR1_OVR)

/*
 * I2C Repeated START(Sr) Macros
 */
#define I2C_DISABLE_SR			RESET
#define I2C_ENABLE_SR			SET


/*
 * I2C Possible Application States
 */
#define I2C_READY				0
#define I2C_BUSY_IN_RX			1
#define I2C_BUSY_IN_TX			2

/*
 * I2C Application Events Macros
 */
#define I2C_EV_TX_CMPLT			0
#define I2C_EV_RX_CMPLT			1
#define I2C_EV_STOP				2
#define I2C_ERROR_BERR  		3
#define I2C_ERROR_ARLO  		4
#define I2C_ERROR_AF    		5
#define I2C_ERROR_OVR  	 		6
#define I2C_ERROR_TIMEOUT 		7

/****************** I2C APIs Prototypes **************************/
/*
 * Peripheral Clock Setup
 */
void I2C_PeriClockControl(I2C_RegDef_t *pI2Cx, uint8_t EnorDi);

/*
 * I2C Init and De-Init
 */
void I2C_Init(I2C_Handle_t *pI2CHandle);
void I2C_DeInit(I2C_RegDef_t *pI2Cx);

/*
 * Data Send and Receive
 */
void I2C_MasterSendData(I2C_Handle_t *pI2CHandle, uint8_t *pTxBuffer, uint8_t Len, uint8_t SlaveAddr, uint8_t Sr);
void I2C_MasterReceiveData(I2C_Handle_t *pI2CHandle, uint8_t *pRxBuffer, uint8_t Len, uint8_t SlaveAddr,uint8_t Sr);

uint8_t I2C_MasterSendDataIT(I2C_Handle_t *pI2CHandle, uint8_t *pTxBuffer, uint8_t Len, uint8_t SlaveAddr, uint8_t Sr);
uint8_t I2C_MasterReceiveDataIT(I2C_Handle_t *pI2CHandle, uint8_t *pRxBuffer, uint8_t Len, uint8_t SlaveAddr,uint8_t Sr);

void I2C_CloseSendData(I2C_Handle_t *pI2CHandle);
void I2C_CloseReceiveData(I2C_Handle_t *pI2CHandle);


/*
 * I2C IRQ Configuration and ISR Handling
 */
void I2C_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
void I2C_IRQPriorityConfig(uint8_t IRQNumber, uint8_t IRQPriority);
void I2C_EV_IRQHandling(I2C_Handle_t *pI2CHandle);
void I2C_ER_IRQHandling(I2C_Handle_t *pI2CHandle);

/*
 * Application Callback
 */
void I2C_ApplicationEventCallback(I2C_Handle_t *pI2CHandle, uint8_t AppEvent);

/*
 * Other Peripheral Control APIs
 */
void I2C_PeripheralControl(I2C_RegDef_t *pI2Cx, uint8_t EnorDi);
uint8_t I2C_GetFlagStatus(I2C_RegDef_t *pI2Cx, uint32_t FlagName);
void I2C_ACKControl(I2C_RegDef_t *pI2Cx, uint8_t EnorDi);
void I2C_GenerateStopCondition(I2C_RegDef_t *pI2Cx);

uint32_t RCC_GetPCLK1Value(void);
uint32_t RCC_GetPLLOutputClock();

#endif /* INC_STM32F446XX_I2C_DRIVER_H_ */
