/* Copyright 2018 Hobum (Vincent) Kwon. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include <sys/time.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <iostream>
#include <stack>
#include <cmath> 
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>

#include "vtz_logger/common/logging.h"
#include "vtz_logger/common/macros.h"
#include "vtz_logger/common/integral_type.h"
#include "network_sender.h"

#define VTZ_NETWORK_DOMAIN_FILE_NAME "/tmp/somefile4"
#define BUF_SIZE 10
#define PORT_NUM 50002
#define SV_SOCK_PATH "/tmp/ud_ucase"

namespace vtz {
namespace network_sender {

 // Type: NETWORK, DOMAIN
 NetworkSender::NetworkSender() {

 }

 void *NetworkSender::StartTCPUnixDomainSocket(void *) {
   int client_fd;
   sockaddr_un client_addr;  
   sockaddr_un server_addr;  
   LOG(INFO) << "[client] socket create.";
   client_fd = socket(AF_UNIX, SOCK_STREAM, IPPROTO_IP); // SOCK_DGRAM, SOCK_STREAM
   client_addr.sun_family = AF_UNIX;
   strcpy(client_addr.sun_path, VTZ_NETWORK_DOMAIN_FILE_NAME);
   LOG(INFO) << "[client] connect.";

   if (connect(client_fd, reinterpret_cast<sockaddr *>(&client_addr), sizeof(client_addr)) == -1)
   {
     perror("connection failed");
     exit(1);
   }
   sleep(1);

  char buffer[1024];
  LOG(INFO) << "[client] send Hello.";
  int numBytes = 1024;
  strncpy(buffer, "send Hello", 1024);

  memset(&server_addr, 0, sizeof(struct sockaddr_un));
  server_addr.sun_family = AF_UNIX;
  strncpy(server_addr.sun_path, SV_SOCK_PATH, sizeof(server_addr.sun_path) - 1);

  send(client_fd, "Hello", sizeof("Hello")+1, 0);
  recv(client_fd, buffer, 1024, 0);
  LOG(INFO) << "[client] received " << buffer;
  LOG(INFO) << "[client] finish.";
 }

}  // network_sender
}  // vtz
