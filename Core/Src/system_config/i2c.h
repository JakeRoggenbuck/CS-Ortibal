/*
 * i2c.h
 *
 *  Created on: Apr 29, 2023
 *      Author: Tim S. , nithinsenthil , Raphael
 */

#ifndef SRC_I2C_H_
#define SRC_I2C_H_

#include "stm32l476xx.h"
#include "gpio.h"

//Macros
#define OP1_I2C2 GPIOF, 1, GPIOF, 0

/**
 * Sets the line mode of a GPIO pin for SoftI2C communication.
 *
 * @param port The GPIO port to set the line mode for.
 * @param pin The pin number to set the line mode for.
 * @param deassert_line A boolean indicating whether to deassert the line or not.
 *                      If true, the line is deasserted. If false, the line is set to output mode.
 *
 * @returns None
 */
void softi2c_line_mode(GPIO_TypeDef * port, int pin, bool deassert_line);

/**
 * Initializes the software implementation of the I2C protocol.
 *
 * @param scl_port The GPIO port for the SCL line.
 * @param scl_pin The GPIO pin for the SCL line.
 * @param sda_port The GPIO port for the SDA line.
 * @param sda_pin The GPIO pin for the SDA line.
 *
 * @returns None
 */
void init_softi2c(GPIO_TypeDef * scl_port, int scl_pin, GPIO_TypeDef * sda_port, int sda_pin);

/**
 * Delays the execution of the program for a short period of time to allow for proper timing in the SoftI2C protocol.
 *
 * @returns None
 */
void softi2c_delay();

/**
 * Generates the start signal for a software-based I2C communication.
 *
 * @param scl_port The GPIO port for the SCL line.
 * @param scl_pin The GPIO pin for the SCL line.
 * @param sda_port The GPIO port for the SDA line.
 * @param sda_pin The GPIO pin for the SDA line.
 *
 * @returns None
 */
void softi2c_sig_start(GPIO_TypeDef * scl_port, int scl_pin, GPIO_TypeDef * sda_port, int sda_pin);

/**
 * Generates a repeated start signal for the SoftI2C protocol.
 *
 * @param scl_port The GPIO port for the SCL line.
 * @param scl_pin The GPIO pin for the SCL line.
 * @param sda_port The GPIO port for the SDA line.
 * @param sda_pin The GPIO pin for the SDA line.
 *
 * @returns None
 */
void softi2c_sig_repeated_start(GPIO_TypeDef * scl_port, int scl_pin, GPIO_TypeDef * sda_port, int sda_pin);

/**
 * Sends a stop signal on the I2C bus using software implementation.
 *
 * @param scl_port The GPIO port of the SCL line.
 * @param scl_pin The GPIO pin of the SCL line.
 * @param sda_port The GPIO port of the SDA line.
 * @param sda_pin The GPIO pin of the SDA line.
 *
 * @returns None
 */
void softi2c_sig_stop(GPIO_TypeDef * scl_port, int scl_pin, GPIO_TypeDef * sda_port, int sda_pin);

/**
 * Sends an 8-bit data over a software I2C bus.
 *
 * @param scl_port The GPIO port of the SCL line.
 * @param scl_pin The GPIO pin of the SCL line.
 * @param sda_port The GPIO port of the SDA line.
 * @param sda_pin The GPIO pin of the SDA line.
 * @param data8 The 8-bit data to be sent.
 *
 * @returns None
 */
void softi2c_send8(GPIO_TypeDef * scl_port, int scl_pin, GPIO_TypeDef * sda_port, int sda_pin, int data8);

/**
 * Reads 8 bits of data from a SoftI2C bus.
 *
 * @param scl_port The GPIO port of the SCL line.
 * @param scl_pin The GPIO pin of the SCL line.
 * @param sda_port The GPIO port of the SDA line.
 * @param sda_pin The GPIO pin of the SDA line.
 *
 * @returns The 8 bits of data read from the SoftI2C bus.
 */
