/***************************************************************************//**
 * 	@file			SPI_ll.h
 *  @brief			Файл подключается к проекту для работы с устройствами на SPI с помощью библиотеки LL.
 *	@author			Рафаэль Абельдинов
 *  @date 			18.12.2023
 ******************************************************************************/

/**
 * @defgroup SPI_group SPI LL
 * @brief Модуль SPI для микроконтроллера F103. Подключается для работы модулей на библиотеке LL. 
 * @details Обеспечивает передачу данных устройству, подключенному к микроконтроллеру по SPI
 * @{
 */
#ifndef INC_SPI_LL_C_
#define INC_SPI_LL_C_

#include "main.h"

/**
 * @brief Дополнительная внутрянняя функция для отлова ошибок в SPI
 * @param SPIx SPI, для которого была вызвана функция для отправки или приема данных
 * @param бит регистра SR, значение которого проверяется
 * @param timeout Время ожидания получения необходимого значения бита
 * @retval status Результат проверки бита I2C. Может быть
 * 					- **HAL_BUSY** - если по истечении времени шина осталась занятой
 * 					- **HAL_ERROR** - если по истечении времени флаг не изменился на указанный
 * 					-  **HAL_OK** - в остальных случаях  
 */
HAL_StatusTypeDef SPI__wait_flag(SPI_TypeDef *SPIx, uint8_t bit, uint8_t timeout);

/* Send bytes to device ------------------------------------------------------*/
/**
 * @brief Отправка байтов по шине SPI
 * @param SPIx SPI, на который отправляются данные
 * @param data Буфер отправляемых данных
 * @param bytes_count Размер буфера в байтах 
 * @param timeout Время ожидания изменения какого либо флага во время передачи данных
 * @retval status Результат отправки данных. Может быть 
 * 					- **HAL_BUSY** - если по истечении времени шина осталась занятой 
 * 					- **HAL_ERROR** - если по истечении времени флаг не изменился на указанный
 *  				- **HAL_OK** - в остальных случаях 
 */
HAL_StatusTypeDef LL_SPI_Transmit(SPI_TypeDef *SPIx, uint8_t* data, uint8_t bytes_count, uint8_t timeout);

/* Read bytes from device ----------------------------------------------------*/
/**
 * @brief Прием байтов с шины SPI
 * @param SPIx SPI, с которого отправляются данные
 * @param buffer Указатель на буффер данных, куда записываются данные. Указатель нужен для изменения переданного буффера
 * @param bytes_count Размер буффера в байтах
 * @param timeout Время ожидания изменения какого либо флага во время приема данных
 * @retval status Результат приема данных. Может быть 
 * 					- **HAL_BUSY** - если по истечении времени шина осталась занятой 
 * 					- **HAL_ERROR** - если по истечении времени флаг не изменился на указанный
 *  				- **HAL_OK** - в остальных случаях
 */
HAL_StatusTypeDef LL_SPI_Receive(SPI *SPIx, uint8_t** buffer, uint8_t bytes_count, uint8_t timeout);

#endif /* INC_SPI_LL_C_ */
