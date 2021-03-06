#include "gtest/gtest.h"
#include "NRF24L01.h"

namespace NRF24L01_Create {

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
    nrf24l01::Nrf24l01 *handle = nrf24l01::Nrf24l01::CreateAndInitStatic(
            send_data,
            &ddr_cs,
            &port_cs,
            pin_cs,
            &ddr_ce,
            &port_ce,
            pin_ce);

    EXPECT_TRUE(NULL != handle);
}

TEST(NRF24L01_Create, pass_null_pointer_send_data)
{
    nrf24l01::Nrf24l01 *handle = nrf24l01::Nrf24l01::CreateAndInitStatic(
            NULL,
            &ddr_cs,
            &port_cs,
            pin_cs,
            &ddr_ce,
            &port_ce,
            pin_ce);

    EXPECT_TRUE(NULL == handle);
}

TEST(NRF24L01_Create, pass_null_pointer_port_cs)
{
    nrf24l01::Nrf24l01 *handle = nrf24l01::Nrf24l01::CreateAndInitStatic(
            send_data,
            &ddr_cs,
            NULL,
            pin_cs,
            &ddr_ce,
            &port_ce,
            pin_ce);

    EXPECT_TRUE(NULL == handle);
}

TEST(NRF24L01_Create, pass_null_pointer_ddr_cs)
{
    nrf24l01::Nrf24l01 *handle = nrf24l01::Nrf24l01::CreateAndInitStatic(
            send_data,
            NULL,
            &port_cs,
            pin_cs,
            &ddr_ce,
            &port_ce,
            pin_ce);

    EXPECT_TRUE(NULL == handle);
}

TEST(NRF24L01_Create, pass_null_pointer_ddr_ce)
{
    nrf24l01::Nrf24l01 *handle = nrf24l01::Nrf24l01::CreateAndInitStatic(
            send_data,
            &ddr_cs,
            &port_cs,
            pin_cs,
            NULL,
            &port_ce,
            pin_ce);

    EXPECT_TRUE(NULL == handle);
}

// This is a test for null pointer port ce
TEST(NRF24L01_Create, pass_null_pointer_port_ce)
{
    nrf24l01::Nrf24l01 *handle = nrf24l01::Nrf24l01::CreateAndInitStatic(
            send_data,
            &ddr_cs,
            &port_cs,
            pin_cs,
            &ddr_ce,
            NULL,
            pin_ce);

    EXPECT_TRUE(NULL == handle);
}

} // namespace NRF24L01_Create
