#include "gtest/gtest.h"
#include "NRF24L01.h"

uint8_t port_ce = 0xB0;
uint8_t ddr_ce  = 0xB1;
uint8_t pin_ce  = 2;
uint8_t port_cs = 0xC0;
uint8_t ddr_cs  = 0xC1;
uint8_t pin_cs  = 4;

uint8_t send_data(uint8_t data) {
    return 0;
}

TEST(NRF24L01_Create, successful_init)
{
    NRF24L01::NRF24L01 *handle = NRF24L01::NRF24L01::CreateAndInitStatic(
            send_data,
            &port_ce,
            &ddr_ce,
            pin_ce,
            &port_cs,
            &ddr_cs,
            pin_cs);

    EXPECT_TRUE(NULL != handle);
}
/*
TEST(NRF24L01_Create, pass_null_pointer_send_data)
{
    NRF24L01::NRF24L01 *handle = NRF24L01::NRF24L01::CreateAndInitStatic(
            NULL,
            &port_ce,
            &ddr_ce,
            pin_ce,
            &port_cs,
            &ddr_cs,
            pin_cs);

    EXPECT_TRUE(NULL == handle);
}*/
