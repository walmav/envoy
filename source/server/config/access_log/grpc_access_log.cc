#include "server/config/access_log/grpc_access_log.h"

#include "envoy/registry/registry.h"
#include "envoy/server/filter_config.h"

#include "common/access_log/grpc_access_log_impl.h"
#include "common/common/macros.h"
#include "common/config/well_known_names.h"
#include "common/protobuf/protobuf.h"

#include "api/filter/accesslog/accesslog.pb.validate.h"

namespace Envoy {
namespace Server {
namespace Configuration {

AccessLog::InstanceSharedPtr
HttpGrpcAccessLogFactory::createAccessLogInstance(const Protobuf::Message& config,
                                                  AccessLog::FilterPtr&& filter, FactoryContext&) {
  const auto& proto_config = MessageUtil::downcastAndValidate<
      const envoy::api::v2::filter::accesslog::HttpGrpcAccessLogConfig&>(config);

  // fixfix request/response headers to add.

  return AccessLog::InstanceSharedPtr{
      new AccessLog::HttpGrpcAccessLog(std::move(filter), proto_config)};
}

ProtobufTypes::MessagePtr HttpGrpcAccessLogFactory::createEmptyConfigProto() {
  return ProtobufTypes::MessagePtr{
      new envoy::api::v2::filter::accesslog::HttpGrpcAccessLogConfig()};
}

std::string HttpGrpcAccessLogFactory::name() const {
  return Config::AccessLogNames::get().HTTP_GRPC;
}

/**
 * Static registration for the HTTP gRPC access log. @see RegisterFactory.
 */
static Registry::RegisterFactory<HttpGrpcAccessLogFactory, AccessLogInstanceFactory> register_;

} // namespace Configuration
} // namespace Server
} // namespace Envoy
