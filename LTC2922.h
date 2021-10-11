/*
 * LTC2922.h
 *
 *  Created on: Oct 11, 2021
 *      Author: Natmatee Pituwarajirakul
 */

#ifndef INC_LTC2922_H_
#define INC_LTC2922_H_

#include "main.h"

#define I2C_DEVICE_ADDRESS 0xDE //Device LTC2922 address
//---------------------- Command -------------------------------
#define LTC2992_CTRLA_REG                                  0x00
#define LTC2992_CTRLB_REG                                  0x01
#define LTC2992_ALERT1_REG                                 0x02
#define LTC2992_FAULT1_REG                                 0x03
#define LTC2992_NADC_REG                                   0x04
#define LTC2992_POWER1_MSB2_REG                            0x05
#define LTC2992_POWER1_MSB1_REG                            0x06
#define LTC2992_POWER1_LSB_REG                             0x07
#define LTC2992_MAX_POWER1_MSB2_REG                        0x08
#define LTC2992_MAX_POWER1_MSB1_REG                        0x09
#define LTC2992_MAX_POWER1_LSB_REG                         0x0A
#define LTC2992_MIN_POWER1_MSB2_REG                        0x0B
#define LTC2992_MIN_POWER1_MSB1_REG                        0x0C
#define LTC2992_MIN_POWER1_LSB_REG                         0x0D
#define LTC2992_MAX_POWER1_THRESHOLD_MSB2_REG              0x0E
#define LTC2992_MAX_POWER1_THRESHOLD_MSB1_REG              0x0F
#define LTC2992_MAX_POWER1_THRESHOLD_LSB_REG               0x10
#define LTC2992_MIN_POWER1_THRESHOLD_MSB2_REG              0x11
#define LTC2992_MIN_POWER1_THRESHOLD_MSB1_REG              0x12
#define LTC2992_MIN_POWER1_THRESHOLD_LSB_REG               0x13
#define LTC2992_DELTA_SENSE1_MSB_REG                       0x14
#define LTC2992_DELTA_SENSE1_LSB_REG                       0x15
#define LTC2992_MAX_DELTA1_SENSE_MSB_REG                   0x16
#define LTC2992_MAX_DELTA1_SENSE_LSB_REG                   0x17
#define LTC2992_MIN_DELTA1_SENSE_MSB_REG                   0x18
#define LTC2992_MIN_DELTA1_SENSE_LSB_REG                   0x19
#define LTC2992_MAX_DELTA1_SENSE_THRESHOLD_MSB_REG         0x1A
#define LTC2992_MAX_DELTA1_SENSE_THRESHOLD_LSB_REG         0x1B
#define LTC2992_MIN_DELTA1_SENSE_THRESHOLD_MSB_REG         0x1C
#define LTC2992_MIN_DELTA1_SENSE_THRESHOLD_LSB_REG         0x1D
#define LTC2992_SENSE1_MSB_REG                             0x1E
#define LTC2992_SENSE1_LSB_REG                             0x1F
#define LTC2992_MAX_SENSE1_MSB_REG                         0x20
#define LTC2992_MAX_SENSE1_LSB_REG                         0x21
#define LTC2992_MIN_SENSE1_MSB_REG                         0x22
#define LTC2992_MIN_SENSE1_LSB_REG                         0x23
#define LTC2992_MAX_SENSE1_THRESHOLD_MSB_REG               0x24
#define LTC2992_MAX_SENSE1_THRESHOLD_LSB_REG               0x25
#define LTC2992_MIN_SENSE1_THRESHOLD_MSB_REG               0x26
#define LTC2992_MIN_SENSE1_THRESHOLD_LSB_REG               0x27
#define LTC2992_GPIO1_MSB_REG                              0x28
#define LTC2992_GPIO1_LSB_REG_REG                          0x29
#define LTC2992_MAX_GPIO1_MSB_REG                          0x2A
#define LTC2992_MAX_GPIO1_LSB_REG                          0x2B
#define LTC2992_MIN_GPIO1_MSB_REG                          0x2C
#define LTC2992_MIN_GPIO1_LSB_REG                          0x2D
#define LTC2992_MAX_GPIO1_THRESHOLD_MSB_REG                0x2E
#define LTC2992_MAX_GPIO1_THRESHOLD_LSB_REG                0x2F
#define LTC2992_MIN_GPIO1_THRESHOLD_MSB_REG                0x30
#define LTC2992_MIN_GPIO1_THRESHOLD_LSB_REG                0x31
#define LTC2992_ADC_STATUS_REG                             0x32
#define LTC2992_ALERT2_REG                                 0x34
#define LTC2992_FAULT2_REG                                 0x35
#define LTC2992_POWER2_MSB2_REG                            0x37
#define LTC2992_POWER2_MSB1_REG                            0x38
#define LTC2992_POWER2_LSB_REG                             0x39
#define LTC2992_MAX_POWER2_MSB2_REG                        0x3A
#define LTC2992_MAX_POWER2_MSB1_REG                        0x3B
#define LTC2992_MAX_POWER2_LSB_REG                         0x3C
#define LTC2992_MIN_POWER2_MSB2_REG                        0x3D
#define LTC2992_MIN_POWER2_MSB1_REG                        0x3E
#define LTC2992_MIN_POWER2_LSB_REG                         0x3F
#define LTC2992_MAX_POWER2_THRESHOLD_MSB2_REG              0x40
#define LTC2992_MAX_POWER2_THRESHOLD_MSB1_REG              0x41
#define LTC2992_MAX_POWER2_THRESHOLD_LSB_REG               0x42
#define LTC2992_MIN_POWER2_THRESHOLD_MSB2_REG              0x43
#define LTC2992_MIN_POWER2_THRESHOLD_MSB1_REG              0x44
#define LTC2992_MIN_POWER2_THRESHOLD_LSB_REG               0x45
#define LTC2992_DELTA_SENSE2_MSB_REG                       0x46
#define LTC2992_DELTA_SENSE2_LSB_REG                       0x47
#define LTC2992_MAX_DELTA2_SENSE_MSB_REG                   0x48
#define LTC2992_MAX_DELTA2_SENSE_LSB_REG                   0x49
#define LTC2992_MIN_DELTA2_SENSE_MSB_REG                   0x4A
#define LTC2992_MIN_DELTA2_SENSE_LSB_REG                   0x4B
#define LTC2992_MAX_DELTA2_SENSE_THRESHOLD_MSB_REG         0x4C
#define LTC2992_MAX_DELTA2_SENSE_THRESHOLD_LSB_REG         0x4D
#define LTC2992_MIN_DELTA2_SENSE_THRESHOLD_MSB_REG         0x4E
#define LTC2992_MIN_DELTA2_SENSE_THRESHOLD_LSB_REG         0x4F
#define LTC2992_SENSE2_MSB_REG                             0x50
#define LTC2992_SENSE2_LSB_REG                             0x51
#define LTC2992_MAX_SENSE2_MSB_REG                         0x52
#define LTC2992_MAX_SENSE2_LSB_REG                         0x53
#define LTC2992_MIN_SENSE2_MSB_REG                         0x54
#define LTC2992_MIN_SENSE2_LSB_REG                         0x55
#define LTC2992_MAX_SENSE2_THRESHOLD_MSB_REG               0x56
#define LTC2992_MAX_SENSE2_THRESHOLD_LSB_REG               0x57
#define LTC2992_MIN_SENSE2_THRESHOLD_MSB_REG               0x58
#define LTC2992_MIN_SENSE2_THRESHOLD_LSB_REG               0x59
#define LTC2992_GPIO2_MSB_REG                              0x5A
#define LTC2992_GPIO2_LSB_REG_REG                          0x5B
#define LTC2992_MAX_GPIO2_MSB_REG                          0x5C
#define LTC2992_MAX_GPIO2_LSB_REG                          0x5D
#define LTC2992_MIN_GPIO2_MSB_REG                          0x5E
#define LTC2992_MIN_GPIO2_LSB_REG                          0x5F
#define LTC2992_MAX_GPIO2_THRESHOLD_MSB_REG                0x60
#define LTC2992_MAX_GPIO2_THRESHOLD_LSB_REG                0x61
#define LTC2992_MIN_GPIO2_THRESHOLD_MSB_REG                0x62
#define LTC2992_MIN_GPIO2_THRESHOLD_LSB_REG                0x63
#define LTC2992_GPIO3_MSB_REG                              0x64
#define LTC2992_GPIO3_LSB_REG_REG                          0x65
#define LTC2992_MAX_GPIO3_MSB_REG                          0x66
#define LTC2992_MAX_GPIO3_LSB_REG                          0x67
#define LTC2992_MIN_GPIO3_MSB_REG                          0x68
#define LTC2992_MIN_GPIO3_LSB_REG                          0x69
#define LTC2992_MAX_GPIO3_THRESHOLD_MSB_REG                0x6A
#define LTC2992_MAX_GPIO3_THRESHOLD_LSB_REG                0x6B
#define LTC2992_MIN_GPIO3_THRESHOLD_MSB_REG                0x6C
#define LTC2992_MIN_GPIO3_THRESHOLD_LSB_REG                0x6D
#define LTC2992_GPIO4_MSB_REG                              0x6E
#define LTC2992_GPIO4_LSB_REG_REG                          0x6F
#define LTC2992_MAX_GPIO4_MSB_REG                          0x70
#define LTC2992_MAX_GPIO4_LSB_REG                          0x71
#define LTC2992_MIN_GPIO4_MSB_REG                          0x72
#define LTC2992_MIN_GPIO4_LSB_REG                          0x73
#define LTC2992_MAX_GPIO4_THRESHOLD_MSB_REG                0x74
#define LTC2992_MAX_GPIO4_THRESHOLD_LSB_REG                0x75
#define LTC2992_MIN_GPIO4_THRESHOLD_MSB_REG                0x76
#define LTC2992_MIN_GPIO4_THRESHOLD_LSB_REG                0x77
#define LTC2992_ISUM_MSB_REG                               0x78
#define LTC2992_ISUM_LSB_REG_REG                           0x79
#define LTC2992_MAX_ISUM_MSB_REG                           0x7A
#define LTC2992_MAX_ISUM_LSB_REG                           0x7B
#define LTC2992_MIN_ISUM_MSB_REG                           0x7C
#define LTC2992_MIN_ISUM_LSB_REG                           0x7D
#define LTC2992_MAX_ISUM_THRESHOLD_MSB_REG                 0x7E
#define LTC2992_MAX_ISUM_THRESHOLD_LSB_REG                 0x7F
#define LTC2992_MIN_ISUM_THRESHOLD_MSB_REG                 0x80
#define LTC2992_MIN_ISUM_THRESHOLD_LSB_REG                 0x81
#define LTC2992_PSUM_MSB1_REG                              0x82
#define LTC2992_PSUM_MSB_REG                               0x83
#define LTC2992_PSUM_LSB_REG_REG                           0x84
#define LTC2992_MAX_PSUM_MSB1_REG                          0x85
#define LTC2992_MAX_PSUM_MSB_REG                           0x86
#define LTC2992_MAX_PSUM_LSB_REG                           0x87
#define LTC2992_MIN_PSUM_MSB1_REG                          0x88
#define LTC2992_MIN_PSUM_MSB_REG                           0x89
#define LTC2992_MIN_PSUM_LSB_REG                           0x8A
#define LTC2992_MAX_PSUM_THRESHOLD_MSB1_REG                0x8B
#define LTC2992_MAX_PSUM_THRESHOLD_MSB_REG                 0x8C
#define LTC2992_MAX_PSUM_THRESHOLD_LSB_REG                 0x8D
#define LTC2992_MIN_PSUM_THRESHOLD_MSB1_REG                0x8E
#define LTC2992_MIN_PSUM_THRESHOLD_MSB_REG                 0x8F
#define LTC2992_MIN_PSUM_THRESHOLD_LSB_REG                 0x90
#define LTC2992_ALERT3_REG                                 0x91
#define LTC2992_FAULT3_REG                                 0x92
#define LTC2992_ALERT4_REG                                 0x93
#define LTC2992_FAULT4_REG                                 0x94
#define LTC2992_GPIO_STATUS_REG                            0x95
#define LTC2992_GPIO_IO_CONT_REG                           0x96
#define LTC2992_GPIO4_CFG_REG                              0x97
//----------------------------------------------------------------------
#define LTC2992_12BITS_MODE								   0
#define LTC2992_8BITS_MODE								   1
#define LTC2992_SENSE_RESISTOR_REG						   10e-3



