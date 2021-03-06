/*
 * Copyright (c) 2017 Spotify AB.
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */
#pragma once

#include <memory>

#include <NFDecoder/Manifest.h>

#include <NFHTTP/Client.h>

namespace nativeformat {
namespace decoder {

class ManifestFactory {
 public:
  typedef std::function<void(std::shared_ptr<Manifest> decrypter)> CREATE_MANIFEST_CALLBACK;

  virtual void createManifest(const std::string &path,
                              const CREATE_MANIFEST_CALLBACK &create_manifest_callback,
                              const Manifest::ERROR_MANIFEST_CALLBACK &error_manifest_callback) = 0;
};

extern std::shared_ptr<ManifestFactory> createManifestFactory(
    std::shared_ptr<http::Client> client = nullptr);

}  // namespace decoder
}  // namespace nativeformat
