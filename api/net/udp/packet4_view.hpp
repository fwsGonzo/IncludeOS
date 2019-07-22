
#pragma once

#include "packet_view.hpp"
#include <net/ip4/packet_ip4.hpp>

namespace net::udp {

template <typename Ptr_type> class Packet4_v;
using Packet4_view = Packet4_v<net::Packet_ptr>;
using Packet4_view_raw = Packet4_v<net::Packet*>;

template <typename Ptr_type>
class Packet4_v : public Packet_v<Ptr_type> {
public:
  Packet4_v(Ptr_type ptr)
    : Packet_v<Ptr_type>(std::move(ptr))
  {
    Expects(packet().is_ipv4());
    this->set_header(packet().ip_data().data());
  }

  inline void init(const net::Socket& src, const net::Socket& dst);

  Protocol ipv() const noexcept override
  { return Protocol::IPv4; }

  ip4::Addr ip4_src() const noexcept
  { return packet().ip_src(); }

  ip4::Addr ip4_dst() const noexcept
  { return packet().ip_dst(); }

private:
  PacketIP4& packet() noexcept
  { return static_cast<PacketIP4&>(*this->pkt); }

  const PacketIP4& packet() const noexcept
  { return static_cast<PacketIP4&>(*this->pkt); }

  void set_ip_src(const net::Addr& addr) noexcept override
  { packet().set_ip_src(addr.v4()); }

  void set_ip_dst(const net::Addr& addr) noexcept override
  { packet().set_ip_dst(addr.v4()); }

  net::Addr ip_src() const noexcept override
  { return packet().ip_src(); }

  net::Addr ip_dst() const noexcept override
  { return packet().ip_dst(); }

  uint16_t ip_data_length() const noexcept override
  { return packet().ip_data_length(); }

  uint16_t ip_header_length() const noexcept override
  { return packet().ip_header_length(); }

};

template <typename Ptr_type>
inline void Packet4_v<Ptr_type>::init(const net::Socket& src, const net::Socket& dst)
{
  Expects(src.address().is_v4() and dst.address().is_v4());
  // set zero length
  this->set_length();
  // zero the optional checksum
  this->udp_header().checksum = 0;

  this->set_source(src);
  this->set_destination(dst);
}

}