typedef struct {
	float Voltage;
	float Delta_sense;
	float Power;
	float sense;
	uint8_t mode;
	uint8_t err;
} CONVERT_DATA;

extern CONVERT_DATA sensor_data;
//-----------------------------------------
void READ_POWER1_DATA(void);
void READ_VOLTAGE1_DATA(void);
void READ_DELTASENSE1_DATA(void);
void READ_SENSE1_DATA(void);
//------------------------------------------
void READ_POWER2_DATA(void);
void READ_VOLTAGE2_DATA(void);
void READ_DELTASENSE2_DATA(void);
void READ_SENSE2_DATA(void);
//------------------------------------------
void SETTING_LTC2922_MODE(uint8_t mode); // 8bits or 12 bits(DEFAULT)
void SETTING_LTC2992_CTRLA_REG(uint8_t offset_calibrate,uint8_t measurement_mode,uint8_t continue_scan,uint8_t snap_scan);
void SETTING_LTC2992_CTRLB_REG(uint8_t offset_calibrate,uint8_t measurement_mode,uint8_t continue_scan,uint8_t snap_scan);
//------------------------------------------
void LTC2922_CONVESIONMODE_CHECK(void);
void LTC2922_CONFIGURATION(void);
void DATA_Init(void);
void UPDATE_DATA(void);
#endif /* INC_LTC2922_H_ */
