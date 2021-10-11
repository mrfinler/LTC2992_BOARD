/*
 * LTC2922.c
 *
 *  Created on: Oct 11, 2021
 *      Author: Natmatee Pituwarajirakul
 */
#include "LTC2922.h"
#include "i2c.h"

CONVERT_DATA sensor_data;
uint8_t data_read_buffer[3] = {0};
uint8_t data_write_buffer[3] = {0};
extern float voltage,delta_sense,power,sense;
extern uint8_t err;

/*=============================================================================*/
/**
 * @brief	Configuration LTC2922
 * @param  	None
 * @retval 	None
 */
void LTC2922_CONFIGURATION(void){
	// setting function
}


/*=============================================================================*/
/**
 * @brief	Initial DATA
 * @param  	None
 * @retval 	None
 */
void DATA_Init(void){
	data_read_buffer[0] = 0;
	data_read_buffer[1] = 0;
	data_read_buffer[2] = 0;
	sensor_data.Power = 0;
	sensor_data.Delta_sense = 0;
	sensor_data.Voltage = 0;
	sensor_data.sense = 0;
	sensor_data.mode = 0;
	sensor_data.err = 0;
}


/*=============================================================================*/
/**
 * @brief	Update Read DATA
 * @param  	None
 * @retval 	None
 */
void UPDATE_DATA(void){
	power = sensor_data.Power;
	delta_sense = sensor_data.Delta_sense;
	voltage = sensor_data.Voltage;
	sense = sensor_data.sense;
	err = sensor_data.err;
}


/*=============================================================================*/
/**
 * @brief	Check CONVERSION MODE 8bits or 12 bits
 * @param  	None
 * @retval 	MODE 0 : 12 bits, MODE 1 : 8bits
 */
void LTC2922_CONVESIONMODE_CHECK(void){
	HAL_I2C_Mem_Read_IT(&hi2c1, I2C_DEVICE_ADDRESS, LTC2992_NADC_REG, I2C_MEMADD_SIZE_8BIT, data_read_buffer, 1);
	sensor_data.mode = data_read_buffer[0]>>7;
}


/*=============================================================================*/
/**
 * @brief	READ_POWER_DATA Channel 1
 * @param  	None
 * @retval 	POWER DATA
 */
void READ_POWER1_DATA(void){
	HAL_I2C_Mem_Read_IT(&hi2c1, I2C_DEVICE_ADDRESS, LTC2992_POWER1_MSB2_REG, I2C_MEMADD_SIZE_8BIT, data_read_buffer, 3);
	if(sensor_data.mode == LTC2992_12BITS_MODE){
		sensor_data.Power = data_read_buffer[0]*65536+data_read_buffer[1]*256+data_read_buffer[2];
	}
	else if(sensor_data.mode == LTC2992_8BITS_MODE){
		sensor_data.Power = (data_read_buffer[0]*256+data_read_buffer[1]);
	}
	else{
		sensor_data.err = 1;
	}
}


/*=============================================================================*/
/**
 * @brief	READ_VOLTAGE_DATA Channel 1
 * @param  	None
 * @retval 	VOLTAGE DATA
 */
void READ_VOLTAGE1_DATA(void){
	HAL_I2C_Mem_Read_IT(&hi2c1, I2C_DEVICE_ADDRESS, LTC2992_GPIO1_MSB_REG, I2C_MEMADD_SIZE_8BIT, data_read_buffer, 2);
	if(sensor_data.mode == LTC2992_12BITS_MODE){
		sensor_data.Voltage = ((data_read_buffer[0]*256+data_read_buffer[1])>>4)*0.5e-3;
	}
	else if(sensor_data.mode == LTC2992_8BITS_MODE){
		sensor_data.Voltage = (data_read_buffer[0])*8e-3;
		}
	else{
		sensor_data.err = 1;
	}
}


/*=============================================================================*/
/**
 * @brief	READ_DELTASENSE_DATA Channel 1
 * @param  	None
 * @retval 	DELTASENSE1 DATA
 */
void READ_DELTASENSE1_DATA(void){
	HAL_I2C_Mem_Read_IT(&hi2c1, I2C_DEVICE_ADDRESS, LTC2992_DELTA_SENSE1_MSB_REG, I2C_MEMADD_SIZE_8BIT, data_read_buffer, 2);
	if(sensor_data.mode == LTC2992_12BITS_MODE){
		sensor_data.Delta_sense = (((data_read_buffer[0]*256+data_read_buffer[1])>>4)*12.5/1e6)/LTC2992_SENSE_RESISTOR_REG/40;
	}
	else if(sensor_data.mode == LTC2992_8BITS_MODE){
		sensor_data.Delta_sense = (data_read_buffer[0])*200/1e6/LTC2992_SENSE_RESISTOR_REG/40;
	}
	else{
		sensor_data.err = 1;
	}
}


