#include "project.h"

void setColor(uint8 r, uint8 g, uint8 b) 
{
    LED_R_Write(r);
    LED_G_Write(g);
    LED_B_Write(b);
}

int main(void)
{
    SW_Tx_UART_Start();
    SW_Tx_UART_PutCRLF();
    SW_Tx_UART_PutString("Software Transmit UART");
    SW_Tx_UART_PutCRLF();
    SW_Tx_UART_PutString("Radyk Dmytro");
    SW_Tx_UART_PutCRLF();
    
    CyGlobalIntEnable;
    
    for(;;)
    {
        if (Button_Read() == 0) // кнопка натиснута
        {
            SW_Tx_UART_PutString("CYAN/Button pressed");
            SW_Tx_UART_PutCRLF();
            // Cyan
            setColor(1, 0, 0);
        }
        else // кнопка відпущена
        {
            SW_Tx_UART_PutString("PURPLE/Button released");
            SW_Tx_UART_PutCRLF();
            // Purple
            setColor(0, 1, 0);
        }
        
        CyDelay(500);
        setColor(1, 1, 1); // вимкнути (Black)
        CyDelay(500);
    }
}