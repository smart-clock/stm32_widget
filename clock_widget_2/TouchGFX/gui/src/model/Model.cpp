#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#ifndef SIMULATOR
#include "main.h"
#include "cmsis_os2.h"
#include <cstring>

extern "C"
{
	extern osMessageQueueId_t uartQueueHandle;
	uartData_t *uartData_r;
	extern void toggleBuzzer(void);
	extern void toggleBuzzerOff(void);
}
#endif

Model::Model() : modelListener(0)
{
	this->hour = 0;
	this->minute = 0;
}

void Model::tick()
{
#ifndef SIMULATOR
	if(osMessageQueueGetCount(uartQueueHandle) > 0)
	{
		if(osMessageQueueGet(uartQueueHandle, &uartData_r, 0, 0) == osOK)
		{
			strncpy(RData, uartData_r->Data, uartData_r->size);
			modelListener->uart_Data(RData);
		}
	}
#endif
}

void Model::hwToggleBuzzer()
{
#ifndef SIMULATOR
	toggleBuzzer();
#endif /* SIMULATOR */
}

void Model::hwToggleBuzzerOff()
{
#ifndef SIMULATOR
	toggleBuzzerOff();
#endif /* SIMULATOR */
}