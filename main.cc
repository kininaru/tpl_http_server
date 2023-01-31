#include <arpa/inet.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string>

#include "workflow/HttpMessage.h"
#include "workflow/HttpUtil.h"
#include "workflow/WFFacilities.h"
#include "workflow/WFHttpServer.h"
#include "workflow/WFServer.h"

#include "./router/init.cc"

int main() {
  InitRouter();
  WFHttpServer server(Entrance);

  if (server.start(8080)) exit(1);
  printf("server started");
  
  getchar();
  server.stop();
  return 0;
}
