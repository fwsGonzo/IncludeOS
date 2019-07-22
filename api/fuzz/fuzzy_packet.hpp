#pragma once
#include "fuzzy_helpers.hpp"
#include <net/ethernet/ethertype.hpp>
#include <net/inet>

namespace fuzzy
{
extern uint8_t *add_eth_layer(uint8_t *data, FuzzyIterator &fuzzer,
			      net::Ethertype type);
extern uint8_t *add_ip4_layer(uint8_t *data, FuzzyIterator &fuzzer,
			      const net::ip4::Addr src_addr,
			      const net::ip4::Addr dst_addr,
			      const uint8_t protocol = 0);
extern uint8_t *add_udp4_layer(uint8_t *data, FuzzyIterator &fuzzer,
			       const uint16_t dport);
extern uint8_t *add_tcp4_layer(uint8_t *data, FuzzyIterator &fuzzer,
			       const uint16_t dport);
} // namespace fuzzy