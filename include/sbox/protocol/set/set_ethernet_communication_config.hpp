/// @file
/// @author Jongkuk Lim <limjk@jmarple.ai>
/// @copyright 2023 J.Marple
/// @brief Set ethernet communication config protocol

#ifndef SLAMBOX_SDK_INCLUDE_SBOX_PROTOCOL_SET_SET_ETHERNET_COMMUNICATION_CONFIG_HPP_
#define SLAMBOX_SDK_INCLUDE_SBOX_PROTOCOL_SET_SET_ETHERNET_COMMUNICATION_CONFIG_HPP_

#include <vector>

#include "sbox/protocol/base_protocol.hpp"
#include "sbox/utils/to_bytes.hpp"

namespace sbox {

/// @brief Set ethernet communication config protocol
class SetEthernetCommunicationConfigProtocol : public BaseProtocol {
 public:
  /// @brief Set ethernet communication config protocol constructor
  /// @param enabled enabled or not
  /// @param port port of ethernet communication
  SetEthernetCommunicationConfigProtocol(bool enabled, uint32_t port)
      : BaseProtocol(protocol::kModeSetEthernetCommConfig),
        enabled_(enabled),
        port_(port) {
    vector<uint8_t> port_bytes = to_bytes::four(port);
    this->payload_.clear();
    this->payload_.push_back(enabled);
    this->payload_.insert(this->payload_.end(), port_bytes.begin(),
                          port_bytes.end());
  }

  /// @brief Set ethernet communication config protocol constructor
  /// @param bytes byte array of whole protocol or payload only
  /// @param payload_only if true, then `bytes` is not decapsulated
  explicit SetEthernetCommunicationConfigProtocol(const vector<uint8_t> &bytes,
                                                  bool payload_only = false)
      : BaseProtocol(bytes, protocol::kModeSetEthernetCommConfig,
                     payload_only) {
    this->init_from_payload_();
  }

  /// @copydoc BaseProtocol::handle_callback
  void handle_callback(
      const vector<ParsedMessageInterface *> &callbacks) override {
    for (auto callback : callbacks) {
      callback->on_set_ethernet_communication_config(this->enabled_,
                                                     this->port_);
    }
  }

  /// @brief Get enabled or not
  /// @return enabled or not
  bool get_enabled() const { return enabled_; }

  /// @brief Get port of ethernet communication
  /// @return port of ethernet communication
  uint32_t get_port() const { return port_; }

 protected:
  /// @brief Initialize `enabled_` and `port_` from `payload`
  void init_from_payload_() override {
    this->enabled_ = this->payload_[0];
    this->port_ = from_bytes::to_int(
        vector<uint8_t>(this->payload_.begin() + 1, this->payload_.end()));
  }

 private:
  /// @brief enabled or not
  bool enabled_;

  /// @brief port of ethernet communication
  uint32_t port_;
};
}  // namespace sbox

#endif  // SLAMBOX_SDK_INCLUDE_SBOX_PROTOCOL_SET_SET_ETHERNET_COMMUNICATION_CONFIG_HPP_
