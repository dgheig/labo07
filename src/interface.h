#ifndef INTERFACE_H
#define INTERFACE_H

const char RESTART_CHAR   = 'O';
const char STOP_CHAR      = 'N';

/**
 * @return true if the user has inputted RESTART_CHAR and false if the user has inputted STOP_CHAR
 * @brief This function keeps looking while the user enters anything other than RESTART_CHAR or STOP_CHAR
 */
bool ask_for_restart();

#endif // INTERFACE_H