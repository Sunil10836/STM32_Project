/*
 * stm32f446xx.h
 *
 *  Created on: Apr 15, 2024
 *      Author: Sunil
 */

#ifndef INC_STM32F446XX_H_
#define INC_STM32F446XX_H_

#include <stdint.h>
#include <stddef.h>

#define __vo 		volatile
#define __weak  	__attribute__((weak))

/********************** Processor Specific Detail ******************************/
/*
 * ARM Cortex Mx Processor NVIC ISERx Register Base Addresses
 */
#define NVIC_ISER0				( (__vo uint32_t *) 0xE000E100 )
#define NVIC_ISER1				( (__vo uint32_t *) 0xE000E104 )
#define NVIC_ISER2				( (__vo uint32_t *) 0xE000E108 )
#define NVIC_ISER3				( (__vo uint32_t *) 0xE000E10C )

#define NVIC_ICER0				( (__vo uint32_t *) 0xE000E180 )
#define NVIC_ICER1				( (__vo uint32_t *) 0xE000E184 )
#define NVIC_ICER2				( (__vo uint32_t *) 0xE000E188 )
#define NVIC_ICER3				( (__vo uint32_t *) 0xE000E18C )

#define NVIC_IPR_BASE_ADDR		( (__vo uint32_t *) 0xE000E400 )


#define NO_PR_BITS_IMPLMENTED	4



/*
 * Base Addresses of Flash and SRAM and ROM Memories
 */

#define FLASH_BASE_ADDR			0x08000000U		/*!< FLASH Base Address */
#define SRAM1_BASE_ADDR			0x20000000U		/*!< SRAM1 Base Address */
#define SRAM2_BASE_ADDR			0x2001C000U		/*!< SRAM2 Base Address */
#define ROM_BASE_ADDR			0x1FFF0000U		/*!< ROM Base Address   */

#define SRAM					SRAM1_BASE_ADDR

/*
 * AHBx and APBx Bus Peripheral Base Address
 */

#define PERIPH_BASE				0x40000000U
#define APB1_PERIPH_BASE		PERIPH_BASE
#define APB2_PERIPH_BASE		0x40010000U
#define AHB1_PERIPH_BASE		0x40020000U
#define AHB2_PERIPH_BASE		0x50000000U

/*
 * Base Address of Peripherals which are connected/hanging on AHB1 Bus
 */
/********** GPIOx Base Addresses *********************** */
#define GPIOA_BASE_ADDR			(AHB1_PERIPH_BASE + 0x0000)
#define GPIOB_BASE_ADDR			(AHB1_PERIPH_BASE + 0x0400)
#define GPIOC_BASE_ADDR			(AHB1_PERIPH_BASE + 0x0800)
#define GPIOD_BASE_ADDR			(AHB1_PERIPH_BASE + 0x0C00)
#define GPIOE_BASE_ADDR			(AHB1_PERIPH_BASE + 0x1000)
#define GPIOF_BASE_ADDR			(AHB1_PERIPH_BASE + 0x1400)
#define GPIOG_BASE_ADDR			(AHB1_PERIPH_BASE + 0x1800)
#define GPIOH_BASE_ADDR			(AHB1_PERIPH_BASE + 0x1C00)

#define RCC_BASE_ADDR			(AHB1_PERIPH_BASE + 0x3800)

/*
 * Base Address of Peripherals which are connected/hanging on APB1 Bus
 */
/***********  I2Cx Base Addresses ************************/
#define I2C1_BASE_ADDR			(APB1_PERIPH_BASE + 0x5400)
#define I2C2_BASE_ADDR			(APB1_PERIPH_BASE + 0x5800)
#define I2C3_BASE_ADDR			(APB1_PERIPH_BASE + 0x5C00)

/************ SPIx Base Addresses ************************/
#define SPI2_BASE_ADDR			(APB1_PERIPH_BASE + 0x3800)
#define SPI3_BASE_ADDR			(APB1_PERIPH_BASE + 0x3C00)

/************ USARTx Base Addresses **********************/
#define USART2_BASE_ADDR		(APB1_PERIPH_BASE + 0x4400)
#define USART3_BASE_ADDR		(APB1_PERIPH_BASE + 0x4800)
#define UART4_BASE_ADDR			(APB1_PERIPH_BASE + 0x4C00)
#define UART5_BASE_ADDR			(APB1_PERIPH_BASE + 0x5000)

