
#pragma once

#include "Nrf24l01Base.h"

namespace nrf24l01 {

class Nrf24l01Avr : public Nrf24l01Base
{
public:
    virtual NrfStatusRegister get_register_status(void);

    virtual Status read(uint8_t payload_tab[], uint8_t payload_size);

    virtual Status write(uint8_t payload_tab[], uint8_t payload_size);

    virtual Status start_listening(void);
    virtual Status stop_listening(void);

    virtual INrf24l01 *init(void);

    virtual ~Nrf24l01Avr() {}
};

} // namespace nrf24l01
