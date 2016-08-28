#include "gtest/gtest.h"
#include "NRF24L01.h"

namespace NRF24L01_Avr_Build {

uint8_t port_ce = 0xB0;
uint8_t ddr_ce	= 0xB1;
uint8_t pin_ce	= 2;
uint8_t port_cs	= 0xC0;
uint8_t ddr_cs	= 0xC1;
uint8_t pin_cs	= 4;

uint8_t send_data(uint8_t data) {
    return 0;
}

TEST(NRF24L01_Avr_Build, successful_build_driver)
{
    nrf24l01::Nrf24l01 Builder;

    nrf24l01::INrf24l01 *driver = Builder.
                                    transport_callback(send_data)->
                                    ddr_cs(&ddr_cs)->
                                    port_cs(&port_cs)->
                                    pin_cs(pin_cs)->
                                    ddr_ce(&ddr_ce)->
                                    port_ce(&port_ce)->
                                    pin_ce(pin_ce)->
                                    build();

    EXPECT_TRUE(NULL != driver);

    delete driver;
}

TEST(NRF24L01_Avr_Build, lack_or_any_data)
{
    nrf24l01::Nrf24l01 Builder;

    nrf24l01::INrf24l01 *driver = Builder.build();

    EXPECT_TRUE(NULL == driver);

    delete driver;
}

TEST(NRF24L01_Avr_Build, null_pointer_send_byte)
{
    nrf24l01::Nrf24l01 Builder;

    nrf24l01::INrf24l01 *driver = Builder.
                                    transport_callback(NULL)->
                                    ddr_cs(&ddr_cs)->
                                    port_cs(&port_cs)->
                                    pin_cs(pin_cs)->
                                    ddr_ce(&ddr_ce)->
                                    port_ce(&port_ce)->
                                    pin_ce(pin_ce)->
                                    build();

    EXPECT_TRUE(NULL == driver);
}

TEST(NRF24L01_Avr_Build, null_pointer_ddr_cs)
{
    nrf24l01::Nrf24l01 Builder;

    nrf24l01::INrf24l01 *driver = Builder.
                                    transport_callback(send_data)->
                                    ddr_cs(NULL)->
                                    port_cs(&port_cs)->
                                    pin_cs(pin_cs)->
                                    ddr_ce(&ddr_ce)->
                                    port_ce(&port_ce)->
                                    pin_ce(pin_ce)->
                                    build();

    EXPECT_TRUE(NULL == driver);

    delete driver;
}

TEST(NRF24L01_Avr_Build, null_pointer_port_cs)
{
    nrf24l01::Nrf24l01 Builder;

    nrf24l01::INrf24l01 *driver = Builder.
                                    transport_callback(send_data)->
                                    ddr_cs(&ddr_cs)->
                                    port_cs(NULL)->
                                    pin_cs(pin_cs)->
                                    ddr_ce(&ddr_ce)->
                                    port_ce(&port_ce)->
                                    pin_ce(pin_ce)->
                                    build();

    EXPECT_TRUE(NULL == driver);

    delete driver;
}

TEST(NRF24L01_Avr_Build, null_pointer_ddr_ce)
{
    nrf24l01::Nrf24l01 Builder;

    nrf24l01::INrf24l01 *driver = Builder.
                                    transport_callback(send_data)->
                                    ddr_cs(&ddr_cs)->
                                    port_cs(&port_cs)->
                                    pin_cs(pin_cs)->
                                    ddr_ce(NULL)->
                                    port_ce(&port_ce)->
                                    pin_ce(pin_ce)->
                                    build();

    EXPECT_TRUE(NULL == driver);

    delete driver;
}

TEST(NRF24L01_Avr_Build, null_pointer_port_ce)
{
    nrf24l01::Nrf24l01 Builder;

    nrf24l01::INrf24l01 *driver = Builder.
                                    transport_callback(send_data)->
                                    ddr_cs(&ddr_cs)->
                                    port_cs(&port_cs)->
                                    pin_cs(pin_cs)->
                                    ddr_ce(&ddr_ce)->
                                    port_ce(NULL)->
                                    pin_ce(pin_ce)->
                                    build();

    EXPECT_TRUE(NULL == driver);

    delete driver;
}

} // namespace NRF24L01_Avr_Build