/*
 * Base Address of Peripherals which are connected/hanging on APB2 Bus
 */
/************ SPIx Base Addresses ************************/
#define SPI1_BASE_ADDR			(APB2_PERIPH_BASE + 0x3000)
#define SPI4_BASE_ADDR			(APB2_PERIPH_BASE + 0x3400)

/************ USARTx Base Addresses **********************/
#define USART1_BASE_ADDR		(APB2_PERIPH_BASE + 0x1000)
#define USART6_BASE_ADDR		(APB2_PERIPH_BASE + 0x1400)

/************ EXTI Base Addresses ************************/
#define EXTI_BASE_ADDR			(APB2_PERIPH_BASE + 0x3C00)

/************ SYSCFG Base Addresses **********************/
#define SYSCFG_BASE_ADDR		(APB2_PERIPH_BASE + 0x3800)


/******************* peripheral register definition structures ***********************/
/*
 * Peripheral register definition structure for GPIO
 */

typedef struct
{
	__vo uint32_t MODER;			/*!< GPIO port mode register, 		  		Address offset: 0x00  */
	__vo uint32_t OTYPER;			/*!< GPIO port Output Type register,  		Address offset: 0x04  */
	__vo uint32_t OSPEEDER;			/*!< GPIO port Output Speed register, 		Address offset: 0x08  */
	__vo uint32_t PUPDR;			/*!< GPIO port Pull-up/Pull-down register,  Address offset: 0x0C  */
	__vo uint32_t IDR;				/*!< GPIO port Input Data register, 		Address offset: 0x10  */
	__vo uint32_t ODR;				/*!< GPIO port Output Data register, 		Address offset: 0x14  */
	__vo uint32_t BSRR;				/*!< GPIO port Bit Set/Reset register, 		Address offset: 0x18  */
	__vo uint32_t LCKR;				/*!< GPIO port configuration lock register, Address offset: 0x1C  */
	__vo uint32_t AFR[2];			/*!< GPIO alternate function register, 		Address offset: 0x20 and 0x24 */

}GPIO_RegDef_t;


/*
 * Peripheral register definition structure for RCC
 */
typedef struct
{
  __vo uint32_t CR;            /*!< TODO,     										Address offset: 0x00 */
  __vo uint32_t PLLCFGR;       /*!< TODO,     										Address offset: 0x04 */
  __vo uint32_t CFGR;          /*!< TODO,     										Address offset: 0x08 */
  __vo uint32_t CIR;           /*!< TODO,     										Address offset: 0x0C */
  __vo uint32_t AHB1RSTR;      /*!< TODO,     										Address offset: 0x10 */
  __vo uint32_t AHB2RSTR;      /*!< TODO,     										Address offset: 0x14 */
  __vo uint32_t AHB3RSTR;      /*!< TODO,     										Address offset: 0x18 */
  uint32_t      RESERVED0;     /*!< Reserved, 0x1C                                                       */
  __vo uint32_t APB1RSTR;      /*!< TODO,     										Address offset: 0x20 */
  __vo uint32_t APB2RSTR;      /*!< TODO,     										Address offset: 0x24 */
  uint32_t      RESERVED1[2];  /*!< Reserved, 0x28-0x2C                                                  */
  __vo uint32_t AHB1ENR;       /*!< TODO,     										Address offset: 0x30 */
  __vo uint32_t AHB2ENR;       /*!< TODO,     										Address offset: 0x34 */
  __vo uint32_t AHB3ENR;       /*!< TODO,     										Address offset: 0x38 */
  uint32_t      RESERVED2;     /*!< Reserved, 0x3C                                                       */
  __vo uint32_t APB1ENR;       /*!< TODO,     										Address offset: 0x40 */
  __vo uint32_t APB2ENR;       /*!< TODO,     										Address offset: 0x44 */
  uint32_t      RESERVED3[2];  /*!< Reserved, 0x48-0x4C                                                  */
  __vo uint32_t AHB1LPENR;     /*!< TODO,     										Address offset: 0x50 */
  __vo uint32_t AHB2LPENR;     /*!< TODO,     										Address offset: 0x54 */
  __vo uint32_t AHB3LPENR;     /*!< TODO,     										Address offset: 0x58 */
  uint32_t      RESERVED4;     /*!< Reserved, 0x5C                                                       */
  __vo uint32_t APB1LPENR;     /*!< TODO,     										Address offset: 0x60 */
  __vo uint32_t APB2LPENR;     /*!< RTODO,     										Address offset: 0x64 */
  uint32_t      RESERVED5[2];  /*!< Reserved, 0x68-0x6C                                                  */
  __vo uint32_t BDCR;          /*!< TODO,     										Address offset: 0x70 */
  __vo uint32_t CSR;           /*!< TODO,     										Address offset: 0x74 */
  uint32_t      RESERVED6[2];  /*!< Reserved, 0x78-0x7C                                                  */
  __vo uint32_t SSCGR;         /*!< TODO,     										Address offset: 0x80 */
  __vo uint32_t PLLI2SCFGR;    /*!< TODO,     										Address offset: 0x84 */
  __vo uint32_t PLLSAICFGR;    /*!< TODO,     										Address offset: 0x88 */
  __vo uint32_t DCKCFGR;       /*!< TODO,     										Address offset: 0x8C */
  __vo uint32_t CKGATENR;      /*!< TODO,     										Address offset: 0x90 */
  __vo uint32_t DCKCFGR2;      /*!< TODO,     										Address offset: 0x94 */

} RCC_RegDef_t;

