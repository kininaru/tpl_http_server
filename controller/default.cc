#include "workflow/HttpMessage.h"
#include "workflow/HttpUtil.h"
#include "workflow/WFFacilities.h"
#include "workflow/WFHttpServer.h"
#include "workflow/WFServer.h"

#include "../define.cc"

void ControllerIndex(REQUEST *req, RESPONSE *res) {
    res->append_output_body("this is index");
}

void ControllerNotFound(REQUEST *req, RESPONSE *res) {
    res->set_status_code("404");
    res->append_output_body("api not found");
}