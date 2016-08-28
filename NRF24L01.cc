#include "NRF24L01.h"
#include "Nrf24l01Avr.h"

namespace nrf24l01 {

static Nrf24l01 object;

/*
 * Defult initialization of object.
 */
Nrf24l01::Nrf24l01(void)
    :
    send_byte_(NULL),
    pddr_cs_(NULL),
    pport_cs_(NULL),
    pin_cs_(0),
    pddr_ce_(NULL),
    pport_ce_(NULL),
    pin_ce_(0)
{
}

/*
 * Build Nrf24l01 driver.
 * Currently this function is building driver for avr.
 */
INrf24l01 *Nrf24l01::build(void) {

    if((NULL == this->send_byte_) ||
       (NULL == this->pddr_cs_)   ||
       (NULL == this->pport_cs_)  ||
       (NULL == this->pddr_ce_)   ||
       (NULL == this->pport_ce_)) {
        return NULL;
    }

    INrf24l01 *driver = new Nrf24l01Avr();

    return driver;
}

Nrf24l01 *Nrf24l01::CreateAndInitStatic(
        send_byte_t         send_byte,
        volatile uint8_t    *pddr_cs,
        volatile uint8_t    *pport_cs,
        uint8_t             pin_cs,
        volatile uint8_t    *pddr_ce,
        volatile uint8_t    *pport_ce,
        uint8_t             pin_ce)
{

    if ((send_byte == NULL) ||
        (pport_cs == NULL) ||
        (pddr_cs == NULL) ||
        (pddr_ce == NULL) ||
        (pport_ce == NULL)) {
        return NULL;
    }

    return &object;
}

} // namespace nrf24l01
