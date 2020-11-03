
#include "hx_drv_tflm.h"

int main(void)
{
	hx_drv_uart_initial();

	hx_drv_uart_print("Hello world\r\n");

	while(1){};
}
