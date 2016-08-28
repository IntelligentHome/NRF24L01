#include "Nrf24l01Avr.h"

namespace nrf24l01 {

Status Nrf24l01Avr::read(uint8_t payload_tab[], uint8_t payload_size) {
    return STATUS_SUCCESS;
}

Status Nrf24l01Avr::write(uint8_t payload_tab[], uint8_t paylaod_size) {
    return STATUS_SUCCESS;
}

Status Nrf24l01Avr::start_listening(void) {
    return STATUS_SUCCESS;
}

Status Nrf24l01Avr::stop_listening(void) {
    return STATUS_SUCCESS;
}

INrf24l01 *Nrf24l01Avr::init(void) {
    return NULL;
}

} // namespace nrf24l01


