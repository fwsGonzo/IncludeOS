
#ifndef KERNEL_SOLO5_MANAGER_HPP
#define KERNEL_SOLO5_MANAGER_HPP

#include <delegate>
#include <hw/block_device.hpp>
#include <hw/nic.hpp>
#include <memory>

class Solo5_manager {
    public:
	using Nic_ptr = std::unique_ptr<hw::Nic>;
	using Blk_ptr = std::unique_ptr<hw::Block_device>;

	static void register_net(delegate<Nic_ptr()>);
	static void register_blk(delegate<Blk_ptr()>);

	static void init();
}; //< class Solo5_manager

#endif //< KERNEL_SOLO5_MANAGER_HPP