/*
 * peripheral register definition structure for EXTI
 */
typedef struct
{
	__vo uint32_t IMR;    /*!< Interrupt mask register,          	  	    Address offset: 0x00 */
	__vo uint32_t EMR;    /*!< Event mask register,                			Address offset: 0x04 */
	__vo uint32_t RTSR;   /*!< Rising trigger selection register,  			Address offset: 0x08 */
	__vo uint32_t FTSR;   /*!< Falling trigger selection register, 			Address offset: 0x0C */
	__vo uint32_t SWIER;  /*!< Software interrupt event register,  			Address offset: 0x10 */
	__vo uint32_t PR;     /*!< Pending register,                   			Address offset: 0x14 */

}EXTI_RegDef_t;

/*
 * peripheral register definition structure for SYSCFG
 */
typedef struct
{
	__vo uint32_t MEMRMP;       /*!< SYSCFG memory remap register,                    Address offset: 0x00      */
	__vo uint32_t PMC;          /*!< SYSCFG peripheral mode configuration register,   Address offset: 0x04      */
	__vo uint32_t EXTICR[4];    /*!< SYSCFG external interrupt configuration register 1 2 3 4, 									  Address offset: 0x08-0x14 */
	uint32_t      RESERVED1[2];  /*!<                 							      Reserved, 0x18-0x1C    	*/
	__vo uint32_t CMPCR;        /*!< SYSCFG Compensation cell control register        Address offset: 0x20      */
	uint32_t      RESERVED2[2];  /*!<                                                 Reserved, 0x24- 0x28 	    */
	__vo uint32_t CFGR;         /*!< SYSCFG configuration register                    Address offset: 0x2C   	*/
} SYSCFG_RegDef_t;


/*
 * peripheral register definition structure for SPI
 */
typedef struct
{
	__vo uint32_t CR1;        /*!< TODO,     										Address offset: 0x00 */
	__vo uint32_t CR2;        /*!< TODO,     										Address offset: 0x04 */
	__vo uint32_t SR;         /*!< TODO,     										Address offset: 0x08 */
	__vo uint32_t DR;         /*!< TODO,     										Address offset: 0x0C */
	__vo uint32_t CRCPR;      /*!< TODO,     										Address offset: 0x10 */
	__vo uint32_t RXCRCR;     /*!< TODO,     										Address offset: 0x14 */
	__vo uint32_t TXCRCR;     /*!< TODO,     										Address offset: 0x18 */
	__vo uint32_t I2SCFGR;    /*!< TODO,     										Address offset: 0x1C */
	__vo uint32_t I2SPR;      /*!< TODO,     										Address offset: 0x20 */
} SPI_RegDef_t;

/*
 * peripheral register definition structure for I2C
 */
