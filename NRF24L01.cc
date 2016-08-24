#include "NRF24L01.h"

namespace NRF24L01 {

static NRF24L01 object;

NRF24L01 *NRF24L01::CreateAndInitStatic(
        send_byte_t         send_byte,
        volatile uint8_t    *pddr_cs,
        volatile uint8_t    *pport_cs,
        uint8_t             pin_cs,
        volatile uint8_t    *pddr_ce,
        volatile uint8_t    *pport_ce,
        uint8_t             pin_ce)
{


    return &object;
}

} // namespace NRF24L01
