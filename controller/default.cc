#include "workflow/HttpMessage.h"
#include "workflow/HttpUtil.h"
#include "workflow/WFFacilities.h"
#include "workflow/WFHttpServer.h"
#include "workflow/WFServer.h"

#include "nlohmann/json.hpp"

#include "../define.cc"

using json = nlohmann::json;

void Response(RESPONSE *res, int code, std::string msg, json data) {
    json body = {
        {"code", code},
        {"msg", msg},
        {"data", data}
    };
    res->append_output_body(body.dump());
}

void ControllerIndex(REQUEST *req, RESPONSE *res) {
    Response(res, 0, "here is index");
}

void ControllerNotFound(REQUEST *req, RESPONSE *res) {
    res->set_status_code("404");
    Response(res, 404, "page not found");
}