typedef struct
{
  __vo uint32_t CR1;        /*!< TODO,     										Address offset: 0x00 */
  __vo uint32_t CR2;        /*!< TODO,     										Address offset: 0x04 */
  __vo uint32_t OAR1;       /*!< TODO,     										Address offset: 0x08 */
  __vo uint32_t OAR2;       /*!< TODO,     										Address offset: 0x0C */
  __vo uint32_t DR;         /*!< TODO,     										Address offset: 0x10 */
  __vo uint32_t SR1;        /*!< TODO,     										Address offset: 0x14 */
  __vo uint32_t SR2;        /*!< TODO,     										Address offset: 0x18 */
  __vo uint32_t CCR;        /*!< TODO,     										Address offset: 0x1C */
  __vo uint32_t TRISE;      /*!< TODO,     										Address offset: 0x20 */
  __vo uint32_t FLTR;       /*!< TODO,     										Address offset: 0x24 */
}I2C_RegDef_t;


/*
 * peripheral register definition structure for USART
 */
typedef struct
{
	__vo uint32_t SR;         /*!< TODO,     										Address offset: 0x00 */
	__vo uint32_t DR;         /*!< TODO,     										Address offset: 0x04 */
	__vo uint32_t BRR;        /*!< TODO,     										Address offset: 0x08 */
	__vo uint32_t CR1;        /*!< TODO,     										Address offset: 0x0C */
	__vo uint32_t CR2;        /*!< TODO,     										Address offset: 0x10 */
	__vo uint32_t CR3;        /*!< TODO,     										Address offset: 0x14 */
	__vo uint32_t GTPR;       /*!< TODO,     										Address offset: 0x18 */
} USART_RegDef_t;


/*
 *  Peripheral Definitions (Peripheral Base Address type casted to xxx_RegDef_t)
 */
#define GPIOA				((GPIO_RegDef_t *) GPIOA_BASE_ADDR)
#define GPIOB				((GPIO_RegDef_t *) GPIOB_BASE_ADDR)
#define GPIOC				((GPIO_RegDef_t *) GPIOC_BASE_ADDR)
#define GPIOD				((GPIO_RegDef_t *) GPIOD_BASE_ADDR)
#define GPIOE				((GPIO_RegDef_t *) GPIOE_BASE_ADDR)
#define GPIOF				((GPIO_RegDef_t *) GPIOF_BASE_ADDR)
#define GPIOG				((GPIO_RegDef_t *) GPIOG_BASE_ADDR)
#define GPIOH				((GPIO_RegDef_t *) GPIOH_BASE_ADDR)

#define RCC					((RCC_RegDef_t *) RCC_BASE_ADDR)

#define EXTI				((EXTI_RegDef_t *) EXTI_BASE_ADDR)

#define SYSCFG				((SYSCFG_RegDef_t *) SYSCFG_BASE_ADDR)

#define SPI1				((SPI_RegDef_t *) SPI1_BASE_ADDR)
#define SPI2				((SPI_RegDef_t *) SPI2_BASE_ADDR)
#define SPI3				((SPI_RegDef_t *) SPI3_BASE_ADDR)
#define SPI4				((SPI_RegDef_t *) SPI4_BASE_ADDR)

#define I2C1				((I2C_RegDef_t *) I2C1_BASE_ADDR)
#define I2C2				((I2C_RegDef_t *) I2C2_BASE_ADDR)
#define I2C3				((I2C_RegDef_t *) I2C3_BASE_ADDR)

#define USART1  			((USART_RegDef_t*)USART1_BASE_ADDR)
#define USART2  			((USART_RegDef_t*)USART2_BASE_ADDR)
#define USART3  			((USART_RegDef_t*)USART3_BASE_ADDR)
#define UART4  				((USART_RegDef_t*)UART4_BASE_ADDR)
#define UART5  				((USART_RegDef_t*)UART5_BASE_ADDR)
#define USART6  			((USART_RegDef_t*)USART6_BASE_ADDR)

/******************* Peripheral Clock Enable Macros **************************/
/*
 * Clock Enable Macros for GPIOx Peripherals
 */
