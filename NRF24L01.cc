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

    if ((send_byte == NULL) ||
        (pport_cs == NULL) ||
        (pddr_cs == NULL) ||
        (pddr_ce == NULL) ||
        (pport_ce == NULL)) {
        return NULL;
    }

    return &object;
}

} // namespace NRF24L01
