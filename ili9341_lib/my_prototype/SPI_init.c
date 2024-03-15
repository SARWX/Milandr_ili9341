#include "MDR32F9Qx_ssp.h"
#include "MDR32Fx.h"

PORT_InitTypeDef* Port_sruct;

// Инициализация RESET и POT B
void PORT_StructInit(Port_sruct);
Port_sruct->PORT_Pin       = (PORT_Pin_6 | PORT_Pin_7); // PB6 = DC, PB7 = RESET
Port_sruct->PORT_OE        = PORT_OE_OUT;
Port_sruct->PORT_SPEED     = PORT_SPEED_MAXFAST;
Port_sruct->PORT_MODE      = PORT_MODE_DIGITAL;         // ???
void PORT_Init(MDR_PORTB, Port_sruct);

// Инициализация CS и PORT F
Port_sruct->PORT_Pin       = PORT_Pin_2;                // PF2 = CS
void PORT_Init(MDR_PORTF, Port_sruct);

// Инициализация SPI
SSP_InitTypeDef* SSP1_struct;
SSP_StructInit(SSP1_struct);    // Инициализируем стандартными значениями
SSP_Init((MDR_SSP_TypeDef*)MDR_SSP1, SSP1_struct);
SSP_Cmd(SSP1_struct, ENABLE);

// uint16_t data = 0;
// SSP_SendData(MDR_SSP1, data);