#define GPIOA_PCLK_EN()			( RCC->AHB1ENR |= (1<<0) )
#define GPIOB_PCLK_EN()			( RCC->AHB1ENR |= (1<<1) )
#define GPIOC_PCLK_EN()			( RCC->AHB1ENR |= (1<<2) )
#define GPIOD_PCLK_EN()			( RCC->AHB1ENR |= (1<<3) )
#define GPIOE_PCLK_EN()			( RCC->AHB1ENR |= (1<<4) )
#define GPIOF_PCLK_EN()			( RCC->AHB1ENR |= (1<<5) )
#define GPIOG_PCLK_EN()			( RCC->AHB1ENR |= (1<<6) )
#define GPIOH_PCLK_EN()			( RCC->AHB1ENR |= (1<<7) )

/*
 * Clock Enable Macros for I2Cx Peripherals
 */
#define I2C1_PCLK_EN()			( RCC->APB1ENR |= (1<<21) )
#define I2C2_PCLK_EN()			( RCC->APB1ENR |= (1<<22) )
#define I2C3_PCLK_EN()			( RCC->APB1ENR |= (1<<23) )

/*
 * Clock Enable Macros for SPIx Peripherals
 */
#define SPI1_PCLK_EN()			( RCC->APB2ENR |= (1<<12) )
#define SPI2_PCLK_EN()			( RCC->APB1ENR |= (1<<14) )
#define SPI3_PCLK_EN()			( RCC->APB1ENR |= (1<<15) )
#define SPI4_PCLK_EN()			( RCC->APB2ENR |= (1<<13) )

/*
 * Clock Enable Macros for USARTx Peripherals
 */
#define USART1_PCLK_EN()		( RCC->APB2ENR |= (1<<4)  )
#define USART2_PCLK_EN()		( RCC->APB1ENR |= (1<<17) )
#define USART3_PCLK_EN()		( RCC->APB1ENR |= (1<<18) )
#define UART4_PCLK_EN()			( RCC->APB1ENR |= (1<<19) )
#define UART5_PCLK_EN()			( RCC->APB1ENR |= (1<<20) )
#define USART6_PCLK_EN()		( RCC->APB2ENR |= (1<<5)  )

/*
 * Clock Enable Macros for SYSCFG Peripherals
 */
#define SYSCFG_PCLK_EN()		( RCC->APB2ENR |= (1<<14) )

/*
 * Clock Enable Macros for SPI Peripherals
 */
#define SPI1_PCLK_EN()			( RCC->APB2ENR |= (1<<12) )
#define SPI2_PCLK_EN()			( RCC->APB1ENR |= (1<<14) )
#define SPI3_PCLK_EN()			( RCC->APB1ENR |= (1<<15) )
#define SPI4_PCLK_EN()			( RCC->APB2ENR |= (1<<13) )


/******************* Peripheral Clock Disable Macros **************************/
/*
 * Clock Disable Macros for GPIOx Peripherals
 */
#define GPIOA_PCLK_DI()			( RCC->AHB1ENR &= ~(1<<0) )
#define GPIOB_PCLK_DI()			( RCC->AHB1ENR &= ~(1<<1) )
#define GPIOC_PCLK_DI()			( RCC->AHB1ENR &= ~(1<<2) )
#define GPIOD_PCLK_DI()			( RCC->AHB1ENR &= ~(1<<3) )
#define GPIOE_PCLK_DI()			( RCC->AHB1ENR &= ~(1<<4) )
#define GPIOF_PCLK_DI()			( RCC->AHB1ENR &= ~(1<<5) )
#define GPIOG_PCLK_DI()			( RCC->AHB1ENR &= ~(1<<6) )
#define GPIOH_PCLK_DI()			( RCC->AHB1ENR &= ~(1<<7) )

/*
 * Clock Disable Macros for I2Cx Peripherals
 */
#define I2C1_PCLK_DI()			( RCC->APB1ENR &= ~(1<<21) )
#define I2C2_PCLK_DI()			( RCC->APB1ENR &= ~(1<<22) )
#define I2C3_PCLK_DI()			( RCC->APB1ENR &= ~(1<<23) )

/*
 * Clock Disable Macros for SPIx Peripherals
 */
#define SPI1_PCLK_DI()			( RCC->APB2ENR &= ~(1<<12) )
#define SPI2_PCLK_DI()			( RCC->APB1ENR &= ~(1<<14) )
#define SPI3_PCLK_DI()			( RCC->APB1ENR &= ~(1<<15) )
#define SPI4_PCLK_DI()			( RCC->APB2ENR &= ~(1<<13) )

