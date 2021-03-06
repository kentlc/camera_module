/**
 * @file tx_pipe.hpp 
 * @brief Transmitter pipe class definition.
 */

#ifndef DEF_TX_PIPE_HPP
#define DEF_TX_PIPE_HPP

#include <fstream>
#include <string>

class TXPipe {
    public: 
        TXPipe(const std::string &pipefile); 
        ~TXPipe();

        void send(const char *data, int dataSize);
    private:
        std::filebuf *m_pipe; 
};

#endif  /* DEF_TX_PIPE_HPP */