/*=============================================================================*/
/**
 * @brief	READ_SENSE_DATA Channel 1
 * @param  	None
 * @retval 	SENSE1+ DATA
 */
void READ_SENSE1_DATA(void){
	HAL_I2C_Mem_Read_IT(&hi2c1, I2C_DEVICE_ADDRESS, LTC2992_SENSE1_MSB_REG, I2C_MEMADD_SIZE_8BIT, data_read_buffer, 2);
	if(sensor_data.mode == LTC2992_12BITS_MODE){
		sensor_data.sense = (((data_read_buffer[0]*256+data_read_buffer[1])>>4)*25e-3)/LTC2992_SENSE_RESISTOR_REG/40;
	}
	else if(sensor_data.mode == LTC2992_8BITS_MODE){
		sensor_data.sense = (data_read_buffer[0])*0.4/LTC2992_SENSE_RESISTOR_REG/40;
	}
	else{
		sensor_data.err = 1;
	}
}


/*=============================================================================*/
/**
 * @brief	SETTING_LTC2922_CONVERSION_MODE
 * @param  	mode : 8 or 12 bits that want to edit
 * 								[1] = 8 bits
 *								[0] = 12 bits(Default)
 * @retval 	None
 */
void SETTING_LTC2922_MODE(uint8_t mode){
	// mode = 0 12bits, mode = 1 8bits
	data_write_buffer[0] = mode<<7;
	HAL_I2C_Mem_Write_IT(&hi2c1, I2C_DEVICE_ADDRESS, LTC2992_NADC_REG, I2C_MEMADD_SIZE_8BIT, data_write_buffer, 1);
}


/*=============================================================================*/
/**
 * @brief	SETTING_LTC2992_CTRLA_REG
 * @param  	offset_calibrate : Offset Calibration for Current Measurements
 * 								[1] = Calibrate on Demand
 *								[0] = Every Conversion (Default)
 *			measurement_mode : [11] = Shutdown
 *							   [10] = Single Cycle mode : The VADC converts SENSE1+, SENSE2+, GPIO1, GPIO2, GPIO3, GPIO4 once and stops. The IADCs stop after one conversion.
 *							   [01] = Snapshot Mode : Snapshot Initializes Conversion on All 3 ADCs Simultaneously.VADC Converts the Channel(s) per CTRLA[2:0]
 *							   [00] = Continuous Scan Mode (Default) : The Selected Channels for VADC are Defined by CTRLA[4:3]
 *			continue_scan	 : Voltage Selection for Continuous Scan Mode
 *							   | [] 		| 		VADC		|			P1			|	 		P2 			|
 *									[11] 	|	GPIO1, GPIO2,	|						|						|
 *											|	GPIO3, GPIO4	|						|						|
 *											|					|	GPIO1 × ∆SENSE1		|	GPIO2 × ∆SENSE2 	|
 *								---------------------------------------------------------------------------------
 *									[10] 	|	GPIO1, GPIO2 	|	GPIO1 × ∆SENSE1		|	GPIO2 × ∆SENSE2		|
 *								---------------------------------------------------------------------------------
 *									[01] 	|	SENSE1+, SENSE2+|	SENSE1+ × ∆SENSE1	|	SENSE2+ × ∆SENSE2	|
 *								---------------------------------------------------------------------------------
 *									[00]	|	SENSE1+, SENSE2+|												|
 *								 (Default)	|	GPIO1, GPIO2,	|												|
 *											|	GPIO3, GPIO4	|												|
 *																|	SENSE1+ × ∆SENSE1	|	SENSE2+ × ∆SENSE2	|
 *								---------------------------------------------------------------------------------
 *
 * @retval 	None
 */
void SETTING_LTC2992_CTRLA_REG(uint8_t offset_calibrate,uint8_t measurement_mode,uint8_t continue_scan,uint8_t snap_scan){
	data_write_buffer[0] = (offset_calibrate<<7)+(measurement_mode<<5)+(continue_scan<<3)+(snap_scan);
	HAL_I2C_Mem_Write_IT(&hi2c1, I2C_DEVICE_ADDRESS, LTC2992_NADC_REG, I2C_MEMADD_SIZE_8BIT, data_write_buffer, 1);
}
//
void SETTING_LTC2992_CTRLB_REG(uint8_t offset_calibrate,uint8_t measurement_mode,uint8_t continue_scan,uint8_t snap_scan){
	data_write_buffer[0] = (offset_calibrate<<7)+(measurement_mode<<5)+(continue_scan<<3)+(snap_scan);
	HAL_I2C_Mem_Write_IT(&hi2c1, I2C_DEVICE_ADDRESS, LTC2992_NADC_REG, I2C_MEMADD_SIZE_8BIT, data_write_buffer, 1);
}
//