/*
 * Clock Disable Macros for USARTx Peripherals
 */
#define USART1_PCLK_DI()		( RCC->APB2ENR &= ~(1<<4)  )
#define USART2_PCLK_DI()		( RCC->APB1ENR &= ~(1<<17) )
#define USART3_PCLK_DI()		( RCC->APB1ENR &= ~(1<<18) )
#define UART4_PCLK_DI()			( RCC->APB1ENR &= ~(1<<19) )
#define UART5_PCLK_DI()			( RCC->APB1ENR &= ~(1<<20) )
#define USART6_PCLK_DI()		( RCC->APB2ENR &= ~(1<<5)  )

/*
 * Clock Disable Macros for SYSCFG Peripherals
 */
#define SYSCFG_PCLK_DI()		( RCC->APB2ENR &= ~(1<<14) )

/*
 * Macros to Reset GPIOx Peripherals
 */
#define GPIOA_REG_RESET()		do { ( RCC->AHB1RSTR |= (1<<0) ); ( RCC->AHB1RSTR &= ~(1<<0)); }while(0)
#define GPIOB_REG_RESET()		do { ( RCC->AHB1RSTR |= (1<<1) ); ( RCC->AHB1RSTR &= ~(1<<1)); }while(0)
#define GPIOC_REG_RESET()		do { ( RCC->AHB1RSTR |= (1<<2) ); ( RCC->AHB1RSTR &= ~(1<<2)); }while(0)
#define GPIOD_REG_RESET()		do { ( RCC->AHB1RSTR |= (1<<3) ); ( RCC->AHB1RSTR &= ~(1<<3)); }while(0)
#define GPIOE_REG_RESET()		do { ( RCC->AHB1RSTR |= (1<<4) ); ( RCC->AHB1RSTR &= ~(1<<4)); }while(0)
#define GPIOF_REG_RESET()		do { ( RCC->AHB1RSTR |= (1<<5) ); ( RCC->AHB1RSTR &= ~(1<<5)); }while(0)
#define GPIOG_REG_RESET()		do { ( RCC->AHB1RSTR |= (1<<6) ); ( RCC->AHB1RSTR &= ~(1<<6)); }while(0)
#define GPIOH_REG_RESET()		do { ( RCC->AHB1RSTR |= (1<<7) ); ( RCC->AHB1RSTR &= ~(1<<7)); }while(0)


/*
 * Macros to Reset SPIx Peripherals
 */
#define SPI1_REG_RESET()		do { ( RCC->APB2RSTR |= (1<<12) ); ( RCC->APB2RSTR &= ~(1<<12)); }while(0)
#define SPI2_REG_RESET()		do { ( RCC->APB1RSTR |= (1<<14) ); ( RCC->APB1RSTR &= ~(1<<14)); }while(0)
#define SPI3_REG_RESET()		do { ( RCC->APB1RSTR |= (1<<15) ); ( RCC->APB1RSTR &= ~(1<<15)); }while(0)
#define SPI4_REG_RESET()		do { ( RCC->APB2RSTR |= (1<<13) ); ( RCC->APB2RSTR &= ~(1<<13)); }while(0)

/*
 * Macros to Reset I2Cx Peripherals
 */
#define I2C1_REG_RESET()		do { ( RCC->APB1RSTR |= (1<<21) ); ( RCC->APB1RSTR &= ~(1<<21)); }while(0)
#define I2C2_REG_RESET()		do { ( RCC->APB1RSTR |= (1<<22) ); ( RCC->APB1RSTR &= ~(1<<22)); }while(0)
#define I2C3_REG_RESET()		do { ( RCC->APB1RSTR |= (1<<23) ); ( RCC->APB1RSTR &= ~(1<<23)); }while(0)

/*
 * Macros to Reset USARTx Peripherals
 */
