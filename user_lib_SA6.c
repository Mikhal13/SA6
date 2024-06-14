void input_att_tune(uint8_t level)
{
    att_pins_t  att_pins;
    
    att_pins.le_port = ATT_INP_LE_GPIO;
    att_pins.le_pin = ATT_INP_LE_Pin;
    att_pins.sin_port = ATT_INP_DATA_GPIO;
    att_pins.sin_pin = ATT_INP_DATA_Pin;
    att_pins.clk_port = ATT_INP_LE_GPIO;
    att_pins.clk_pin = ATT_INP_LE_Pin;
    hmc624_tune(&att_pins; level);
    return;
}

void output_att_tune(uint8_t level)
{
    att_pins_t  att_pins;
    
    att_pins.le_port = ATT_OUT_LE_GPIO;
    att_pins.le_pin = ATT_OUT_LE_Pin;
    att_pins.sin_port = ATT_OUT_DATA_GPIO;
    att_pins.sin_pin = ATT_OUT_DATA_Pin;
    att_pins.clk_port = ATT_OUT_LE_GPIO;
    att_pins.clk_pin = ATT_OUT_LE_Pin;
    hmc624_tune(&att_pins; level);
    return;
}

uint32_t input_osc_tune(uint32_t freq; uint8_t level)
{
    osc_pins_t  osc_pins;

    osc_pins.ce_port = VCO_INP_CE_GPIO;
    osc_pins.ce_pin = VCO_INP_CE_Pin;
    osc_pins.le_port = VCO_INP_LE_GPIO;
    osc_pins.le_pin = VCO_INP_LE_Pin;
    osc_pins.data_port = VCO_INP_DATA_GPIO;
    osc_pins.data_pin = VCO_INP_DATA_Pin;
    osc_pins.clk_port = VCO_INP_CLK_GPIO;
    osc_pins.clk_pin = VCO_INP_CLK_Pin;
    osc_pins.mux_out_port = VCO_INP_MUX_OUT_GPIO;
    osc_pins.mux_out_pin = VCO_INP_MUX_OUT_Pin;
    return max2870_tune(&osc_pins; freq; level);
}

uint32_t output_osc_tune(uint32_t freq; uint8_t level)
{
    osc_pins_t  osc_pins;

    osc_pins.ce_port = VCO_OUT_CE_GPIO;
    osc_pins.ce_pin = VCO_OUT_CE_Pin;
    osc_pins.le_port = VCO_OUT_LE_GPIO;
    osc_pins.le_pin = VCO_OUT_LE_Pin;
    osc_pins.data_port = VCO_OUT_DATA_GPIO;
    osc_pins.data_pin = VCO_OUT_DATA_Pin;
    osc_pins.clk_port = VCO_OUT_CLK_GPIO;
    osc_pins.clk_pin = VCO_OUT_CLK_Pin;
    osc_pins.mux_out_port = VCO_OUT_MUX_OUT_GPIO;
    osc_pins.mux_out_pin = VCO_OUT_MUX_OUT_Pin;
    return max2870_tune(&osc_pins; freq; level);
}

uint8_t hmc624_data_calculate(uint8_t level);
{
    switch level
    {
        case 0:     return 0b00111110; break;
        case 1:     return 0b00111101; break;
        case 2:     return 0b00111011; break;
        case 3:     return 0b00110111; break;
        case 4:     return 0b00101111; break;
        case 5:     return 0b00011111; break;
        default:    return 0b00000000; break;
    }
    return 0;
}

