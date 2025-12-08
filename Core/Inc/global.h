/*
 * global.h
 *
 *  Created on: Aug 23, 2023
 *      Author: User
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

enum BOOL {
	false,
	true
};

extern CAN_HandleTypeDef hcan;
extern I2C_HandleTypeDef hi2c1;


#endif /* INC_GLOBAL_H_ */