#define USART1_REG_RESET()		do { ( RCC->APB2RSTR |= (1<<4) );  ( RCC->APB2RSTR &= ~(1<<4));  }while(0)
#define USART2_REG_RESET()		do { ( RCC->APB1RSTR |= (1<<17) ); ( RCC->APB1RSTR &= ~(1<<17)); }while(0)
#define USART3_REG_RESET()		do { ( RCC->APB1RSTR |= (1<<18) ); ( RCC->APB1RSTR &= ~(1<<18)); }while(0)
#define UART4_REG_RESET()		do { ( RCC->APB1RSTR |= (1<<19) ); ( RCC->APB1RSTR &= ~(1<<19)); }while(0)
#define UART5_REG_RESET()		do { ( RCC->APB1RSTR |= (1<<20) ); ( RCC->APB1RSTR &= ~(1<<20)); }while(0)
#define USART6_REG_RESET()		do { ( RCC->APB2RSTR |= (1<<5) );  ( RCC->APB2RSTR &= ~(1<<5));  }while(0)

/*
 * IRQ Numbers for EXTI Lines
 */
#define IRQ_NO_EXTI0			6
#define IRQ_NO_EXTI1			7
#define IRQ_NO_EXTI2			8
#define IRQ_NO_EXTI3			9
#define IRQ_NO_EXTI4			10
#define IRQ_NO_EXTI5_9			23
#define IRQ_NO_EXTI10_15		40

/*
 * IRQ Numbers for SPI
 */
#define IRQ_NO_SPI1				35
#define IRQ_NO_SPI2				36
#define IRQ_NO_SPI3				51

/*
 * IRQ Numbers for I2C
 */
#define IRQ_NO_I2C1_EV			31
#define IRQ_NO_I2C1_ER			32
#define IRQ_NO_I2C2_EV			33
#define IRQ_NO_I2C2_ER			34
#define IRQ_NO_I2C3_EV			72
#define IRQ_NO_I2C3_ER			73

/*
 * Macros For All The possible priority levels
 */
#define NVIC_IRQ_PRI0			0
#define NVIC_IRQ_PRI1			1
#define NVIC_IRQ_PRI2			2
#define NVIC_IRQ_PRI3			3
#define NVIC_IRQ_PRI4			4
#define NVIC_IRQ_PRI5			5
#define NVIC_IRQ_PRI6			6
#define NVIC_IRQ_PRI7			7
#define NVIC_IRQ_PRI8			8
#define NVIC_IRQ_PRI9			9
#define NVIC_IRQ_PRI10			10
#define NVIC_IRQ_PRI11			11
#define NVIC_IRQ_PRI12			12
#define NVIC_IRQ_PRI13			13
#define NVIC_IRQ_PRI14			14
#define NVIC_IRQ_PRI15			15

//Some Generic Macros

#define ENABLE 				1
#define DISABLE				0
#define SET					ENABLE
#define RESET				DISABLE
#define GPIO_PIN_SET		SET
#define GPIO_PIN_RESET		RESET

#define FLAG_RESET			RESET
#define FLAG_SET			SET

/******************************************************************************************
 *Bit position definitions of SPI peripheral
 ******************************************************************************************/
/*
 * SPI_CR1 Register
 */
#define SPI_CR1_CPHA		0
#define SPI_CR1_CPOL		1
#define SPI_CR1_MSTR		2
#define SPI_CR1_BR			3
#define SPI_CR1_SPE			4
#define SPI_CR1_LSBFIRST	7
#define SPI_CR1_SSI			8
#define SPI_CR1_SSM			9
#define SPI_CR1_RXONLY		10
#define SPI_CR1_DFF			11
#define SPI_CR1_CRCNEXT		12
#define SPI_CR1_CRCEN		13
#define SPI_CR1_BIDIOE		14
#define SPI_CR1_BIDIMODE	15


/*
 * SPI_CR2 Register
 */

#define SPI_CR2_RXDMAEN		0
#define SPI_CR2_TXDMAEN		1
#define SPI_CR2_SSOE		2
#define SPI_CR2_FRF			4
#define SPI_CR2_ERRIE		5
#define SPI_CR2_RXNEIE		6
#define SPI_CR2_TXEIE		7

/*
 * SPI_SR Register
 */
#define SPI_SR_RXNE			0
#define SPI_SR_TXE			1
#define SPI_SR_CHSIDE		2
#define SPI_SR_UDR			3
#define SPI_SR_CRCERR		4
#define SPI_SR_MODF			5
#define SPI_SR_OVR			6
#define SPI_SR_BSY			7
#define SPI_SR_FRE			8

/******************************************************************************************
 *Bit position definitions of I2C peripheral
 ******************************************************************************************/
/*
 * Bit position definitions I2C_CR1
 */
