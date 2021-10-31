#include <iostream>
#include <chrono>
#include <thread>
#include "NTPClient.h"

int main(){
    int64_t ntp_time1, ntp_time2, local_time1, local_time2, ntp_diff, local_diff;
    NTPClient client("ntp.ubuntu.com");
    int delay;
    std::cout << "This program counts difference between NTP-server and local time in ms over a given time period.\nInput a preferable time delay in ms: ";
    std::cin >> delay;
    ntp_time1 = client.unix_millis();

    local_time1 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    std::this_thread::sleep_for(std::chrono::milliseconds(delay));

    ntp_time2 = client.unix_millis();

    local_time2 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    ntp_diff = ntp_time2 -ntp_time1;
    local_diff = local_time2 - local_time1;
    std::cout << ntp_diff - local_diff << "\n";
    return 0;
}