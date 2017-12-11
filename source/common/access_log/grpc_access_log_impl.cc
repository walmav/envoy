#include "common/access_log/grpc_access_log_impl.h"

namespace Envoy {
namespace AccessLog {

HttpGrpcAccessLog::HttpGrpcAccessLog(
    FilterPtr&& filter, const envoy::api::v2::filter::accesslog::HttpGrpcAccessLogConfig&)
    : filter_(std::move(filter))

{}

void HttpGrpcAccessLog::log(const Http::HeaderMap*, const Http::HeaderMap*, const RequestInfo&) {}

} // namespace AccessLog
} // namespace Envoy
