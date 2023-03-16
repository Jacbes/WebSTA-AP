#include "site.h"
#include "ap.h"

void app_main(void)
{
    start_ap();
    start_site();
}

// httpd_txrx: httpd_sock_err: error in recv : 104 (site down after time)