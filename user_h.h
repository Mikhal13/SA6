// 
#define H264_DATA_SIZE 6
#define MAX2870_DATA_SIZE 6

// Attenuator driver pins structure
typedef struct
{
    GPIO_TypeDef*   le_port;
    uint16          le_pin;
    GPIO_TypeDef*   sin_port;
    uint16          sin_pin;
    GPIO_TypeDef*   clk_port;
    uint16          clk_pin;
} att_pins_t;

// Oscillator driver pins structure
typedef struct
{
    GPIO_TypeDef*   ce_port;
    uint16          ce_pin;
    GPIO_TypeDef*   le_port;
    uint16          le_pin;
    GPIO_TypeDef*   data_port;
    uint16          data_pin;
    GPIO_TypeDef*   clk_port;
    uint16          clk_pin;
    GPIO_TypeDef*   mux_out_port;
    uint16          mux_out_pin;
} osc_pins_t;