#define I2C_CR1_PE						0
#define I2C_CR1_NOSTRETCH  				7
#define I2C_CR1_START 					8
#define I2C_CR1_STOP  				 	9
#define I2C_CR1_ACK 				 	10
#define I2C_CR1_SWRST  				 	15

/*
 * Bit position definitions I2C_CR2
 */
#define I2C_CR2_FREQ				 	0
#define I2C_CR2_ITERREN				 	8
#define I2C_CR2_ITEVTEN				 	9
#define I2C_CR2_ITBUFEN 			    10

/*
 * Bit position definitions I2C_OAR1
 */
#define I2C_OAR1_ADD0    				 0
#define I2C_OAR1_ADD71 				 	 1
#define I2C_OAR1_ADD98  			 	 8
#define I2C_OAR1_ADDMODE   			 	15

/*
 * Bit position definitions I2C_SR1
 */

#define I2C_SR1_SB 					 	0
#define I2C_SR1_ADDR 				 	1
#define I2C_SR1_BTF 					2
#define I2C_SR1_ADD10 					3
#define I2C_SR1_STOPF 					4
#define I2C_SR1_RXNE 					6
#define I2C_SR1_TXE 					7
#define I2C_SR1_BERR 					8
#define I2C_SR1_ARLO 					9
#define I2C_SR1_AF 					 	10
#define I2C_SR1_OVR 					11
#define I2C_SR1_TIMEOUT 				14

/*
 * Bit position definitions I2C_SR2
 */
#define I2C_SR2_MSL						0
#define I2C_SR2_BUSY 					1
#define I2C_SR2_TRA 					2
#define I2C_SR2_GENCALL 				4
#define I2C_SR2_DUALF 					7

/*
 * Bit position definitions I2C_CCR
 */
#define I2C_CCR_CCR 					 0
#define I2C_CCR_DUTY 					14
#define I2C_CCR_FS  				 	15


/******************************************************************************************
 *Bit position definitions of USART peripheral
 ******************************************************************************************/
/*
 * Bit position definitions USART_CR1
 */
#define USART_CR1_SBK					0
#define USART_CR1_RWU 					1
#define USART_CR1_RE  					2
#define USART_CR1_TE 					3
#define USART_CR1_IDLEIE 				4
#define USART_CR1_RXNEIE  				5
#define USART_CR1_TCIE					6
#define USART_CR1_TXEIE					7
#define USART_CR1_PEIE 					8
#define USART_CR1_PS 					9
#define USART_CR1_PCE 					10
#define USART_CR1_WAKE  				11
#define USART_CR1_M 					12
#define USART_CR1_UE 					13
#define USART_CR1_OVER8  				15

/*
 * Bit position definitions USART_CR2
 */
#define USART_CR2_ADD   				0
#define USART_CR2_LBDL   				5
#define USART_CR2_LBDIE  				6
#define USART_CR2_LBCL   				8
#define USART_CR2_CPHA   				9
#define USART_CR2_CPOL   				10
#define USART_CR2_STOP   				12
#define USART_CR2_LINEN   				14

/*
 * Bit position definitions USART_CR3
 */
#define USART_CR3_EIE   				0
#define USART_CR3_IREN   				1
#define USART_CR3_IRLP  				2
#define USART_CR3_HDSEL   				3
#define USART_CR3_NACK   				4
#define USART_CR3_SCEN   				5
#define USART_CR3_DMAR  				6
#define USART_CR3_DMAT   				7
#define USART_CR3_RTSE   				8
#define USART_CR3_CTSE   				9
#define USART_CR3_CTSIE   				10
#define USART_CR3_ONEBIT   				11

/*
 * Bit position definitions USART_SR
 */
#define USART_SR_PE        				0
#define USART_SR_FE        				1
#define USART_SR_NE        				2
#define USART_SR_ORE       				3
#define USART_SR_IDLE       			4
#define USART_SR_RXNE        			5
#define USART_SR_TC        				6
#define USART_SR_TXE        			7
#define USART_SR_LBD        			8
#define USART_SR_CTS        			9


#include "stm32f446xx_gpio_driver.h"
#include "stm32f446xx_i2c_driver.h"
#include "stm32f446xx_rcc_driver.h"


#endif /* INC_STM32F446XX_H_ */
