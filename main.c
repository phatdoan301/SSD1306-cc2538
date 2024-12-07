#include "contiki.h"
#include "SSD_1306_CC2538.h"
#include <stdio.h>
#include "horse_anim.h"
#include "bitmap.h"
PROCESS(ssd1306_demo_process, "SSD1306 Demo Process");
AUTOSTART_PROCESSES(&ssd1306_demo_process);

PROCESS_THREAD(ssd1306_demo_process, ev, data)
{
  PROCESS_BEGIN();

  SSD1306_Name mySSD1306 = {
    .I2C_Config.SDA_port = 0,
    .I2C_Config.SDA_pin = 6,
    .I2C_Config.SCL_port = 0,
    .I2C_Config.SCL_pin = 5,
    .I2C_Config.bus_speed = 400000
  };


  if (SSD1306_Init(&mySSD1306)) {
    printf("SSD1306 initialized successfully.\r\n");
  } else {
    printf("SSD1306 initialization failed.\r\n");
    PROCESS_EXIT();
  }

  SSD1306_DrawBitmap(&mySSD1306, 2, 0, images, 128, 64, 1);
  SSD1306_UpdateScreen(&mySSD1306);
  clock_wait(CLOCK_SECOND * 5);
  SSD1306_Clear(&mySSD1306);
  SSD1306_UpdateScreen(&mySSD1306);
  while(1)
  {
  	  SSD1306_Clear(&mySSD1306);
	  SSD1306_DrawBitmap(&mySSD1306, 2, 0, horse1, 128, 64, 1);
	  SSD1306_UpdateScreen(&mySSD1306);

	  SSD1306_Clear(&mySSD1306);
	  SSD1306_DrawBitmap(&mySSD1306, 2, 0, horse2, 128, 64, 1);
	  SSD1306_UpdateScreen(&mySSD1306);

	  SSD1306_Clear(&mySSD1306);
	  SSD1306_DrawBitmap(&mySSD1306, 2, 0, horse3, 128, 64, 1);
	  SSD1306_UpdateScreen(&mySSD1306);

	  SSD1306_Clear(&mySSD1306);
	  SSD1306_DrawBitmap(&mySSD1306, 2, 0, horse4, 128, 64, 1);
	  SSD1306_UpdateScreen(&mySSD1306);

	  SSD1306_Clear(&mySSD1306);
	  SSD1306_DrawBitmap(&mySSD1306, 2, 0, horse5, 128, 64, 1);
	  SSD1306_UpdateScreen(&mySSD1306);

	  SSD1306_Clear(&mySSD1306);
	  SSD1306_DrawBitmap(&mySSD1306, 2, 0, horse6, 128, 64, 1);
	  SSD1306_UpdateScreen(&mySSD1306);

	  SSD1306_Clear(&mySSD1306);
	  SSD1306_DrawBitmap(&mySSD1306, 2, 0, horse7, 128, 64, 1);
	  SSD1306_UpdateScreen(&mySSD1306);

	  SSD1306_Clear(&mySSD1306);
	  SSD1306_DrawBitmap(&mySSD1306, 2, 0, horse8, 128, 64, 1);
	  SSD1306_UpdateScreen(&mySSD1306);

	  SSD1306_Clear(&mySSD1306);
	  SSD1306_DrawBitmap(&mySSD1306, 2, 0, horse9, 128, 64, 1);
	  SSD1306_UpdateScreen(&mySSD1306);

	  SSD1306_Clear(&mySSD1306);
	  SSD1306_DrawBitmap(&mySSD1306, 2, 0, horse10, 128, 64, 1);
	  SSD1306_UpdateScreen(&mySSD1306);
  }

  // clock_wait(CLOCK_SECOND * 5);
  // SSD1306_OFF(&mySSD1306);
  // printf("SSD1306 display turned off.\r\n");
  PROCESS_END();
}
