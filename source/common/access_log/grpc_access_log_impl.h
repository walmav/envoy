#pragma once

#include "envoy/access_log/access_log.h"

#include "api/filter/accesslog/accesslog.pb.h"

namespace Envoy {
namespace AccessLog {

/**
 * Access log Instance that streams HTTP logs over gRPC.
 */
class HttpGrpcAccessLog : public Instance {
public:
  HttpGrpcAccessLog(FilterPtr&& filter,
                    const envoy::api::v2::filter::accesslog::HttpGrpcAccessLogConfig& config);

  // AccessLog::Instance
  void log(const Http::HeaderMap* request_headers, const Http::HeaderMap* response_headers,
           const RequestInfo& request_info) override;

private:
  FilterPtr filter_;
};

} // namespace AccessLog
} // namespace Envoy
