

#pragma one

#include <stdint.h>

#ifndef NULL
#define NULL 0
#endif

namespace NRF24L01 {

typedef uint8_t (*send_byte_t) (uint8_t data);

class NRF24L01 {
    public:
        static NRF24L01 *CreateAndInitStatic(
                send_byte_t         send_byte,
                volatile uint8_t    *pddr_cs,
                volatile uint8_t    *pport_cs,
                uint8_t             pin_cs,
                volatile uint8_t    *pddr_ce,
                volatile uint8_t    *pport_ce,
                uint8_t             pin_ce);

        void Destroy(NRF24L01 *handle);

    private:

        send_byte_t	_send_byte;

        volatile uint8_t    *pddr_cs_;
        volatile uint8_t    *pport_cs_;
        uint8_t             pin_cs_;
        volatile uint8_t    *pddr_ce_;
        volatile uint8_t    *pport_ce_;
        uint8_t             pin_ce_;
};

} // namespace NRF24L01
