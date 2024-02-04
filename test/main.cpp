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

#include <unistd.h>  //optarg 
#include <stdlib.h>  //malloc, free
#include <stdio.h>   //printf
#include <string.h>  //memset
#include <stdbool.h> //true, false
#include <sys/types.h>
#include <vector>
#include <tuple>
#include "vtz_logger/common/logging.h"
//#include "vtz_bit_manipulator/bit_manipulator.h"
#include "vtz_network_sender/network_sender.h"


int main (int argc, char **args) {
  LOG(INFO) << "[Test] Nework Domain Sender....start";
  vtz::network_sender::NetworkSender* ns = new vtz::network_sender::NetworkSender();
  ns->StartTCPUnixDomainSocket(NULL);
  LOG(INFO) << "[Test] Nework Domain Sender....finish";
  return 0;
}
