#include <string>
#include <map>
#include "workflow/HttpMessage.h"
#include "workflow/HttpUtil.h"
#include "workflow/WFFacilities.h"
#include "workflow/WFHttpServer.h"
#include "workflow/WFServer.h"

#include "../controller/default.cc"
#include "../define.cc"

std::map<std::string, std::function<void (REQUEST *, RESPONSE *)>> router;

void InitRouter() {
    router["/"] = controller_index;
}

void Entrance(WFHttpTask *server_task) {
    REQUEST *req = server_task->get_req();
    RESPONSE *res = server_task->get_resp();
    const char *path = req->get_request_uri();

    std::function<void (REQUEST *, RESPONSE *)> controller = controller_not_found;
    if (router.count(path)) controller = router[path];

    controller(req, res);
}