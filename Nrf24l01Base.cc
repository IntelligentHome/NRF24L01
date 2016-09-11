
#include "Nrf24l01Base.h"

namespace nrf24l01 {

NrfStatusRegister Nrf24l01Base::get_register_status(void) {
    NrfStatusRegister a;

    return a;
}

Status Nrf24l01Base::read(uint8_t payload_tab[], uint8_t payload_size) {
    return STATUS_SUCCESS;
}

Status Nrf24l01Base::write(uint8_t payload_tab[], uint8_t payload_size) {
    return STATUS_SUCCESS;
}

Status Nrf24l01Base::start_listening(void) {
    return STATUS_SUCCESS;
}

Status Nrf24l01Base::stop_listening(void) {
    return STATUS_SUCCESS;
}

INrf24l01 *Nrf24l01Base::init(void) {
    return NULL;
}

} // namespace nrf24l01
