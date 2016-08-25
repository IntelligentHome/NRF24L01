

#pragma one

#include <stdint.h>

#ifndef NULL
// Define NULL if unknown.
#define NULL 0
#endif

namespace nrf24l01 {

enum Status
{
    STATUS_SUCCESS = 0,
    STATUS_FAILURE,
    STATUS_PTR_ERROR,
    NUM_OF_STATUS,
};

union NrfStatusRegister
{
    struct
    {
        uint8_t tx_full         : 1,
                rx_pipe_no      : 3,
                max_rt          : 1,
                tx_data_ready   : 1,
                rx_data_ready   : 1,
                reserved        : 1;
    };

    uint8_t raw_data;
};

typedef uint8_t (*send_byte_t) (uint8_t data);

// Interface for all NRF24L01 implementations
class INrf24l01
{
    public:
        virtual NrfStatusRegister get_register_status(void) = 0;

        virtual Status read(uint8_t payload_tab[], uint8_t payload_size) = 0;
        virtual Status write(uint8_t payload_tab[], uint8_t payload_size) = 0;

        virtual Status start_listening(void) = 0;
        virtual Status stop_listening(void) = 0;
};

class Nrf24l01 {
    public:
        static Nrf24l01 *CreateAndInitStatic(
                send_byte_t         send_byte,
                volatile uint8_t    *pddr_cs,
                volatile uint8_t    *pport_cs,
                uint8_t             pin_cs,
                volatile uint8_t    *pddr_ce,
                volatile uint8_t    *pport_ce,
                uint8_t             pin_ce);

        void Destroy(Nrf24l01 *handle);

    private:

        send_byte_t	_send_byte;

        volatile uint8_t    *pddr_cs_;
        volatile uint8_t    *pport_cs_;
        uint8_t             pin_cs_;
        volatile uint8_t    *pddr_ce_;
        volatile uint8_t    *pport_ce_;
        uint8_t             pin_ce_;
};

} // namespace nrf24l01
