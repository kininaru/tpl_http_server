#include "workflow/HttpMessage.h"
#include "workflow/HttpUtil.h"
#include "workflow/WFFacilities.h"
#include "workflow/WFHttpServer.h"
#include "workflow/WFServer.h"

#include "nlohmann/json.hpp"

#include "../define.cc"

using json = nlohmann::json;

void response(RESPONSE *res, int code, std::string msg) {
    json body = { {"code", code}, {"msg", msg} };
    res->append_output_body(body.dump());
}

// response deletes *data
void response(RESPONSE *res, int code, std::string msg, json *data) {
    json body = { {"code", code}, {"msg", msg} };
    if (data) body["data"] = *data;
    res->append_output_body(body.dump());
    if (data) delete data;
}

void response(RESPONSE *res, int code, std::string msg, json data) {
    json body = { {"code", code}, {"msg", msg}, {"data", data} };
    res->append_output_body(body.dump());
}

void controller_index(REQUEST *req, RESPONSE *res) {
    response(res, 0, "here is index", nullptr);
}

void controller_not_found(REQUEST *req, RESPONSE *res) {
    res->set_status_code("404");
    response(res, 404, "page not found", nullptr);
}