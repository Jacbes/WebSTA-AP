#ifndef SITE_H
#define SITE_H

/* Simple HTTP Server Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include <esp_wifi.h>
#include <esp_event.h>
#include <esp_log.h>
#include <esp_system.h>
#include <nvs_flash.h>
#include <sys/param.h>
#include "nvs_flash.h"
#include "esp_netif.h"
#include "esp_eth.h"
#include "esp_tls_crypto.h"
#include <esp_http_server.h>

/* A simple example that demonstrates how to create GET and POST
 * handlers for the web server.
 */

esp_err_t hello_get_handler(httpd_req_t *req);
esp_err_t echo_post_handler(httpd_req_t *req);
esp_err_t http_404_error_handler(httpd_req_t *req, httpd_err_code_t err);
esp_err_t ctrl_put_handler(httpd_req_t *req);
httpd_handle_t start_webserver(void);
esp_err_t stop_webserver(httpd_handle_t server);
void connect_handler(void* arg, esp_event_base_t event_base,
                            int32_t event_id, void* event_data);
void start_site(void);

#define INDEX_HTML "<html>\
<head></head>\
<body>\
  <form action=\"http://192.168.0.1/echo\" id=\"wifiform\">\
	<input type=\"text\" name=\"ssid\" value=\"\" placeholder=\"SSID\"/>\
	<input type=\"text\" name=\"password\" value=\"\" placeholder=\"Password\"/>\
    <input type=\"submit\" value=\"Submit\"/>\
  </form>\
  <script>\
    document.getElementById(\"wifiform\").addEventListener(\"submit\", submitForm);\
    function submitForm(event) {\
    	event.preventDefault();\
    	let formData = new FormData(event.target);\
    	let obj = {};\
    	formData.forEach((value, key) => obj[key] = value);\
    	let request = new Request(event.target.action, {\
        	method: 'POST',\
        	body: JSON.stringify(obj),\
        	headers: {\
            	'Content-Type': 'application/json',\
        	},\
    	});\
    	fetch(request)\
	}\
  </script>\
</html>\
"

#endif // SITE_h