int softi2c_read8(GPIO_TypeDef * scl_port, int scl_pin, GPIO_TypeDef * sda_port, int sda_pin);

/**
 * Sends a NACK (Not Acknowledged) signal over a software I2C bus.
 *
 * @param scl_port The GPIO port of the SCL line.
 * @param scl_pin The GPIO pin of the SCL line.
 * @param sda_port The GPIO port of the SDA line.
 * @param sda_pin The GPIO pin of the SDA line.
 *
 * @returns None
 */
void softi2c_send_nack(GPIO_TypeDef * scl_port, int scl_pin, GPIO_TypeDef * sda_port, int sda_pin);

/**
 * Reads a single byte from a SoftI2C device with a NACK signal.
 *
 * @param scl_port The GPIO port of the SCL line.
 * @param scl_pin The GPIO pin of the SCL line.
 * @param sda_port The GPIO port of the SDA line.
 * @param sda_pin The GPIO pin of the SDA line.
 *
 * @returns The byte read from the SoftI2C device.
 */
int softi2c_read_nack(GPIO_TypeDef * scl_port, int scl_pin, GPIO_TypeDef * sda_port, int sda_pin);

/**
 * Writes data to a register of a device using software I2C protocol.
 *
 * @param scl_port The GPIO port of the SCL pin.
 * @param scl_pin The pin number of the SCL pin.
 * @param sda_port The GPIO port of the SDA pin.
 * @param sda_pin The pin number of the SDA pin.
 * @param device_addr The address of the device to write to.
 * @param reg_addr The address of the register to write to.
 * @param data The data to write to the register.
 *
 * @returns The number of NACKs received during the write operation.
 */
int softi2c_write_reg(GPIO_TypeDef * scl_port, int scl_pin, GPIO_TypeDef * sda_port, int sda_pin, int device_addr, int reg_addr, int data);

/**
 * Reads a register from a device using software I2C protocol.
 *
 * @param scl_port The GPIO port of the SCL pin.
 * @param scl_pin The GPIO pin number of the SCL pin.
 * @param sda_port The GPIO port of the SDA pin.
 * @param sda_pin The GPIO pin number of the SDA pin.
 * @param device_addr The address of the device to read from.
 * @param reg_addr The address of the register to read.
 *
 * @returns The value of the register read from the device.
 */
int softi2c_read_reg(GPIO_TypeDef * scl_port, int scl_pin, GPIO_TypeDef * sda_port, int sda_pin, int device_addr, int reg_addr);

/**
 * Probes a device on the I2C bus using software I2C.
 *
 * @param scl_port The GPIO port for the SCL pin.
 * @param scl_pin The GPIO pin for the SCL pin.
 * @param sda_port The GPIO port for the SDA pin.
 * @param sda_pin The GPIO pin for the SDA pin.
 * @param device_addr The address of the device to probe.
 *
 * @returns True if the device is present on the bus, false otherwise.
 */
bool softi2c_probe(GPIO_TypeDef * scl_port, int scl_pin, GPIO_TypeDef * sda_port, int sda_pin, int device_addr);

/**
 * Reads a 16-bit register value from a device using software I2C protocol.
 *
 * @param scl_port The GPIO port of the SCL pin.
 * @param scl_pin The pin number of the SCL pin.
 * @param sda_port The GPIO port of the SDA pin.
 * @param sda_pin The pin number of the SDA pin.
 * @param device_addr The address of the device to read from.
 * @param high_reg_addr The address of the high byte of the register to read.
 * @param low_reg_addr The address of the low byte of the register to read.
 *
 * @returns The 16-bit register value read from the device.
 */
int16_t softi2c_read_reg_hl(GPIO_TypeDef * scl_port, int scl_pin, GPIO_TypeDef * sda_port, int sda_pin, int device_addr, int high_reg_addr, int low_reg_addr);

#endif /* SRC_I2C_H_ */