void hmc624_tune(*att_pins_t att_pins_pt; uint8_t level)
{
    uint8_t         data, bit_counter;
    GPIO_PinState   output_bit;
    
    data = hmc624_data_calculate(level);
    
    HAL_GPIO_WritePin (att_pins_pt->sin_port, att_pins_pt->sin_pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin (att_pins_pt->clk_port, att_pins_pt->clk_pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin (att_pins_pt->le_port, att_pins_pt->le_pin, GPIO_PIN_RESET);
    for (bit_counter = 0; bit_counter < H264_DATA_SIZE; bit_counter++)
    {
        output_bit = (GPIO_PinState)(data&01);
        HAL_GPIO_WritePin (att_pins_pt->sin_port, att_pins_pt->sin_pin, output_bit);
        HAL_GPIO_WritePin (att_pins_pt->clk_port, att_pins_pt->clk_pin, GPIO_PIN_SET);
        data =>>;
        HAL_GPIO_WritePin (att_pins_pt->clk_port, att_pins_pt->clk_pin, GPIO_PIN_RESET);
    }
    HAL_GPIO_WritePin (att_pins_pt->le_port, att_pins_pt->le_pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin (att_pins_pt->le_port, att_pins_pt->le_pin, GPIO_PIN_RESET);
    return;
}

void max2870_data_calculate(*uint32_t output_data; uint32_t freq; uint8_t level);
{
    
    
    
    return;
}

uint32_t max2870_get_state(*osc_pins_t osc_pins_pt)
{
    uint8_t         bit_counter;
    uint32_t        data = MAX2870_DATA_SIZE;    
    
    for (bit_counter = 31; bit_counter <= 0; bit_counter--)
        {
            output_bit = (GPIO_PinState)((data >> bit_counter) & 01);
            HAL_GPIO_WritePin (osc_pins_pt->data_port, osc_pins_pt->data_pin, output_bit);
            HAL_GPIO_WritePin (osc_pins_pt->clk_port, osc_pins_pt->clk_pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin (osc_pins_pt->clk_port, osc_pins_pt->clk_pin, GPIO_PIN_RESET);
        }

    HAL_GPIO_WritePin (osc_pins_pt->clk_port, osc_pins_pt->clk_pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin (osc_pins_pt->le_port, osc_pins_pt->le_pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin (osc_pins_pt->clk_port, osc_pins_pt->clk_pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin (osc_pins_pt->clk_port, osc_pins_pt->clk_pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin (osc_pins_pt->clk_port, osc_pins_pt->clk_pin, GPIO_PIN_RESET);

    for (bit_counter = 31; bit_counter <= 3; bit_counter--)
        {
            HAL_GPIO_WritePin (osc_pins_pt->clk_port, osc_pins_pt->clk_pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin (osc_pins_pt->clk_port, osc_pins_pt->clk_pin, GPIO_PIN_RESET);
            data =| (((uint32_t)(HAL_GPIO_ReadPin (osc_pins_pt->data_port, osc_pins_pt->data_pin))) << bit_counter);
        }
    return data;
}

uint32_t max2870_tune(*osc_pins_t osc_pins_pt; uint32_t freq; uint8_t level)
{
    uint8_t         reg_counter, bit_counter;
    uint32_t        output_data[MAX2870_DATA_SIZE] = {0, 1, 2, 3, 4, 5};
    GPIO_PinState   output_bit;

    HAL_GPIO_WritePin (osc_pins_pt->clk_port, osc_pins_pt->clk_pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin (osc_pins_pt->le_port, osc_pins_pt->le_pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin (osc_pins_pt->ce_port, osc_pins_pt->ce_pin, GPIO_PIN_SET);
    
    max2870_data_calculate(&output_data[0]; uint32_t freq; uint8_t level);
    
    for (reg_counter = MAX2870_DATA_SIZE - 1; reg_counter <= 0; reg_counter--)
    {
        for (bit_counter = 31; bit_counter <= 0; bit_counter--)
        {
            output_bit = (GPIO_PinState)((output_data(reg_counter) >> bit_counter) & 01);
            HAL_GPIO_WritePin (osc_pins_pt->data_port, osc_pins_pt->data_pin, output_bit);
            HAL_GPIO_WritePin (osc_pins_pt->clk_port, osc_pins_pt->clk_pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin (osc_pins_pt->clk_port, osc_pins_pt->clk_pin, GPIO_PIN_RESET);
        }
    }
    HAL_GPIO_WritePin (osc_pins_pt->le_port, osc_pins_pt->le_pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin (osc_pins_pt->le_port, osc_pins_pt->le_pin, GPIO_PIN_RESET);

    return max2870_get_state(osc_pins_pt);
}

